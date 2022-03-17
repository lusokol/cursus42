/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Litteral.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:51:49 by lusokol           #+#    #+#             */
/*   Updated: 2022/03/17 19:37:54 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Litteral.hpp"

bool Litteral::isInt(const char *toCheck){
    char *end = NULL;
	long int res = strtol(toCheck, &end, 10);

	if (*end != '\0' || res > INTMAX || res < INTMIN)
		return (false);

	this->type = INT;
	this->_int = static_cast<int>(res);
	return (true);
}

bool Litteral::isDouble(const char *toCheck){
    char *end = NULL;
	long int res = strtod(toCheck, &end);

	if (*end != '\0')
		return (false);

	this->type = DOUBLE;
	this->_double = static_cast<double>(res);
	return (true);
}

bool Litteral::isFloat(const char *toCheck){
    char *end = NULL;
	long int res = strtof(toCheck, &end);

	if (*end != 'f' || *(end + 1) != '\0')
		return (false);

	this->type = FLOAT;
	this->_float = static_cast<float>(res);
	return (true);
}

bool Litteral::isChar(const char *toCheck){
    char a = toCheck[0];

	if ((toCheck[0] && toCheck[1] != '\0') || std::isprint(a) == false)
		return (false);

	this->type = CHAR;
	this->_char = a;
	return (true);
}

Litteral::Litteral(const char *toConvert) {
    std::cout << "Litteral constructor called" << std::endl;
    this->type = 0;
    if (this->isInt(toConvert) == false)
        if (this->isDouble(toConvert) == false)
            if (this->isFloat(toConvert) == false)
                this->isChar(toConvert) == false;
    std::cout << "Arg type : " << this->type << std::endl;
    this->aff_all();
}

Litteral::~Litteral(void) {
    std::cout << "Litteral destructor called" << std::endl;
}