/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 10:23:38 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/07 10:51:44 by ibotha           ###   ########.fr       */
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
	:ClapTrap(name)
{
	m_HitPoints = 100;
	m_MaxHitPoints = 100;
	m_EnergyPoints = 50;
	m_MaxEnergyPoints = 50;
	m_Level = 1;
	m_MeleeDamage = 20;
	m_RangedDamage = 15;
	m_ArmourDamageReduction = 3;
	m_Type = "SC4V-TP";
	std::cout << "SC4V-TP" << m_Name << " created !\n";
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
