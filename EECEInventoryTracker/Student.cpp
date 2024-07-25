#include "Student.h"
#include "InventoryManagerUI.h"

static System::String^ converterToString(const std::string& temp) {
    return gcnew System::String(temp.c_str()); // Converts std::string to System::String^
}

Student::Student() = default;

int Student::getLineNumber(const std::string& filePath, const std::string& targetUser) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return -1; // Return -1 if the file couldn't be opened
    }

    std::string line;
    int lineNumber = 0;

    while (std::getline(file, line)) { // Read line by line
        lineNumber++;
        if (line == targetUser) { // Compare each line with the targetUser
            return lineNumber; // Return the line number if the target user is found
        }
    }

    return -1; // Return -1 if the target user is not found
}

std::string Student::getDetailAtLine(const std::string& filePath, int lineNumber) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return ""; // Return an empty string if the file couldn't be opened
    }

    std::string line;
    int currentLine = 0;
    while (std::getline(file, line)) {
        currentLine++;
        if (currentLine == lineNumber) {
            return line;
        }
    }

    return ""; // Return empty string if line number is not found
}

std::string Student::getName(const std::string& studentNumber) {
    int lineNumber = getLineNumber("C:\\Users\\Keith Naval\\source\\repos\\EECEInventoryTrackerLogin\\x64\\Debug\\username.txt", studentNumber);
    if (lineNumber != -1) {
        return getDetailAtLine("C:\\Users\\Keith Naval\\source\\repos\\EECEInventoryTrackerLogin\\x64\\Debug\\studentNames.txt", lineNumber);
    }
    return "";
}

std::string Student::getProgram(const std::string& studentNumber) {
    int lineNumber = getLineNumber("C:\\Users\\Keith Naval\\source\\repos\\EECEInventoryTrackerLogin\\x64\\Debug\\username.txt", studentNumber);
    if (lineNumber != -1) {
        return getDetailAtLine("C:\\Users\\Keith Naval\\source\\repos\\EECEInventoryTrackerLogin\\x64\\Debug\\programs.txt", lineNumber);
    }
    return "";
}

std::string Student::getContactInfo(const std::string& studentNumber) {
    int lineNumber = getLineNumber("C:\\Users\\Keith Naval\\source\\repos\\EECEInventoryTrackerLogin\\x64\\Debug\\username.txt", studentNumber);
    if (lineNumber != -1) {
        return getDetailAtLine("C:\\Users\\Keith Naval\\source\\repos\\EECEInventoryTrackerLogin\\x64\\Debug\\studentContactInfo.txt", lineNumber);
    }
    return "";
}

std::string Student::getID(const std::string& studentNumber) {
    int lineNumber = getLineNumber("C:\\Users\\Keith Naval\\source\\repos\\EECEInventoryTrackerLogin\\x64\\Debug\\username.txt", studentNumber);
    if (lineNumber != -1) {
        return getDetailAtLine("C:\\Users\\Keith Naval\\source\\repos\\EECEInventoryTrackerLogin\\x64\\Debug\\username.txt", lineNumber);
    }
    return "";
}

std::string Student::getEmail(const std::string& studentNumber) {
    int lineNumber = getLineNumber("C:\\Users\\Keith Naval\\source\\repos\\EECEInventoryTrackerLogin\\x64\\Debug\\username.txt", studentNumber);
    if (lineNumber != -1) {
        return getDetailAtLine("C:\\Users\\Keith Naval\\source\\repos\\EECEInventoryTrackerLogin\\x64\\Debug\\studentEmails.txt", lineNumber);
    }
    return "";
}