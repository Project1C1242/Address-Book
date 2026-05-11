#include "Contact.h"

// --- Contact ---
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

// --- Person ---
Person::Person(std::string n, std::string p, std::string e, std::string c, std::string b)
    : Contact(n, p, e, c), birthday(b) {}

void Person::display() const {
    std::cout << "[Person] " << name << " | Ph: " << phoneNumber 
              << " | B-Day: " << birthday << std::endl;
}

// --- Business ---
Business::Business(std::string n, std::string p, std::string e, std::string c, std::string w)
    : Contact(n, p, e, c), website(w) {}

void Business::display() const {
    std::cout << "[Business] " << name << " | Web: " << website << std::endl;
}

// --- Vendor ---
Vendor::Vendor(std::string n, std::string p, std::string e, std::string c, std::string s)
    : Contact(n, p, e, c), serviceType(s) {}

void Vendor::display() const {
    std::cout << "[Vendor] " << name << " | Service: " << serviceType << std::endl;
}

// --- Emergency ---
Emergency::Emergency(std::string n, std::string p, std::string e, std::string c, std::string r)
    : Contact(n, p, e, c), relationship(r) {}

void Emergency::display() const {
    std::cout << "!!! EMERGENCY: " << name << " (" << relationship << ") | Ph: " << phoneNumber << std::endl;
}