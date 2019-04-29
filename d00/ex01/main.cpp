#include "phonebook.h"
#include <iostream>

int main() {
    Phonebook phonebook = Phonebook();

    bool exit = false;
    while (!exit) {
        std::string command;
        std::getline(std::cin, command);
        if (command == "EXIT") {
            exit = true;
        } else if (command == "ADD") {
            if (!phonebook.add()) {
                std::cout << "Contacts are full";
            }
        } else if (command == "SEARCH") {
            std::cout << phonebook.format() << "\n";
            std::cout << "Index: ";
            int index;
            std::cin >> index;
            std::cout << phonebook.get_contact(index) << "\n";
        }
    }

    return 0;
}