/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Litteral.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:37:41 by lusokol           #+#    #+#             */
/*   Updated: 2022/03/17 14:57:56 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LITTERAL_HPP
# define LITTERAL_HPP

#include <iostream>

class Litteral {

public:

    Litteral(std::string toConvert);
    Litteral(Litteral const &ref);
    ~Litteral(void);

private:

    int type; // 1 = char, 2 = int, 3 = float, 4 = double
    std::string str;

};

#endif