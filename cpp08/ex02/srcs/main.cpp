/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:51:59 by nlegrand          #+#    #+#             */
/*   Updated: 2024/02/17 19:28:40 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MutantStack.hpp"

int main()
{
	std::cout << "\e[32;7;1mSubject tests:\e[0m" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	// other tests
	std::cout << "\n\e[32;7;1mOther tests:\e[0m" << std::endl;
	std::cout << "top of stack conversion from subject tests: " << s.top() << std::endl;

	// iterator 
	std::cout << "Iterator: ";
	for (MutantStack<int>::iterator it1 = mstack.begin(); it1 != mstack.end(); ++it1)
		std::cout << *it1 << " ";
	std::cout << std::endl;
	// reverse iterator 
	std::cout << "Reverse iterator: ";
	for (MutantStack<int>::reverse_iterator it1 = mstack.rbegin(); it1 != mstack.rend(); ++it1)
		std::cout << *it1 << " ";
	std::cout << std::endl;
	// const iterator 
	std::cout << "Const iterator: ";
	for (MutantStack<int>::const_iterator it1 = mstack.cbegin(); it1 != mstack.cend(); ++it1)
	{
		//if (it1 == mstack.cbegin()) // won't compile
		//	*it1 += 69;
		std::cout << *it1 << " ";
	}
	std::cout << std::endl;
	std::cout << "Const reverse iterator: ";
	for (MutantStack<int>::const_reverse_iterator it1 = mstack.crbegin(); it1 != mstack.crend(); ++it1)
	{
		//if (it1 == mstack.crbegin()) // won't compile
		//	*it1 += 69;
		std::cout << *it1 << " ";
	}
	std::cout << std::endl;
	return 0;
}

//// SUBJECT MAIN TESTS
//int main()
//{
//	MutantStack<int> mstack;
//	mstack.push(5);
//	mstack.push(17);
//	std::cout << mstack.top() << std::endl;
//	mstack.pop();
//	std::cout << mstack.size() << std::endl;
//	mstack.push(3);
//	mstack.push(5);
//	mstack.push(737);
//	//[...]
//	mstack.push(0);
//	MutantStack<int>::iterator it = mstack.begin();
//	MutantStack<int>::iterator ite = mstack.end();
//	++it;
//	--it;
//	while (it != ite)
//	{
//		std::cout << *it << std::endl;
//		++it;
//	}
//	std::stack<int> s(mstack);
//	return 0;
//}
