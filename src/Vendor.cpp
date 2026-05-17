#include "Vendor.h"
#include <iostream>

Vendor::Vendor(std::string n, std::string p, std::string e, std::string c, std::string s)
    : Contact(n, p, e, c), serviceType(s) {}

void Vendor::display() const {
    std::cout << "[Vendor] " << name << " | Service: " << serviceType << std::endl;
}