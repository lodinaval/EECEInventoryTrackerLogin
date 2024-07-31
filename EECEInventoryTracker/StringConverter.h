#pragma once
#pragma once
#include <msclr/marshal_cppstd.h>
#include <string>

namespace EECEInventoryTracker {
    static std::string convertToStdString(System::String^ sysString) {
        return msclr::interop::marshal_as<std::string>(sysString);
    }

    static System::String^ converterToString(const std::string& stdString) {
        return gcnew System::String(stdString.c_str());
    }
}
