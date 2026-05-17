#include "Contact.h"

Contact::Contact(std::string n, std::string p, std::string e, std::string c)
    : name(n), phoneNumber(p), email(e), city(c) {}

Contact::~Contact() {}

std::string Contact::getName() const { return name; }
std::string Contact::getEmail() const { return email; }
std::string Contact::getPhoneNumber() const { return phoneNumber; }
std::string Contact::getCity() const { return city; }

void Contact::setPhoneNumber(const std::string& p) { phoneNumber = p; }
void Contact::setGroup(const std::string& g) { group = g; }
void Contact::addTag(const std::string& tag) { tags.push_back(tag); }