#pragma once

#ifndef Equipment_H
#define Equipment_H

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Equipment {
public:
    Equipment();
    Equipment(const std::string& filePath);
    Equipment(const string& id, const string& name, const string& type, const string& status, const string& specs);

    // Accessors
    string getId() const;
    string getName() const;
    string getType() const;
    string getStatus() const;
    string getSpecs() const;
    vector<string> getMaintenanceHistory() const;

    // Mutators
    void setId(const string& id);
    void setName(const string& name);
    void setType(const string& type);
    void updateStatus(const string& status);
    void setSpecs(const string& specs);
    void addMaintenanceRecord(const string& record);

    // Methods
    void addEquipment(const string& id, const string& name, const string& type, const string& status, const string& specs, const string& filePath);
    void checkOut();
    void returnEquipment();
    void getDetails() const; // Prints out object details (ID, Name, Type, Status, Specs, and Maintenance)
    void generateReport() const;

    // Static methods for managing equipment list
    static vector<Equipment> initializeEquipmentList();
    static void displayAvailableEquipment(const vector<Equipment>& equipmentList);
    static vector<string> selectEquipment(vector<Equipment>& equipmentList, int count);

    // Accessor for equipmentData
    const std::unordered_map<std::string, Equipment>& getEquipmentData() const;

private:
    string equipmentId;
    string equipmentName;
    string equipmentType;
    string equipmentStatus;
    string equipmentSpecs;
    vector<string> maintenanceHistory;

    std::unordered_map<std::string, Equipment> equipmentData;
    void loadData(const std::string& filePath);
};

#endif
