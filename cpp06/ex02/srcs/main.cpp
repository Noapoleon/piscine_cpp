/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 08:50:01 by nlegrand          #+#    #+#             */
/*   Updated: 2024/02/17 14:28:33 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:40:21 by vegret            #+#    #+#             */
/*   Updated: 2023/10/27 02:20:33 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class Base
{
public:
	virtual ~Base(void) {};
};
class A : public Base {};
class B : public Base {};
class C : public Base {};

Base*	generate(void)
{
	Base*	tmp;
	int		r;

	tmp = NULL;
	r = rand() % 3;
	try {
		if (r == 0)
		{
			tmp = new A;
			std::cout << "Generated -> A" << std::endl;
		}
		else if (r == 1)
		{
			tmp = new B;
			std::cout << "Generated -> B" << std::endl;
		}
		else
		{
			tmp = new C;
			std::cout << "Generated -> C" << std::endl;
		}
	} catch (const std::exception& e) {
		std::cout << "Exception generate(): " << e.what() << std::endl;
	}
	return (tmp);
}

void	identify(Base* p)
{
	char	type;

	type = '0';
	if (dynamic_cast<A*>(p))
		type = 'A';
	if (dynamic_cast<B*>(p))
		type = 'B';
	if (dynamic_cast<C*>(p))
		type = 'C';
	std::cout << type << std::endl;
}

void	identify(Base& p)
{
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	} catch (const std::exception& e) {}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	} catch (const std::exception& e) {}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	} catch (const std::exception& e) {}
	std::cout << "Couldn't identify" << std::endl;
}

int	main(void)
{
	Base *tmp[10];

	srand(time(NULL));
	// generate
	for (int i = 0; i < 10; ++i)
		tmp[i] = generate();

	// identify pointer
	for (int i = 0; i < 10; ++i)
		identify(tmp[i]);
	std::cout << std::endl;
	// identify reference
	for (int i = 0; i < 10; ++i)
		identify(*(tmp[i]));

	// delete
	for (int i = 0; i < 10; ++i)
		delete tmp[i];
	return (0);
}
