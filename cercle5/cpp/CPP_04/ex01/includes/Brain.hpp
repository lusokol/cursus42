/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:19:01 by lusokol           #+#    #+#             */
/*   Updated: 2022/02/28 18:27:25 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain {

public:
  
    Brain(void);
    Brain(Brain const &ref);
    ~Brain(void);
    Brain &operator=(Brain const &ref);

private:
    
    std::string ideas[100];
    
};

#endif