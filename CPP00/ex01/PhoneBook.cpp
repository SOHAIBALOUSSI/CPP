#include "PhoneBook.hpp"
#include <cstdlib>

PhoneBook::PhoneBook()
{
    this->size = 0;
}

void    PhoneBook::setContact(Contact newContact)
{
    static int i = 0;
    if (this->size < 8)
        this->size++;
    if (i == 8) i = 0;
    this->contacts[i++] = newContact;
}

void    PhoneBook::list_current_contacts(PhoneBook& list)
{
    std::cout << "     Index|First Name| Last Name|  Nickname|\n";
    for (size_t i = 0; i < list.size; i++)
    {
        std::cout << std::setw(10) << i << "|";
        for (size_t j = 0; j < 3; j++)
        {
            std::string field = list.contacts[i].get_data()[j];
            if (field.length() > 9)
                field = field.substr(0, 9) + ".";
            std::cout << std::setw(10) << field << "|";
        }
        std::cout << "\n";
    }
}

int    get_contacts_index(bool& err)
{
    std::cout << "\nEnter contact's index to display it's informations: ";
    std::string index_arr;
    std::getline(std::cin, index_arr);
    if (index_arr.empty())
        return (err = true, -1);
    for (int i = 0 ; index_arr[i]; i++)
    {
        if (!std::isdigit(index_arr[i])) 
            return (err = true, -1);
    }
    return std::atoi(index_arr.c_str());
}

void PhoneBook::search_for_contacts(PhoneBook& list)
{
    bool err = false;

    if (list.size == 0) {
        std::cout << "No contact available\n";
        return ;
    }
    const std::string details[] = {
        "First Name: ","Last Name: ","Nickname: ", "Phone Number: ", "Darkest Secret: "
    };
    list_current_contacts(list);
    size_t index = get_contacts_index(err);
    if (err) {
        std::cout << "Invalid Index\n";
        return ;
    }
    if (index >= list.size) {
        std::cout << "Out of range\n";
        return ;
    }
    std::cout << "Contact details:\n";
    for (size_t i = 0; i < 5; i++) {
        std::cout << details[i] << list.contacts[index].get_data()[i] << "\n";
    }
}

int main()
{
    PhoneBook   list;
    Contact     newContact;
    std::string buffer;

    std::cout << INSTRUCTIONS;
    while (1)
    {
        std::getline(std::cin, buffer);
        if (std::cin.eof())
            return EXIT_FAILURE;
        else if (buffer == "ADD")
        {
            list.setContact(PhoneBook::create_a_new_contact());
            std::cout << "\nContact added succesfuly\n";
        }
        else if (buffer == "SEARCH")
            list.search_for_contacts(list);
        else if (buffer == "EXIT")
            break;
        else
            std::cout << "Not a valid input\n";
    }
    return 0;
}
