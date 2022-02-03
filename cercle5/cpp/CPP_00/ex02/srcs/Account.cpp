/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:12:01 by lusokol           #+#    #+#             */
/*   Updated: 2022/02/01 15:34:19 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _amount(initial_deposit) {
	Account::_displayTimestamp();
	_accountIndex = _nbAccounts;
	_nbAccounts += 1;
	_totalAmount += _amount;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	std::cout << "\e[0m index:\e[38;5;208m" << this->_accountIndex << "\e[0m;amount:\e[38;5;208m" << _amount << "\e[0m;created" << std::endl;
	return ;
}

Account::~Account(void) {
	Account::_displayTimestamp();
	std::cout << "\e[0m index:\e[38;5;208m" << this->_accountIndex << "\e[0m;amount:\e[38;5;208m" << _amount << "\e[0m;closed" << std::endl;
	return ;
}

int Account::getNbAccounts(void) {
	return _nbAccounts;
}

int Account::getTotalAmount(void) {
	return _totalAmount;
}

int Account::getNbDeposits(void) {
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void) {
	Account::_displayTimestamp();
	std::cout << "\e[0m accounts:\e[38;5;208m" << getNbAccounts() << "\e[0m;total:\e[38;5;208m" << getTotalAmount() << "\e[0m;deposits:\e[38;5;208m" << getNbDeposits() << "\e[0m;withdrawals:\e[38;5;208m" << getNbWithdrawals() << "\e[0m" << std::endl;
	return ;
}
void Account::makeDeposit(int deposit) {
	Account::_displayTimestamp();
	int p_amount = _amount;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits += 1;
	_totalNbDeposits += 1;
	std::cout << "\e[0m index:\e[38;5;208m" << _accountIndex << "\e[0m;p_amount:\e[38;5;208m" << p_amount << "\e[0m;deposit:\e[38;5;208m" << deposit << "\e[0m;amount:\e[38;5;208m" << _amount << "\e[0m;nb_deposits:\e[38;5;208m" << _nbDeposits << "\e[0m" << std::endl;
	return ;
}

bool Account::makeWithdrawal(int withdrawal) {
	Account::_displayTimestamp();
	int p_amount = _amount;
	if (withdrawal > _amount)
		std::cout << "\e[0m index:\e[38;5;208m" << _accountIndex << "\e[0m;p_amount:\e[38;5;208m" << p_amount << "\e[0m;withdrawal:refused" <<std::endl;
	else {
		_amount -= withdrawal;
		_nbWithdrawals += 1;
		_totalNbWithdrawals += 1;
		_totalAmount -= withdrawal;
		std::cout << "\e[0m index:\e[38;5;208m" << _accountIndex << "\e[0m;p_amount:\e[38;5;208m" << p_amount << "\e[0m;withdrawal:\e[38;5;208m" << withdrawal << "\e[0m;amount:\e[38;5;208m" << _amount << "\e[0m;nb_withdrawals:\e[38;5;208m" << _nbWithdrawals << "\e[0m" << std::endl;
	}
	return true;
}

int Account::checkAmount(void) const {
	std::cout << _accountIndex << "\e[0m check amount" << std::endl;
	return 0;
}

void Account::displayStatus(void) const {
	Account::_displayTimestamp();
	std::cout << "\e[0m index:\e[38;5;208m" << _accountIndex << "\e[0m;amount:\e[38;5;208m" << _amount << "\e[0m;deposits:\e[38;5;208m" << _nbDeposits << "\e[0m;withdrawals:\e[38;5;208m" << _nbWithdrawals << "\e[0m" << std::endl;
	return ;
}

void Account::_displayTimestamp(void) {
	char str[512];
	time_t rawtime;
	struct tm * timeinfo;

	time (&rawtime);
	timeinfo = localtime (&rawtime);
	strftime(str, 512, "[%Y%m%d_%H%M%S]", timeinfo);
	std::cout << str;
}