/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:27:01 by lusokol           #+#    #+#             */
/*   Updated: 2022/03/22 16:00:02 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.hpp"
#include "color.hpp"

Base *generate(void) {
    struct timeval time;
	gettimeofday(&time, NULL);
	srand(time.tv_usec);
    Base *ptr = NULL;
    switch (rand() % 3) {
        case 0:
            ptr = new A();
            std::cout << BLUE << "Generating instance of class A" << std::endl << STOP;
            break;
            
        case 1:
            ptr = new B();
            std::cout << BLUE << "Generating instance of class B" << std::endl << STOP;
            break;
            
        case 2:
            ptr = new C();
            std::cout << BLUE << "Generating instance of class C" << std::endl << STOP;
            break;
    }
    return ptr;
}

void identify(Base *p) {
    std::cout << ORANGE << "\"P\" is a pointer of type : " << STOP;
    if (dynamic_cast<A *>(p) != NULL)
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p) != NULL)
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p) != NULL)
        std::cout << "C" << std::endl;
}

void identify(Base &p) {
    int i = 0;
    std::cout << ORANGE << "\"P\" is a pointer of type : " << STOP;
    try {
        (void)dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
    }
    catch (std::exception &e) {
        i++;
    }
    try {
        (void)dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
    }
    catch (std::exception &e) {
        i++;
    }
    try {
        (void)dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
    }
    catch (std::exception &e) {
        i++;
    }
    if (i == 3)
        std::cout << RED << "Type unknown" << std::endl;
}