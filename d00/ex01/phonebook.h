#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include "contact.h"
#define MAX_CONTACTS 8

class Phonebook
{
private:
    Contact *contacts[MAX_CONTACTS];
    int amount = 0;
public:
    Phonebook();

    bool add();
    int get_contact_amount();

    std::string format();
    std::string columnize(std::string val);
    std::string get_contact(int index);

    ~Phonebook();
};

#endif