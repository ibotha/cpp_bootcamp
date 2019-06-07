/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 08:23:33 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/07 15:18:45 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::s_Point = 8;

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return a > b ? a : b;
}

const Fixed & Fixed::min(Fixed const &a, Fixed const &b)
{
	return a < b ? a : b;
}

Fixed const & Fixed::max(Fixed const &a, Fixed const &b)
{
	return a > b ? a : b;
}

Fixed::Fixed()
	:m_Number(0)
{
}

Fixed::Fixed(float const &n)
{
	m_Number = roundf(n * (1 << s_Point));
}

Fixed::Fixed(Fixed const &src)
{
	*this = src;
}

Fixed::~Fixed()
{
}

Fixed &Fixed::operator=(Fixed const &src)
{
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

bool Fixed::operator<(Fixed const &f) const
{
	return m_Number < f.m_Number;
}

bool Fixed::operator>(Fixed const &f) const
{
	return m_Number > f.m_Number;
}

bool Fixed::operator>=(Fixed const &f) const
{
	return m_Number >= f.m_Number;
}

bool Fixed::operator<=(Fixed const &f) const
{
	return m_Number <= f.m_Number;
}

bool Fixed::operator==(Fixed const &f) const
{
	return m_Number == f.m_Number;
}

bool Fixed::operator!=(Fixed const &f) const
{
	return m_Number != f.m_Number;
}

Fixed Fixed::operator+(Fixed const &f) const
{
	return Fixed(toFloat() + f.toFloat());
}

Fixed Fixed::operator-(Fixed const &f) const
{
	return Fixed(toFloat() - f.toFloat());
}

Fixed Fixed::operator*(Fixed const &f) const
{
	return Fixed(toFloat() * f.toFloat());
}

Fixed Fixed::operator/(Fixed const &f) const
{
	return Fixed(toFloat() / f.toFloat());
}

Fixed Fixed::operator++()
{
	m_Number++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	const Fixed old = *this;
	m_Number++;
	return old;
}

Fixed Fixed::operator--()
{
	m_Number--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	const Fixed old = *this;
	m_Number--;
	return old;
}