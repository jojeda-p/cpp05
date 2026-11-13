#include "Form.hpp"

#include <string>
#include <exception>
#include <iostream>

Form::Form() : _name("default"), _isSigned(false), _gradeToSign(1), _gradeToExecute(1)
{
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string const & name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
    std::cout << "Form " << _name << " constructor called" << std::endl;
}

Form::Form(Form const & src) : _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
    std::cout << "Form copy constructor called" << std::endl;
}

Form & Form::operator=(Form const & rhs)
{
    std::cout << "Form copy assignment operator called" << std::endl;
    if (this != &rhs)
        _isSigned = rhs._isSigned;
    return *this;
}

Form::~Form()
{
    std::cout << "Form " << _name << " destructor called" << std::endl;
}

std::string const & Form::getName() const
{
    return _name;
}

int Form::getGradeToExecute() const
{
    return _gradeToExecute;
}

int Form::getGradeToSign() const
{
    return _gradeToSign;
}

void Form::beSigned(Bureaucrat const & bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    if (_isSigned)
        return;
    _isSigned = true;
}

bool Form::getIsSigned() const
{
    return _isSigned;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Form: grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Form: grade is too low";
}

std::ostream & operator<<(std::ostream & os, Form const & f)
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

