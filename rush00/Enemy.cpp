/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 15:59:59 by cletinic          #+#    #+#             */
/*   Updated: 2019/06/10 14:20:33 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"
#include "Game.hpp"
#include "Projectile.hpp"
#include <random>

Enemy::Enemy()
	:AEntity(getmaxx(Game::getInstance()->getWindow()), (std::rand() % (getmaxy(Game::getInstance()->getWindow()) - 2) + 1), Game::getInstance()->getSprite(1), Game::getInstance()->getSprite(2))
{
}

Enemy::Enemy(int xPos, int yPos, char sprite)
	:AEntity(xPos, yPos, sprite)
{
}

Enemy::Enemy(Enemy const & src)
{
	*this = src;
}

Enemy::~Enemy(void)
{
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
	int change;
	change = rand() % 1000;
	if (change < 5)
	{
		Projectile *newProj = new Projectile(getEntityX(), getEntityY(), -4, 0);
		Game::getInstance()->getEnemyList().Push(newProj);
	}
	if (change < 100)
		change = -1;
	else if (change < 200)
		change = +1;
	else
		change = 0;
	setEntityY(getEntityY() + change);
	if (getEntityY() < 2)
		setEntityY(2);
	if (getEntityY() > (getmaxy(Game::getInstance()->getWindow()) - 5))
		setEntityY(getmaxy(Game::getInstance()->getWindow()) - 5);
	if (getEntityX() < 0)
		setEntityX(getmaxx(Game::getInstance()->getWindow()));
}

AEntity *Enemy::clone()
{
	return new Enemy(*this);
}
