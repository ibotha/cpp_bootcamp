/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 15:59:59 by cletinic          #+#    #+#             */
/*   Updated: 2019/06/09 16:07:54 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"
#include "Game.hpp"
#include <random>

Enemy::Enemy()
	:AEntity(getmaxx(Game::getInstance()->getWindow()), (std::rand() % (getmaxy(Game::getInstance()->getWindow()) - 2) + 1), '=')
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
	(void)keystate;
	setEntityX(getEntityX() - 1);
	if (getEntityX() < 0)
		setEntityX(getmaxx(Game::getInstance()->getWindow()));
}

void Enemy::Render()
{
	mvaddch(this->getEntityY(), this->getEntityX(), this->getEntitySprite());
}

AEntity *Enemy::clone()
{
	return new Enemy(*this);
}
