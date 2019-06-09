/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 16:00:24 by cletinic          #+#    #+#             */
/*   Updated: 2019/06/09 15:55:22 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"
#include "Game.hpp"
#include <iostream>

Player::Player()
	:AEntity(2, getmaxy(Game::getInstance()->getWindow()) / 2, 'X')
{
    return;
}

Player::Player(Player const &player)
	:AEntity(player)
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
        setEntityX(rhs.getEntityX());
        setEntityY(rhs.getEntityY());
        setEntitySprite(rhs.getEntitySprite());
    }
    return *this;
}

void Player::Update(bool keyboard[KEY_MAX])
{
    if (keyboard[KEY_UP] && getEntityY() > 1)
        setEntityY(getEntityY() - 1);
    if (keyboard[KEY_DOWN] && getEntityY() < (getmaxy(Game::getInstance()->getWindow()) - 2))
        setEntityY(getEntityY() + 1);
    return;
}

void Player::Render()
{
    mvaddch(this->getEntityY(), this->getEntityX(), this->getEntitySprite());
    return;
}

AEntity *Player::clone()
{
	return new Player(*this);
}