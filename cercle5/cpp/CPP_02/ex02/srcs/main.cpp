/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:26:47 by macbookpro        #+#    #+#             */
/*   Updated: 2022/02/16 13:41:33 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#define RED "\e[38;5;196m"
#define GREEN "\e[38;5;118m"
#define ORANGE "\e[38;5;208m"
#define STOP "\e[0m"

// sources operateur de surcharge
// http://casteyde.christian.free.fr/cpp/cours/online/x3244.html#:~:text=Le%20C%2B%2B%20permet%20donc%20de,d%C3%A9finir%20des%20fonctions%20membres%20normales.&text=Par%20exemple%2C%20la%20plupart%20des,classe%20sur%20laquelle%20ils%20travaillent.

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << GREEN << "Incrementation (a++ and ++a)" << STOP << std::endl;
	
	std::cout << GREEN << "Base value : " << RED << a << STOP << std::endl;
	std::cout << GREEN << "++a :        " << RED << ++a << STOP << std::endl;
	std::cout << GREEN << "actual :     " << RED << a << STOP << std::endl;
	std::cout << GREEN << "a++ :        " << RED << a++ << STOP << std::endl;
	std::cout << GREEN << "actual :     " << RED << a << STOP << std::endl;

	std::cout << GREEN << std::endl << "Decrementation (a-- and --a)" << std::endl;
	std::cout << GREEN << "Base value : " << RED << a << STOP << std::endl;
	std::cout << GREEN << "--a :        " << RED << --a << STOP << std::endl;
	std::cout << GREEN << "Actual :     " << RED << a << STOP << std::endl;
	std::cout << GREEN << "a-- :        " << RED << a-- << STOP << std::endl;
	std::cout << GREEN << "Actual :     " << RED << a << STOP << std::endl;

	Fixed c(10.09f);
	Fixed d(10.01f);

	std::cout << std::endl << GREEN << "Comparaison :" << std::endl;
	std::cout << GREEN << "Start value, c = " << RED << c << GREEN << " and d = " << RED << d << STOP << std::endl;
	std::cout << GREEN << "Comparator \"==\" : " << RED << c << GREEN << GREEN << " == " << RED << d << GREEN << " -> " << ORANGE << ((c == d) ? "true" : "false") << STOP << std::endl;
	std::cout << GREEN << "Comparator \"!=\" : " << RED << c << GREEN << GREEN <<" != " << RED << d << GREEN << " -> " << ORANGE << ((c != d) ? "true" : "false") << STOP << std::endl;
	std::cout << GREEN << "Comparator \">\" : " << RED << c << GREEN << GREEN <<" > " << RED << d << GREEN << " -> " << ORANGE << ((c > d) ? "true" : "false") << STOP << std::endl;
	std::cout << GREEN << "Comparator \">=\" : " << RED << c << GREEN << GREEN <<" >= " << RED << d << GREEN << " -> " << ORANGE << ((c >= d) ? "true" : "false") << STOP << std::endl;
	std::cout << GREEN << "Comparator \"<\" : " << RED << c << GREEN << GREEN <<" < " << RED << d << GREEN << " -> " << ORANGE << ((c < d) ? "true" : "false") << STOP << std::endl;
	std::cout << GREEN << "Comparator \"<=\" : " << RED << c << GREEN << GREEN <<" <= " << RED << d << GREEN << " -> " << ORANGE << ((c <= d) ? "true" : "false") << STOP << std::endl << std::endl;

	std::cout << GREEN << "Normal variable" << std::endl;
	std::cout << GREEN << "Smallest between " << RED << c << GREEN << " and " << RED << d << GREEN << " : " << ORANGE << Fixed::min( c, d ) << STOP << std::endl;
	std::cout << GREEN << "Smallest between " << RED << d << GREEN << " and " << RED << c << GREEN << " : " << ORANGE << Fixed::min( d, c ) << STOP << std::endl;
	std::cout << GREEN << "Biggest between " << RED << c << GREEN << " and " << RED << d << GREEN << " : " << ORANGE << Fixed::max( c, d ) << STOP << std::endl;
	std::cout << GREEN << "Biggest between " << RED << d << GREEN << " and " << RED << c << GREEN << " : " << ORANGE << Fixed::max( d, c ) << STOP << std::endl << std::endl;
	
	Fixed const c2( 13.45f );
	Fixed const d2( 8.42f );
	std::cout << GREEN << "Const variable" << std::endl;
	std::cout << GREEN << "Smallest between " << RED << c2 << GREEN << " and " << RED << d2 << GREEN << " : " << ORANGE << Fixed::min( c2, d2 ) << STOP << std::endl;
	std::cout << GREEN << "Smallest between " << RED << d2 << GREEN << " and " << RED << c2 << GREEN << " : " << ORANGE << Fixed::min( d2, c2 ) << STOP << std::endl;
	std::cout << GREEN << "Biggest between " << RED << c2 << GREEN << " and " << RED << d2 << GREEN << " : " << ORANGE << Fixed::max( c2, d2 ) << STOP << std::endl;
	std::cout << GREEN << "Biggest between " << RED << d2 << GREEN << " and " << RED << c2 << GREEN << " : " << ORANGE << Fixed::max( d2, c2 ) << STOP << std::endl;
	return 0;
}