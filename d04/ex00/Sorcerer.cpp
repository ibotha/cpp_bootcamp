/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 10:07:15 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/08 10:07:16 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"
#include <iostream>

Sorcerer::Sorcerer() {}

Sorcerer::Sorcerer(std::string name, std::string title)
	:m_Name(name), m_Title(title)
{
	std::cout << m_Name << ", " << m_Title << " is born!\n";
}

Sorcerer::Sorcerer(Sorcerer const & src) {
	*this = src;	
}

Sorcerer::~Sorcerer()
{
	std::cout << m_Name << ", " << m_Title << " is dead. Consequences will never be the same!\n";
}

Sorcerer & Sorcerer::operator=(Sorcerer const & src) {
	if (this != &src)
	{
	*this = src;
	}
	return (*this);
}

std::string const &Sorcerer::getName() const
{
	return m_Name;
}

std::string const &Sorcerer::getTitle() const
{
	return m_Title;
}

std::ostream &operator<<(std::ostream &out, Sorcerer const &s)
{
	out << "I am " << s.getName() << ", " << s.getTitle() << ", and I like ponies!\n";
	return out;
}

void Sorcerer::polymorph(Victim const &v)
{
	v.getPolymorphed();
}
