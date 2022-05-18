/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:27:30 by macbookpro        #+#    #+#             */
/*   Updated: 2022/05/18 18:59:30 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"
#include <iostream>

int main(void) {
	ft::map<int> yolo;

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

	yolo.insert(7);
	yolo.insert(3);
	yolo.insert(1);
	yolo.insert(0);
	yolo.insert(2);
	yolo.insert(5);
	yolo.insert(4);
	yolo.insert(6);
	yolo.insert(8);
	yolo.insert(10);
	yolo.insert(9);
	yolo.insert(11);
	
	// yolo.insert(0);
	// yolo.insert(1);
	// yolo.insert(2);
	// yolo.insert(3);
	// yolo.insert(4);
	// yolo.insert(5);
	// yolo.insert(6);
	// yolo.insert(7);
	// yolo.insert(8);
	// yolo.insert(9);
	// yolo.insert(10);
	// yolo.insert(11);
	
	yolo.print_tree(yolo.getNode());
	std::cout << std::endl;
	return 0;
}