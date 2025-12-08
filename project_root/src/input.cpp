#include <iostream>
#include <string>
#include "input.h"

int generateId() {
    int maxId = 0;

    for (int i = 0; i < contactsCount; i++) {
        if (contacts[i].id > maxId) {
            maxId = contacts[i].id;
        }
    }

    return maxId + 1;
}


Contact inputContact() {
    Contact c;

    c.id = generateId();

    std::cout << "Input contacts name: ";
    std::getline(std::cin, c.name);

    std::cout << "Input contacts phone: ";
    std::getline(std::cin, c.phone);

    std::cout << "Input contacts category: ";
    std::getline(std::cin, c.category);

    std::cout << "Input contacts birthday: ";
    std::getline(std::cin, c.birthday);

    std::cout << "Input contacts age: ";
    std::cin >> c.age;
    std::cin.ignore();

    c.deleted = false;
    return c;
}


