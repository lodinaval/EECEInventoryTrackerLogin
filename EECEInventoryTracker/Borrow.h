#pragma once
#ifndef BORROW_H
#define BORROW_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <msclr/marshal_cppstd.h>

using namespace std;
using namespace System; 
using namespace System::Data; //Used to access datagridview

inline bool is_number(const std::string& s) // Just used to check if string is number
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

class Stock {
public:
    Stock() {}
    Stock(const string& id, const string& quantity) {
        borrowID = id;
        borrowQuantity = quantity;
    }

    std::string getID(String^ id) {
        borrowID = msclr::interop::marshal_as<std::string>(id);
        return borrowID;
    }

    std::string getQuantity(String^ quantity) {
        borrowQuantity = msclr::interop::marshal_as<std::string>(quantity);
        return borrowQuantity;
    }

    bool BorrowValid() { // Checks if there is input at least
        if (borrowID.empty() || borrowQuantity.empty()) {
            return false;
        }
        int borrowQuantityInt = stoi(borrowQuantity);
        if (!is_number(borrowQuantity) || borrowQuantityInt == 0) { // If quantity input is not a number or a zero, return false
            return false;
        }
        return true;
    }

    String^ generateTransactionID() {
        int counter = 0;
        String^ currentDate;
        DateTime now = DateTime::Now;
        String^ date = now.ToString("yyyyMMdd");

        if (currentDate != date) {
            currentDate = date;
            counter = 0; // Reset the counter for a new day
        }
        counter++;
        return date + counter.ToString("D4"); // Date + counter with leading zeros (4 digits)
    }

    void exportBorrowedItemsToCSV(String^ studentNumber, String^ transactionID, const std::string& filePath, DataTable^ borrowedItemsTable) {
        DateTime now = DateTime::Now;
        String^ dateTime = now.ToString("yyyy-MM-dd HH:mm:ss");

        std::ofstream outFile;
        outFile.open(filePath, std::ios::app); // std::ios::app appends to the end of the file

        if (!outFile.is_open()) {
            cerr << "File couldn't be opened at " << filePath << endl;
            return;
        }

        for each (DataRow ^ row in borrowedItemsTable->Rows) {
            outFile << msclr::interop::marshal_as<std::string>(transactionID) << ","
                << msclr::interop::marshal_as<std::string>(studentNumber) << ","
                << msclr::interop::marshal_as<std::string>(dateTime) << ","
                << msclr::interop::marshal_as<std::string>(row["ID"]->ToString()) << ","
                << msclr::interop::marshal_as<std::string>(row["Name"]->ToString()) << ","
                << msclr::interop::marshal_as<std::string>(row["Type"]->ToString()) << ","
                << msclr::interop::marshal_as<std::string>(row["Status"]->ToString()) << ","
                << msclr::interop::marshal_as<std::string>(row["Specs"]->ToString()) << ","
                << msclr::interop::marshal_as<std::string>(row["Quantity"]->ToString()) << endl;
        }

        outFile.close();
    }

    void exportEquipmentDataToCSV(const string& filePath, System::Data::DataTable^ equipmentTable) {
        std::ofstream outFile;
        outFile.open(filePath, std::ios::trunc); // std::ios::trunc overwrites the file

        if (!outFile.is_open()) {
            cerr << "File couldn't be opened at " << filePath << endl;
            return;
        }

        // Write the header
        outFile << "ID,Name,Type,Status,Specs,Quantity" << endl;

        for each (DataRow ^ row in equipmentTable->Rows) {
            outFile << msclr::interop::marshal_as<std::string>(row["ID"]->ToString()) << ","
                << msclr::interop::marshal_as<std::string>(row["Name"]->ToString()) << ","
                << msclr::interop::marshal_as<std::string>(row["Type"]->ToString()) << ","
                << msclr::interop::marshal_as<std::string>(row["Status"]->ToString()) << ","
                << msclr::interop::marshal_as<std::string>(row["Specs"]->ToString()) << ","
                << msclr::interop::marshal_as<std::string>(row["Quantity"]->ToString()) << endl;
        }

        outFile.close();
    }


    // Method for when borrow is clicked
    vector<string> Borrow(String^ id, String^ quantity, bool& found, bool& sufficientStock) {
        string borrowID = getID(id);
        string borrowQuantity = getQuantity(quantity);

        // If input is valid it gets input from the file
        if (BorrowValid()) {
            ifstream file("C:\\Users\\Keith Naval\\Downloads\\equipments.csv"); // open file path
            string line;
            vector<string> borrowedData;
            found = false;

            while (getline(file, line)) {
                stringstream ss(line);
                string currentID, name, type, status, specs, currentQuantity;

                getline(ss, currentID, ',');
                getline(ss, name, ',');
                getline(ss, type, ',');
                getline(ss, status, ',');
                getline(ss, specs, ',');
                getline(ss, currentQuantity, ',');

                if (currentID == borrowID) {
                    found = true;
                    if (currentQuantity == "0") {
                        sufficientStock = false;
                    }
                    else if (stoi(currentQuantity) >= stoi(borrowQuantity)) {
                        sufficientStock = true;
                        borrowedData = { currentID, name, type, status, specs, currentQuantity };
                    }
                    else {
                        sufficientStock = false;
                    }
                    break;
                }
            }

            file.close();
            return borrowedData;
        }
        return {};
    }

private:
    string borrowID = "99999";
    string borrowQuantity = "-1";
};

#endif
