#pragma once
#include <string>

class Faculty {
public:
    Faculty();
    Faculty(const std::string& filePath);
    void loadData(const std::string& filePath);
    bool verifyCredentials(const std::string& facultyID, const std::string& password);
    std::string getName(const std::string& facultyID);
    std::string getDepartment(const std::string& facultyID);
    std::string getContactInfo(const std::string& facultyID);
    std::string getEmail(const std::string& facultyID);
    void setName(const std::string& facultyID, const std::string& name);
    void setDepartment(const std::string& facultyID, const std::string& department);
    void setContactInfo(const std::string& facultyID, const std::string& contactInfo);
    void setEmail(const std::string& facultyID, const std::string& email);
    void setPassword(const std::string& facultyID, const std::string& password);
    bool isFaculty(const std::string& facultyID);

private:
    struct FacultyData {
        std::string facultyID;
        std::string name;
        std::string department;
        std::string contactInfo;
        std::string email;
        std::string password;
    };

    FacultyData facultyData[100];
    int facultyCount;
};
