#include <iostream>
#include "contact.h"
#include "input.h"
#include "output.h"
#include "file_io.h"


using namespace std;

void printMenu() {
    cout << "\n====== MENU ======\n";
    cout << "1. Add contact\n";
    cout << "2. Show all contacts\n";
    cout << "3. Save to file\n";
    cout << "4. Load from file\n";
    cout << "0. Exit\n";
    cout << "==================\n";
    cout << "Choose option: ";
}


int main() {
    while (true) {
        printMenu();

        int choice;
        cin >> choice;
        cin.ignore(); // чтобы съесть \n

        if (choice == 1) {
            cout << "\n--- Add Contact ---\n";
            Contact c = inputContact();
            contacts[contactsCount++] = c;
            cout << "Contact added!\n";
        }
        else if (choice == 2) {
            cout << "\n--- Contact List ---\n";
            printContacts();
        }
        else if (choice == 3) {
            cout << "Enter file name: ";
            string filename;
            getline(cin, filename);
        
            cout << "Choose mode (1 — new file, 2 — append): ";
            int mode;
            cin >> mode;
            cin.ignore();
        
            if (saveToFile(filename, mode)) {
                cout << "Saved successfully!\n";
            } else {
                cout << "Save error!\n";
            }
        }
        else if (choice == 4) {
            cout << "Enter file name: ";
            string filename;
            getline(cin, filename);
        
            if (loadFromFile(filename)) {
                cout << "Loaded successfully!\n";
            } else {
                cout << "Error while loading!\n";
            }
        }
        


        else if (choice == 0) {
            cout << "Exiting...\n";
            break; // завершение программы
        }
        else {
            cout << "Invalid option, try again!\n";
        }
    }
    return 0;
}