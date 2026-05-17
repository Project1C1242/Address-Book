#include <iostream>
#include <string>
#include <memory>
#include "AddressBook.h"
#include "Person.h"
#include "Business.h"
#include "Vendor.h"
#include "Emergency.h"

using namespace std;

void displayMenu() {
    cout << "\n===== ADDRESS BOOK =====\n";
    cout << "1. Add a Contact\n";
    cout << "2. List All Contacts\n";
    cout << "3. Search Contact by Name\n";
    cout << "4. Filter by City\n";
    cout << "5. Delete a Contact\n";
    cout << "6. Missing Info Report\n";
    cout << "7. Save to File\n";
    cout << "8. Exit\n";
    cout << "Enter choice: ";
}

int main() {
    AddressBook myAddressBook;
    int choice = 0;

    // Load existing data at startup
    myAddressBook.loadFromFile("contacts.txt");

    while (true) {
        displayMenu();
        if (!(cin >> choice)) {
            cout << "Invalid input. Exiting.\n";
            break;
        }
        cin.ignore(); // Clear buffer

        if (choice == 8) {
            cout << "Saving and exiting...\n";
            myAddressBook.saveToFile("contacts.txt");
            break;
        }

        switch (choice) {
            case 1: {
                cout << "Select Type (1: Person, 2: Emergency, 3: Business, 4: Vendor): ";
                int type;
                cin >> type;
                cin.ignore();

                string name, phone, email, city;
                cout << "Enter Name: "; getline(cin, name);
                cout << "Enter Phone: "; getline(cin, phone);
                cout << "Enter Email: "; getline(cin, email);
                cout << "Enter City: "; getline(cin, city);

                if (type == 1) {
                    string birthday;
                    cout << "Enter Birthday: "; getline(cin, birthday);
                    myAddressBook.addContact(make_unique<Person>(name, phone, email, city, birthday));
                } else if (type == 2) {
                    string relationship;
                    cout << "Enter Relationship: "; getline(cin, relationship);
                    myAddressBook.addContact(make_unique<Emergency>(name, phone, email, city, relationship));
                } else if (type == 3) {
                    string website;
                    cout << "Enter Website: "; getline(cin, website);
                    myAddressBook.addContact(make_unique<Business>(name, phone, email, city, website));
                } else if (type == 4) {
                    string service;
                    cout << "Enter Service Type: "; getline(cin, service);
                    myAddressBook.addContact(make_unique<Vendor>(name, phone, email, city, service));
                } else {
                    cout << "Invalid contact type.\n";
                }
                break;
            }
            case 2:
                myAddressBook.listAllContacts();
                break;
            case 3: {
                string searchName;
                cout << "Enter name to search: ";
                getline(cin, searchName);
                myAddressBook.searchByName(searchName);
                break;
            }
            case 4: {
                string searchCity;
                cout << "Enter city to filter: ";
                getline(cin, searchCity);
                myAddressBook.filterByCity(searchCity);
                break;
            }
            case 5: {
                string deleteName;
                cout << "Enter exact name to delete: ";
                getline(cin, deleteName);
                myAddressBook.deleteContact(deleteName);
                break;
            }
            case 6:
                myAddressBook.showMissingInfoReport();
                break;
            case 7:
                myAddressBook.saveToFile("contacts.txt");
                cout << "Contacts saved successfully.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}