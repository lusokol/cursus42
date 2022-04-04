/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:33:47 by lusokol           #+#    #+#             */
/*   Updated: 2022/04/04 17:17:21 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_CPP
# define SPAN_CPP

class Span {
    
    public:
        
        Span(unsigned int N = 0);
        Span(Span const &ref);
        ~Span(void);
        Span &operator=(Span const &ref);
        void addNumber(int nbr);
        void affData(void);
        int longestSpan(void);
        int shortestSpan(void);

        int getSize(void) const {return this->size;}
        int getIndex(void) const {return this->index;}

    private:

        int size;
        int *data;
        int index;

        int findHigher(void);
        int findLower(void);

};

#endif