#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>

class   AForm;

class Intern
{
	public:
		Intern();
		Intern(Intern const & src);
		Intern & operator=(Intern const & rhs);
		~Intern();

        AForm*  makeForm(std::string const & nameForm, std::string const & targetForm) const;

};

#endif