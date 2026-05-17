#include <iostream>
#include <string>
#include <memory>
#include "AddressBook.h"
#include "Person.h"
#include "Business.h"
#include "Vendor.h"
#include "Emergency.h"

void displayMenu() {
    std::cout << "\n===== ADDRESS BOOK =====\n";
    std::cout << "1. Add a Contact\n";
    std::cout << "2. List All Contacts\n";
    std::cout << "3. Search Contact by Name\n";
    std::cout << "4. Save to File\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter choice: ";
}

int main() {
    AddressBook myAddressBook;
    int choice = 0;

    // Load existing data
    myAddressBook.loadFromFile("contacts.txt");

    while (true) {
        displayMenu();
        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Exiting.\n";
            break;
        }
        std::cin.ignore(); // Clear buffer

        if (choice == 5) {
            std::cout << "Saving and exiting...\n";
            myAddressBook.saveToFile("contacts.txt");
            break;
        }

        switch (choice) {
            case 1: {
                std::cout << "Select Type (1: Person, 2: Emergency): ";
                int type;
                std::cin >> type;
                std::cin.ignore();

                std::string name, phone, email, city;
                std::cout << "Enter Name: "; std::getline(std::cin, name);
                std::cout << "Enter Phone: "; std::getline(std::cin, phone);
                std::cout << "Enter Email: "; std::getline(std::cin, email);
                std::cout << "Enter City: "; std::getline(std::cin, city);

                if (type == 1) {
                    std::string birthday;
                    std::cout << "Enter Birthday: "; std::getline(std::cin, birthday);
                    myAddressBook.addContact(std::make_unique<Person>(name, phone, email, city, birthday));
                } else if (type == 2) {
                    std::string relationship;
                    std::cout << "Enter Relationship: "; std::getline(std::cin, relationship);
                    myAddressBook.addContact(std::make_unique<Emergency>(name, phone, email, city, relationship));
                }
                break;
            }
            case 2:
                myAddressBook.listAllContacts();
                break;
            case 3: {
                std::string searchName;
                std::cout << "Enter name to search: ";
                std::getline(std::cin, searchName);
                myAddressBook.searchByName(searchName);
                break;
            }
            case 4:
                myAddressBook.saveToFile("contacts.txt");
                std::cout << "Contacts saved successfully.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}