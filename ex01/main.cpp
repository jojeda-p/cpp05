#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <iostream>
#include <string>

int main()
{
	std::cout << "----- FORM -----" << std::endl;
	try
	{
		Form form("Form", 75, 50);
		std::cout << form << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n----- CONSTRUCTOR ERRORS -----" << std::endl;
	try
	{
		Form zero("ZeroSign", 0, 10);
		std::cout << zero << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	try
	{
		Form tooLow("TooLowSign", 151, 10);
		std::cout << tooLow << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	try
	{
		Form zero("ZeroExec", 10, 0);
		std::cout << zero << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	try
	{
		Form tooLow("TooLowExec", 10, 151);
		std::cout << tooLow << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n----- DEFAULT CONSTRUCTOR -----" << std::endl;
	try
	{
		Form def;
		std::cout << def << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n----- NO PERMISSIONS -----" << std::endl;
	try
	{
		Bureaucrat b("B", 100);
		Form f("F", 50, 50);
		std::cout << f << std::endl;   // signed: false
		b.signForm(f);                 // no se firma
		std::cout << f << std::endl;   // sigue en false
	}
	catch (std::exception & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n----- SIGNMENT -----" << std::endl;
	try
	{
		Bureaucrat b("B", 5);
		Form f("F", 20, 20);
		std::cout << f << std::endl;   // signed: false
		b.signForm(f);                 // signed
		std::cout << f << std::endl;   // signed: true
	}
	catch (std::exception & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n----- BORDER (50 vs 50, 51 vs 50) -----" << std::endl;
	try
	{
		Bureaucrat exact("Exact", 50);
		Bureaucrat justBelow("JustBelow", 51);
		Form f("Border", 50, 50);
		justBelow.signForm(f);         // no debe firmar
		std::cout << f << std::endl;   // false
		exact.signForm(f);             // debe firmar
		std::cout << f << std::endl;   // true
	}
	catch (std::exception & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n----- ALREADY SIGNED -----" << std::endl;
	try
	{
		Bureaucrat b1("First", 10);
		Bureaucrat b2("Second", 10);
		Bureaucrat weak("Weak", 150);
		Form f("Twice", 20, 20);
		b1.signForm(f);
		b2.signForm(f);                // ya firmado
		weak.signForm(f);              // sin permisos, aunque ya esté firmado
		std::cout << f << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n----- COPY -----" << std::endl;
	try
	{
		Bureaucrat b("B", 1);
		Form original("Original", 42, 42);
		b.signForm(original);
		Form copy(original);
		std::cout << original << std::endl;   // true
		std::cout << copy << std::endl;       // true, mismo nombre
	}
	catch (std::exception & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n----- ASSIGNMENT -----" << std::endl;
	try
	{
		Form src("Source", 10, 10);
		Form dst("Dest", 100, 100);
		Bureaucrat b("B", 10);
		b.signForm(src);
		std::cout << "Before: " << dst << std::endl;   // signed: false
		dst = src;
		std::cout << "After:  " << dst << std::endl;   // true, pero sigue siendo Dest/100/100
	}
	catch (std::exception & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}