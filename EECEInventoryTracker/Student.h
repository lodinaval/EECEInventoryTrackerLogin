#pragma once
#include <string>

class Student {
public:
    Student();
    Student(const std::string& filePath);
    bool verifyCredentials(const std::string& studentNo, const std::string& password);
    std::string getName(const std::string& studentNo);
    std::string getProgram(const std::string& studentNo);
    std::string getContactInfo(const std::string& studentNo);
    std::string getEmail(const std::string& studentNo);

    void setName(const std::string& studentNo, const std::string& name);
    void setProgram(const std::string& studentNo, const std::string& program);
    void setContactInfo(const std::string& studentNo, const std::string& contactInfo);
    void setEmail(const std::string& studentNo, const std::string& email);
    void setPassword(const std::string& studentNo, const std::string& password);
    bool isStudent(const std::string& studentNo);

private:
    struct StudentInfo {
        std::string studentNo;
        std::string name;
        std::string program;
        std::string contactInfo;
        std::string email;
        std::string password;
    };

    StudentInfo studentData[1000];  // Assuming a maximum of 1000 students for simplicity
    int studentCount;

    void loadData(const std::string& filePath);
};
