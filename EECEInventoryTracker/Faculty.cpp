#include "Faculty.h"
#include <fstream>
#include <sstream>
#include <iostream>

Faculty::Faculty() {}

Faculty::Faculty(const std::string& filePath) {
    loadData(filePath);
}

void Faculty::loadData(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filePath << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line); // Skip the first line (header)

    int index = 0;

    while (std::getline(file, line) && index < 100) { // Assume max faculty is 100.
        std::stringstream ss(line); // String stream allows us to insert and extract from the csv file
        std::getline(ss, facultyData[index].facultyID, ',');
        std::getline(ss, facultyData[index].name, ',');
        std::getline(ss, facultyData[index].department, ',');
        std::getline(ss, facultyData[index].contactInfo, ',');
        std::getline(ss, facultyData[index].email, ',');
        std::getline(ss, facultyData[index].password, ',');

        index++;
    }
    facultyCount = index;

    // Debugging: Print loaded data
    for (int i = 0; i < facultyCount; ++i) {
        std::cout << "FacultyID: " << facultyData[i].facultyID
            << ", Name: " << facultyData[i].name
            << ", Department: " << facultyData[i].department
            << ", ContactInfo: " << facultyData[i].contactInfo
            << ", Email: " << facultyData[i].email
            << ", Password: " << facultyData[i].password << std::endl;
    }
}

bool Faculty::verifyCredentials(const std::string& facultyID, const std::string& password) {
    for (int i = 0; i < facultyCount; ++i) {
        if (facultyData[i].facultyID == facultyID && facultyData[i].password == password) {
            return true;
        }
    }
    return false;
}

std::string Faculty::getName(const std::string& facultyID) {
    for (int i = 0; i < facultyCount; ++i) {
        if (facultyData[i].facultyID == facultyID) {
            return facultyData[i].name;
        }
    }
    return "";
}

std::string Faculty::getDepartment(const std::string& facultyID) {
    for (int i = 0; i < facultyCount; ++i) {
        if (facultyData[i].facultyID == facultyID) {
            return facultyData[i].department;
        }
    }
    return "";
}

std::string Faculty::getContactInfo(const std::string& facultyID) {
    for (int i = 0; i < facultyCount; ++i) {
        if (facultyData[i].facultyID == facultyID) {
            return facultyData[i].contactInfo;
        }
    }
    return "";
}

std::string Faculty::getEmail(const std::string& facultyID) {
    for (int i = 0; i < facultyCount; ++i) {
        if (facultyData[i].facultyID == facultyID) {
            return facultyData[i].email;
        }
    }
    return "";
}

void Faculty::setName(const std::string& facultyID, const std::string& name) {
    for (int i = 0; i < facultyCount; ++i) {
        if (facultyData[i].facultyID == facultyID) {
            facultyData[i].name = name;
            break;
        }
    }
}

void Faculty::setDepartment(const std::string& facultyID, const std::string& department) {
    for (int i = 0; i < facultyCount; ++i) {
        if (facultyData[i].facultyID == facultyID) {
            facultyData[i].department = department;
            break;
        }
    }
}

void Faculty::setContactInfo(const std::string& facultyID, const std::string& contactInfo) {
    for (int i = 0; i < facultyCount; ++i) {
        if (facultyData[i].facultyID == facultyID) {
            facultyData[i].contactInfo = contactInfo;
            break;
        }
    }
}

void Faculty::setEmail(const std::string& facultyID, const std::string& email) {
    for (int i = 0; i < facultyCount; ++i) {
        if (facultyData[i].facultyID == facultyID) {
            facultyData[i].email = email;
            break;
        }
    }
}

void Faculty::setPassword(const std::string& facultyID, const std::string& password) {
    for (int i = 0; i < facultyCount; ++i) {
        if (facultyData[i].facultyID == facultyID) {
            facultyData[i].password = password;
            break;
        }
    }
}

bool Faculty::isFaculty(const std::string& facultyID) {
    for (int i = 0; i < facultyCount; ++i) {
        if (facultyData[i].facultyID == facultyID) {
            return true;
        }
    }
    return false;
}
