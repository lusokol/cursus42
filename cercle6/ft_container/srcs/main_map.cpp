/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:27:30 by macbookpro        #+#    #+#             */
/*   Updated: 2022/05/30 17:32:38 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"
#include "rbt.hpp"
#include "pair.hpp"
#include <iostream>

#include <stdlib.h>
#include <time.h>  
	#include <list>

int main(void) {
	ft::map<int, std::string> yolo;
	// ft::rbt<ft::pair<int, std::string> > yolo;
	// ft::pair<int, int> p;
	// srand (time(NULL));
	// std::cout << "How much random node do you want ?" << std::endl;
	// int nb;
	// std::cin >> nb;
	// for (int i = 0; i < nb; i++)
	// 	yolo.insert(rand() % 1000 + 1);
	// for (int i = 0; i < 10; i++) {
	// yolo.insert(ft::pair<int, std::string>(42, std::string("test")));
	// yolo.insert(ft::pair<int, std::string>(25, std::string("test")));
	// yolo.insert(ft::pair<int, std::string>(80, std::string("test")));
	// yolo.insert(ft::pair<int, std::string>(12, std::string("test")));
	// yolo.insert(ft::pair<int, std::string>(27, std::string("test")));
	// yolo.insert(ft::pair<int, std::string>(90, std::string("test")));
	yolo[42] = "test";
	yolo[25] = "test";
	yolo[80] = "test";
	yolo[12] = "test";
	yolo[27] = "test";
	yolo[90] = "test";
	yolo.print_tree();
	// }
	// yolo.print_tree();
	// std::cout << std::endl;

// #include "../containers_test/srcs/map/common.hpp"
// #define TESTED_NAMESPACE ft

// #define T1 int
// #define T2 int
// typedef _pair<const T1, T2> T3;

// int		main(void)
// {
// 	std::list<T3> lst;
// 	unsigned int lst_size = 7;
// 	for (unsigned int i = 0; i < lst_size; ++i)
// 		lst.push_back(T3(lst_size - i, i));

// 	TESTED_NAMESPACE::map<T1, T2> mp(lst.begin(), lst.end());
// 	TESTED_NAMESPACE::map<T1, T2>::iterator it = mp.begin(), ite = mp.end();

// 	TESTED_NAMESPACE::map<T1, T2> mp_range(it, --(--ite));
// 	for (int i = 0; it != ite; ++it)
// 		it->second = ++i * 5;

// 	it = mp.begin(); ite = --(--mp.end());
// 	TESTED_NAMESPACE::map<T1, T2> mp_copy(mp);
// 	for (int i = 0; it != ite; ++it)
// 		it->second = ++i * 7;

// 	std::cout << "\t-- PART ONE --" << std::endl;
// 	printSize(mp);
// 	printSize(mp_range);
// 	printSize(mp_copy);

// 	mp = mp_copy;
// 	mp_copy = mp_range;
// 	mp_range.clear();

// 	std::cout << "\t-- PART TWO --" << std::endl;
// 	printSize(mp);
// 	std::cout << "\t-- PART THREE --" << std::endl;
// 	printSize(mp_range);
// 	std::cout << "\t-- PART FOUR --" << std::endl;
// 	printSize(mp_copy);
// 	return (0);
// }

	// std::cout << std::endl;
	// std::cout << std::endl;
	// yolo.delete_node(yolo.getNode()->left);
	// yolo.print_tree(yolo.getNode());
	// std::cout << std::endl;
	// std::cout << std::endl;
	// // return 0;
	// yolo.delete_node(yolo.getNode()->right);
	// yolo.print_tree(yolo.getNode());
	// std::cout << std::endl;
	// std::cout << std::endl;
	// yolo.delete_node(yolo.getNode()->right);
	// yolo.print_tree(yolo.getNode());
	// std::cout << std::endl;
	// std::cout << std::endl;
	// yolo.delete_node(yolo.getNode()->right);
	// yolo.print_tree(yolo.getNode());
	// std::cout << std::endl;
	// std::cout << std::endl;
	// yolo.delete_node(yolo.getNode()->right);
	// yolo.print_tree(yolo.getNode());
	// std::cout << std::endl;
	// std::cout << std::endl;
	// yolo.delete_node(yolo.getNode());
	// yolo.print_tree(yolo.getNode());
	// std::cout << std::endl;
	// std::cout << std::endl;
	
	// yolo.delete_node(yolo.getNode());
	// yolo.print_tree(yolo.getNode());
	// std::cout << std::endl;
	// std::cout << std::endl;

	// yolo.delete_node(yolo.getNode());
	// yolo.print_tree(yolo.getNode());
	// std::cout << std::endl;
	// std::cout << std::endl;

	// yolo.delete_node(yolo.getNode());
	// yolo.print_tree(yolo.getNode());
	// std::cout << std::endl;
	// std::cout << std::endl;
	
	// yolo.delete_node(yolo.getNode());
	// yolo.print_tree(yolo.getNode());
	// std::cout << std::endl;
	// std::cout << std::endl;
	
	// yolo.delete_node(yolo.getNode());
	// yolo.print_tree(yolo.getNode());
	// std::cout << std::endl;
	// std::cout << std::endl;

	// yolo.delete_node(yolo.getNode());
	// yolo.print_tree(yolo.getNode());
	// std::cout << std::endl;
	// std::cout << std::endl;
	
	// yolo.insert(3);
	// yolo.print_tree(yolo.getNode());
	// std::cout << std::endl;
	// std::cout << std::endl;

	// yolo.delete_node(yolo.getNode());
	// yolo.print_tree(yolo.getNode());
	// std::cout << std::endl;
	// std::cout << std::endl;

	// yolo.delete_node(yolo.getNode());
	// yolo.print_tree(yolo.getNode());
	// std::cout << std::endl;
	// std::cout << std::endl;
	
	// yolo.delete_node(yolo.getNode());
	// yolo.print_tree(yolo.getNode());
	// std::cout << std::endl;
	// std::cout << std::endl;
	
	// yolo.delete_node(yolo.getNode()->right);
	// yolo.print_tree(yolo.getNode());
	// std::cout << std::endl;
	// std::cout << std::endl;

	// yolo.insert(6);
	// yolo.insert(3);
	// yolo.insert(7);
	// yolo.insert(5);
	// yolo.insert(8);
	// yolo.insert(2);
	// yolo.insert(9);
	// yolo.insert(1);
	// yolo.insert(4);
	// yolo.insert(10);
	// yolo.insert(30);
	// yolo.insert(20);
	// yolo.insert(40);
	// yolo.insert(50);
	// yolo.insert(60);
	// yolo.insert(90);
	// yolo.insert(70);
	// yolo.insert(80);
	// yolo.insert(1120);
	// yolo.insert(3540);
	// yolo.insert(1230);
	// yolo.insert(3210);
	// yolo.insert(1320);
	// yolo.insert(350);
	// yolo.insert(840);
	// yolo.insert(960);
	// yolo.insert(780);
	// yolo.insert(980);
	// yolo.insert(480);
	// yolo.insert(260);
	// yolo.insert(730);
	// yolo.insert(840);
	// yolo.insert(550);
/* 	yolo.insert(0);
	yolo.insert(1);
	yolo.insert(2);
	yolo.insert(3);
	yolo.insert(4);
	yolo.insert(5);
	yolo.insert(6);
	yolo.insert(7);
	yolo.insert(8);
	yolo.insert(9);
	yolo.insert(10);
	yolo.insert(11); */

	// yolo.insert(7);
	// yolo.insert(3);
	// yolo.insert(1);
	// yolo.insert(0);
	// yolo.insert(2);
	// yolo.insert(5);
	// yolo.insert(4);
	// yolo.insert(6);
	// yolo.insert(8);
	// yolo.insert(100);
	// yolo.insert(9);
	// yolo.insert(11);
	
	// yolo.insert(4);
	// yolo.insert(2);
	// yolo.insert(1); // for right rotation
	// yolo.insert(5);
	// yolo.insert(3);
	
	// yolo.insert(2);
	// yolo.insert(1);
	// yolo.insert(4); // for left rotation
	// yolo.insert(3);
	// yolo.insert(5);

	// yolo.insert(6);
	// yolo.insert(4);
	// yolo.insert(8);
	// yolo.insert(2);
	// yolo.insert(5);
	// yolo.insert(7);
	// yolo.insert(9);
	// yolo.insert(1);
	// yolo.insert(3);

	// yolo.insert(12);
	// yolo.insert(234);
	// yolo.insert(2);
	// yolo.insert(23);
	// yolo.insert(13);
	// yolo.insert(54);

	// yolo.insert(3);
	// yolo.insert(5);
	// yolo.insert(4);
	
	// yolo.print_tree(yolo.getNode());

	// ////////////////////////////////////
	// yolo.rotate_right_left(yolo.getNode());
	////////////////////////////////////
	// std::cout << std::endl;
	// yolo.rotate_left(yolo.getNode()->left);
	
	// yolo.print_tree(yolo.getNode());
	// std::cout << std::endl;
	// yolo.rotate_right(yolo.getNode());
	////////////////////////////////////
	
	// yolo.print_tree(yolo.getNode());
	// std::cout << std::endl;

	
	// yolo.print_tree(yolo.getNode());
	// yolo.rotate_right(yolo.getNode()->left);
	// std::cout << std::endl;
	// yolo.print_tree(yolo.getNode());
	// std::cout << std::endl;
	// yolo.rotate_left(yolo.getNode()->left);
	// std::cout << std::endl;
	// yolo.print_tree(yolo.getNode());
	// std::cout << std::endl;
	// return 0;
}