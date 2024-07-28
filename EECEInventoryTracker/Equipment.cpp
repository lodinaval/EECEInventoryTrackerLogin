#include "Equipment.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

Equipment::Equipment() {}

Equipment::Equipment(const std::string& filePath) {
    loadData(filePath);
}

void Equipment::loadData(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filePath << std::endl;
        return;
    }
    std::string id, name, type, status, specs, quantity, line;
    vector<string> maintenanceHistory;

    std::getline(file, line); // Skip header row

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::getline(ss, id, ',');
        std::getline(ss, name, ',');
        std::getline(ss, type, ',');
        std::getline(ss, status, ',');
        std::getline(ss, specs, ',');
        std::getline(ss, quantity, ',');

        equipmentData[id] = Equipment(id, name, type, status, specs, quantity);
    }
}

Equipment::Equipment(const string& id, const string& name, const string& type, const string& status, const string& specs, const string& quantity) {
    equipmentId = id;
    equipmentName = name;
    equipmentType = type;
    equipmentStatus = status;
    equipmentSpecs = specs;
    equipmentQuantity = quantity;
}

string Equipment::getId() const {
    return equipmentId;
}

string Equipment::getName() const {
    return equipmentName;
}

string Equipment::getType() const {
    return equipmentType;
}

string Equipment::getStatus() const {
    return equipmentStatus;
}

string Equipment::getSpecs() const {
    return equipmentSpecs;
}

string Equipment::getQuantity() const {
    return equipmentQuantity;
}

vector<string> Equipment::getMaintenanceHistory() const {
    return maintenanceHistory;
}

void Equipment::setId(const string& id) {
    equipmentId = id;
}

void Equipment::setName(const string& name) {
    equipmentName = name;
}

void Equipment::setType(const string& type) {
    equipmentType = type;
}

void Equipment::updateStatus(const string& status) {
    equipmentStatus = status;
}

void Equipment::setSpecs(const string& specs) {
    equipmentSpecs = specs;
}

void Equipment::setQuantity(const string& quantity) {
    equipmentQuantity = quantity;
}

void Equipment::addMaintenanceRecord(const string& record) {
    maintenanceHistory.push_back(record);
}

void Equipment::checkOut() {
    if (equipmentStatus == "available") {
        equipmentStatus = "in use";
        cout << equipmentName << " checked out successfully." << endl;
    }
    else {
        cout << equipmentName << " is not available for check out." << endl;
    }
}

void Equipment::returnEquipment() {
    if (equipmentStatus == "in use") {
        equipmentStatus = "available";
        cout << equipmentName << " returned successfully." << endl;
    }
    else {
        cout << equipmentName << " is not checked out." << endl;
    }
}

void Equipment::getDetails() const {
    cout << "ID: " << equipmentId << endl;
    cout << "Name: " << equipmentName << endl;
    cout << "Type: " << equipmentType << endl;
    cout << "Status: " << equipmentStatus << endl;
    cout << "Specs: " << equipmentSpecs << endl;
    cout << "Quantity: " << equipmentQuantity << endl;
    cout << "Maintenance History: ";
    for (const auto& record : maintenanceHistory) {
        cout << record << " ";
    }
    cout << endl;
}

void Equipment::generateReport() const {
    cout << "Equipment Report for " << equipmentName << ":" << endl;
    getDetails();
}

void Equipment::addEquipment(const string& id, const string& name, const string& type, const string& status, const string& specs, const string& quantity, const string& filePath) {
    std::ofstream file(filePath, std::ios::app);
    if (!file.is_open()) {
        std::cerr << "Error opening file" << filePath << std::endl;
        return;
    }
    file << id << "," << name << "," << type << "," << status << "," << specs << "," << quantity << std::endl;
    file.close();

    equipmentData[id] = Equipment(id, name, type, status, specs, quantity);
}

const std::unordered_map<std::string, Equipment>& Equipment::getEquipmentData() const {
    return equipmentData;
}
