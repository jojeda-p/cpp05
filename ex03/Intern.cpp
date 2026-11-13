#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

#include <string>
#include <iostream>

Intern::Intern()
{
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(Intern const & src)
{
	(void)src;
    std::cout << "Intern copy constructor called" << std::endl;
}

Intern & Intern::operator=(Intern const & rhs)
{
    std::cout << "Intern copy assignment operator called" << std::endl;
    (void)rhs;
    return *this;
}

Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}

typedef AForm * (*Creator)(std::string const &);


static AForm * createPardon(std::string const & target)
{
	return new PresidentialPardonForm(target);
}

static AForm * createRobotomy(std::string const & target)
{
	return new RobotomyRequestForm(target);
}

static AForm * createShrubbery(std::string const & target)
{
	return new ShrubberyCreationForm(target);
}

AForm*  Intern::makeForm(std::string const & nameForm, std::string const & targetForm) const
{
    std::string names[3] = { "presidential pardon", "robotomy request", "shrubbery creation" };
    Creator     creators[3] = { &createPardon, &createRobotomy, &createShrubbery};

    for (int i = 0; i < 3; i++)
    {
        if (names[i] == nameForm)
        {
            std::cout << "Intern creates " << nameForm << std::endl;
            return creators[i](targetForm);
        }
    }
    std::cout << "ERROR: Intern can't create \"" << nameForm << "\": form does not exist" << std::endl;
    return NULL;
}
