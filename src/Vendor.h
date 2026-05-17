#pragma once
#include "Contact.h"

class Vendor : public Contact {
private:
    std::string serviceType;

public:
    Vendor(std::string n, std::string p, std::string e, std::string c, std::string s);
    void display() const override;
};