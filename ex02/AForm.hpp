#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include <exception>
#include <iostream>

#include "Bureaucrat.hpp"

class AForm
{
	private:
		std::string const	_name;
        bool                _isSigned;
        int	const			_gradeToSign;
		int	const			_gradeToExecute;
	protected:
		virtual void		executeAction() const = 0;
	public:
		AForm();
		AForm(std::string const & name, int gradeToSign, int gradeToExecute);
		AForm(AForm const & src);
		AForm & operator=(AForm const & rhs);
		virtual ~AForm();
	
		std::string const &	getName() const;
		int					getGradeToExecute() const;
		int					getGradeToSign() const;
		bool				getIsSigned() const;
    	void				beSigned(Bureaucrat const & bureaucrat);
		void				execute(Bureaucrat const & executor) const;

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
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, const AForm &af);

#endif