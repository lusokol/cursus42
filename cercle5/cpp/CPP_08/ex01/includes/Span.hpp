/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:33:47 by lusokol           #+#    #+#             */
/*   Updated: 2022/04/05 17:10:02 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_CPP
# define SPAN_CPP

# include <vector>

class Span {
    
    public:
        
        Span(unsigned int N = 0);
        Span(Span const &ref);
        ~Span(void);
        Span &operator=(Span const &ref);
        void addNumber(int nbr);
        void affData(void);
        template <typename T>
        void addNumber(T it, T ite) {
            if (this->data.size() + std::distance(it, ite) > this->size)
                throw std::runtime_error("Cannot fill span from range : size too small");
            for (; it != ite; it++)
                this->data.push_back(*it);
        }
        int longestSpan(void);
        int shortestSpan(void);

        int getSize(void) const {return this->size;}
        std::vector<int> getData(void) const {return this->data;}

    private:

        unsigned long int size;
        std::vector<int> data;

        int findHigher(void);
        int findLower(void);

};

std::ostream &operator<<(std::ostream &ostream, Span const &ref);

#endif