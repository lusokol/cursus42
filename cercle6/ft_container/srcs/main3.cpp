/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 14:55:10 by lusokol           #+#    #+#             */
/*   Updated: 2022/05/12 15:51:53 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <iostream>
#include <vector>

#define __VECTOR ft
using namespace std;

int main() {
// vector<int> myvector;
//   int myint;

//   std::cout << "Please enter some integers (enter 0 to end):\n";

//   do {
//     std::cin >> myint;
//     myvector.push_back (myint);
//   } while (myint);

//   std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";

	std::cout << "\nERASE\n";
	vector<vector<int> >	erase_in_me(12);
	vector<vector<int> >	erase_in_you(16);
	
		std::cout << "capacity : " << erase_in_me.capacity() << std::endl;
	// for (int i = 0; i < 15; i++)
	// {
		std::cout << "AVANT" << std::endl;
		std::cout << "capacity : " << erase_in_me.capacity() << std::endl;
		std::cout << "NON V" << std::endl;
		vector<int>	j(1, 1);
		std::cout << "NON A" << std::endl;
		std::cout << "erase in you =======================================================" << std::endl;
		erase_in_you.push_back(j);
		std::cout << "erase in me ========================================================" << std::endl;
		erase_in_me.push_back(j);
		std::cout << "stop ===============================================================" << std::endl;
		std::cout << "APRES" << std::endl;
		std::cout << "size : " << erase_in_me.size() << std::endl;
	// }
	
	/* 	std::cout << "BEFORRRRRRE" << std::endl;
	for (size_t i = 0; i < erase_in_me.size(); i++) {
		std::cout << "[i = " << i << "] " << std::endl;
		std::cout << erase_in_me.at(i).front() << ' ';
	}
	std::cout << '\n';

	erase_in_me.erase(erase_in_me.begin() + 7);
	for (size_t i = 0; i < erase_in_me.size(); i++)
		std::cout << erase_in_me.at(i).front() << ' ';
	std::cout << '\n';
	erase_in_me.erase(erase_in_me.begin() + 2, erase_in_me.begin() + 6);
	for (size_t i = 0; i < erase_in_me.size(); i++)
		std::cout << erase_in_me.at(i).front() << ' ';
	std::cout << '\n'; */

return 0;

}