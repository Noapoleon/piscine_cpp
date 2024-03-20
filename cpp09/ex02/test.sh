#!/bin/bash

# test number global variable
test_num=0
# function to increment it
test_show()
{
	((test_num++))
	echo -e "\e[31mTest $test_num:\e[0m" 
}

# testing function
testing()
{
	test_show
	echo -e "\e[33margc ->\e[0m " $#
	echo -e "\e[33margv ->\e[0m " "$@"
	./PmergeMe "$@"
	#valgrind --track-fds=yes --leak-check=full --track-origins=yes --show-leak-kinds=all -s ./PmergeMe $@
}

echo -e "\e[34;7;3mBad arguments:\e[0m"
testing
testing ""
testing "    "
testing "123" "456"

echo -e "\e[34;7;3mGood arguments:\e[0m"
testing "0"
testing "1"
testing "9"
testing "     123     "
testing "456     "
testing "     789"
testing "1 2 3"
testing "  1 2 3"
testing "1 2 3   "
