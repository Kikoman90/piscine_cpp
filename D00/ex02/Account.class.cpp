/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 14:11:48 by fsidler           #+#    #+#             */
/*   Updated: 2016/11/03 13:06:42 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Account.class.hpp"

Account::Account( int initial_deposit ) {
	Account::_displayTimestamp();
	std::cout << "index:" << (Account::_accountIndex = Account::_nbAccounts)
		<< ";amount:" << (Account::_amount = initial_deposit)
		<< ";created" << std::endl;
	Account::_nbDeposits = 0;
	Account::_nbWithdrawals = 0;
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	return;
}

Account::~Account( void ) {
	Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";amount:"
		<< Account::checkAmount() << ";closed" << std::endl;
	return ;
}

void		Account::makeDeposit( int deposit ) {
	Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";p_amount:"
		<< Account::_amount << ";deposit:" << deposit << ";";
	Account::_amount += deposit;
	Account::_totalAmount += deposit;
	Account::_nbDeposits++;
	Account::_totalNbDeposits++;
	std::cout << "amount:" << Account::_amount << ";nb_deposits:"
		<< Account::_nbDeposits << std::endl;
}

bool		Account::makeWithdrawal( int withdrawal ) {
	Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";p_amount:"
		<< Account::_amount << ";withdrawal:";
	if (withdrawal > Account::_amount)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	Account::_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	Account::_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
	std::cout << "amount:" << Account::_amount << ";nb_withdrawals:"
		<< Account::_nbWithdrawals << std::endl;
	return (false);
}

int			Account::checkAmount( void ) const {
	return (Account::_amount);
}

void		Account::displayStatus( void ) const {
	Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";amount:"
		<< Account::_amount << ";deposits:" << Account::_nbDeposits
		<< ";withdrawals:" << Account::_nbWithdrawals << std::endl;
}

void		Account::displayAccountsInfos( void ) {
	Account::_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:"
		<< getTotalAmount() << ";deposits:" << getNbDeposits()
		<< ";withdrawals:" << getNbWithdrawals() << std::endl;
}

int			Account::getNbAccounts( void ) {
	return (Account::_nbAccounts);
}

int			Account::getTotalAmount( void ) {
	return (Account::_totalAmount);
}

int			Account::getNbDeposits( void ) {
	return (Account::_totalNbDeposits);
}

int			Account::getNbWithdrawals( void ) {
	return (Account::_totalNbWithdrawals);
}

void    Account::_displayTimestamp(void)
{
	time_t    cur_time = time(NULL);
	struct tm*local_t = localtime(&cur_time);
	char    time_dis[32];

	strftime(time_dis, 32, "[%Y%d%m_%H%M%S] ", local_t);
	std::cout << time_dis;
}

Account::Account( void ) {
	return ;
}

int			Account::_nbAccounts = 0;
int			Account::_totalAmount = 0;
int			Account::_totalNbDeposits = 0;
int			Account::_totalNbWithdrawals = 0;
