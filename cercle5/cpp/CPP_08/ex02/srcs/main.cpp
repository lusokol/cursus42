/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:07:46 by lusokol           #+#    #+#             */
/*   Updated: 2022/04/06 16:08:30 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>
#include "color.hpp"

int main(void) {
    std::cout << BLUE << "MutantStack tests :" << STOP << std::endl;
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << ORANGE << "top element : " << STOP << mstack.top() << std::endl;
    mstack.pop();
    std::cout  << ORANGE << "size : " << STOP << mstack.size() << STOP << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    std::cout << ORANGE << "Iteration : " << STOP;
    while (it != ite) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
    std::stack<int> s(mstack);
}
std::cout << std::endl;
std::cout << BLUE << "Same tests with list instead of MutantStack:" << STOP << std::endl;
{
    std::list<int> mstack;
    mstack.push_back(5);
    mstack.push_back(17);
    std::cout << ORANGE << "top element : " << STOP << mstack.back() << std::endl;
    mstack.pop_back();
    std::cout << ORANGE << "size : " << STOP << mstack.size() << std::endl;
    mstack.push_back(3);
    mstack.push_back(5);
    mstack.push_back(737);
    mstack.push_back(0);
    std::list<int>::iterator it = mstack.begin();
    std::list<int>::iterator ite = mstack.end();
    ++it;
    --it;
    std::cout << ORANGE << "Iteration : " << STOP;
    while (it != ite) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
}
std::cout << std::endl;
{
    std::cout << ORANGE << "Tests with const iterator" << STOP << std::endl;
	MutantStack<int> ms;
	ms.push(10);
	ms.push(20);
	ms.push(30);
	ms.push(40);
	ms.push(50);
	for (MutantStack<int>::const_iterator it = ms.begin(), ite = ms.end(); it != ite; it++) {
		// ++(*it); // it's const /!\.
		std::cout << *it;
		if (it + 1 != ite)
			std::cout << ' ';
	}
		std::cout << std::endl;
    std::cout << ORANGE << "Tests with const reverse iterator" << STOP << std::endl;
	for (MutantStack<int>::const_reverse_iterator it = ms.rbegin(), ite = ms.rend(); it != ite; it++) {
	// ++(*it); // it's const /!\.
			std::cout << *it;
		if (it + 1 != ite)
			std::cout << ' ';
	}
	std::cout << std::endl;
    std::cout << ORANGE << "Tests with iterator" << STOP << std::endl;
	for (MutantStack<int>::iterator it = ms.begin(), ite = ms.end(); it != ite; it++) {
		++(*it); // you can here
		std::cout << *it;
		if (it + 1 != ite)
			std::cout << ' ';
	}
	std::cout << std::endl;
    std::cout << ORANGE << "Tests with reverse iterator" << STOP << std::endl;
	for (MutantStack<int>::reverse_iterator it = ms.rbegin(), ite = ms.rend(); it != ite; it++) {
		++(*it); // you can here
		std::cout << *it;
		if (it + 1 != ite)
			std::cout << ' ';
	}
	std::cout << std::endl;
}
    return 0;
}