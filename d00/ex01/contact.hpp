#ifndef CONTACT_H
#define CONTACT_H
#include <string>

class Contact
{
public:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string login;
    std::string postal_address;
    std::string email;
    std::string phone_number;
    std::string birthday;
    std::string favorite_meal;
    std::string underwear_color;
    std::string darkest_secret;

    Contact();

    std::string to_string();

    ~Contact();
};

#endif