#include <iostream>
#include <string>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

#define COL_PARA	"\e[34;7;1m"
#define COL_TEST	"\e[4;3;1m"
#define COL_ERR		"\e[31;1m"
#define COL_RST		"\e[0m"

void	show_err(const std::exception& e)
{
	std::cout << COL_ERR "error -> " << e.what() << COL_RST << std::endl;
}

template <typename T>
void	try_form(T& form)
{
	Bureaucrat	jon("Jon", Bureaucrat::maxGrade);
	Bureaucrat	bob("Bob", Bureaucrat::minGrade);

	std::cout << "Jon (max grade):" << std::endl;
	try {
		jon.signForm(form);
		jon.executeForm(form);
	} catch (const std::exception& e) {
		show_err(e);
	}
	std::cout << "Bob (min grade):" << std::endl;
	try {
		bob.signForm(form);
		bob.executeForm(form);
	} catch (const std::exception& e) {
		show_err(e);
	}
}

int	main(void)
{
	// Init rng
	srand(time(NULL));

	try
	{
		Intern		someRandomIntern;
		AForm		*form;

		std::cout << "\e[32;7;1mRobotomy test:\e[0m" << std::endl;
		form = someRandomIntern.makeForm("robotomy request", "Bender");
		try_form(*(static_cast<RobotomyRequestForm*>(form)));
		delete form;

		std::cout << "\n\e[32;7;1mPresidential test:\e[0m" << std::endl;
		form = someRandomIntern.makeForm("presidential pardon", "Bender");
		try_form(*(static_cast<PresidentialPardonForm*>(form)));
		delete form;

		std::cout << "\n\e[32;7;1mShrubbery test:\e[0m" << std::endl;
		form = someRandomIntern.makeForm("shrubbery creation", "Bender");
		try_form(*(static_cast<ShrubberyCreationForm*>(form)));
		delete form;

		std::cout << "\n\e[32;7;1mWrong test:\e[0m" << std::endl;
		form = someRandomIntern.makeForm("wrong form", "Bender");
	} catch (const std::exception& e) {
		show_err(e);
	}

	return (0);
}
