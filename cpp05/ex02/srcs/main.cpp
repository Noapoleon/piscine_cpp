#include <iostream>
#include <string>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

#define COL_TEST	"\e[4;3;1m"
#define COL_ERR		"\e[31;1m"
#define COL_RST		"\e[0m"

void	show_err(const std::exception& e)
{
	std::cout << COL_ERR "error -> " << e.what() << COL_RST << std::endl;
}

int	main(void)
{
	// Init rng
	srand(time(NULL));

	try {
		std::cout << COL_TEST "PresidentialPardonForm Test #1" COL_RST << std::endl;
		Bureaucrat				b1("Miguel", 2);
		PresidentialPardonForm	f1;

		b1.signForm(f1);
		b1.executeForm(f1);
		f1.execute(b1);
	} catch (std::exception& e) {
		show_err(e);
	}

	try {
		std::cout << COL_TEST "\nRobotomyRequestForm Test #1" COL_RST << std::endl;
		Bureaucrat				b1("Pedro", 45);
		RobotomyRequestForm	f1;

		b1.signForm(f1);
		b1.executeForm(f1);
		f1.execute(b1);
	} catch (std::exception& e) {
		show_err(e);
	}
	try {
		std::cout << COL_TEST "\nRobotomyRequestForm Test #2" COL_RST << std::endl;
		Bureaucrat				b1("Pedro", 46);
		RobotomyRequestForm	f1;

		b1.signForm(f1);
		b1.executeForm(f1);
		f1.execute(b1);
	} catch (std::exception& e) {
		show_err(e);
	}
	try {
		std::cout << COL_TEST "\nRobotomyRequestForm Test #3" COL_RST << std::endl;
		Bureaucrat				b1("Pedro", 72);
		RobotomyRequestForm	f1;

		b1.signForm(f1);
		b1.executeForm(f1);
		f1.execute(b1);
	} catch (std::exception& e) {
		show_err(e);
	}
	try {
		std::cout << COL_TEST "\nRobotomyRequestForm Test #4" COL_RST << std::endl;
		Bureaucrat				b1("Pedro", 73);
		RobotomyRequestForm	f1;

		b1.signForm(f1);
		b1.executeForm(f1);
		f1.execute(b1);
	} catch (std::exception& e) {
		show_err(e);
	}

	return (0);
}
