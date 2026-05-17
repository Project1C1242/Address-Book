#include "Person.h"
#include <iostream>

Person::Person(std::string n, std::string p, std::string e, std::string c, std::string b)
    : Contact(n, p, e, c), birthday(b) {}

void Person::display() const {
    std::cout << "[Person] " << name << " | Ph: " << phoneNumber 
              << " | B-Day: " << birthday << std::endl;
}