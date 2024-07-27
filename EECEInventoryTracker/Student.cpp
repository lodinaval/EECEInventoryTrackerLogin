#include "Student.h"
#include <fstream>
#include <sstream>
#include <iostream>

Student::Student() {
}

Student::Student(const std::string& filePath) {
    loadData(filePath);
}

void Student::loadData(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filePath << std::endl;
        return;
    }

    std::string line, studentNo, name, program, contactInfo, email, password;

    // Skip the first line (header)
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::getline(ss, studentNo, ',');
        std::getline(ss, name, ',');
        std::getline(ss, program, ',');
        std::getline(ss, contactInfo, ',');
        std::getline(ss, email, ',');
        std::getline(ss, password, ',');

        studentData[studentNo] = { name, program, contactInfo, email, password };
    }
}

bool Student::verifyCredentials(const std::string& studentNo, const std::string& password) {
    return studentData.find(studentNo) != studentData.end() && studentData[studentNo].password == password;
}

std::string Student::getName(const std::string& studentNo) {
    return studentData[studentNo].name;
}

std::string Student::getProgram(const std::string& studentNo) {
    return studentData[studentNo].program;
}

std::string Student::getContactInfo(const std::string& studentNo) {
    return studentData[studentNo].contactInfo;
}

std::string Student::getEmail(const std::string& studentNo) {
    return studentData[studentNo].email;
}
