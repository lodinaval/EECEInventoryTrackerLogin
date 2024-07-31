#pragma once

#ifndef MAINTENANCE_H
#define MAINTENANCE_H

#include <string>
#include <fstream>
#include <msclr/marshal_cppstd.h>
#include <sstream>
#include "Equipment.h"

using namespace System;
using namespace System::Data;
using namespace System::Windows::Forms;

class Maintenance {
private:
    std::string equipmentID;
    std::string date;
    std::string description;
    std::string technician;

public:
    // Constructors
    Maintenance() {}

    Maintenance(std::string ID, std::string d, std::string desc, std::string tech) {
        equipmentID = ID;
        date = d;
        description = desc;
        technician = tech;
    }

    // Accessors
    std::string getEquipmentID() const {
        return equipmentID;
    }

    std::string getDate() const {
        return date;
    }

    std::string getDescription() const {
        return description;
    }

    std::string getTechnician() const {
        return technician;
    }

    // Mutators
    void setEquipmentID(const std::string& ID) {
        equipmentID = ID;
    }

    void setDate(const std::string& d) {
        date = d;
    }

    void setDescription(const std::string& desc) {
        description = desc;
    }

    void setTechnician(const std::string& tech) {
        technician = tech;
    }

    // Load maintenance data from CSV
    DataTable^ LoadMaintenanceData(String^ filePath) {
        std::ifstream file(msclr::interop::marshal_as<std::string>(filePath));
        std::string line;
        DataTable^ dt = gcnew DataTable();
        dt->Columns->Add("Equipment ID");
        dt->Columns->Add("Date");
        dt->Columns->Add("Description");
        dt->Columns->Add("Technician");

        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string equipmentID, date, description, technician;

            std::getline(iss, equipmentID, ',');
            std::getline(iss, date, ',');
            std::getline(iss, description, ',');
            std::getline(iss, technician, ',');

            DataRow^ row = dt->NewRow();
            row["Equipment ID"] = gcnew String(equipmentID.c_str());
            row["Date"] = gcnew String(date.c_str());
            row["Description"] = gcnew String(description.c_str());
            row["Technician"] = gcnew String(technician.c_str());
            dt->Rows->Add(row);
        }

        return dt;
    }

    // Load equipment data from CSV
    DataTable^ LoadEquipmentData(String^ filePath) {
        Equipment equipment(msclr::interop::marshal_as<std::string>(filePath));
        DataTable^ dt = gcnew DataTable(); // Create new table
        dt->Columns->Add("ID");
        dt->Columns->Add("Name");
        dt->Columns->Add("Type");
        dt->Columns->Add("Status");
        dt->Columns->Add("Specs");
        dt->Columns->Add("Quantity");

        for (int i = 0; i < equipment.equipmentCount; ++i) {
            DataRow^ row = dt->NewRow();
            row["ID"] = gcnew String(equipment.getId(equipment.equipmentData[i].equipmentId).c_str());
            row["Name"] = gcnew String(equipment.getName(equipment.equipmentData[i].equipmentId).c_str());
            row["Type"] = gcnew String(equipment.getType(equipment.equipmentData[i].equipmentId).c_str());
            row["Status"] = gcnew String(equipment.getStatus(equipment.equipmentData[i].equipmentId).c_str());
            row["Specs"] = gcnew String(equipment.getSpecs(equipment.equipmentData[i].equipmentId).c_str());
            row["Quantity"] = gcnew String(equipment.getQuantity(equipment.equipmentData[i].equipmentId).c_str());
            dt->Rows->Add(row);
        }

        return dt;
    }
};

#endif
#pragma once

#ifndef MAINTENANCE_H
#define MAINTENANCE_H

#include <string>
#include <fstream>
#include <msclr/marshal_cppstd.h>
#include <sstream>
#include "Equipment.h"

using namespace System;
using namespace System::Data;
using namespace System::Windows::Forms;

class Maintenance {
private:
    std::string equipmentID;
    std::string date;
    std::string description;
    std::string technician;

public:
    // Constructors
    Maintenance() {}

    Maintenance(std::string ID, std::string d, std::string desc, std::string tech) {
        equipmentID = ID;
        date = d;
        description = desc;
        technician = tech;
    }

    // Accessors
    std::string getEquipmentID() const {
        return equipmentID;
    }

    std::string getDate() const {
        return date;
    }

    std::string getDescription() const {
        return description;
    }

    std::string getTechnician() const {
        return technician;
    }

    // Mutators
    void setEquipmentID(const std::string& ID) {
        equipmentID = ID;
    }

    void setDate(const std::string& d) {
        date = d;
    }

    void setDescription(const std::string& desc) {
        description = desc;
    }

    void setTechnician(const std::string& tech) {
        technician = tech;
    }

    // Load maintenance data from CSV
    DataTable^ LoadMaintenanceData(String^ filePath) {
        std::ifstream file(msclr::interop::marshal_as<std::string>(filePath));
        std::string line;
        DataTable^ dt = gcnew DataTable();
        dt->Columns->Add("Equipment ID");
        dt->Columns->Add("Date");
        dt->Columns->Add("Description");
        dt->Columns->Add("Technician");

        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string equipmentID, date, description, technician;

            std::getline(iss, equipmentID, ',');
            std::getline(iss, date, ',');
            std::getline(iss, description, ',');
            std::getline(iss, technician, ',');

            DataRow^ row = dt->NewRow();
            row["Equipment ID"] = gcnew String(equipmentID.c_str());
            row["Date"] = gcnew String(date.c_str());
            row["Description"] = gcnew String(description.c_str());
            row["Technician"] = gcnew String(technician.c_str());
            dt->Rows->Add(row);
        }

        return dt;
    }

    // Load equipment data from CSV
    DataTable^ LoadEquipmentData(String^ filePath) {
        Equipment equipment(msclr::interop::marshal_as<std::string>(filePath));
        DataTable^ dt = gcnew DataTable(); // Create new table
        dt->Columns->Add("ID");
        dt->Columns->Add("Name");
        dt->Columns->Add("Type");
        dt->Columns->Add("Status");
        dt->Columns->Add("Specs");
        dt->Columns->Add("Quantity");

        for (int i = 0; i < equipment.equipmentCount; ++i) {
            DataRow^ row = dt->NewRow();
            row["ID"] = gcnew String(equipment.getId(equipment.equipmentData[i].equipmentId).c_str());
            row["Name"] = gcnew String(equipment.getName(equipment.equipmentData[i].equipmentId).c_str());
            row["Type"] = gcnew String(equipment.getType(equipment.equipmentData[i].equipmentId).c_str());
            row["Status"] = gcnew String(equipment.getStatus(equipment.equipmentData[i].equipmentId).c_str());
            row["Specs"] = gcnew String(equipment.getSpecs(equipment.equipmentData[i].equipmentId).c_str());
            row["Quantity"] = gcnew String(equipment.getQuantity(equipment.equipmentData[i].equipmentId).c_str());
            dt->Rows->Add(row);
        }

        return dt;
    }
};

#endif
