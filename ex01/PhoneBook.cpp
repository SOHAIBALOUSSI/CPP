#include "PhoneBook.hpp"
#include <cstdlib>

void    PhoneBook::setContactAt(Contact newContact, int i)
{
    if (this->size < 8)
        this->size++;
    this->contacts[i] = newContact;
}

void clear_screen() {
    std::cout << "\033[2J\033[1;1H";  // ANSI escape code to clear screen and move cursor to home
}

void PhoneBook::search_for_contacts(PhoneBook& list)
{
    if (list.size == 0) {
        std::cout << "No contact available\n";
        sleep(2);
        clear_screen();
        return ;
    }
    const char *details[] = {
        "First Name: ","Last Name: ","Nickname: ", "Phone Number: ", "Darkest Secret: "
    };
    // List current contacts
    std::cout << "     Index|First Name| Last Name|  Nickname|\n";
    for (size_t i = 0; i < list.size; i++) {
        std::cout << std::setw(10) << i << "|";
        for (size_t j = 0; j < 3; j++) {
            std::string field = list.contacts[i].get_data()[j];
            if (field.length() > 9)
                field = field.substr(0, 9) + ".";
            std::cout << std::setw(10) << field << "|";
        }
        std::cout << "\n";
    }
    // split the parse logic
    std::cout << "\nEnter contact's index to display it's informations: ";
    std::string index_arr;
    std::getline(std::cin, index_arr);
    if (index_arr.empty()) {
        std::cout << "Invalid Index\n";
        sleep(2);
        clear_screen();
        return ;
    }
    for (int i = 0 ; index_arr[i]; i++) {
        if (!std::isdigit(index_arr[i])) {
            std::cout << "Invalid Index\n";
            sleep(2);
            clear_screen();
            return ;
        }
    }
    size_t index = std::atoi(index_arr.c_str());
    if (index >= list.size) {
        std::cout << "Out of range\n";
        return ;
    }
    std::cout << "Contact details:\n";
    for (size_t i = 0; i < 5; i++) {
        std::cout << details[i] << list.contacts[index].get_data()[i] << "\n";
    }
    sleep(3);
}

int main()
{
    PhoneBook   list;
    Contact     newContact;
    std::string buffer;
    clear_screen();
    list.size = 0;
    while (1)
    {
        std::cout << INSTRUCTIONS;
        std::getline(std::cin, buffer);
        if (std::cin.eof()) return EXIT_FAILURE;
        else if (buffer == "ADD") {
            clear_screen();
            static int i = 0;
            list.setContactAt(newContact.create_a_new_contact(), i++);
            if (i == 8) i = 0;
            std::cout << "\nContact added succesfuly\n";
            sleep(2);
            clear_screen();
        }
        else if (buffer == "SEARCH") {
            clear_screen();
            list.search_for_contacts(list);
        }
        else if (buffer == "EXIT")
            break;
        else {
            std::cout << "Not a valid input\n";
            sleep(1);
        }
    }
    clear_screen();
    return 0;
}
