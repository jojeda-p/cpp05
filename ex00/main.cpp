#include "Bureaucrat.hpp"

#include <iostream>
#include <string>

int main()
{
    try {
        Bureaucrat a("Alice", 0);
        std::cout << a << std::endl;
    }
    catch (std::exception & e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
	
    return 0;
}