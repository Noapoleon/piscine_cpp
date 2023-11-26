#include <iostream>
#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat b1;
	Bureaucrat b2("Ritupon", 123);
	Bureaucrat b3(b2);

	std::cout << "Hello world" << std::endl;
	std::cout << b1.getName() << " has authority level " << b1.getGrade() << std::endl;
	std::cout << b2.getName() << " has authority level " << b2.getGrade() << std::endl;
	std::cout << b3.getName() << " has authority level " << b3.getGrade() << std::endl;

	b1 = b2;
	std::cout << b1.getName() << " has authority level " << b1.getGrade() << std::endl;
	b1.incrementGrade();
	std::cout << b1.getName() << " has authority level " << b1.getGrade() << std::endl;
	b1.incrementGrade();
	std::cout << b1.getName() << " has authority level " << b1.getGrade() << std::endl;
	b1.incrementGrade();
	std::cout << b1.getName() << " has authority level " << b1.getGrade() << std::endl;
	b1.incrementGrade();
	std::cout << b1.getName() << " has authority level " << b1.getGrade() << std::endl;
	b1.decrementGrade();
	std::cout << b1.getName() << " has authority level " << b1.getGrade() << std::endl;
	b1.incrementGrade();
	std::cout << b1.getName() << " has authority level " << b1.getGrade() << std::endl;

	Bureaucrat b4("Miguel", 1);
	Bureaucrat b5("Javier", 150);
	try
	{
		b4.incrementGrade();
	}
	catch (std::exception& e)
	{
		std::cout << "Failed to increment grade: " << e.what() << std::endl;
	}
	try
	{
		b5.decrementGrade();
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cout << "Failed to decrement grade: " << e.what() << std::endl;
	}

	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
	std::cout << b3 << std::endl;
	std::cout << b4 << std::endl;
	std::cout << b5 << std::endl;

	return (0);
}
