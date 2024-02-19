/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:56:14 by nlegrand          #+#    #+#             */
/*   Updated: 2024/02/17 19:26:53 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <stack>
#include <iterator>

template< typename T>
class MutantStack : public std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

	// Iterators
	iterator	begin(void) { return (this->c.begin()); }
	iterator	end(void) { return (this->c.end()); }
	const_iterator	cbegin(void) const { return (this->c.begin()); }
	const_iterator	cend(void) const { return (this->c.end()); }
	reverse_iterator	rbegin(void) { return (this->c.rbegin()); }
	reverse_iterator	rend(void) { return (this->c.rend()); }
	const_reverse_iterator	crbegin(void) const { return (this->c.rbegin()); }
	const_reverse_iterator	crend(void) const { return (this->c.rend()); }
};

#endif // MUTANT_STACK_HPP
