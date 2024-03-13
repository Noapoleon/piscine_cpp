/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:52:23 by nlegrand          #+#    #+#             */
/*   Updated: 2024/02/21 18:31:24 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <string>
#include <stdexcept>
#include <iostream>
#include <map>
#include <sys/stat.h>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <sstream>

class BitcoinExchange
{
public:
	// Destructors
	~BitcoinExchange(void);

	// Utils
	//static void	btc(std::string data, std::string input);
	static void	btc(const std::string dataName, const std::string inputName);
private:
	// Constructors (private)
	BitcoinExchange(void);
	BitcoinExchange(const BitcoinExchange& copy);

	// Operators (private)
	BitcoinExchange& operator=(const BitcoinExchange& copy);
};

#endif // BITCOIN_EXCHANGE_HPP
