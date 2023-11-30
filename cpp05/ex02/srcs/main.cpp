#include <iostream>
#include <string>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define COL_PARA	"\e[34;7;1m"
#define COL_TEST	"\e[4;3;1m"
#define COL_ERR		"\e[31;1m"
#define COL_RST		"\e[0m"

void	show_err(const std::exception& e)
{
	std::cout << COL_ERR "error -> " << e.what() << COL_RST << std::endl;
}

template <typename T>
void	try_form(T form, int b_grade)
{
	if (b_grade == -1)
	{
		try {
			Bureaucrat	b("Miguel", 1);

			b.executeForm(form);
		} catch (std::exception& e) {
			show_err(e);
		}
		return ;
	}
	try {
		Bureaucrat	b("Miguel", b_grade);

		b.signForm(form);
		b.executeForm(form);
		form.execute(b);
	} catch (std::exception& e) {
		show_err(e);
	}
}

int	main(void)
{
	// Init rng
	srand(time(NULL));

	// PresidentialPardonForm TESTS //
	std::cout << COL_PARA "PresidentialPardonForm TESTS:" COL_RST << std::endl;
	std::cout << COL_TEST "PresidentialPardonForm Test #1" COL_RST << std::endl;
	try_form(PresidentialPardonForm(), 26);
	std::cout << COL_TEST "PresidentialPardonForm Test #2" COL_RST << std::endl;
	try_form(PresidentialPardonForm(), 25);
	std::cout << COL_TEST "PresidentialPardonForm Test #3" COL_RST << std::endl;
	try_form(PresidentialPardonForm(), 6);
	std::cout << COL_TEST "PresidentialPardonForm Test #4" COL_RST << std::endl;
	try_form(PresidentialPardonForm(), 5);
	std::cout << COL_TEST "PresidentialPardonForm Test #5" COL_RST << std::endl;
	try_form(PresidentialPardonForm(), -1);
	// ---------------------------- //

	// RobotomyRequestForm TESTS //
	std::cout << "\n\n" COL_PARA "RobotomyRequestForm TESTS:" COL_RST << std::endl;
	std::cout << COL_TEST "RobotomyRequestForm Test #1" COL_RST << std::endl;
	try_form(RobotomyRequestForm(), 73);
	std::cout << COL_TEST "RobotomyRequestForm Test #2" COL_RST << std::endl;
	try_form(RobotomyRequestForm(), 72);
	std::cout << COL_TEST "RobotomyRequestForm Test #3" COL_RST << std::endl;
	try_form(RobotomyRequestForm(), 46);
	std::cout << COL_TEST "RobotomyRequestForm Test #4" COL_RST << std::endl;
	try_form(RobotomyRequestForm(), 45);
	std::cout << COL_TEST "RobotomyRequestForm Test #5" COL_RST << std::endl;
	try_form(RobotomyRequestForm(), -1);
	// ---------------------------- //

	// ShrubberyCreationForm TESTS //
	std::cout << "\n\n" COL_PARA "ShrubberyCreationForm TESTS:" COL_RST << std::endl;
	std::cout << COL_TEST "ShrubberyCreationForm Test #1" COL_RST << std::endl;
	try_form(ShrubberyCreationForm(), 146);
	std::cout << COL_TEST "ShrubberyCreationForm Test #2" COL_RST << std::endl;
	try_form(ShrubberyCreationForm(), 145);
	std::cout << COL_TEST "ShrubberyCreationForm Test #3" COL_RST << std::endl;
	try_form(ShrubberyCreationForm(), 138);
	std::cout << COL_TEST "ShrubberyCreationForm Test #4" COL_RST << std::endl;
	try_form(ShrubberyCreationForm(), 137);
	std::cout << COL_TEST "ShrubberyCreationForm Test #5" COL_RST << std::endl;
	try_form(ShrubberyCreationForm(), -1);
	// ---------------------------- //
	return (0);
}
