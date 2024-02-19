/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:19:50 by nlegrand          #+#    #+#             */
/*   Updated: 2024/02/19 15:50:00 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <iostream>
//#include <string>
//#include "Array.hpp"

//int	main(void)
//{
//	try {
//		Array<int>		a(5);
//		Array<int>		b;
//		Array<float>	c(2);
//
//		std::cout << "a.size() = " << a.size() << std::endl;
//		std::cout << "b.size() = " << b.size() << std::endl << std::endl;
//
//		//b = a;
//
//		std::cout << "a.size() = " << a.size() << std::endl;
//		std::cout << "b.size() = " << b.size() << std::endl << std::endl;
//
//		a[0] = 69;
//		a[1] = 420;
//		a[2] = 1337;
//		a[3] = 42;
//		a[4] = 24;
//		for (int i = 0; i < 5; ++i)
//			std::cout << "a[" << i << "] = " << a[i] << std::endl;
//		b = a;
//		std::cout << std::endl;
//		for (int i = 0; i < 5; ++i)
//			std::cout << "b[" << i << "] = " << b[i] << std::endl;
//		//std::cout << "a[234] = " << a[234] << std::endl;
//		//std::cout << "a[234] = " << a[234] << std::endl;
//
//	} catch (const std::exception& e) {
//		std::cerr << "Exception in main(): " << e.what() << std::endl;
//	}
//	return (0);
//}

#include "Array.hpp"
#include <iostream>
#include <cstdlib>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}
