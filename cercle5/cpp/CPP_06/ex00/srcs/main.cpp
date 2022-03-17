/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:15:29 by lusokol           #+#    #+#             */
/*   Updated: 2022/03/17 15:00:07 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "color.hpp"
#include "Litteral.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
       std::cerr << RED << "Wrong usage :" << std::endl << av[0] << " <string to convert>" << std::endl << STOP;
       return (1);
    }
    Litteral test(av[1]);
  //  test.print();
}