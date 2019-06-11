/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 22:59:53 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/09 08:33:48 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {}

AMateria::AMateria(std::string const &type)
	: m_Type(type), m_XP(0)
{
}

AMateria::AMateria(AMateria const &src)
{
	*this = src;
}

AMateria::~AMateria() {}

AMateria &AMateria::operator=(AMateria const &src)
{
	if (this != &src)
	{
		*this = src;
	}
	return (*this);
}

std::string const &AMateria::getType() const
{
	return m_Type;
}

unsigned int AMateria::getXP() const
{
	return m_XP;
}

void AMateria::use(ICharacter &target)
{
	m_XP += 10;
}
