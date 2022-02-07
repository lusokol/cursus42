/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:37:58 by lusokol           #+#    #+#             */
/*   Updated: 2022/02/07 16:55:26 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void) {
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR(&str);
	std::string &stringREF(str);
	
	std::cout << "str addr : " << &str << std::endl;
	std::cout << "ptr addr : " << stringPTR << std::endl;
	std::cout << "ref addr : " << &stringREF << std::endl;
	
	std::cout << "str : " << str << std::endl;
	std::cout << "ptr : " << *stringPTR << std::endl;
	std::cout << "ref : " << stringREF << std::endl;
}