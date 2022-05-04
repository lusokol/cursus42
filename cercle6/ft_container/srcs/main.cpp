/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:16:05 by lusokol           #+#    #+#             */
/*   Updated: 2022/05/04 16:03:15 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.tpp"

int main(void) {
std::cout << "Test constructeur de fill" << std::endl;
{
    //ft::vector<int> test(5, 8);
    ft::vector<int> test(5, 8);
    ft::Iterator<int> it = test.begin();
    ft::Iterator<int> ite = test.end();
    while (it != ite) {
        std::cout << "(" << *it << ") ";
        it++;
    }
    std::cout << std::endl;
}
std::cout << "Test isintegral" << std::endl;
{
    std::cout << std::boolalpha;
  std::cout << "is_integral:" << std::endl;
  std::cout << "char: " << ft::is_integral<char>::value << std::endl;
  std::cout << "int: " << ft::is_integral<int>::value << std::endl;
  std::cout << "float: " << ft::is_integral<float>::value << std::endl;   
}

}