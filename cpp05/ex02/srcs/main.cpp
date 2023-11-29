#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int	main(void)
{
	Bureaucrat				b1("Miguel", 2);
	PresidentialPardonForm	f1("bbno$");

	b1.executeForm(f1);
	f1.execute(b1);
	return (0);
}
