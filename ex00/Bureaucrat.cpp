#include "Bureaucrat.hpp"

#include <string>
#include <exception>
#include <iostream>

Bureaucrat::Bureaucrat() : _name("default"), _grade(1)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const & name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	std::cout << "Bureaucrat " << _name << " constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src._name), _grade(src._grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs)
{
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	if (this != &rhs)
		_grade = rhs._grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat default destructor called" << std::endl;
}

std::string const &	Bureaucrat::getName() const
{
	return _name;
}

int	Bureaucrat::getGrade() const
{
	return _grade;
}

void	Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    	return "grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "grade is too low";
}

std::ostream & operator<<(std::ostream & os, Bureaucrat const & b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}