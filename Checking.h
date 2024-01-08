#pragma once
#include <string>

class Checking {
    public:
    static bool nameCheck(std::string name);
    static bool intCheck(std::string balance);
    static bool boolCheck(std::string str);
};