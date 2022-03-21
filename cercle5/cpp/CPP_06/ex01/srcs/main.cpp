/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:47:04 by lusokol           #+#    #+#             */
/*   Updated: 2022/03/21 17:43:04 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serialisation.hpp"
#include "color.hpp"

int main(void) {
    Data data;
    Data *bis;
    uintptr_t dataPtr;

    data.str = "Wow, this string is beautiful !";
    std::cout << ORANGE << "string at start : " << STOP << data.str << std::endl;
    std::cout << YELLOW << "serialize..." << STOP << std::endl;
    dataPtr = serialize(&data);
    std::cout << BLUE << "address from data    : " << &data << std::endl << STOP;
    std::cout << BLUE << "address from uintptr : " << "0x" << std::hex << dataPtr << std::endl << STOP;
    std::cout << YELLOW << "deserialize..." << STOP << std::endl;
    bis = deserialize(dataPtr);
    std::cout << ORANGE << "string at the end : " << STOP << bis->str << std::endl;
    return 0;
}