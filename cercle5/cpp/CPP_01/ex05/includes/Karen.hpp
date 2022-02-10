/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:34:22 by macbookpro        #+#    #+#             */
/*   Updated: 2022/02/09 18:37:50 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP
# define KAREN_HPP

# include <iostream>

class Karen {

public:

	Karen(void);
	~Karen(void);
	void complain( std::string level );

private:

	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
};

#endif