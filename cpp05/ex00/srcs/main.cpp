#include <iostream>
#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat b1;
	Bureaucrat b2("Ritupon", 5);
	Bureaucrat b22("Baishya", 145);
	Bureaucrat b3(b2);

	// TEST //
	std::cout << std::endl << "TEST: bad construction values" << std::endl;
	try {
		Bureaucrat b4("Vegretdinateur", 0);
	}
	catch (const std::exception& e) {
		std::cout << "error: " << e.what() << std::endl;
	}
	try {
		Bureaucrat b5("tom bearnaise", 151);
	}
	catch (const std::exception& e) {
		std::cout << "error: " << e.what() << std::endl;
	}
	try {
		Bureaucrat b7("danil aime la serveuse", 150);
	}
	catch (const std::exception& e) {
		std::cout << "error: " << e.what() << std::endl;
	}
	// ---- //

	// TEST //
	std::cout << std::endl << "TEST: manually using getName() and getGrade() methods" << std::endl;
	std::cout << b1.getName() << " has authority level " << b1.getGrade() << std::endl;
	std::cout << b2.getName() << " has authority level " << b2.getGrade() << std::endl;
	std::cout << b22.getName() << " has authority level " << b22.getGrade() << std::endl;
	std::cout << b3.getName() << " has authority level " << b3.getGrade() << std::endl;
	// ---- //

	// TEST
	std::cout << std::endl << "TEST: assignment operator" << std::endl;
	b1 = b2;
	std::cout << b1 << std::endl;
	b3 = b22;
	std::cout << b3 << std::endl;
	// ---- //

	// TEST
	std::cout << std::endl << "TEST: increment loop" << std::endl;
	while (1)
	{
		std::cout << b2 << std::endl;
		try {
			b2.incrementGrade();
		} catch (const std::exception& e) {
			std::cout << "increment error -> " << e.what() << std::endl;
			break ;
		}
	}
	// ---- //

	// TEST
	std::cout << std::endl << "TEST: decrement loop" << std::endl;
	while (1)
	{
		std::cout << b22 << std::endl;
		try {
			b22.decrementGrade();
		} catch (const std::exception& e) {
			std::cout << "decrement error -> " << e.what() << std::endl;
			break ;
		}
	}
	// ---- //

	return (0);
}
