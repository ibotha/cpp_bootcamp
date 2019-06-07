/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 10:22:52 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/07 10:22:53 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

const FragTrap::ability FragTrap::s_VaultHunterAbilities[] = {
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

FragTrap::FragTrap(std::string const & name)
	:m_HitPoints(100),
	m_MaxHitPoints(100),
	m_EnergyPoints(100),
	m_MaxEnergyPoints(100),
	m_Level(1),
	m_MeleeDamage(30),
	m_RangedDamage(20),
	m_ArmourDamageReduction(5),
	m_Name(name)
{
		std::cout << "FR4G-TP " << m_Name << " created !\n";
}

FragTrap::FragTrap(FragTrap const & src) {
	*this = src;
	std::cout << "FR4G-TP " << m_Name << " copied !\n";
}

FragTrap::~FragTrap()
{
	std::cout << "FR4G-TP " << m_Name << " destroyed !\n";
}

FragTrap & FragTrap::operator=(FragTrap const & src) {
	if (this != &src)
	{
	*this = src;
	}
	return (*this);
	std::cout << "FR4G-TP " << m_Name << " assigned !\n";
}

void FragTrap::setHitPoints(unsigned int hp)
{
	m_HitPoints = hp;
}

void FragTrap::setMaxHitPoints(unsigned int mhp)
{
	m_MaxHitPoints = mhp;
}

void FragTrap::setEnergyPoints(unsigned int ep)
{
	m_EnergyPoints = ep;
}

void FragTrap::setMaxEnergyPoints(unsigned int mep)
{
	m_MaxEnergyPoints = mep;
}

void FragTrap::setLevel(unsigned int level)
{
	m_Level = level;
}

void FragTrap::setMeleeDamage(unsigned int md)
{
	m_MeleeDamage = md;
}

void FragTrap::setRangedDamage(unsigned int rd)
{
	m_RangedDamage = rd;
}

void FragTrap::setArmourDamageReduction(unsigned int adr)
{
	m_ArmourDamageReduction = adr;
}

void FragTrap::setName(std::string const & name)
{
	m_Name = name;
}


unsigned int FragTrap::getHitPoints()
{
	return m_HitPoints;
}

unsigned int FragTrap::getMaxHitPoints()
{
	return m_MaxHitPoints;
}

unsigned int FragTrap::getEnergyPoints()
{
	return m_EnergyPoints;
}

unsigned int FragTrap::getMaxEnergyPoints()
{
	return m_MaxEnergyPoints;
}

unsigned int FragTrap::getLevel()
{
	return m_Level;
}

unsigned int FragTrap::getMeleeDamage()
{
	return m_MeleeDamage;
}

unsigned int FragTrap::getRangedDamage()
{
	return m_RangedDamage;
}

unsigned int FragTrap::getArmourDamageReduction()
{
	return m_ArmourDamageReduction;
}

std::string const & FragTrap::getName()
{
	return m_Name;
}

void FragTrap::meleeAttack(std::string const &target)
{
	std::cout << "FR4G-TP " << m_Name << " attacks " << target << " in melee, causing " << m_MeleeDamage << " points of damage !\n";
}

void FragTrap::rangedAttack(std::string const &target)
{
	std::cout << "FR4G-TP " << m_Name << " attacks " << target << " at range, causing " << m_MeleeDamage << " points of damage !\n";
}

void FragTrap::takeDamage(unsigned int amount)
{
	if (amount < m_ArmourDamageReduction)
		amount = m_ArmourDamageReduction;
	amount -= m_ArmourDamageReduction;
	if (amount > m_HitPoints)
		amount = m_HitPoints;
	std::cout << "FR4G-TP " << m_Name << " was attacked causing " << amount << " points of damage !\n";
	m_HitPoints -= amount;
}

void FragTrap::beRepaired(unsigned int amount)
{
	if ((amount + m_HitPoints) > 100)
		amount = 100 - m_HitPoints;
	std::cout << "FR4G-TP " << m_Name << " was repaired for " << amount << " points !\n";
	m_HitPoints += amount;
}

void FragTrap::vaulthunter_dot_exe(std::string const &target)
{
	if (25 <= m_EnergyPoints)
	{
		m_EnergyPoints -= 25;
		ability choose;
		int i = std::rand() % 4;
		choose.damage = s_VaultHunterAbilities[i].damage;
		choose.name = s_VaultHunterAbilities[i].name;
		std::cout << "FR4G-TP " << m_Name << " attacks " << target << " by " << choose.name << ", causing " << choose.damage << " points of damage !\n";
	}
	else
	{
		std::cout << "FR4G-TP " << m_Name << " does not have enough energy !\n";
	}
}
