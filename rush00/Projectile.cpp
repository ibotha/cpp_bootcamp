/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 16:00:24 by cletinic          #+#    #+#             */
/*   Updated: 2019/06/09 13:10:54 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Projectile.hpp"
#include "Game.hpp"
#include <iostream>

Projectile::Projectile()
	:AEntity(2, getmaxy(Game::getInstance()->getWindow()) / 2, 'X')
{
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
        setEntityX(rhs.getEntityX());
        setEntityY(rhs.getEntityY());
        setEntitySprite(rhs.getEntitySprite());
    }
    return *this;
}

void Projectile::Update(bool keyboard[KEY_MAX])
{
	setEntityY(getEntityY() + m_VX);
	setEntityY(getEntityY() + m_VY);
	int x = getEntityX();
	if (x < 0 || x > getmaxx(Game::getInstance()->getWindow()))
		FlagForDelete();
	int y = getEntityY();
	if (y < 0 || y > getmaxy(Game::getInstance()->getWindow()))
		FlagForDelete();
    return;
}

void Projectile::Render()
{
    mvaddch(this->getEntityY(), this->getEntityX(), this->getEntitySprite());
    return;
}

AEntity *Projectile::clone()
{
	return new Projectile(*this);
}