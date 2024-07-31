
/*
#include "Borrow.h"
#include <fstream>
#include <ctime>

Borrow::Borrow() {
    borrowID = "99999";
    borrowQuantity = "-1";
}
Borrow::Borrow(const std::string& filePath) {
    Equipment(filePath);
    borrowID = "99999";
    borrowQuantity = "-1";
}

std::string Borrow::getID(System::String^ id) {
    borrowID = msclr::interop::marshal_as<std::string>(id);
    return borrowID;
}

std::string Borrow::getQuantity(System::String^ quantity) {
    borrowQuantity = msclr::interop::marshal_as<std::string>(quantity);
    return borrowQuantity;
}

bool Borrow::BorrowValid() const {
    if (borrowID.empty() || borrowQuantity.empty()) {
        return false;
    }
    if (borrowQuantity == "0" || !std::all_of(borrowQuantity.begin(), borrowQuantity.end(), ::isdigit)) {
        return false;
    }
    return true;
}

System::String^ Borrow::generateTransactionID() const {
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y%m%d%H%M%S", &tstruct);
    return gcnew System::String(buf);
}

void Borrow::exportBorrowedItemsToCSV(System::String^ studentNumber, System::String^ transactionID, const std::string& filePath, System::Data::DataTable^ borrowedItemsTable) {
    std::ofstream outFile(filePath, std::ios::app);
    if (!outFile.is_open()) {
        throw std::runtime_error("File couldn't be opened at " + filePath);
    }

    DateTime now = DateTime::Now;
    System::String^ dateTime = now.ToString("yyyy-MM-dd HH:mm:ss");

    for each (System::Data::DataRow ^ row in borrowedItemsTable->Rows) {
        outFile << msclr::interop::marshal_as<std::string>(transactionID) << ","
            << msclr::interop::marshal_as<std::string>(studentNumber) << ","
            << msclr::interop::marshal_as<std::string>(dateTime) << ","
            << msclr::interop::marshal_as<std::string>(row["ID"]->ToString()) << ","
            << msclr::interop::marshal_as<std::string>(row["Name"]->ToString()) << ","
            << msclr::interop::marshal_as<std::string>(row["Type"]->ToString()) << ","
            << msclr::interop::marshal_as<std::string>(row["Status"]->ToString()) << ","
            << msclr::interop::marshal_as<std::string>(row["Specs"]->ToString()) << ","
            << msclr::interop::marshal_as<std::string>(row["Quantity"]->ToString()) << std::endl;
    }

    outFile.close();
}

void Borrow::exportEquipmentDataToCSV(const std::string& filePath, System::Data::DataTable^ equipmentTable) {
    std::ofstream outFile(filePath, std::ios::trunc);
    if (!outFile.is_open()) {
        throw std::runtime_error("File couldn't be opened at " + filePath);
    }

    outFile << "ID,Name,Type,Status,Specs,Quantity" << std::endl;

    for each (System::Data::DataRow ^ row in equipmentTable->Rows) {
        outFile << msclr::interop::marshal_as<std::string>(row["ID"]->ToString()) << ","
            << msclr::interop::marshal_as<std::string>(row["Name"]->ToString()) << ","
            << msclr::interop::marshal_as<std::string>(row["Type"]->ToString()) << ","
            << msclr::interop::marshal_as<std::string>(row["Status"]->ToString()) << ","
            << msclr::interop::marshal_as<std::string>(row["Specs"]->ToString()) << ","
            << msclr::interop::marshal_as<std::string>(row["Quantity"]->ToString()) << std::endl;
    }

    outFile.close();
}

BorrowedItem Borrow::BorrowItem(String^ id, String^ quantity, bool& found, bool& sufficientStock) {
    std::string borrowId = msclr::interop::marshal_as<std::string>(id);
    std::string borrowQuantity = msclr::interop::marshal_as<std::string>(quantity);
    std::ifstream file("C:\\Users\\Keith Naval\\Downloads\\equipments.csv");

    std::string line;
    BorrowedItem item;
    found = false;

    while (getline(file, line)) {
        std::stringstream ss(line);
        getline(ss, item.id, ',');
        getline(ss, item.name, ',');
        getline(ss, item.type, ',');
        getline(ss, item.status, ',');
        getline(ss, item.specs, ',');
        getline(ss, item.quantity, ',');

        if (item.id == borrowId) {
            found = true;
            int currentQuantity = std::stoi(item.quantity);
            int borrowQuantityInt = std::stoi(borrowQuantity);
            if (currentQuantity >= borrowQuantityInt) {
                sufficientStock = true;
            }
            else {
                sufficientStock = false;
            }
            break;
        }
    }

    return item;
}
*/