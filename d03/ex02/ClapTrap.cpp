/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 10:22:30 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/07 10:52:23 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string const & name)
	:m_HitPoints(100),
	m_MaxHitPoints(100),
	m_EnergyPoints(100),
	m_MaxEnergyPoints(100),
	m_Level(1),
	m_MeleeDamage(30),
	m_RangedDamage(20),
	m_ArmourDamageReduction(5)
{
	m_Name = name;
	m_Type = "CL4P-TP";
}

ClapTrap::ClapTrap(ClapTrap const & src) {
	*this = src;
	std::cout << m_Type << m_Name << " copied !\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << m_Type << m_Name << " destroyed !\n";
}

ClapTrap & ClapTrap::operator=(ClapTrap const & src) {
	if (this != &src)
	{
	*this = src;
	}
	return (*this);
	std::cout << m_Type << m_Name << " assigned !\n";
}

void ClapTrap::setHitPoints(unsigned int hp)
{
	m_HitPoints = hp;
}

void ClapTrap::setMaxHitPoints(unsigned int mhp)
{
	m_MaxHitPoints = mhp;
}

void ClapTrap::setEnergyPoints(unsigned int ep)
{
	m_EnergyPoints = ep;
}

void ClapTrap::setMaxEnergyPoints(unsigned int mep)
{
	m_MaxEnergyPoints = mep;
}

void ClapTrap::setLevel(unsigned int level)
{
	m_Level = level;
}

void ClapTrap::setMeleeDamage(unsigned int md)
{
	m_MeleeDamage = md;
}

void ClapTrap::setRangedDamage(unsigned int rd)
{
	m_RangedDamage = rd;
}

void ClapTrap::setArmourDamageReduction(unsigned int adr)
{
	m_ArmourDamageReduction = adr;
}

void ClapTrap::setName(std::string const & name)
{
	m_Name = name;
}


unsigned int ClapTrap::getHitPoints()
{
	return m_HitPoints;
}

unsigned int ClapTrap::getMaxHitPoints()
{
	return m_MaxHitPoints;
}

unsigned int ClapTrap::getEnergyPoints()
{
	return m_EnergyPoints;
}

unsigned int ClapTrap::getMaxEnergyPoints()
{
	return m_MaxEnergyPoints;
}

unsigned int ClapTrap::getLevel()
{
	return m_Level;
}

unsigned int ClapTrap::getMeleeDamage()
{
	return m_MeleeDamage;
}

unsigned int ClapTrap::getRangedDamage()
{
	return m_RangedDamage;
}

unsigned int ClapTrap::getArmourDamageReduction()
{
	return m_ArmourDamageReduction;
}

std::string const & ClapTrap::getName()
{
	return m_Name;
}

void ClapTrap::meleeAttack(std::string const &target)
{
	std::cout << m_Type << m_Name << " attacks " << target << " in melee, causing " << m_MeleeDamage << " points of damage !\n";
}

void ClapTrap::rangedAttack(std::string const &target)
{
	std::cout << m_Type << m_Name << " attacks " << target << " at range, causing " << m_MeleeDamage << " points of damage !\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount < m_ArmourDamageReduction)
		amount = m_ArmourDamageReduction;
	amount -= m_ArmourDamageReduction;
	if (amount > m_HitPoints)
		amount = m_HitPoints;
	std::cout << m_Type << m_Name << " was attacked causing " << amount << " points of damage !\n";
	m_HitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if ((amount + m_HitPoints) > 100)
		amount = 100 - m_HitPoints;
	std::cout << m_Type << m_Name << " was repaired for " << amount << " points !\n";
	m_HitPoints += amount;
}
