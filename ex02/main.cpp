#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(std::time(NULL));

	std::cout << "----- NOT SIGNED -----" << std::endl;
	try
	{
		Bureaucrat boss("Boss", 1);
		PresidentialPardonForm	pardon("Mikel");
		RobotomyRequestForm		robot("Bender");
		ShrubberyCreationForm	shrub("garden");
		boss.executeForm(pardon);
		boss.executeForm(robot);
		boss.executeForm(shrub);
	}
	catch (std::exception & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n----- CAN'T SIGN -----" << std::endl;
	try
	{
		Bureaucrat low("Low", 26);
		PresidentialPardonForm pardon("Mikel");
		low.signForm(pardon);
		low.executeForm(pardon);
	}
	catch (std::exception & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n----- SIGN OK, EXECUTE GRADE TOO LOW -----" << std::endl;
	try
	{
		Bureaucrat b1("Six", 6);
		Bureaucrat b2("FortySix", 46);
		Bureaucrat b3("OneThirtyEight", 138);
		PresidentialPardonForm	pardon("Mikel");
		RobotomyRequestForm		robot("Bender");
		ShrubberyCreationForm	shrub("garden");
		b1.signForm(pardon);
		b1.executeForm(pardon);
		b2.signForm(robot);
		b2.executeForm(robot);
		b3.signForm(shrub);
		b3.executeForm(shrub);
	}
	catch (std::exception & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n----- EXECUTE OK -----" << std::endl;
	try
	{
		Bureaucrat b1("Five", 5);
		Bureaucrat b2("FortyFive", 45);
		Bureaucrat b3("OneThirtySeven", 137);
		PresidentialPardonForm	pardon("Mikel");
		std::cout << pardon << std::endl;
		RobotomyRequestForm		robot("Bender");
		std::cout << robot << std::endl;
		ShrubberyCreationForm	shrub("garden");
		std::cout << shrub << std::endl;
		b1.signForm(pardon);
		b1.executeForm(pardon);
		b2.signForm(robot);
		b3.signForm(shrub);
		b3.executeForm(shrub);
		std::cout << "-- robotomy x10 --" << std::endl;
		for (int i = 0; i < 10; i++)
			b2.executeForm(robot);
	}
	catch (std::exception & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n----- SHRUBBERY FILE ERROR -----" << std::endl;
	try
	{
		Bureaucrat boss("Boss", 1);
		ShrubberyCreationForm shrub("/noexiste/home");
		boss.signForm(shrub);
		boss.executeForm(shrub);
	}
	catch (std::exception & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n----- POLYMORPHISM (AForm *) -----" << std::endl;
	try
	{
		/* AForm x; No  se puede istanciar ni declarar una variable abstractamake fclea
		AForm * y = new AForm(); */
		Bureaucrat boss("Boss", 1);
		AForm * forms[3];
		forms[0] = new PresidentialPardonForm("Mikel");
		forms[1] = new RobotomyRequestForm("Bender");
		forms[2] = new ShrubberyCreationForm("garden");
		for (int i = 0; i < 3; i++)
		{
			std::cout << *forms[i] << std::endl;
			boss.signForm(*forms[i]);
			boss.executeForm(*forms[i]);
		}
		for (int i = 0; i < 3; i++)
			delete forms[i];
	}
	catch (std::exception & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n----- COPY AND ASSIGNMENT -----" << std::endl;
try
{
	Bureaucrat boss("Boss", 1);
	PresidentialPardonForm original("Original");
	boss.signForm(original);
	PresidentialPardonForm copy(original);
	PresidentialPardonForm other("Other");
	other = original;
	boss.executeForm(copy);
	boss.executeForm(other);
}
catch (std::exception & e)
{
	std::cout << "Error: " << e.what() << std::endl;
}

	return 0;
}