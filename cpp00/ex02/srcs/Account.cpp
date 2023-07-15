/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 04:59:44 by nlegrand          #+#    #+#             */
/*   Updated: 2023/07/15 07:42:15 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.hpp"

Account::Account( int initial_deposit )
{
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;

	++Account::_nbAccounts;
	Account::_totalAmount += initial_deposit;
	++Account::_totalNbDeposits;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << initial_deposit;
	std::cout << ";created" << std::endl;
}

Account::~Account( void )
{
	--Account::_nbAccounts;
	Account::_totalAmount -= this->_amount;
}

int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

void	Account::makeDeposit( int deposit )
{
	this->_amount += deposit;
	++this->_nbDeposits;
	++Account::_totalNbDeposits;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (this->_amount < withdrawal)
		return (false);
	this->_amount -= withdrawal;
	++this->_nbWithdrawals;
	++Account::_totalNbWithdrawals;
	return (true);
}

int	Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawls:" << this->_nbWithdrawals << std::endl;
}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts();
	std::cout << ";total:" << getTotalAmount();
	std::cout << ";deposits:" << getNbDeposits();
	std::cout << ";withdrawals:" << getNbWithdrawals() << std::endl;
}


void	Account::_displayTimestamp( void )
{
	std::time_t		time = std::time(NULL);
	struct std::tm	*tm = std::localtime(&time);

	std::cout << "[";
	std::cout << std::setw(4) << std::setfill('0') << tm->tm_year + 1900;
	std::cout << std::setw(2) << std::setfill('0') << tm->tm_mon << tm->tm_mday;
	std::cout << "_" << std::setw(2) << std::setfill('0') << tm->tm_hour;
	std::cout << std::setw(2) << std::setfill('0') << tm->tm_min;
	std::cout << std::setw(2) << std::setfill('0') << tm->tm_sec;
	std::cout << "] ";
}

int	Account::_nbAccounts			= 0;
int	Account::_totalAmount			= 0;
int	Account::_totalNbDeposits		= 0;
int	Account::_totalNbWithdrawals	= 0;
