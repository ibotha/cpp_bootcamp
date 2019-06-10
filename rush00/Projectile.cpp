/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 16:00:24 by cletinic          #+#    #+#             */
/*   Updated: 2019/06/10 13:12:31 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Projectile.hpp"
#include "Game.hpp"
#include <iostream>

Projectile::Projectile()
	:AEntity(2, getmaxy(Game::getInstance()->getWindow()) / 2, Game::getInstance()->getSprite(2))
{
    return;
}

Projectile::Projectile(int x, int y, int vx, int vy) : AEntity(x, y, Game::getInstance()->getSprite(3),Game::getInstance()->getSprite(4)), m_VX(vx), m_VY(vy)
{
    // this->setEntityX = x;
    // this->setEntityY = y;
    // this->setEntitySprite = '-';
    

    // this->m_VX = vx;
    // this->m_VY = vy;
    return;
}

Projectile::Projectile(Projectile const &p)
{
	*this = p;
}

Projectile::~Projectile()
{
    return;
}

Projectile &Projectile::operator=(Projectile const &rhs)
{
    if (this != &rhs)
    {
        *this = rhs;
    }
    return *this;
}

void Projectile::Update(bool keyboard[KEY_MAX])
{
    (void) keyboard;

	setEntityX(getEntityX() + m_VX);
	setEntityY(getEntityY() + m_VY);

	int x = getEntityX();
	if (x < 0 || x > getmaxx(Game::getInstance()->getWindow()))
		FlagForDelete();
	int y = getEntityY();
	if (y < 0 || y > getmaxy(Game::getInstance()->getWindow()))
		FlagForDelete();
    return;
}

AEntity *Projectile::clone()
{
	return new Projectile(*this);
}