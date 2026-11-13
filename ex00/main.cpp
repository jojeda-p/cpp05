#include "Bureaucrat.hpp"

#include <iostream>
#include <string>

int main()
{
	std::cout << "----- SUCCESS -----" << std::endl;
	try {
		Bureaucrat mid("Mid", 75);
		std::cout << mid << std::endl;
	}
	catch (std::exception & e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n----- CONSTRUCTOR ERRORS -----" << std::endl;
	try {
		Bureaucrat zero("Zero", 0);
		std::cout << zero << std::endl;
	}
	catch (std::exception & e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	try {
		Bureaucrat tooLow("TooLow", 151);
		std::cout << tooLow << std::endl;
	}
	catch (std::exception & e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n----- VALID LIMITS -----" << std::endl;
	try {
		Bureaucrat top("Top", 1);
		std::cout << top << std::endl;
	}
	catch (std::exception & e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	try {
		Bureaucrat bottom("Bottom", 150);
		std::cout << bottom << std::endl;
	}
	catch (std::exception & e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n----- DEFAULT CONSTRUCTOR -----" << std::endl;
	try {
		Bureaucrat def;
		std::cout << def << std::endl;
	}
	catch (std::exception & e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n----- INCREMENT / DECREMENT SUCCESS -----" << std::endl;
	try {
		Bureaucrat inc("Inc", 5);
		inc.incrementGrade();
		std::cout << inc << std::endl;
	}
	catch (std::exception & e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	try {
		Bureaucrat dec("Dec", 5);
		dec.decrementGrade();
		std::cout << dec << std::endl;
	}
	catch (std::exception & e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n----- INCREMENT / DECREMENT ERRORS -----" << std::endl;
	try {
		Bureaucrat incErr("IncErr", 1);
		incErr.incrementGrade();
		std::cout << incErr << std::endl;
	}
	catch (std::exception & e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	try {
		Bureaucrat decErr("DecErr", 150);
		decErr.decrementGrade();
		std::cout << decErr << std::endl;
	}
	catch (std::exception & e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n----- BORDER: success then failure -----" << std::endl;
	try {
		Bureaucrat border("Border", 2);
		border.incrementGrade();
		std::cout << border << std::endl;   // grade 1
		border.incrementGrade();            // lanza
		std::cout << border << std::endl;   // no se ejecuta
	}
	catch (std::exception & e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n----- COPY -----" << std::endl;
	try {
		Bureaucrat original("Original", 42);
		Bureaucrat copy(original);
		copy.incrementGrade();
		std::cout << original << std::endl;   // sigue en 42
		std::cout << copy << std::endl;       // 41
	}
	catch (std::exception & e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n----- ASSIGNMENT -----" << std::endl;
	try {
		Bureaucrat src("Source", 10);
		Bureaucrat dst("Dest", 100);
		std::cout << "Before: " << dst << std::endl;
		dst = src;
		std::cout << "After:  " << dst << std::endl;   // nombre "Dest", grado 10
	}
	catch (std::exception & e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}