/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 17/18/32 by ibotha          #+#    #+#             */
/*   Updated: 2019/06/08 17/18/32 by ibotha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character() {}

Character::Character(Character const & src) {
	*this = src;	
}

Character::~Character() {}

Character & Character::operator=(Character const & src) {
	if (this != &src)
	{
	*this = src;
	}
	return (*this);
}

Character::Character(std::string const &name)
	:m_Name(name), m_AP(40), m_Weapon(nullptr)
{

}

void Character::recoverAP()
{
	m_AP += 10;
	if (m_AP > 40)
		m_AP = 40;
}

void Character::equip(AWeapon* w)
{
	m_Weapon = w;
}

void Character::attack(Enemy* e)
{
	if (!m_Weapon || m_AP < m_Weapon->getAPCost())
		return;
	
	std::cout << m_Name << " attacks " << e->getType() << " with a " << m_Weapon->getName() << std::endl;
	m_Weapon->attack();
	m_AP -= m_Weapon->getAPCost();
	e->takeDamage(m_Weapon->getDamage());
	if (e->getHP() < 0)
		delete e;
}

std::string const &Character::getName() const
{
	return m_Name;
}

int Character::getAP() const
{
	return m_AP;
}
const AWeapon *Character::getWeapon() const
{
	return m_Weapon;
}

std::ostream &operator<<(std::ostream &out, Character const &c)
{
	out << c.getName() << " has " << c.getAP() << " AP and ";
	if (c.getWeapon())
		out << "wields a " << c.getWeapon()->getName();
	else
		out << "is unarmed";
	return out;
}

