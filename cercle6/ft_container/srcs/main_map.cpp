/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:27:30 by macbookpro        #+#    #+#             */
/*   Updated: 2022/05/17 18:15:31 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"
#include <iostream>
#include "../bst_visu/visu/visualizer.cpp"

int main(void) {
	ft::map<int> yolo;

	yolo.insert(6);
	// yolo.aff_tree(yolo.getNode());
	// std::cout << std::endl;
	yolo.insert(3);
	// yolo.aff_tree(yolo.getNode());
	// std::cout << std::endl;
	yolo.insert(7);
	// yolo.aff_tree(yolo.getNode());
	// std::cout << std::endl;
	yolo.insert(5);
	// yolo.aff_tree(yolo.getNode());
	// std::cout << std::endl;
	yolo.insert(8);
	// yolo.aff_tree(yolo.getNode());
	// std::cout << std::endl;
	yolo.insert(2);
	// yolo.aff_tree(yolo.getNode());
	// std::cout << std::endl;
	yolo.insert(9);
	// yolo.aff_tree(yolo.getNode());
	// std::cout << std::endl;
	yolo.insert(1);
	// yolo.aff_tree(yolo.getNode());
	// std::cout << std::endl;
	yolo.insert(4);
	// yolo.aff_tree(yolo.getNode());
	// std::cout << std::endl;
	yolo.insert(0);
	// yolo.aff_tree(yolo.getNode());
	// std::cout << std::endl;
	const visualizer<int> v(yolo);
	cout << endl << endl;
	v.visualize();
	cout << endl << endl;
	return 0;
}