#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Bureaucrat b1;
	Bureaucrat b2("Pedro", 77);
	Bureaucrat b3("Miguel", 78);
	Bureaucrat b4("Javier", 79);

	try {
		Bureaucrat b5("Roberto", 0);
	} catch (const std::exception& e) {
		std::cout << "bureaucrat constructor error: " << e.what() << std::endl;
	}
	try {
		Bureaucrat b6("Roberto", 151);
	} catch (const std::exception& e) {
		std::cout << "bureaucrat constructor error: " << e.what() << std::endl;
	}

	Form	f1;
	Form	f2("Mall construction Request", 78, 78);
	try {
		Form	f4("lalalalaalalalalalalalaal", -1, 151);
	} catch (const std::exception& e) {
		std::cerr << "Form constructor error: " << e.what() << std::endl;
	}

	try {
		std::cout << "\nTEST: signForm" << std::endl;
		b2.signForm(f2);
		b3.signForm(f2);
		b4.signForm(f2);
	} catch (const std::exception& e) {
		std::cerr << "signForm failed: " << e.what() << std::endl;
	}

	try {
		std::cout << "\nTEST: beSigned" << std::endl;
		f2.beSigned(b2);
		std::cout << "signed f2 with b2" << std::endl;
		f2.beSigned(b3);
		std::cout << "signed f2 with b3" << std::endl;
		f2.beSigned(b4); // will throw an exception
		std::cout << "signed f2 with b4" << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "beSigned failed: " << e.what() << std::endl;
	}

	std::cout << "\nTEST: Stream operator" << std::endl;
	std::cout << f1 << std::endl;
	std::cout << f2 << std::endl;

	return (0);
}
