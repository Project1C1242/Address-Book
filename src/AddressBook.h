#pragma once

#include <vector>
#include <memory>
#include <string>
#include "Contact.h"

class AddressBook {
private:
    // Holds all contacts (polymorphism)
    std::vector<std::unique_ptr<Contact>> contacts;

public:
    // Core
    void addContact(std::unique_ptr<Contact> contact);
    void listAllContacts() const;
    void deleteContact(const std::string& name);
    
    // Searching & Filtering
    void searchByName(const std::string& name) const;
    void filterByCity(const std::string& city) const;

    // Import/Export
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

    // Reports
    void showMissingInfoReport() const;
};