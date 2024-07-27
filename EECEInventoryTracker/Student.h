#pragma once

#include <string>
#include <vector>
#include <unordered_map>

class Student {
public:
    Student();
    Student(const std::string& filePath);
    bool verifyCredentials(const std::string& studentNo, const std::string& password);
    std::string getName(const std::string& studentNo);
    std::string getProgram(const std::string& studentNo);
    std::string getContactInfo(const std::string& studentNo);
    std::string getEmail(const std::string& studentNo);

private:
    struct StudentInfo {
        std::string name;
        std::string program;
        std::string contactInfo;
        std::string email;
        std::string password;
    };
    std::unordered_map<std::string, StudentInfo> studentData;
    void loadData(const std::string& filePath);
};
