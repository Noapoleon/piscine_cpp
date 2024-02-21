/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 01:33:38 by nlegrand          #+#    #+#             */
/*   Updated: 2024/02/21 01:43:35 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <stdexcept>
#include <algorithm>
#include <cctype>
#include <climits>

class RPN
{
public:
	// Destructors
	~RPN(void);

	// Utils
	static int	rpn(const std::string format);
private:
	// Constructors (private)
	RPN(void);
	RPN(const RPN& copy);

	// Operatos (private)
	RPN&	operator=(const RPN& copy);
};

#endif // RPN_HPP
