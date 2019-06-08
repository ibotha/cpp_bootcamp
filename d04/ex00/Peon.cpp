/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 10:07:31 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/08 10:07:31 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"
#include <iostream>

Peon::Peon() {}

Peon::Peon(std::string name)
	:Victim(name)
{
	std::cout << "Zog zog\n";
}

Peon::Peon(Peon const & src) {
	*this = src;	
}

Peon::~Peon()
{
	std::cout << "Bleuark...\n";
}

void Peon::getPolymorphed() const
{
	std::cout << m_Name << " has been turned into a pink pony!\n";
}

Peon & Peon::operator=(Peon const & src) {
	if (this != &src)
	{
	*this = src;
	}
	return (*this);
}

