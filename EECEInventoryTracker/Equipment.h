#pragma once

#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <string>
#include <vector>
#include <cstring>
#include <fstream>
#include <sstream>
using namespace std;

struct EquipmentData {
    string equipmentId;
    string equipmentName;
    string equipmentType;
    string equipmentStatus;
    string equipmentSpecs;
    string equipmentQuantity;
};

class Equipment {
public:
    Equipment();
    Equipment(const std::string& filePath);

    // Accessors
    string getId(const std::string& id) const;
    string getName(const std::string& id) const;
    string getType(const std::string& id) const;
    string getStatus(const std::string& id) const;
    string getSpecs(const std::string& id) const;
    string getQuantity(const std::string& id) const;

    // Mutators
    void setId(const std::string& id, const string& newid);
    void setName(const std::string& id, const string& newname);
    void setType(const std::string& id, const string& newtype);
    void updateStatus(const std::string& id, const string& newstatus);
    void setSpecs(const std::string& id, const string& newspecs);
    void setQuantity(const std::string& id, const string& newquantity);

    // Methods
    void loadData(const std::string& filePath);
    void addEquipment(const string& id, const string& name, const string& type, const string& status, const string& specs, const string& quantity, const string& filePath);
    bool verifyEquipment(const string& id, const string& name);

    void updateCsv(const std::string& id, const std::string& name, const std::string& type, const std::string& status, const std::string& specs, const std::string& quantity, const std::string& filePath);
    void removeEntryFromCsv(const std::string& id, const std::string& filePath);
    bool isEquipmentInCSV(const std::string& id);
    int equipmentCount;

    static const int MAX_EQUIPMENT = 1000;
    EquipmentData equipmentData[MAX_EQUIPMENT];
};

#endif
