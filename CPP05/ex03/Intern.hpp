#ifndef INTERN_HPP
#define INTERN_HPP

#include <bits/stdc++.h>
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"


typedef AForm* (*CreateFormFunction)(std::string);

class Intern
{

public:
    Intern();
    Intern(Intern const &intern);
    Intern &operator=(Intern const &intern);
    ~Intern();

    AForm *makeForm(std::string formName, std::string target);
    class FormNotFoundException : public std::exception
    {
        public:
            const char *what() const throw();
    };
};

#endif