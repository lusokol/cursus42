/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:19:09 by lusokol           #+#    #+#             */
/*   Updated: 2022/03/22 16:00:09 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.hpp"

int main(void) {
    for (int i = 0; i < 10; i++) {
        Base *test = generate();
        identify(test);
        identify(*test);
        delete test;
        std::cout << std::endl;
    }
    return 0;
}