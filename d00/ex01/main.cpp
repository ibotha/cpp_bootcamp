#include "phonebook.hpp"
#include <iostream>

int main() {
    Phonebook phonebook = Phonebook();

    std::cout <<    "\nADD - add a contact\n"
                    "SEARCH - search for a contact\n"
                    "EXIT - Terminate the program\n\n";

    bool exit = false;
    while (!exit) {
        std::string command;
        std::cout << "\r$ ";
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
            bool run = true;
            while(run) {
                if(std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Not an integer, Please try again: ";
                    std::cin >> index;
                }
                if(!std::cin.fail())
                    run = false;
            }
            std::cout << phonebook.get_contact(index) << "\n";
        }
    }

    return 0;
}