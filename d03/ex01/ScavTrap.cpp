/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 10:23:01 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/07 10:23:02 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

const ScavTrap::challenge ScavTrap::s_Challenges[] = {
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

ScavTrap::ScavTrap(std::string const & name)
	:m_HitPoints(100),
	m_MaxHitPoints(100),
	m_EnergyPoints(50),
	m_MaxEnergyPoints(50),
	m_Level(1),
	m_MeleeDamage(20),
	m_RangedDamage(15),
	m_ArmourDamageReduction(3),
	m_Name(name)
{
		std::cout << "SC4V-TP " << m_Name << " created !\n";
}

ScavTrap::ScavTrap(ScavTrap const & src) {
	*this = src;
	std::cout << "SC4V-TP " << m_Name << " copied !\n";
}

ScavTrap::~ScavTrap()
{
	std::cout << "SC4V-TP " << m_Name << " destroyed !\n";
}

ScavTrap & ScavTrap::operator=(ScavTrap const & src) {
	if (this != &src)
	{
	*this = src;
	}
	return (*this);
	std::cout << "SC4V-TP " << m_Name << " assigned !\n";
}

void ScavTrap::setHitPoints(unsigned int hp)
{
	m_HitPoints = hp;
}

void ScavTrap::setMaxHitPoints(unsigned int mhp)
{
	m_MaxHitPoints = mhp;
}

void ScavTrap::setEnergyPoints(unsigned int ep)
{
	m_EnergyPoints = ep;
}

void ScavTrap::setMaxEnergyPoints(unsigned int mep)
{
	m_MaxEnergyPoints = mep;
}

void ScavTrap::setLevel(unsigned int level)
{
	m_Level = level;
}

void ScavTrap::setMeleeDamage(unsigned int md)
{
	m_MeleeDamage = md;
}

void ScavTrap::setRangedDamage(unsigned int rd)
{
	m_RangedDamage = rd;
}

void ScavTrap::setArmourDamageReduction(unsigned int adr)
{
	m_ArmourDamageReduction = adr;
}

void ScavTrap::setName(std::string const & name)
{
	m_Name = name;
}


unsigned int ScavTrap::getHitPoints()
{
	return m_HitPoints;
}

unsigned int ScavTrap::getMaxHitPoints()
{
	return m_MaxHitPoints;
}

unsigned int ScavTrap::getEnergyPoints()
{
	return m_EnergyPoints;
}

unsigned int ScavTrap::getMaxEnergyPoints()
{
	return m_MaxEnergyPoints;
}

unsigned int ScavTrap::getLevel()
{
	return m_Level;
}

unsigned int ScavTrap::getMeleeDamage()
{
	return m_MeleeDamage;
}

unsigned int ScavTrap::getRangedDamage()
{
	return m_RangedDamage;
}

unsigned int ScavTrap::getArmourDamageReduction()
{
	return m_ArmourDamageReduction;
}

std::string const & ScavTrap::getName()
{
	return m_Name;
}

void ScavTrap::meleeAttack(std::string const &target)
{
	std::cout << "SC4V-TP " << m_Name << " attacks " << target << " in melee, causing " << m_MeleeDamage << " points of damage !\n";
}

void ScavTrap::rangedAttack(std::string const &target)
{
	std::cout << "SC4V-TP " << m_Name << " attacks " << target << " at range, causing " << m_MeleeDamage << " points of damage !\n";
}

void ScavTrap::takeDamage(unsigned int amount)
{
	if (amount < m_ArmourDamageReduction)
		amount = m_ArmourDamageReduction;
	amount -= m_ArmourDamageReduction;
	if (amount > m_HitPoints)
		amount = m_HitPoints;
	std::cout << "SC4V-TP " << m_Name << " was attacked causing " << amount << " points of damage !\n";
	m_HitPoints -= amount;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if ((amount + m_HitPoints) > 100)
		amount = 100 - m_HitPoints;
	std::cout << "SC4V-TP " << m_Name << " was repaired for " << amount << " points !\n";
	m_HitPoints += amount;
}

void ScavTrap::challengeNewcomer(std::string const &target)
{
	if (25 <= m_EnergyPoints)
	{
		m_EnergyPoints -= 25;
		challenge choose;
		int i = std::rand() % 4;
		choose.name = s_Challenges[i].name;
		std::cout << "SC4V-TP " << m_Name << " challenges " << target << " to " << choose.name << " !\n";
	}
	else
	{
		std::cout << "SC4V-TP " << m_Name << " does not have enough energy !\n";
	}
}
