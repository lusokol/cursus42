/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Litteral.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:37:41 by lusokol           #+#    #+#             */
/*   Updated: 2022/03/17 19:29:58 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LITTERAL_HPP
# define LITTERAL_HPP

#include <iostream>

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

private:

    int type;
    int _int;
    char _char;
    float _float;
    double _double;
    std::string str;

};

#endif