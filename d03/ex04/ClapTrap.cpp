/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 10:22:30 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/07 14:15:35 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string const & name)
	:m_Name(name)
{
	std::cout << "CL4P-TP" << m_Name << " constructed !\n";
}

ClapTrap::ClapTrap(ClapTrap const & src) {
	*this = src;
	std::cout << "CL4P-TP" << m_Name << " copied !\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << "CL4P-TP" << m_Name << " destroyed !\n";
}

ClapTrap & ClapTrap::operator=(ClapTrap const & src) {
	if (this != &src)
	{
	*this = src;
	}
	return (*this);
	std::cout << "CL4P-TP" << m_Name << " assigned !\n";
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


unsigned int ClapTrap::getHitPoints() const
{
	return m_HitPoints;
}

unsigned int ClapTrap::getMaxHitPoints() const
{
	return m_MaxHitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const
{
	return m_EnergyPoints;
}

unsigned int ClapTrap::getMaxEnergyPoints() const
{
	return m_MaxEnergyPoints;
}

unsigned int ClapTrap::getLevel() const
{
	return m_Level;
}

unsigned int ClapTrap::getMeleeDamage() const
{
	return m_MeleeDamage;
}

unsigned int ClapTrap::getRangedDamage() const
{
	return m_RangedDamage;
}

unsigned int ClapTrap::getArmourDamageReduction() const
{
	return m_ArmourDamageReduction;
}

std::string const & ClapTrap::getName() const
{
	return m_Name;
}

void ClapTrap::meleeAttack(std::string const &target)
{
	std::cout << "CL4P-TP" << m_Name << " attacks " << target << " in melee, causing " << m_MeleeDamage << " points of damage !\n";
}

void ClapTrap::rangedAttack(std::string const &target)
{
	std::cout << "CL4P-TP" << m_Name << " attacks " << target << " at range, causing " << m_MeleeDamage << " points of damage !\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount < m_ArmourDamageReduction)
		amount = m_ArmourDamageReduction;
	amount -= m_ArmourDamageReduction;
	if (amount > m_HitPoints)
		amount = m_HitPoints;
	std::cout << "CL4P-TP" << m_Name << " was attacked causing " << amount << " points of damage !\n";
	m_HitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if ((amount + m_HitPoints) > 100)
		amount = 100 - m_HitPoints;
	std::cout << "CL4P-TP" << m_Name << " was repaired for " << amount << " points !\n";
	m_HitPoints += amount;
}