/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:27:30 by macbookpro        #+#    #+#             */
/*   Updated: 2022/05/25 18:18:56 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rbt.hpp"
#include <iostream>

#include <stdlib.h>
#include <time.h>  

int main(void) {
	ft::rbt<int> yolo;
	// srand (time(NULL));
	// std::cout << "How much random node do you want ?" << std::endl;
	// int nb;
	// std::cin >> nb;
	// for (int i = 0; i < nb; i++)
	// 	yolo.insert(rand() % 1000 + 1);
	for (int i = 0; i < 15; i++)
		yolo.insert(i);
	yolo.print_tree(yolo.getNode());
	std::cout << std::endl;
	std::cout << std::endl;
	yolo.delete_node(yolo.getNode()->left);
	yolo.print_tree(yolo.getNode());
	std::cout << std::endl;
	std::cout << std::endl;
	// return 0;
	yolo.delete_node(yolo.getNode()->right);
	yolo.print_tree(yolo.getNode());
	std::cout << std::endl;
	std::cout << std::endl;
	yolo.delete_node(yolo.getNode()->right);
	yolo.print_tree(yolo.getNode());
	std::cout << std::endl;
	std::cout << std::endl;
	yolo.delete_node(yolo.getNode()->right);
	yolo.print_tree(yolo.getNode());
	std::cout << std::endl;
	std::cout << std::endl;
	yolo.delete_node(yolo.getNode()->right);
	yolo.print_tree(yolo.getNode());
	std::cout << std::endl;
	std::cout << std::endl;
	yolo.delete_node(yolo.getNode());
	yolo.print_tree(yolo.getNode());
	std::cout << std::endl;
	std::cout << std::endl;
	
	yolo.delete_node(yolo.getNode());
	yolo.print_tree(yolo.getNode());
	std::cout << std::endl;
	std::cout << std::endl;

	yolo.delete_node(yolo.getNode());
	yolo.print_tree(yolo.getNode());
	std::cout << std::endl;
	std::cout << std::endl;

	yolo.delete_node(yolo.getNode());
	yolo.print_tree(yolo.getNode());
	std::cout << std::endl;
	std::cout << std::endl;
	
	yolo.delete_node(yolo.getNode());
	yolo.print_tree(yolo.getNode());
	std::cout << std::endl;
	std::cout << std::endl;
	
	yolo.delete_node(yolo.getNode());
	yolo.print_tree(yolo.getNode());
	std::cout << std::endl;
	std::cout << std::endl;

	yolo.delete_node(yolo.getNode());
	yolo.print_tree(yolo.getNode());
	std::cout << std::endl;
	std::cout << std::endl;
	
	yolo.insert(3);
	yolo.print_tree(yolo.getNode());
	std::cout << std::endl;
	std::cout << std::endl;

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
	return 0;
}