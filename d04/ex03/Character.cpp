/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 00:04:34 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/09 08:26:21 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() {}

Character::Character(std::string name)
	:m_Name(name), m_Materia({nullptr,nullptr,nullptr,nullptr})
{}

Character::Character(Character const & src)
{
	m_Name = src.m_Name;
	for (int i = 0; i < 4; i++)
	{
		m_Materia[i] = src.m_Materia[i]->clone();
	}
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (m_Materia[i])
			delete m_Materia[i];
	}
}

Character & Character::operator=(Character const & src) {
	if (this != &src)
    {
		m_Name = src.m_Name;
		for (int i = 0; i < 4; i++)
		{
			if (m_Materia[i])
				delete m_Materia[i];
			m_Materia[i] = src.m_Materia[i]->clone();
		}
    }
	return (*this);
}

std::string const & Character::getName() const
{
	return m_Name;
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!m_Materia[i])
		{
			m_Materia[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 4 && idx >= 0)
	{
		m_Materia[idx] = nullptr;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 4 && idx >= 0 && m_Materia[idx])
	{
		m_Materia[idx]->use(target);
	}
}
