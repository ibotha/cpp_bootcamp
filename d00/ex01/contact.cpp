#include "contact.hpp"

Contact::Contact()
{
}

std::string Contact::to_string() {
    std::string ret;
    ret += "First Name: ";
    ret += first_name;
    ret += "\nLast Name: ";
    ret += last_name;
    ret += "\nNickname: ";
    ret += nickname;
    ret += "\nLogin: ";
    ret += login;
    ret += "\nPostal Adress: ";
    ret += postal_address;
    ret += "\nEmail: ";
    ret += email;
    ret += "\nPhone Number: ";
    ret += phone_number;
    ret += "\nBirthday: ";
    ret += birthday;
    ret += "\nFavorite Meal: ";
    ret += favorite_meal;
    ret += "\nUnderwear Color: ";
    ret += underwear_color;
    ret += "\nDarkest Secret: ";
    ret += darkest_secret;
    return ret;
}

Contact::~Contact()
{
}