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
    std::string id, name, type, status, specs, line;
    vector<string> maintenanceHistory;

    std::getline(file, line); // Skip header row

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::getline(ss, id, ',');
        std::getline(ss, name, ',');
        std::getline(ss, type, ',');
        std::getline(ss, status, ',');
        std::getline(ss, specs, ',');

        equipmentData[id] = Equipment(id, name, type, status, specs);
    }
}

Equipment::Equipment(const string& id, const string& name, const string& type, const string& status, const string& specs) {
    equipmentId = id;
    equipmentName = name;
    equipmentType = type;
    equipmentStatus = status;
    equipmentSpecs = specs;
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

vector<Equipment> Equipment::initializeEquipmentList() {
    return {
        Equipment("E001", "Microscope", "Optical", "available", "10x-100x magnification"),
        Equipment("E002", "Oscilloscope", "Electrical", "available", "100MHz bandwidth"),
        Equipment("E003", "Soldering Station", "Tool", "available", "Adjustable temperature"),
        Equipment("E004", "Function Generator", "Electrical", "available", "1Hz-1MHz frequency range"),
        Equipment("E005", "Multimeter", "Electrical", "available", "Voltage, current, resistance measurements"),
        Equipment("E006", "Spectrometer", "Optical", "available", "UV-Visible range"),
        Equipment("E007", "Power Supply", "Electrical", "available", "0-30V adjustable output"),
        Equipment("E008", "Breadboard", "Tool", "available", "For prototyping circuits"),
        Equipment("E009", "Laser", "Optical", "available", "Various wavelengths"),
        Equipment("E010", "Ammeter", "Electrical", "available", "Current measurement"),
        Equipment("E011", "Voltmeter", "Electrical", "available", "Voltage measurement"),
        Equipment("E012", "Capacitance Meter", "Electrical", "available", "Capacitance measurement"),
        Equipment("E013", "Inductance Meter", "Electrical", "available", "Inductance measurement"),
        Equipment("E014", "DC Motor", "Mechanical", "available", "Variable speed"),
        Equipment("E015", "Thermocouple", "Thermal", "available", "Temperature measurement"),
        Equipment("E016", "pH Meter", "Chemical", "available", "pH measurement"),
        Equipment("E017", "Micrometer", "Mechanical", "available", "Precision measurement"),
        Equipment("E018", "Waveform Generator", "Electrical", "available", "Waveform generation"),
        Equipment("E019", "Signal Analyzer", "Electrical", "available", "Signal analysis"),
        Equipment("E020", "Digital Thermometer", "Thermal", "available", "Temperature measurement"),
    };
}

void Equipment::addEquipment(const string& id, const string& name, const string& type, const string& status, const string& specs, const string& filePath) {
    std::ofstream file(filePath, std::ios::app);
    if (!file.is_open()) {
        std::cerr << "Error opening file" << filePath << std::endl;
        return;
    }
    file << id << "," << name << "," << type << "," << status << "," << specs << std::endl;
    file.close();

    // Add to internal data structure
    equipmentData[id] = Equipment(id, name, type, status, specs);
}

void Equipment::displayAvailableEquipment(const vector<Equipment>& equipmentList) {
    cout << "Available Equipment:" << endl;
    for (size_t i = 0; i < equipmentList.size(); ++i) {
        cout << i + 1 << ". " << equipmentList[i].getName() << " - " << equipmentList[i].getStatus() << endl;
    }
}

vector<string> Equipment::selectEquipment(vector<Equipment>& equipmentList, int count) {
    vector<string> selectedEquipment;
    int equipmentChoice;

    for (int i = 0; i < count; ++i) {
        cout << "Select equipment " << i + 1 << " (by number): ";
        cin >> equipmentChoice;
        cin.ignore(); // Ignore newline

        if (equipmentChoice > 0 && equipmentChoice <= equipmentList.size()) {
            selectedEquipment.push_back(equipmentList[equipmentChoice - 1].getName());
            equipmentList[equipmentChoice - 1].checkOut(); // Mark equipment as in use
        }
        else {
            cout << "Invalid choice, try again." << endl;
            --i; // Try again
        }
    }

    return selectedEquipment;
}

const std::unordered_map<std::string, Equipment>& Equipment::getEquipmentData() const {
    return equipmentData;
}