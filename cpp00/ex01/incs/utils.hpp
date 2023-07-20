/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 02:05:51 by nlegrand          #+#    #+#             */
/*   Updated: 2023/07/20 20:59:37 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

#include <iostream>
#include <limits>

void		clear_cin(void);
bool		reachedEof(void);
std::string	truncField(std::string str);
int			is_valid_phone(std::string &str);

#endif
