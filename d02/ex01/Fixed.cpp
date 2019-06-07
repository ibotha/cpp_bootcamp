/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 08:23:33 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/07 15:02:39 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::s_Point = 8;

Fixed::Fixed()
	:m_Number(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(float const &n)
{
	std::cout << "Float constructor called\n";
	m_Number = roundf(n * (1 << s_Point));
}

Fixed::Fixed(int const &n)
{
	std::cout << "Int constructor called\n";
	m_Number = n * (1 << s_Point);
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
	return m_Number;	
}

void Fixed::setRawBits(int number)
{
	m_Number = number;
}

int Fixed::toInt() const
{
	return m_Number / (1 << s_Point);
}

float Fixed::toFloat() const
{
	float res = (float)m_Number;
	res /= (1 << s_Point);
	return res;
}

std::ostream &operator<<(std::ostream &o, Fixed const &f)
{
	o << f.toFloat();
	return o;
}