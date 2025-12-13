#include <fstream>
#include <sstream>
#include <iostream>
#include "file_io.h"

bool saveToFile(const std::string& filename, int mode) {
    std::ios_base::openmode openMode;

    // режим выбора
    if (mode == 1) {
        openMode = std::ios::out;          // создаём новый, перезаписываем
    } 
    else if (mode == 2) {
        openMode = std::ios::app;          // дописываем
    } 
    else {
        std::cout << "Invalid mode!\n";
        return false;
    }

    // открываем файл
    std::ofstream file(filename, openMode);
    if (!file.is_open()) {
        std::cout << "Cannot open file!\n";
        return false;
    }

    // записываем все контакты
    for (int i = 0; i < contactsCount; i++) {
        const Contact& c = contacts[i];

        // формат: поля через ;
        file << c.id << ";"
             << c.name << ";"
             << c.phone << ";"
             << c.category << ";"
             << c.birthday << ";"
             << c.age << ";"
             << c.deleted << "\n";
    }

    file.close();
    return true;
}

bool loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Cannot open file!\n";
        return false;
    }
    contactsCount = 0;
    std::string line;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        Contact c;
        std::string field;

        // ---- читаем поля из строки ----

        std::getline(ss, field, ';');
        c.id = std::stoi(field);

        std::getline(ss, c.name, ';');
        std::getline(ss, c.phone, ';');
        std::getline(ss, c.category, ';');
        std::getline(ss, c.birthday, ';');

        std::getline(ss, field, ';');
        c.age = std::stoi(field);

        std::getline(ss, field, ';');
        c.deleted = (field == "1");

        // ---- кладём контакт в массив ----
        contacts[contactsCount++] = c;
    }

    file.close();
    return true;
}

