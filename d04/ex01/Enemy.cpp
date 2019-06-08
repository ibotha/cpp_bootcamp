/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 16/44/47 by ibotha          #+#    #+#             */
/*   Updated: 2019/06/08 16/44/47 by ibotha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy() {}

Enemy::Enemy(Enemy const & src) {
	*this = src;	
}

Enemy::~Enemy() {}

Enemy & Enemy::operator=(Enemy const & src) {
	if (this != &src)
	{
	*this = src;
	}
	return (*this);
}

Enemy::Enemy(int hp, std::string const & type)
	:m_Type(type), m_HP(hp)
{

}


std::string const &Enemy::getType() const
{
	return m_Type;
}

int Enemy::getHP() const
{
	return m_HP;
}


void Enemy::takeDamage(int amount)
{
	if (amount > 0)
	{
		m_HP -= amount;
	}
}

