#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	try {
		Bureaucrat				b1("Miguel", 2);
		PresidentialPardonForm	f2;


		b1.signForm(f2);
		b1.executeForm(f2);
		f2.execute(b1);
	} catch (std::exception& e) {
		std::cout << "error -> " << e.what() << std::endl;
	}

	return (0);
}
