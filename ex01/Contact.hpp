#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact
{
    private:
        std::string ContactField[5];    
    public:
        Contact create_a_new_contact(void);
        std::string *get_data();
        void setDataAt(const std::string& data, int index);
};

#endif