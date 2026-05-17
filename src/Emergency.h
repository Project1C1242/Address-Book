#pragma once
#include "Contact.h"

class Emergency : public Contact {
private:
    std::string relationship;

public:
    Emergency(std::string n, std::string p, std::string e, std::string c, std::string r);
    void display() const override;
};