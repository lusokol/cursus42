/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 18:27:58 by macbookpro        #+#    #+#             */
/*   Updated: 2022/01/29 20:29:00 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "main.hpp"

class Contact {

public:

    Contact(void);
    ~Contact(void);

	void	Add_contact(void);
	void	Aff_itself_less(int index);
	void	Aff_itself(void);
	std::string	info[5];
};

#endif