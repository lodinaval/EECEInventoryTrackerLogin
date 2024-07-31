#pragma once

#ifndef BORROW_H
#define BORROW_H

#include <string>
#include <msclr/marshal_cppstd.h>
#include <fstream>
#include "Equipment.h"

using namespace System;
using namespace System::Data;
using namespace System::Windows::Forms;

class Borrow {
public:
    static void BorrowEquipment(TextBox^ borrowIDTextBox, TextBox^ borrowQuantityTextBox, DataTable^ equipmentTable, DataTable^ borrowedItemsTable, DataGridView^ dataGridView) {
        // Convert System::String^ to std::string
        std::string borrowIDStr = msclr::interop::marshal_as<std::string>(borrowIDTextBox->Text);
        std::string borrowQuantityStr = msclr::interop::marshal_as<std::string>(borrowQuantityTextBox->Text);

        // Validate the input values
        if (borrowIDStr.empty() || borrowQuantityStr.empty()) {
            MessageBox::Show("Please input valid values in all the required fields: ID, Quantity", "Input Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        // Convert borrowQuantityStr to an integer
        int borrowQuantityInt;
        try {
            borrowQuantityInt = std::stoi(borrowQuantityStr); //Makes the integer into a string. If its invalid, that means the input wasnt an integer
        }
        catch (const std::invalid_argument&) {
            MessageBox::Show("Please input a valid quantity.", "Input Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        // Search for the equipment in equipmentTable using borrowID
        DataRow^ foundRow = nullptr;
        for each (DataRow ^ row in equipmentTable->Rows) {
            if (row["ID"]->ToString() == gcnew String(borrowIDStr.c_str())) {
                foundRow = row;
                break;
            }
        }

        if (foundRow == nullptr) {
            MessageBox::Show("ID not found in the equipment list.", "ID Not Found", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        // Check if the quantity is sufficient
        int currentQuantity = Int32::Parse(foundRow["Quantity"]->ToString());
        if (borrowQuantityInt > currentQuantity) {
            MessageBox::Show("Not enough stock available.", "Stock Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        // Update the quantity in equipmentTable
        foundRow["Quantity"] = (currentQuantity - borrowQuantityInt).ToString();

        // Add the equipment details to borrowedItemsGrid
        DataRow^ newRow = borrowedItemsTable->NewRow();
        newRow["ID"] = foundRow["ID"];
        newRow["Name"] = foundRow["Name"];
        newRow["Type"] = foundRow["Type"];
        newRow["Status"] = foundRow["Status"];
        newRow["Specs"] = foundRow["Specs"];
        newRow["Quantity"] = gcnew String(borrowQuantityStr.c_str());
        borrowedItemsTable->Rows->Add(newRow);

        // Refresh the dataGridView to reflect the updated equipmentTable
        dataGridView->DataSource = equipmentTable;
    }

    static void CheckOut(DataTable^ borrowedItemsTable, DataTable^ equipmentTable, Form^ InventoryManager, String^ StudentNumber) {
        if (borrowedItemsTable->Rows->Count == 0) {
            MessageBox::Show("No items have been added to borrow.", "Finalize Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        std::string transactionsFilePath = "C:\\Users\\Keith Naval\\Downloads\\borrowTransactions.csv";
        std::string equipmentFilePath = "C:\\Users\\Keith Naval\\Downloads\\equipments.csv";

        // Generate a Transaction ID using the current date and time
        String^ transactionID = GenerateTransactionID();
        DateTime now = DateTime::Now;
        String^ dateTimeString = now.ToString("M/d/yyyy HH:mm");

        // Export borrowed items to borrowTransactions.csv
        ExportBorrowedItemsToCSV(transactionID, StudentNumber, dateTimeString, transactionsFilePath, borrowedItemsTable);

        // Update equipment data in equipments.csv
        ExportEquipmentDataToCSV(equipmentFilePath, equipmentTable);

        // Show the Transaction ID
        String^ message = String::Format("Please remember your Transaction ID: {0}", transactionID);
        MessageBox::Show(message, "Finalization Successful", MessageBoxButtons::OK, MessageBoxIcon::Information);

        // Show the InventoryManager form
        InventoryManager->Show();

        // Clear the borrowed items table after checkout
        borrowedItemsTable->Clear();
    }

private:
    // Function to generate a Transaction ID using the current date and time
    static String^ GenerateTransactionID() {
        DateTime now = DateTime::Now;
        return now.ToString("yyyyMMddHHmm");
    }

    // Function to export borrowed items to a CSV file
    static void ExportBorrowedItemsToCSV(String^ transactionID, String^ studentNumber, String^ dateTimeString, std::string transactionsFilePath, DataTable^ borrowedItemsTable) {
        std::ofstream file(transactionsFilePath, std::ios::app); // Open file in append mode
        if (!file.is_open()) {
            MessageBox::Show("Failed to open transactions file.", "File Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        for each (DataRow ^ row in borrowedItemsTable->Rows) {
            file << msclr::interop::marshal_as<std::string>(transactionID) << ","
                << msclr::interop::marshal_as<std::string>(studentNumber) << ","
                << msclr::interop::marshal_as<std::string>(dateTimeString) << ","
                << msclr::interop::marshal_as<std::string>(row["ID"]->ToString()) << ","
                << msclr::interop::marshal_as<std::string>(row["Name"]->ToString()) << ","
                << msclr::interop::marshal_as<std::string>(row["Type"]->ToString()) << ","
                << msclr::interop::marshal_as<std::string>(row["Status"]->ToString()) << ","
                << msclr::interop::marshal_as<std::string>(row["Specs"]->ToString()) << ","
                << msclr::interop::marshal_as<std::string>(row["Quantity"]->ToString()) << "\n";
        }

        file.close();
    }

    // Function to update equipment data in a CSV file
    static void ExportEquipmentDataToCSV(std::string equipmentFilePath, DataTable^ equipmentTable) {
        std::ofstream file(equipmentFilePath); // Open file in write mode
        if (!file.is_open()) {
            MessageBox::Show("Failed to open equipment file.", "File Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        // Write headers
        file << "ID,Name,Type,Status,Specs,Quantity\n";

        for each (DataRow ^ row in equipmentTable->Rows) {
            file << msclr::interop::marshal_as<std::string>(row["ID"]->ToString()) << ","
                << msclr::interop::marshal_as<std::string>(row["Name"]->ToString()) << ","
                << msclr::interop::marshal_as<std::string>(row["Type"]->ToString()) << ","
                << msclr::interop::marshal_as<std::string>(row["Status"]->ToString()) << ","
                << msclr::interop::marshal_as<std::string>(row["Specs"]->ToString()) << ","
                << msclr::interop::marshal_as<std::string>(row["Quantity"]->ToString()) << "\n";
        }

        file.close();
    }
};

#endif
