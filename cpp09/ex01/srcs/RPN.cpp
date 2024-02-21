/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 01:32:35 by nlegrand          #+#    #+#             */
/*   Updated: 2024/02/21 02:05:23 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

static bool	isOperator(char c)
{ return (c == '+' || c == '-' || c == '*' || c == '/'); }

static void	handleOperator(char op, std::stack<long>& ops)
{
	long	tmp;

	tmp = ops.top();
	ops.pop();
	switch (op)
	{
		case '+':
			ops.top() = ops.top() + tmp;
			break;
		case '-':
			ops.top() = ops.top() - tmp;
			break;
		case '*':
			ops.top() = ops.top() * tmp;
			break;
		case '/':
			if (tmp == 0)
				throw std::runtime_error("Division by zero");
			ops.top() = ops.top() / tmp;
			break;

	}
	if (ops.top() > INT_MAX || ops.top() < INT_MIN)
		throw std::runtime_error("Integer overflow/underflow");
}

int	RPN::rpn(const std::string format)
{
	std::stack<long>	ops;

	for (size_t i = 0; format[i]; ++i)
	{
		if (isdigit(format[i]))
			ops.push(format[i] - '0');
		else if (isOperator(format[i]))
		{
			if (ops.size() < 2)
				throw std::runtime_error("Missing operand");
			handleOperator(format[i], ops);
		}
		else if (format[i] != ' ')
			throw std::runtime_error("Unknown operator or operand");
	}
	if (ops.size() > 1)
		throw std::runtime_error("Missing operator");
	else if (ops.size() == 0)
		return (0);
	else
		return (static_cast<int>(ops.top()));
}

// Constructors (private)
RPN::RPN(void) {}
RPN::RPN(const RPN& copy) { (void)copy; }

// Operatos (private)
RPN&	RPN::operator=(const RPN& copy) { (void)copy; return (*this); }
