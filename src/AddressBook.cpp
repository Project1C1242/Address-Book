#include "AddressBook.h"
#include "Person.h"
#include "Business.h"
#include "Vendor.h"
#include "Emergency.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void AddressBook::addContact(unique_ptr<Contact> contact) {
    contacts.push_back(move(contact));
    cout << "Contact added.\n";
}

void AddressBook::listAllContacts() const {
    if (contacts.size() == 0) {
        cout << "Address book is empty.\n";
        return;
    }

    for (int i = 0; i < contacts.size(); i++) {
        contacts[i]->display();
    }
}

void AddressBook::deleteContact(const string& name) {
    for (int i = 0; i < contacts.size(); i++) {
        if (contacts[i]->getName() == name) {
            contacts.erase(contacts.begin() + i);
            cout << "Contact deleted.\n";
            return;
        }
    }
    cout << "Contact not found.\n";
}

void AddressBook::searchByName(const string& name) const {
    bool found = false;
    for (int i = 0; i < contacts.size(); i++) {
        if (contacts[i]->getName() == name) {
            contacts[i]->display();
            found = true;
        }
    }
    if (!found) {
        cout << "Name not found.\n";
    }
}

void AddressBook::filterByCity(const string& city) const {
    bool found = false;
    for (int i = 0; i < contacts.size(); i++) {
        if (contacts[i]->getCity() == city) {
            contacts[i]->display();
            found = true;
        }
    }
    if (!found) {
        cout << "No contacts in that city.\n";
    }
}

void AddressBook::showMissingInfoReport() const {
    cout << "--- Missing Info Report ---\n";
    for (int i = 0; i < contacts.size(); i++) {
        string email = contacts[i]->getEmail();
        string phone = contacts[i]->getPhoneNumber();

        // Checks if it is completely empty or just has the placeholder "..."
        if (email == "" || email == "..." || phone == "" || phone == "...") {
            cout << contacts[i]->getName() << " is missing phone or email info.\n";
        }
    }
}

void AddressBook::saveToFile(const string& filename) const {
    ofstream outFile(filename);
    
    if (outFile.is_open()) {
        for (int i = 0; i < contacts.size(); i++) {
            outFile << contacts[i]->getName() << ","
                    << contacts[i]->getPhoneNumber() << ","
                    << contacts[i]->getEmail() << ","
                    << contacts[i]->getCity() << "\n";
        }
        outFile.close();
    } else {
        cout << "Error: Could not open file to save.\n";
    }
}

void AddressBook::loadFromFile(const string& filename) {
    ifstream inFile(filename);
    string line;

    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            stringstream ss(line);
            string name, phone, email, city;

            // Break apart the line at every comma
            getline(ss, name, ',');
            getline(ss, phone, ',');
            getline(ss, email, ',');
            getline(ss, city, ',');

            if (name != "") {
                // Creates a new base Person object to hold the loaded data
                contacts.push_back(make_unique<Person>(name, phone, email, city, "Unknown"));
            }
        }
        inFile.close();
    }
}
