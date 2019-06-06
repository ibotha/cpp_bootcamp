/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 08:23:33 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/06 09:34:38 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

const int Fixed::s_Point = 8;

Fixed::Fixed()
	:m_Number(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called\n";
	*this = src;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed &Fixed::operator=(Fixed const &src)
{
	std::cout << "Assignment constructor called\n";
	m_Number = src.getRawBits();
	return (*this);
}


int Fixed::getRawBits() const
{
	std::cout << "getRawBits called\n";
	return m_Number;	
}

void Fixed::setRawBits(int number)
{
	m_Number = number;
}
