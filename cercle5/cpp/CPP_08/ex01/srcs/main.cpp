/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:05:24 by lusokol           #+#    #+#             */
/*   Updated: 2022/04/05 14:56:14 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.hpp"
#include "Span.hpp"
#include <iostream>

int main(void) {
    std::cout << BLUE << "Creation of array step by step" << STOP << std::endl;
    Span sp = Span(5);
    sp.affData();
    sp.addNumber(6);
    sp.affData();
    sp.addNumber(3);
    sp.affData();
    sp.addNumber(17);
    sp.affData();
    sp.addNumber(9);
    sp.affData();
    sp.addNumber(11);
    sp.affData();

    std::cout << BLUE << "Shortest span : " << LGREEN << sp.shortestSpan() << STOP << std::endl;
    std::cout << BLUE << "Longest span : " << LGREEN << sp.longestSpan() << STOP << std::endl;
}