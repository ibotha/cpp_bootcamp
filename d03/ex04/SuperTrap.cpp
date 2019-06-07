/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 10:23:38 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/07 13:20:16 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"
#include <iostream>

const SuperTrap::challenge SuperTrap::s_Challenges[] = {
	{
		"be better"
	},
	{
		"live for you not society"
	},
	{
		"ask yourself the real questions"
	},
	{
		"go buy cigarettes"
	}
};

SuperTrap::SuperTrap(std::string const & name)
	:ClapTrap(name), FragTrap(name), NinjaTrap(name)
{
	FragTrap f(name);
	m_HitPoints = f.getHitPoints();
	m_MaxHitPoints = f.getMaxHitPoints();
	m_Level = 1;
	m_RangedDamage = f.getRangedDamage();
	m_ArmourDamageReduction = f.getArmourDamageReduction();
	std::cout << "SUP3R-TP " << m_Name << " created !\n";
}

SuperTrap::SuperTrap(SuperTrap const & src)
	:ClapTrap(src), FragTrap(src), NinjaTrap(src)
{
	*this = src;
	std::cout << "SUP3R-TP " << m_Name << " copied !\n";
}

SuperTrap::~SuperTrap()
{
	std::cout << "SUP3R-TP " << m_Name << " destroyed !\n";
}

SuperTrap & SuperTrap::operator=(SuperTrap const & src) {
	if (this != &src)
	{
	*this = src;
	}
	return (*this);
	std::cout << "SUP3R-TP " << m_Name << " assigned !\n";
}

void SuperTrap::meleeAttack(std::string const &target)
{
	NinjaTrap::meleeAttack(target);
}

void SuperTrap::rangedAttack(std::string const &target)
{
	FragTrap::rangedAttack(target);
}

void SuperTrap::takeDamage(unsigned int amount)
{
	if (amount < m_ArmourDamageReduction)
		amount = m_ArmourDamageReduction;
	amount -= m_ArmourDamageReduction;
	if (amount > m_HitPoints)
		amount = m_HitPoints;
	std::cout << "SUP3R-TP " << m_Name << " was attacked causing " << amount << " points of damage !\n";
	m_HitPoints -= amount;
}

void SuperTrap::beRepaired(unsigned int amount)
{
	if ((amount + m_HitPoints) > 100)
		amount = 100 - m_HitPoints;
	std::cout << "SUP3R-TP " << m_Name << " was repaired for " << amount << " points !\n";
	m_HitPoints += amount;
}