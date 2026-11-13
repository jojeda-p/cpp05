#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(std::time(NULL));
	Intern	intern;

	std::cout << "----- VALID NAMES -----" << std::endl;
	AForm * pardon = intern.makeForm("presidential pardon", "Mikel");
	AForm * robot  = intern.makeForm("robotomy request", "Bender");
	AForm * shrub  = intern.makeForm("shrubbery creation", "garden");
	if (pardon) std::cout << *pardon << std::endl;
	if (robot)  std::cout << *robot << std::endl;
	if (shrub)  std::cout << *shrub << std::endl;

	std::cout << "\n----- INVALID NAME -----" << std::endl;
	AForm * invalid = intern.makeForm("coffee", "Jon");
	if (!invalid)
		std::cout << "makeForm returned NULL" << std::endl;

	std::cout << "\n----- FULL FLOW -----" << std::endl;
	Bureaucrat boss("Boss", 1);
	if (robot)
	{
		boss.signForm(*robot);
		boss.executeForm(*robot);
	}

	delete pardon;
	delete robot;
	delete shrub;
	delete invalid;
	return 0;
}