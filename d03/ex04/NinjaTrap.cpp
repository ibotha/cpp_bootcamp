/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 13:52:50 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/07 14:43:46 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"
#include <iostream>

const NinjaTrap::ability NinjaTrap::s_VaultHunterAbilities[] = {
	{
		"going gunzerk",
		50
	},
	{
		"belching",
		1
	},
	{
		"staring dissaprovingly",
		500
	},
	{
		"going to buy cigarettes",
		0
	}
};

NinjaTrap::NinjaTrap(std::string const & name)
	:ClapTrap(name)
{
	m_HitPoints = 60;
	m_MaxHitPoints = 60;
	m_EnergyPoints = 120;
	m_MaxEnergyPoints = 120;
	m_Level = 1;
	m_MeleeDamage = 60;
	m_RangedDamage = 5;
	m_ArmourDamageReduction = 0;
	std::cout << "N1NJ4-TP " << m_Name << " created !\n";
}

NinjaTrap::NinjaTrap(NinjaTrap const & src)
	:ClapTrap(src)
{
	*this = src;
	std::cout << "N1NJ4-TP " << m_Name << " copied !\n";
}

NinjaTrap::~NinjaTrap()
{
	std::cout << "N1NJ4-TP " << m_Name << " destroyed !\n";
}

NinjaTrap & NinjaTrap::operator=(NinjaTrap const & src) {
	if (this != &src)
	{
	*this = src;
	}
	return (*this);
	std::cout << "N1NJ4-TP " << m_Name << " assigned !\n";
}

void NinjaTrap::meleeAttack(std::string const &target)
{
	std::cout << "N1NJ4-TP " << m_Name << " attacks " << target << " in melee, causing " << m_MeleeDamage << " points of damage !\n";
}

void NinjaTrap::rangedAttack(std::string const &target)
{
	std::cout << "N1NJ4-TP " << m_Name << " attacks " << target << " at range, causing " << m_MeleeDamage << " points of damage !\n";
}

void NinjaTrap::takeDamage(unsigned int amount)
{
	if (amount < m_ArmourDamageReduction)
		amount = m_ArmourDamageReduction;
	amount -= m_ArmourDamageReduction;
	if (amount > m_HitPoints)
		amount = m_HitPoints;
	std::cout << "N1NJ4-TP " << m_Name << " was attacked causing " << amount << " points of damage !\n";
	m_HitPoints -= amount;
}

void NinjaTrap::beRepaired(unsigned int amount)
{
	if ((amount + m_HitPoints) > 100)
		amount = 100 - m_HitPoints;
	std::cout << "N1NJ4-TP " << m_Name << " was repaired for " << amount << " points !\n";
	m_HitPoints += amount;
}

void NinjaTrap::ninjaShoebox(FragTrap &target)
{
	if (25 <= m_EnergyPoints)
	{
		m_EnergyPoints -= 25;
		std::cout << "N1NJ4-TP " << m_Name << " wibblwobbles FR4G-TP " << target.getName() << " for 20 points of damage !\n";
		target.takeDamage(20);
	}
	else
	{
		std::cout << "N1NJ4-TP " << m_Name << " does not have enough energy !\n";
	}
}

void NinjaTrap::ninjaShoebox(ScavTrap &target)
{
	if (25 <= m_EnergyPoints)
	{
		m_EnergyPoints -= 25;
		std::cout << "N1NJ4-TP " << m_Name << " gobblewibbles SC4V-TP " << target.getName() << " for 40 points of damage !\n";
		target.takeDamage(40);
	}
	else
	{
		std::cout << "N1NJ4-TP " << m_Name << " does not have enough energy !\n";
	}
}

void NinjaTrap::ninjaShoebox(NinjaTrap &target)
{
	if (25 <= m_EnergyPoints)
	{
		m_EnergyPoints -= 25;
		std::cout << "N1NJ4-TP " << m_Name << " fibblewibbles N1NJ4-TP " << target.getName() << " for 80 points of damage !\n";
		target.takeDamage(80);
	}
	else
	{
		std::cout << "N1NJ4-TP " << m_Name << " does not have enough energy !\n";
	}
}