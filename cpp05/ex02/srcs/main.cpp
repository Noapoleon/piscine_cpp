#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int	main(void)
{
	// try catch
	Bureaucrat b1;
	Bureaucrat b2("Pedro", 77);
	Bureaucrat b3("Miguel", 78);
	Bureaucrat b4("Javier", 79);

	// will throw exception so needs to be in try catch block too
	try {
		Bureaucrat b5("Roberto", -1);
		Bureaucrat b6("Roberto", 151);
	}
	catch (std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}

	// try catch
	AForm	f1;
	AForm	f2("Mall construction Request", 0, 78, 78);

	// will throw exception so needs to be in try catch block too
	//AForm	f4("lalalalaalalalalalalalaal", -1, 151);

	b2.signForm(f2);
	b3.signForm(f2);
	b4.signForm(f2);

	f2.beSigned(b2);
	f2.beSigned(b3);
	//f2.beSigned(b4); // will throw an exception

	return (0);
}
