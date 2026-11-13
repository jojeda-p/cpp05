#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

#include <string>

class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;
    
    protected:
        virtual void		executeAction() const;
    
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string const & target);
        PresidentialPardonForm(PresidentialPardonForm const & src);
        PresidentialPardonForm & operator=(PresidentialPardonForm const & rhs);
        ~PresidentialPardonForm();
};

#endif