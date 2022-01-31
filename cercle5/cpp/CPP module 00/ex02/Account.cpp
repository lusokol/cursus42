/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:12:01 by lusokol           #+#    #+#             */
/*   Updated: 2022/01/31 18:38:50 by lusokol          ###   ########.fr       */
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
	//_totalNbDeposits += 1;
	std::cout << " index:" << this->_accountIndex << ";amount:" << _amount << ";created" << std::endl;
	return ;
}

Account::~Account(void) {
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << _amount << ";closed" << std::endl;
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
	std::cout << " accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
	return ;
}
void Account::makeDeposit(int deposit) {
	Account::_displayTimestamp();
	int p_amount = _amount;
	_amount += deposit;
	_nbDeposits += 1;
	std::cout << " index:" << _accountIndex << ";p_amount:" << p_amount << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;	return ;
}
// [19920104_091532] index:0;p_amount:47;withdrawal:refused
// [19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
bool Account::makeWithdrawal(int withdrawal) {
	Account::_displayTimestamp();
	int p_amount = _amount;
	if (withdrawal > _amount)
		std::cout << " index:" << _accountIndex << ";p_amount:" << p_amount << ";withdrawal:refused" <<std::endl;
	else {
		_amount -= withdrawal;
		_nbWithdrawals += 1;
		std::cout << " index:" << _accountIndex << ";p_amount:" << p_amount << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	}
	return true;
}

int Account::checkAmount(void) const {
	std::cout << _accountIndex << " check amount" << std::endl;
	return 0;
}

void Account::displayStatus(void) const {
	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
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