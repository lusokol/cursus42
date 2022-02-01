/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:57:32 by lusokol           #+#    #+#             */
/*   Updated: 2022/01/29 19:37:44 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include "main.hpp"

class Book {

public:

    Book(void);
    ~Book(void);

	void Add(void);
	void Search(void);
	Contact list[8];
	int	nb_contact;
};

#endif