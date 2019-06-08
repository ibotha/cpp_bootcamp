/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 10:07:04 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/08 10:07:07 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"
#include <iostream>

Victim::Victim() {}

Victim::Victim(std::string name)
	:m_Name(name)
{
	std::cout << "Some random victim called " << m_Name << " just popped!\n";
}

Victim::Victim(Victim const & src) {
	*this = src;
}

Victim::~Victim()
{
	std::cout << "Victim " << m_Name << " just died for no apparent reason!\n";
}

std::string const &Victim::getName() const
{
	return m_Name;
}

Victim & Victim::operator=(Victim const & src) {
	if (this != &src)
	{
	*this = src;
	}
	return (*this);
}

void Victim::getPolymorphed() const
{
	std::cout << m_Name << " has been turned into a cute little sheep !\n";
}

std::ostream &operator<<(std::ostream &out, Victim const &v)
{
	out << "I am " << v.getName() << " and I like otters!\n";
	return out;
}
