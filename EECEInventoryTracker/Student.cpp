#include "Student.h"
#include <fstream>
#include <sstream>
#include <iostream>

Student::Student(){}

Student::Student(const std::string& filePath){
    loadData(filePath);
}

void Student::loadData(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filePath << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line); // Skip the first line (header)

    int index = 0;

    while (std::getline(file, line) && index < 1000) { // Assume max students is 1000.
        std::stringstream ss(line); // String stream allows us to insert and extract from the csv file
        std::getline(ss, studentData[index].studentNo, ',');
        std::getline(ss, studentData[index].name, ',');
        std::getline(ss, studentData[index].program, ',');
        std::getline(ss, studentData[index].contactInfo, ',');
        std::getline(ss, studentData[index].email, ',');
        std::getline(ss, studentData[index].password, ',');

        index++;
    }
    studentCount = index;
}

bool Student::verifyCredentials(const std::string& studentNo, const std::string& password) {
    for (int i = 0; i < studentCount; ++i) {
        if (studentData[i].studentNo == studentNo && studentData[i].password == password) {
            return true;
        }
    }
    return false;
}

std::string Student::getName(const std::string& studentNo) {
    for (int i = 0; i < studentCount; ++i) {
        if (studentData[i].studentNo == studentNo) {
            return studentData[i].name;
        }
    }
    return "";
}

std::string Student::getProgram(const std::string& studentNo) {
    for (int i = 0; i < studentCount; ++i) {
        if (studentData[i].studentNo == studentNo) {
            return studentData[i].program;
        }
    }
    return "";
}

std::string Student::getContactInfo(const std::string& studentNo) {
    for (int i = 0; i < studentCount; ++i) {
        if (studentData[i].studentNo == studentNo) {
            return studentData[i].contactInfo;
        }
    }
    return "";
}

std::string Student::getEmail(const std::string& studentNo) {
    for (int i = 0; i < studentCount; ++i) {
        if (studentData[i].studentNo == studentNo) {
            return studentData[i].email;
        }
    }
    return "";
}

void Student::setName(const std::string& studentNo, const std::string& name) {
    for (int i = 0; i < studentCount; ++i) {
        if (studentData[i].studentNo == studentNo) {
            studentData[i].name = name;
            break;
        }
    }
}

void Student::setProgram(const std::string& studentNo, const std::string& program) {
    for (int i = 0; i < studentCount; ++i) {
        if (studentData[i].studentNo == studentNo) {
            studentData[i].program = program;
            break;
        }
    }
}

void Student::setContactInfo(const std::string& studentNo, const std::string& contactInfo) {
    for (int i = 0; i < studentCount; ++i) {
        if (studentData[i].studentNo == studentNo) {
            studentData[i].contactInfo = contactInfo;
            break;
        }
    }
}

void Student::setEmail(const std::string& studentNo, const std::string& email) {
    for (int i = 0; i < studentCount; ++i) {
        if (studentData[i].studentNo == studentNo) {
            studentData[i].email = email;
            break;
        }
    }
}

void Student::setPassword(const std::string& studentNo, const std::string& password) {
    for (int i = 0; i < studentCount; ++i) {
        if (studentData[i].studentNo == studentNo) {
            studentData[i].password = password;
            break;
        }
    }
}

bool Student::isStudent(const std::string& studentNo) {
    for (int i = 0; i < studentCount; ++i) {
        if (studentData[i].studentNo == studentNo) {
            return true;
            break;
        }
        else
            return false;
    }
}