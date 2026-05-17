#include "Business.h"
#include <iostream>

Business::Business(std::string n, std::string p, std::string e, std::string c, std::string w)
    : Contact(n, p, e, c), website(w) {}

void Business::display() const {
    std::cout << "[Business] " << name << " | Web: " << website << std::endl;
}