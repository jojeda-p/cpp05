#include "ShrubberyCreationForm.hpp"

#include <string>
#include <fstream>
#include <iostream>
#include <exception>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
    std::cout << "ShrubberyCreationForm default constructor called " << _target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    std::cout << "ShrubberyCreationForm named constructor called " << _target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : AForm(src), _target(src._target)
{
    std::cout << "ShrubberyCreationForm copy constructor called " << _target << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
    std::cout << "ShrubberyCreationForm copy assignment operator called " << _target << std::endl;
    if (this != &rhs)
    {
        AForm::operator=(rhs);
        _target = rhs._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor called " << _target << std::endl;
}

const char  *ShrubberyCreationForm::FileOpenException::what() const throw()
{
    return "ShrubberyCreationForm: could not open the output file.";
}

void	ShrubberyCreationForm::executeAction() const
{
	std::ofstream	file((_target + "_shrubbery").c_str());

	if (!file.is_open())
		throw FileOpenException();

	char const *	tree[] = {
		"    ^    ",
		"   /^\\   ",
		"  /^^^\\  ",
		" /^^^^^\\ ",
		"/^^^^^^^\\",
		"    |    "
	};
	int	lines = sizeof(tree) / sizeof(tree[0]);

	for (int n = 0; n < 3; n++)
	{
		for (int i = 0; i < lines; i++)
			file << tree[i] << std::endl;
		file << std::endl;
	}
}