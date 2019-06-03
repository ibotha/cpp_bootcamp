#include "phonebook.hpp"
#include <iostream>

Phonebook::Phonebook()
    :amount(0)
{
}

bool Phonebook::add()
{
    if (amount < MAX_CONTACTS) {

        std::cout << "First Name: ";
        std::getline(std::cin, contacts[amount].first_name);
        std::cout << "Last Name: ";
        std::getline(std::cin, contacts[amount].last_name);
        std::cout << "Nickname: ";
        std::getline(std::cin, contacts[amount].nickname);
        std::cout << "Login: ";
        std::getline(std::cin, contacts[amount].login);
        std::cout << "Postal Address: ";
        std::getline(std::cin, contacts[amount].postal_address);
        std::cout << "Email: ";
        std::getline(std::cin, contacts[amount].email);
        std::cout << "Phone Number: ";
        std::getline(std::cin, contacts[amount].phone_number);
        std::cout << "Birthday: ";
        std::getline(std::cin, contacts[amount].birthday);
        std::cout << "Favorite Meal: ";
        std::getline(std::cin, contacts[amount].favorite_meal);
        std::cout << "Underwear Color: ";
        std::getline(std::cin, contacts[amount].underwear_color);
        std::cout << "Darkest Secret: ";
        std::getline(std::cin, contacts[amount].darkest_secret);
        amount++;
        return true;
    }
    return false;
}

int Phonebook::get_contact_amount() {
    return amount;
}

std::string Phonebook::get_contact(int index) {
    if (index < amount && index >= 0) {
        return contacts[index].to_string();
    } else {
        return "Invalid Index";
    }
}

std::string Phonebook::columnize(std::string val) {
    std::string ret;
    unsigned int start = (((10 - (int)val.length()) < 0) ? 0 : (10 - val.length())) / 2;

    unsigned int j = 0;
    for (unsigned int i = 0; i < 10; i++) {
        if (i == 9 && i < (val.length() - 1)) {
            ret += '.';
        } else if (i >= start) {
            if (j < val.length())
                ret += val[j++];
            else 
                ret += ' ';
        } else {
            ret += ' ';
        }
    }
    return ret;
}

std::string Phonebook::format() {
    std::string ret;
    ret += "+----------+----------+----------+----------+\n";
    ret += "|  Index   |First Name|Last Name | Nickname |\n";
    ret += "+----------+----------+----------+----------+\n";
    for (int i = 0; i < amount; i++) {
        ret += "|";
        ret += columnize(std::to_string(i));
        ret += "|";
        ret += columnize(contacts[i].first_name);
        ret += "|";
        ret += columnize(contacts[i].last_name);
        ret += "|";
        ret += columnize(contacts[i].nickname);
        ret += "|";
        ret += "\n";
        ret += "+----------+----------+----------+----------+\n";
    }
    return ret;
}

Phonebook::~Phonebook()
{
}