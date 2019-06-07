/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 10:22:41 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/07 10:49:06 by ibotha           ###   ########.fr       */
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
	:ClapTrap(name)
{
	m_HitPoints = 100;
	m_MaxHitPoints = 100;
	m_EnergyPoints = 100;
	m_MaxEnergyPoints = 100;
	m_Level = 1;
	m_MeleeDamage = 30;
	m_RangedDamage = 20;
	m_ArmourDamageReduction = 5;
	m_Type = "FR4G-TP";
	std::cout << m_Type << m_Name << " created !\n";
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
		std::cout << m_Type << m_Name << " attacks " << target << " by " << choose.name << ", causing " << choose.damage << " points of damage !\n";
	}
	else
	{
		std::cout << m_Type << m_Name << " does not have enough energy !\n";
	}
}
