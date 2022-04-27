/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:36:59 by lusokol           #+#    #+#             */
/*   Updated: 2022/04/05 17:09:21 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "color.hpp"
#include <iostream>
#include <climits>

Span::Span(unsigned int N) : size(N) {
    this->data.reserve(N);
};

Span::Span(Span const &ref) : size(ref.getSize()) {
    this->data.reserve(ref.getSize());
    *this = ref;
}

Span::~Span(void) {}

Span &Span::operator=(Span const &ref) {
    if (ref.data != this->data) {
        this->data = ref.data;
    }
    return (*this);
}

void Span::addNumber(int nbr) {
    if (this->data.size() == this->size)
        throw std::runtime_error("Max size reached");
    this->data.push_back(nbr);
}

int Span::shortestSpan(void) {
    if (this->size <= 1)
        throw std::runtime_error("Size too small");
    std::vector<int> tmp = this->data;
    std::sort(tmp.begin(), tmp.end());
    long int shortest = UINT_MAX;
    for (unsigned long int i = 0; i < tmp.size() - 1; i++) {
        shortest = ((tmp[i+1]-tmp[i]) < shortest) ? (tmp[i + 1] - tmp[i]) : shortest;
    }
    return shortest;
}

int Span::longestSpan(void) {
    if (this->size <= 1)
        throw std::runtime_error("Size too small");
    int max = *std::max_element(this->data.begin(), this->data.end());
    int min = *std::min_element(this->data.begin(), this->data.end());
    return (max - min);
}

void Span::affData(void) {
    std::cout << LGREEN << "Array : " << ORANGE;
    for (unsigned long int i = 0; i < this->data.size(); i++) {
        std::cout << this->data[i] << "\t";
    }
    std::cout << std::endl << STOP;
}

std::ostream &operator<<(std::ostream &ostream, Span const &ref) {
    ostream << LGREEN << "Array : " << ORANGE;
    for (unsigned long int i = 0; i < ref.getData().size(); i++) {
        ostream << ref.getData()[i] << "\t";
    }
    ostream << std::endl << STOP;
    return ostream;
}