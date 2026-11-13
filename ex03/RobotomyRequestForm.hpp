#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

#include <string>

class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;
    
    protected:
        virtual void		executeAction() const;
    
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string const & target);
        RobotomyRequestForm(RobotomyRequestForm const & src);
        RobotomyRequestForm & operator=(RobotomyRequestForm const & rhs);
        ~RobotomyRequestForm();

};

#endif