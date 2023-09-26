/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:38:37 by mneri             #+#    #+#             */
/*   Updated: 2023/09/26 17:19:43 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
int Account::_totalAmount = 0;


int	Account::getNbAccounts( void )
{
	return _nbAccounts;
}

int Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals ( void )
{
	return _totalNbWithdrawals;
}

int Account::getTotalAmount ( void )
{
	return _totalAmount;
}

int Account::checkAmount ( void ) const
{
	return _amount;
}


Account::Account( int initial_deposit )
{
	_nbAccounts++;
	_accountIndex = _nbAccounts - 1;
	_totalAmount += initial_deposit;
	_amount = initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" << "amount:" << _amount << ";created" << std::endl;
}

Account::~Account(void)
{
	_nbAccounts--;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" << "amount:" << _amount << ";closed" << std::endl;
}

void Account::displayAccountsInfos ( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";" << "total:" 
			  << Account::getTotalAmount() << ";" << "deposits:" << Account::getNbDeposits() 
			  << ";" << "withdrawls:" << Account::getNbWithdrawals() << ';' << std::endl;
}

void Account::displayStatus ( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" << "amount:" << _amount << ";" << "deposits:" << _nbDeposits
			  << ";" << "withdrawals:" << _nbWithdrawals << ";" << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	if(withdrawal > _amount)
	{
		std::cout << "index:" << _accountIndex << ";" << "p_amount:" << _amount << ";" << "withdrawal:refused"
				  << std::endl;
		return 0;
	}
	else
	{
		int p_amount = _amount;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		std::cout << "index:" << _accountIndex << ";" << "p_amount:" << p_amount << ";" << "withdrawal:" << withdrawal
				  << ";" << "amount:" << _amount << ";" << "nb_withdrawal:" << _nbWithdrawals << ";" << std::endl; 
		return 1;
	}
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	int p_amount = _amount;
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	_amount += deposit;
	std::cout << "index:" << _accountIndex << ";" << "p_amount:" << p_amount << ";" << "deposit:" << deposit << ";"
			  << "amount:" << _amount << ";" "nb_deposits:" << _nbDeposits << ';' << std::endl; 
}

void	Account::_displayTimestamp( void )
{
	//  Get the current time
    std::time_t rawTime;
    std::tm* timeInfo;
    char timestamp[20]; // Assuming the timestamp will always have 20 characters

    std::time(&rawTime);
    timeInfo = std::localtime(&rawTime);

    // Format the time as a string in the desired format
    std::strftime(timestamp, sizeof(timestamp), "[%Y%m%d_%H%M%S]", timeInfo);

    // Display the timestamp
    std::cout << timestamp;
}
