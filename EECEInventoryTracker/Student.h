#ifndef STUDENT_H
#define STUDENT_H

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <unordered_map>


class Student
{
private:
    std::string name;
    std::string program;
    std::string email;
    long long studentID;
    long long contactInfo;
    std::vector<std::string> reservations;       // List of reservations
    std::vector<std::string> experimentHistory;  // Experiment history

public:
    Student();
    int getLineNumber(const std::string& filePath, const std::string& targetUser);
    std::string getDetailAtLine(const std::string& filePath, int lineNumber);
    std::string getName(const std::string& studentNumber);
    std::string getProgram(const std::string& studentNumber);
    std::string getContactInfo(const std::string& studentNumber);
    std::string getID(const std::string& studentNumber);
    std::string getEmail(const std::string& studentNumber);
};

#endif // STUDENT_H
