#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <exception>
#include <iostream>

#include "Bureaucrat.hpp"

class Form
{
	private:
		std::string const	_name;
        bool                _isSigned;
        int	const			_gradeToSign;
		int	const			_gradeToExecute;
	public:
		Form();
		Form(std::string const & name, int gradeToSign, int gradeToExecute);
		Form(Form const & src);
		Form & operator=(Form const & rhs);
		~Form();
	
		std::string const &	getName() const;
		int					getGradeToExecute() const;
		int					getGradeToSign() const;
		bool				getIsSigned() const;
        void				beSigned(Bureaucrat const & bureaucrat);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, const Form &f);

#endif