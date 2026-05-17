#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "LibraryStorage.h"
#include "Book.h"
#include "Movie.h"
#include "Magazine.h"

using namespace std;

int main() {
    cout << "========================================\n";
    cout << "  LIBRARY INVENTORY SYSTEM AUTOGRADER   \n";
    cout << "========================================\n\n";

    // Create the main storage system (e.g., 5 shelves)
    LibraryStorage libraryInventory(5);

    cout << "--- 1. ADDING ITEMS TO STORAGE ---\n";
    // Creating items using Polymorphism
    auto book1 = make_shared<Book>("B001", "The Great Gatsby", "Classic novel", "F. Scott Fitzgerald", "1925");
    auto book2 = make_shared<Book>("B002", "1984", "Dystopian sci-fi", "George Orwell", "1949");
    
    vector<string> actors = {"Keanu Reeves", "Laurence Fishburne"};
    auto movie1 = make_shared<Movie>("M001", "The Matrix", "Sci-fi action", "The Wachowskis", actors);
    
    auto mag1 = make_shared<Magazine>("Z001", "National Geographic", "Nature and science", "June 2026", "The Deep Ocean");

    // Adding to specific shelves [shelf][compartment]
    libraryInventory.addItem(0, 0, book1);
    libraryInventory.addItem(0, 1, book2);
    libraryInventory.addItem(1, 0, movie1);
    libraryInventory.addItem(2, 4, mag1); // 3rd shelf, 5th compartment

    cout << "Added Books, a Movie, and a Magazine to the shelves.\n\n";

    cout << "--- 2. PRINTING ITEMS IN STORAGE (Testing << overload) ---\n";
    libraryInventory.printStorage();
    cout << "\n";

    cout << "--- 3. CHECKING OUT ITEMS ---\n";
    libraryInventory.checkoutItem(0, 0, "Marcus", "05-24-2026");
    libraryInventory.checkoutItem(1, 0, "Emmanuel", "05-21-2026");
    cout << "Checked out 'The Great Gatsby' and 'The Matrix'.\n\n";

    cout << "--- 4. PRINTING CHECKED-OUT ITEMS ---\n";
    libraryInventory.printCheckedOut();
    cout << "\n";

    cout << "--- 5. TESTING OPERATOR OVERLOAD [] ---\n";
    cout << "Accessing item at Shelf 3, Compartment 5 using libraryInventory[2][4]:\n";
    // This tests the specific requirement from the PDF
    if (libraryInventory[2][4] != nullptr) {
        cout << *(libraryInventory[2][4]) << "\n";
    }
    cout << "\n";

    cout << "--- 6. SWAPPING ITEMS ---\n";
    cout << "Swapping Book at [0][1] with Magazine at [2][4]...\n";
    libraryInventory.swapItems(0, 1, 2, 4);
    libraryInventory.printStorage();
    cout << "\n";

    cout << "--- 7. CHECKING IN ITEMS ---\n";
    cout << "Marcus returns 'The Great Gatsby'.\n";
    libraryInventory.checkinItem(0, 0);
    cout << "\n";

    cout << "--- 8. ERROR HANDLING & EDGE CASES (Exception Testing) ---\n";
    
    cout << "Test A: Accessing a shelf that doesn't exist...\n";
    try {
        libraryInventory.addItem(99, 0, book1);
    } catch (const exception& e) {
        cout << "Caught Error: " << e.what() << "\n";
    }

    cout << "\nTest B: Checking out an empty compartment...\n";
    try {
        libraryInventory.checkoutItem(4, 14, "Ghost User", "Never");
    } catch (const exception& e) {
        cout << "Caught Error: " << e.what() << "\n";
    }

    cout << "\nTest C: Swapping with an empty compartment...\n";
    try {
        libraryInventory.swapItems(0, 0, 4, 14);
    } catch (const exception& e) {
        cout << "Caught Error: " << e.what() << "\n";
    }

    cout << "\n========================================\n";
    cout << "          TEST SCRIPT COMPLETE          \n";
    cout << "========================================\n";

    return 0;
}
