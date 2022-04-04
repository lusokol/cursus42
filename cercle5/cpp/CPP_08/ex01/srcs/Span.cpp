/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:36:59 by lusokol           #+#    #+#             */
/*   Updated: 2022/04/04 17:28:27 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "color.hpp"
#include <iostream>

Span::Span(unsigned int N) : size(N), data(new int[N]), index(0) {
    for (unsigned int i = 0; i < N; i++) {
        this->data[i] = 0;
    }
};

Span::Span(Span const &ref) : size(ref.getSize()), data(new int[ref.getSize()]), index(ref.getIndex()) {
    *this = ref;
}

Span::~Span(void) {}

Span &Span::operator=(Span const &ref) {
    if (ref.data != this->data) {
        delete[] this->data;
        this->data = new int[ref.getSize()];
        for (int i = 0; i < ref.getSize(); i++) {
            this->data[i] = ref.data[i];
        }
        this->index = ref.index;
    }
    return (*this);
}

void Span::addNumber(int nbr) {
    this->data[this->index] = nbr;
    this->index++;
}

int Span::shortestSpan(void) {
    if (this->size <= 1)
        throw std::runtime_error("Size too small");
    return this->findHigher() - this->findLower();
}

int Span::longestSpan(void) {
    if (this->size <= 1)
        throw std::runtime_error("Size too small");
    return std::this->findHigher() - this->findLower();
}

void Span::affData(void) {
    std::cout << ORANGE;
    for (int i = 0; i < this->size; i++) {
        std::cout << this->data[i] << "\t";
    }
    std::cout << std::endl << STOP;
}