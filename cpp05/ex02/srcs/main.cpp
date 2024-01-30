#include <iostream>
#include <string>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define COL_PARA	"\e[34;7;1m"
#define COL_TEST	"\e[4;3;1m"
#define COL_ERR		"\e[31;1m"
#define COL_RST		"\e[0m"

template<typename T>
void	testing(T form)
{
	Bureaucrat	b1("Ritu", T::defaultGradeSign + 1); // 
	Bureaucrat	b2("Pon", T::defaultGradeSign);
	Bureaucrat	b3("Bai", T::defaultGradeExec + 1);
	Bureaucrat	b4("Shya", T::defaultGradeExec);

	std::cout << "\e[36;1m===TEST===\e[0m" << std::endl;
	std::cout << form << std::endl;
	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
	std::cout << b3 << std::endl;
	std::cout << b4 << std::endl;

	// Signing tests
	std::cout << "\nSIGN TESTS:" << std::endl;
	try {
		form.beSigned(b2);
		form.beSigned(b1); // fail here
	} catch (const std::exception& e) {
		std::cerr << "Signing failed: " << e.what() << std::endl;
	}
	b1.signForm(form); // fail here
	b2.signForm(form);

	// Exec tests
	std::cout << "\nEXEC TESTS:" << std::endl;
	try {
		form.execute(b4);
		form.execute(b3); // fail here
	} catch (const std::exception& e) {
		std::cerr << "Executing failed: " << e.what() << std::endl;
	}
	b3.executeForm(form); // fail here
	b4.executeForm(form);
}

int	main(void)
{
	// Init rng
	srand(time(NULL));

	// PresidentialPardonForm
	testing(ShrubberyCreationForm("Rattatak"));
	std::cout << std::endl;
	testing(RobotomyRequestForm("Lalalala"));
	std::cout << std::endl;
	testing(PresidentialPardonForm("Noapoleon"));
	return (0);
}
