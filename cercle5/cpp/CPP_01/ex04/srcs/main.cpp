/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:05:43 by macbookpro        #+#    #+#             */
/*   Updated: 2022/02/09 15:12:09 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string>
#include <fstream>

int main (int ac, char **av)
{
	// parsing
	if (ac != 4) {
		std::cout << "Invalid arguments" << std::endl << "./mySed [file from] [search] [replace]" << std::endl;
		return (1);
	}
	
	// reading file from
	std::string str;
	std::ifstream file (av[1], std::ios::in);
	if (file.is_open()) {
		while (!file.eof())
			str.push_back(file.get());
		str.pop_back();
  	}
	else {
		std::cout << "Unable to open " << av[1] << std::endl;
		return (1);
	}

	// search and replace
	
	std::string str2 (av[2]);
	std::string str3 (av[3]);
	int index;
	while ((index = str.find(str2)) != std::string::npos) {
		str.erase(index, str2.length());
		str.insert(index, str3);
	}

	// create and write in file.replace
	std::string outputFile (av[1]);
	outputFile.insert(outputFile.length(), ".replace");
	std::ofstream file2 (outputFile);
	if (file2.is_open())
		file2 << str;
	else {
		std::cout << "Unable to create " << av[1] << std::endl;
		return (1);
	}
	
	std::cout << "\e[38;5;118mEnd of mySed, search and replace program\e[0m" << std::endl;
  return 0;
}