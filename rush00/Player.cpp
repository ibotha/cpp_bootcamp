/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 16:00:24 by cletinic          #+#    #+#             */
/*   Updated: 2019/06/10 14:42:53 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"
#include "Projectile.hpp"
#include "Game.hpp"
#include <iostream>

Player::Player() : AEntity(2, getmaxy(Game::getInstance()->getWindow()) / 2, Game::getInstance()->getSprite(0))
{
	m_Cooldown = 5;
    return;
}

Player::Player(Player const &player) : AEntity(player)
{
    return;
}

Player::~Player()
{
    return;
}

Player &Player::operator=(Player const &rhs)
{
    if (this != &rhs)
    {
        *this = rhs;
    }
    return *this;
}

void Player::Update(bool keyboard[KEY_MAX])
{
	m_Cooldown--;
	if (m_Cooldown < 5)
		m_Cooldown = 5;
    if (keyboard[KEY_UP] && getEntityY() > 1)
        setEntityY(getEntityY() - 1);
    if (keyboard[KEY_DOWN] && getEntityY() < (getmaxy(Game::getInstance()->getWindow()) - 3))
        setEntityY(getEntityY() + 1);
    if (keyboard[(int)' '])
    {
		if (m_Cooldown < 10)
		{
			Projectile *newProj = new Projectile(getEntityX() + getEntitySprite().getWidth(), getEntityY(), 4, 0);
			Game::getInstance()->getProjectileList().Push(newProj);
			m_Cooldown = 20;
		}
        
    }
    return;
}

AEntity *Player::clone()
{
	return new Player(*this);
}