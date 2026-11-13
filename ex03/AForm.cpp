#include "AForm.hpp"

#include <string>
#include <exception>
#include <iostream>

AForm::AForm() : _name("default"), _isSigned(false), _gradeToSign(1), _gradeToExecute(1)
{
    std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string const & name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
    std::cout << "AForm " << _name << " constructor called" << std::endl;
}

AForm::AForm(AForm const & src) : _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
    std::cout << "AForm copy constructor called" << std::endl;
}

AForm & AForm::operator=(AForm const & rhs)
{
    std::cout << "AForm copy assignment operator called" << std::endl;
    if (this != &rhs)
        _isSigned = rhs._isSigned;
    return *this;
}

AForm::~AForm()
{
    std::cout << "AForm " << _name << " destructor called" << std::endl;
}

std::string const & AForm::getName() const
{
    return _name;
}

int AForm::getGradeToExecute() const
{
    return _gradeToExecute;
}

int AForm::getGradeToSign() const
{
    return _gradeToSign;
}

void AForm::beSigned(Bureaucrat const & bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    if (_isSigned)
        return;
    _isSigned = true;
}

bool AForm::getIsSigned() const
{
    return _isSigned;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Form: grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Form: grade is too low";
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return "Form: form is not signed";
}

std::ostream & operator<<(std::ostream & os, AForm const & f)
{
    os << "Form " << f.getName() << ", signed: ";
    if (f.getIsSigned())
    {
            os << "true";
        }
        else
        {
            os << "false";
        }
        os << ", grade to sign: " << f.getGradeToSign() << ", grade to execute: " << f.getGradeToExecute();
        return os;
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (!_isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > _gradeToExecute)
        throw GradeTooLowException();
    executeAction();
}



