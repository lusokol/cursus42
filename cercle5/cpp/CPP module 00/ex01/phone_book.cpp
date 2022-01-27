/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:59:31 by lusokol           #+#    #+#             */
/*   Updated: 2022/01/27 18:01:33 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone_book.hpp"

Book::Book( void ) {
    std::cout << "constructeur !" << std::endl;
    return;
}

Book::~Book( void ) {
    std::cout << "Destructeur !" << std::endl;
    return;
}