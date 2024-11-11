
#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <stdlib.h>

std::string* Contact::get_data(void)
{
    return this->ContactField;
}

Contact PhoneBook::create_a_new_contact(void)
{
    Contact new_contact;
    std::string buffer;

    const std::string prompts[] = {
        "Enter contact's first name:",
        "Enter contact's last name:",
        "Enter contact's nickname:",
        "Enter contact's phone number:",
        "Enter contact's darkest secret:"
    };
    for (int i = 0; i < 5; i++)
    {
        for (;;)
        {
            std::cout << prompts[i] << "\n";
            std::getline(std::cin, buffer);
            if (std::cin.eof())
                exit(1);
            if (buffer.empty())
                std::cout << "Can't have an empty field\n";
            else
            {
                new_contact.setDataAt(buffer, i);
                break;
            }
        }
    }
    return new_contact;
}

void    Contact::setDataAt(const std::string& data, int index)
{
    this->ContactField[index] = data;
}