/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:36:03 by lusokol           #+#    #+#             */
/*   Updated: 2022/05/31 18:51:14 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "stack.hpp"
#include "map.hpp"
#include <vector>
#include <stack>
#include <map>
#include <iostream>

// #ifndef STD
//     #define TESTED_NAMESPACE ft
// #else
//     #define TESTED_NAMESPACE std
// #endif

#define TESTED_NAMESPACE ft

int main(void) {
	{
		// TESTED_NAMESPACE::vector<int> first;
		// TESTED_NAMESPACE::vector<int> second(1000, int(42));
		// TESTED_NAMESPACE::vector<int> third(second);
		// TESTED_NAMESPACE::vector<int> const fourth(third.begin(), third.end());
		// first = fourth;
		// second.assign(500, 21);
		// third.assign(second.begin(), second.end());
		// TESTED_NAMESPACE::vector<int>::allocator_type alloc;
		// int *ptr = alloc.allocate(1);
		// alloc.destroy(ptr);
		// std::cout << first.size() << std::endl;
		// std::cout << first.capacity() << std::endl;
		// std::cout << first.empty() << std::endl;
		// first.clear();
		// std::cout << first.size() << std::endl;
		// std::cout << first.capacity() << std::endl;
		// std::cout << first.empty() << std::endl;
		// for (int i = 0; i < 1000; i++)
			// first.push_back(i);
		// std::cout << first.size() << std::endl;
		// std::cout << first.capacity() << std::endl;
		// std::cout << first.empty() << std::endl;
		// std::cout << first[42] << std::endl;
		// std::cout << fourth[42] << std::endl;
		// std::cout << first.at(21) << std::endl;
		// std::cout << fourth.at(12) << std::endl;
		// std::cout << first.front() << std::endl;
		// std::cout << fourth.front() << std::endl;
		// std::cout << first.back() << std::endl;
		// std::cout << fourth.back() << std::endl;
		// std::cout << second.size() << std::endl;
		// std::cout << second.capacity() << std::endl;
		// second.reserve(42);
		// std::cout << second.capacity() << std::endl;
		// std::cout << third.max_size() << std::endl;
		// std::cout << third.size() << std::endl;
		// third.resize(750, 12);
		// std::cout << third.size() << std::endl;
		// for (int i = 0; i < 20; i++)
			// third.pop_back();
		// std::cout << third.size()<< std::endl;
		// first.insert(first.begin() + 17, 65);
		// second.insert(second.begin() + 14, 5, 21);
		// third.insert(third.begin() + 6, first.begin(), first.end());
		// second.erase(second.end() - 23);
		// third.erase(third.end() - 12, third.end());
		// first.swap(second);
		// swap(third, second);
		// for (TESTED_NAMESPACE::vector<int>::const_iterator it = first.begin(), ite = first.end(); it != ite; ++it)
			// std::cout << *it << std::endl;
		// for (TESTED_NAMESPACE::vector<int>::iterator it = third.begin(), ite = third.end(); it != ite; it++)
			// std::cout << *it << std::endl;
		// for (TESTED_NAMESPACE::vector<int>::const_reverse_iterator it = fourth.rbegin(), ite = fourth.rend(); it != ite; ++it)
			// std::cout << *it << std::endl;
		// for (TESTED_NAMESPACE::vector<int>::reverse_iterator it = third.rbegin(), ite = third.rend(); it != ite; it++)
			// std::cout << *it << std::endl;
		// std::cout << (first == second) << std::endl;
		// std::cout << (third != second) << std::endl;
		// std::cout << (third <= second) << std::endl;
		// std::cout << (third >= second) << std::endl;
		// std::cout << (third < fourth) << std::endl;
		// std::cout << (third > fourth) << std::endl;
		// first.clear();
		// for (int i = 0; i < 100000000; ++i)
			// first.push_back(i);
		// while (first.empty() == false)
			// first.pop_back();
	} {
		// TESTED_NAMESPACE::stack<int> first;
		// std::cout << first.empty() << std::endl;
		// std::cout << first.size() << std::endl;
		// for (int i = 0; i < 10000000; ++i) {
			// first.push(i);
			// std::cout << first.top() << std::endl;
		// }
		// while (first.empty() == false)
			// first.pop();
		// TESTED_NAMESPACE::stack<int> second;
		// for (int i = 10000000; i < 20000000; ++i) {
			// second.push(i);
			// std::cout << second.top() << std::endl;
		// }
		// std::cout << (first == second) << std::endl;
		// std::cout << (third != second) << std::endl;
		// std::cout << (third <= second) << std::endl;
		// std::cout << (third >= second) << std::endl;
		// std::cout << (third < fourth) << std::endl;
		// std::cout << (third > fourth) << std::endl;
	} {
		TESTED_NAMESPACE::map<int, int> first;
		TESTED_NAMESPACE::pair<TESTED_NAMESPACE::map<int, int>::iterator, bool> p;
		for (int i = 0; i < 500; ++i) {
			p = first.insert(TESTED_NAMESPACE::make_pair(i, 500 - i));
			std::cout << p.first->first << " " << p.first->second << " " << p.second << std::endl;
		}
		std::cout << first.size() << std::endl;
		TESTED_NAMESPACE::map<int, int> second(first.begin(), first.end());
		second[645] = 42;
		std::cout << first.size() << std::endl;
		second[845] = 45;
		second[16584] = 12;
		second[43] = 142;
		std::cout << first.size() << std::endl;
		second[56] = 144;
		second[84] = 111;
		std::cout << first.size() << std::endl;
		TESTED_NAMESPACE::map<int, int> third(second);
		std::cout << third.max_size() << std::endl;
		TESTED_NAMESPACE::map<int, int> const fourth = third;
		TESTED_NAMESPACE::map<int, int> fifth;
		TESTED_NAMESPACE::map<int, int> sixth;
		third.insert(first.begin(), first.end());
		TESTED_NAMESPACE::map<int, int>::iterator it;
		TESTED_NAMESPACE::map<int, int>::iterator _it;
		for (it = third.begin(); it != third.end(); it++) {
			_it = fifth.insert(third.begin(), TESTED_NAMESPACE::make_pair<int, int>(it->first * 2, it->second * 4));
			std::cout << it->first << " " << it->second << std::endl;
		}
		for (int i = 0; i < 500; ++i) {
			p = first.insert(TESTED_NAMESPACE::make_pair(i, 500 - i));
			std::cout << p.first->first << " " << p.first->second << " " << p.second << std::endl;
		}
		std::cout << sixth.size() << std::endl;
		sixth.insert(fifth.begin(), fifth.end());
		std::cout << sixth.size() << std::endl;
		// it = second.begin();
		// for (int i = 0; i < 42; ++i)
			// it++;
		// second.erase(it);
		// second.erase(second.begin());
		// second.erase(second.begin());
		// second.erase(second.end());
		// second.erase(second.end());
		// second.erase(51);
		// second.erase(299);
		// second.erase(123);
		// second.erase(111);
		// it = fifth.begin();
		// for (int i = 0; i < 42; ++i)
			// it++;
		// _it = fifth.end();
		// for (int i = 0; i < 42; ++i)
			// it--;
		// fifth.erase(it, _it);
		// fifth.swap(sixth);

	}
	return (0);
}