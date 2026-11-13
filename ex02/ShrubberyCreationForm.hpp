#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

#include <string>
#include <exception>

class ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;
    
    protected:
        virtual void		executeAction() const;
    
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string const & target);
        ShrubberyCreationForm(ShrubberyCreationForm const & src);
        ShrubberyCreationForm & operator=(ShrubberyCreationForm const & rhs);
        ~ShrubberyCreationForm();
    
    class FileOpenException : public std::exception
    {
        public:
            virtual const char *what() const throw();
    };

};

#endif