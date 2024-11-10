#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include <iostream>
#include <iomanip>
#include <unistd.h>
#include "Contact.hpp"

//instructions
#define INSTRUCTIONS "---------------------------\nADD: To add a new contact\nSEARCH: List current contacts\nEXIT: End the program\n---------------------------\n"

class PhoneBook
{
    private:
        Contact contacts[8];
    public:
        size_t size;
        void search_for_contacts(PhoneBook& list);
        void setContactAt(Contact newContact, int i);
};

#endif