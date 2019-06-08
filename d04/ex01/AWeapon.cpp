/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aweapon.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 10/05/32 by ibotha          #+#    #+#             */
/*   Updated: 2019/06/08 10/05/32 by ibotha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Aweapon.hpp"

AWeapon::AWeapon() {}

AWeapon::AWeapon(AWeapon const & src) {
	*this = src;	
}

AWeapon::~AWeapon() {}

AWeapon & AWeapon::operator=(AWeapon const & src) {
	if (this != &src)
	{
	*this = src;
	}
	return (*this);
}

std::string const &AWeapon::getName() const
{
	return m_Name;
}

int AWeapon::getAPCost() const
{
	return m_APCost;
}

int AWeapon::getDamage() const
{
	return m_Damage;
}

AWeapon::AWeapon(std::string const & name, int apcost, int damage)
	:m_Name(name), m_APCost(apcost), m_Damage(damage)
{
	
}
