#include "Contact.h"

class Business : public Contact {
private:
    std::string website;

public:
    Business(std::string n, std::string p, std::string e, std::string c, std::string w);
    void display() const override;
};