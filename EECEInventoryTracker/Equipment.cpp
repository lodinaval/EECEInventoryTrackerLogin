#include "Equipment.h"

Equipment::Equipment() {
    equipmentCount = 0;
}

Equipment::Equipment(const std::string& filePath) {
    loadData(filePath);
}

void Equipment::loadData(const std::string& filePath) {
    std::ifstream file(filePath);
    std::string line;
    equipmentCount = 0;

    while (std::getline(file, line)) {
        EquipmentData& data = equipmentData[equipmentCount];
        std::istringstream iss(line);
        std::getline(iss, data.equipmentId, ',');
        std::getline(iss, data.equipmentName, ',');
        std::getline(iss, data.equipmentType, ',');
        std::getline(iss, data.equipmentStatus, ',');
        std::getline(iss, data.equipmentSpecs, ',');
        std::getline(iss, data.equipmentQuantity, ',');
        equipmentCount++;
    }
}

string Equipment::getId(const std::string& id) const {
    for (int i = 0; i < equipmentCount; ++i) {
        if (equipmentData[i].equipmentId == id) {
            return equipmentData[i].equipmentId;
        }
    }
    return "";
}

string Equipment::getName(const std::string& id) const {
    for (int i = 0; i < equipmentCount; ++i) {
        if (equipmentData[i].equipmentId == id) {
            return equipmentData[i].equipmentName;
        }
    }
    return "";
}

string Equipment::getType(const std::string& id) const {
    for (int i = 0; i < equipmentCount; ++i) {
        if (equipmentData[i].equipmentId == id) {
            return equipmentData[i].equipmentType;
        }
    }
    return "";
}

string Equipment::getStatus(const std::string& id) const {
    for (int i = 0; i < equipmentCount; ++i) {
        if (equipmentData[i].equipmentId == id) {
            return equipmentData[i].equipmentStatus;
        }
    }
    return "";
}

string Equipment::getSpecs(const std::string& id) const {
    for (int i = 0; i < equipmentCount; ++i) {
        if (equipmentData[i].equipmentId == id) {
            return equipmentData[i].equipmentSpecs;
        }
    }
    return "";
}

string Equipment::getQuantity(const std::string& id) const {
    for (int i = 0; i < equipmentCount; ++i) {
        if (equipmentData[i].equipmentId == id) {
            return equipmentData[i].equipmentQuantity;
        }
    }
    return "";
}

// Mutators
void Equipment::setId(const std::string& id, const string& newid) {
    for (int i = 0; i < equipmentCount; ++i) {
        if (equipmentData[i].equipmentId == id) {
            equipmentData[i].equipmentId = newid;
        }
    }
}

void Equipment::setName(const std::string& id, const string& newname) {
    for (int i = 0; i < equipmentCount; ++i) {
        if (equipmentData[i].equipmentId == id) {
            equipmentData[i].equipmentName = newname;
        }
    }
}

void Equipment::setType(const std::string& id, const string& newtype) {
    for (int i = 0; i < equipmentCount; ++i) {
        if (equipmentData[i].equipmentId == id) {
            equipmentData[i].equipmentType = newtype;
        }
    }
}

void Equipment::updateStatus(const std::string& id, const string& newstatus) {
    for (int i = 0; i < equipmentCount; ++i) {
        if (equipmentData[i].equipmentId == id) {
            equipmentData[i].equipmentStatus = newstatus;
        }
    }
}

void Equipment::setSpecs(const std::string& id, const string& newspecs) {
    for (int i = 0; i < equipmentCount; ++i) {
        if (equipmentData[i].equipmentId == id) {
            equipmentData[i].equipmentSpecs = newspecs;
        }
    }
}

void Equipment::setQuantity(const std::string& id, const string& newquantity) {
    for (int i = 0; i < equipmentCount; ++i) {
        if (equipmentData[i].equipmentId == id) {
            equipmentData[i].equipmentQuantity = newquantity;
        }
    }
}

void Equipment::addEquipment(const string& id, const string& name, const string& type, const string& status, const string& specs, const string& quantity, const string& filePath) {
    std::ofstream file(filePath, std::ios::app);
    file << id << "," << name << "," << type << "," << status << "," << specs << "," << quantity << std::endl;
    file.close();
    loadData(filePath);
}

bool Equipment::verifyEquipment(const string& id, const string& name) {
    for (int i = 0; i < equipmentCount; ++i) {
        if (equipmentData[i].equipmentId == id && equipmentData[i].equipmentName == name) {
            return true;
        }
    }
    return false;
}

void Equipment::updateCsv(const std::string& id, const std::string& name, const std::string& type, const std::string& status, const std::string& specs, const std::string& quantity, const std::string& filePath) {
    std::ofstream file(filePath, std::ios::trunc);
    for (int i = 0; i < equipmentCount; ++i) {
        if (equipmentData[i].equipmentId == id) {
            equipmentData[i].equipmentName = name;
            equipmentData[i].equipmentType = type;
            equipmentData[i].equipmentStatus = status;
            equipmentData[i].equipmentSpecs = specs;
            equipmentData[i].equipmentQuantity = quantity;
        }
        file << equipmentData[i].equipmentId << "," << equipmentData[i].equipmentName << "," << equipmentData[i].equipmentType << "," << equipmentData[i].equipmentStatus << "," << equipmentData[i].equipmentSpecs << "," << equipmentData[i].equipmentQuantity << std::endl;
    }
    file.close();
    loadData(filePath);
}

void Equipment::removeEntryFromCsv(const std::string& id, const std::string& filePath) {
    std::ofstream file(filePath, std::ios::trunc);
    for (int i = 0; i < equipmentCount; ++i) {
        if (equipmentData[i].equipmentId != id) {
            file << equipmentData[i].equipmentId << "," << equipmentData[i].equipmentName << "," << equipmentData[i].equipmentType << "," << equipmentData[i].equipmentStatus << "," << equipmentData[i].equipmentSpecs << "," << equipmentData[i].equipmentQuantity << std::endl;
        }
    }
    file.close();
    loadData(filePath);
}

bool Equipment::isEquipmentInCSV(const std::string& id) {
    for (int i = 0; i < equipmentCount; ++i) {
        if (equipmentData[i].equipmentId == id) {
            return true;
        }
    }
    return false;
}

