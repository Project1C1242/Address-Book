#pragma once
#include "Contact.h"

class Person : public Contact {
private:
    std::string birthday;

public:
    Person(std::string n, std::string p, std::string e, std::string c, std::string b);
    void display() const override;
};