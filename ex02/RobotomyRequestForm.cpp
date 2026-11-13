#include "RobotomyRequestForm.hpp"

#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default")
{
    std::cout << "RobotomyRequestForm default constructor called " << _target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    std::cout << "RobotomyRequestForm named constructor called " << _target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : AForm(src), _target(src._target)
{
    std::cout << "RobotomyRequestForm copy constructor called " << _target << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
    std::cout << "RobotomyRequestForm copy assignment operator called " << _target << std::endl;
    if (this != &rhs)
    {
        AForm::operator=(rhs);
        _target = rhs._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor called " << _target << std::endl;
}

void	RobotomyRequestForm::executeAction() const
{
    std::cout << "brrrrrrr...brrrrrr...brrrrrr" << std::endl;
	if (std::rand() % 2)
        std::cout << _target << " has been robotomized successfully." << std::endl;
    else
        std::cout << _target << " robotomy has failed." << std::endl;
}