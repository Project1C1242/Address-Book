#include "Emergency.h"
#include <iostream>

Emergency::Emergency(std::string n, std::string p, std::string e, std::string c, std::string r)
    : Contact(n, p, e, c), relationship(r) {}

void Emergency::display() const {
    std::cout << "EMERGENCY: " << name << " (" << relationship << ") | Ph: " << phoneNumber << std::endl;
}