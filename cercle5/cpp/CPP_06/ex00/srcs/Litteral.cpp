/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Litteral.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:51:49 by lusokol           #+#    #+#             */
/*   Updated: 2022/03/21 16:19:32 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Litteral.hpp"

//////////////////////////// CAST /////////////////////////////

void Litteral::cast_all(void) {
	switch (this->type) {
		case CHAR:
			this->_int = static_cast<int>(this->_char);
			this->_double = static_cast<double>(this->_char);
			this->_float = static_cast<float>(this->_char);
			break;

		case INT:
			this->_char = static_cast<char>(this->_int);
			this->_double = static_cast<double>(this->_int);
			this->_float = static_cast<float>(this->_int);
			break;

		case DOUBLE:
			this->_char = static_cast<char>(this->_double);
			this->_int = static_cast<int>(this->_double);
			this->_float = static_cast<float>(this->_double);
			break;

		case FLOAT:
			this->_char = static_cast<char>(this->_float);
			this->_int = static_cast<int>(this->_float);
			this->_double = static_cast<double>(this->_float);
			break;

		default:
			this->char_print = 0;
			this->int_print = 0;
			this->_double = NAN;
			this->_float = NAN;
			break;
	}
}

//////////////////////////// CHECK TYPE //////////////////////////////////

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
	double res = strtod(toCheck, &end);

	if (*end != '\0')
		return (false);

	this->type = DOUBLE;
	this->_double = res;
	return (true);
}
 
bool Litteral::isFloat(const char *toCheck){
    char *end = NULL;
	float res = strtof(toCheck, &end);

	if (*end != 'f' || *(end + 1) != '\0')
		return (false);

	this->type = FLOAT;
	this->_float = res;
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

//////////////////////////// PRINT //////////////////////////////////

void Litteral::check_printable(void) {
	this->char_print = 1;
	this->int_print = 1;
	double d = this->_double;
	
	if (d < static_cast<double>(INTMIN) || d > static_cast<double>(INTMAX) || std::isnan(d) == true || std::isinf(d) == true) {
		this->char_print = 0;
		this->int_print = 0;
	}
	else if (d < CHAR_MIN || d > CHAR_MAX)
		this->char_print = 0;
	else if (std::isprint(this->_char) == false)
		this->char_print = 2;
}

void Litteral::print_char(void) {
	std::cout << ORANGE << "char: " << STOP;
	if (this->char_print == 1)
		std::cout << this->_char << std::endl;
	else if (this->char_print == 2)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "impossible" << std::endl;
}

void Litteral::print_int(void) {
	std::cout << ORANGE << "int: " << STOP;
	if (this->int_print == 1)
		std::cout << this->_int << std::endl;
	else if (this->char_print == 0)
		std::cout << "impossible" << std::endl;
}

void Litteral::print_nb(void) {
	this->cast_all();
	this->check_printable();
	
	std::cout << std::fixed << std::setprecision(1);
	
	this->print_char();
	this->print_int();
	std::cout << ORANGE << "float: " << STOP << this->_float << "f" << std::endl;
	std::cout << ORANGE << "double: " << STOP << this->_double << std::endl;
}

/////////////////// CONSTRUCTEUR / DESTRUCTEUR //////////////////////

Litteral::Litteral(const char *toConvert) {
    //std::cout << "Litteral constructor called" << std::endl;
    this->type = 0;
    if (this->isInt(toConvert) == false)
        if (this->isDouble(toConvert) == false)
            if (this->isFloat(toConvert) == false)
                this->isChar(toConvert);
}

Litteral::~Litteral(void) {
    //std::cout << BLUE << "Litteral destructor called" << std::endl << STOP;
}
