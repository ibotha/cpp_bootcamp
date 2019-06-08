/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 23:39:51 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/09 00:03:26 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>

Ice::Ice()
	:AMateria("ice")
{

}

Ice::Ice(Ice const & src)
	:AMateria(src)
{	
}

Ice::~Ice() {}

Ice & Ice::operator=(Ice const & src) {
	if (this != &src)
    {
		m_XP = src.m_XP;
    }
	return (*this);
}

void Ice::use(ICharacter& target)
{
	AMateria::use(target);
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
