/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Litteral.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:37:41 by lusokol           #+#    #+#             */
/*   Updated: 2022/03/21 17:47:28 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LITTERAL_HPP
# define LITTERAL_HPP

#include <iostream>
#include "color.hpp"
#include <cmath>
#include <iomanip>

#define INTMAX 2147483647
#define INTMIN -2147483648
#define CHAR 1
#define INT 2
#define DOUBLE 3
#define FLOAT 4

class Litteral {

public:

    Litteral(const char *toConvert);
    Litteral(Litteral const &ref);
    ~Litteral(void);
    bool isInt(const char *str);
    bool isDouble(const char *str);
    bool isFloat(const char *str);
    bool isChar(const char *str);
    void print_nb(void);
    Litteral &operator=(Litteral const &ref);

private:

    int type;
    int _int;
    char _char;
    float _float;
    double _double;
    
    void cast_all(void);
    void check_printable(void);
    void print_char(void);
    void print_int(void);
    int char_print; // non printable : 2, printable : 1, impossible char : 0
    int int_print;  // impossible int : 0, else 1
    std::string str;

};

#endif