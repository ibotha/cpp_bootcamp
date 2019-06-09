/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 15:59:59 by cletinic          #+#    #+#             */
/*   Updated: 2019/06/09 12:16:37 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy()
{
	addstr("Enemy here");
}

Enemy::Enemy(int xPos, int yPos, char sprite)
	:AEntity(xPos, yPos, sprite)
{
	addstr("Enemy there");
}

Enemy::Enemy(Enemy const & src)
{
	*this = src;
	addstr("Enemy everywhere");
}

Enemy::~Enemy(void)
{
	addstr("Enemy nowhere");
}

Enemy &Enemy::operator=(Enemy const &e)
{
	if (this != &e)
	{
		*this = e;
	}
	return *this;
}


void Enemy::Update(bool keystate[KEY_MAX])
{
	if (keystate[(int)'a'])
	{
		setEntityX(getEntityX() + 1);
	}
}

void Enemy::Render()
{
	mvaddch(this->getEntityX(), this->getEntityY(), this->getEntitySprite());
}

AEntity *Enemy::clone()
{
	return new Enemy(*this);
}
