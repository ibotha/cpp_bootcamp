/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntity.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 10:15:57 by cletinic          #+#    #+#             */
/*   Updated: 2019/06/10 14:30:20 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AEntity.hpp"
#include "Game.hpp"


AEntity::AEntity()
	:m_X(0), m_Y(0), m_Sprite(Game::getInstance()->getSprite(0)), m_Aux(Game::getInstance()->getSprite(0)), m_ToDelete(false)
{
    return;
}

AEntity::AEntity(int xPos, int yPos, Sprite const &sprite) : m_X(xPos), m_Y(yPos), m_Sprite(sprite), m_Aux(sprite), m_ToDelete(false)
{
	return;
}

AEntity::AEntity(int xPos, int yPos, Sprite const &sprite1, Sprite const &sprite2) : m_X(xPos), m_Y(yPos), m_Sprite(sprite1), m_Aux(sprite2), m_ToDelete(false)
{
    return;
}

AEntity::AEntity(AEntity const &src)
	:m_Sprite(src.m_Sprite), m_Aux(src.m_Aux)
{
    *this = src;

    return;
}

AEntity::~AEntity(void)
{
    return;
}

AEntity &AEntity::operator=(AEntity const &rhs)
{
    if (this != &rhs)
    {
        *this = rhs;
    }

    return *this;
}

// // cannot have multiple renders within each Entity
// // rather render once a movement has been made.
void AEntity::Render() // for now let renderer take in the base class- should be done through inheritance? / friend?
{ 
//	mvaddch(this->m_Y, this->m_X, this->m_Sprite);
    m_Frame++;
    if (m_Frame >= 20)
        m_Frame = 0;
    if (m_Frame < 10)
	    m_Sprite.Draw(this->m_Y, this->m_X, Game::getInstance()->getWindow());
    else if (m_Frame < 20)
	    m_Aux.Draw(this->m_Y, this->m_X, Game::getInstance()->getWindow());
    return;
}

// bool RunThroughOverlay(char *a, char *b)

//if the enemies move within a predictable manner, then the only collision to be concerned with is the player colliding witht the enemy
bool AEntity::checkIfOverlay(AEntity *instance)
{
	int x, y, mx, my;
	x = instance->getEntityX();
	y = instance->getEntityY();
	my = instance->getEntityY() + instance->getEntitySprite().getHeight();
	mx = instance->getEntityX() + instance->getEntitySprite().getWidth();
	int x1, y1, mx1, my1;
	x1 = this->getEntityX();
	y1 = this->getEntityY();
	my1 = this->getEntityY() + this->getEntitySprite().getHeight();
	mx1 = this->getEntityX() + this->getEntitySprite().getWidth();

    if (
		x >= x1 && x < mx1 && y >= y1 && y < my1
	)
        return true;
	if (
		x1 >= x && x1 < mx && y1 >= y && y1 < my
	)
		return true;
    return false;
}

bool AEntity::checkToDelete(void)
{
    // add logic here to detect if off screen
    // return true
    return m_ToDelete;
}

// Accessors
int AEntity::getEntityX(void) const
{
    return this->m_X;
}

int AEntity::getEntityY(void) const
{
    return this->m_Y;
}

Sprite const &AEntity::getEntitySprite(void) const
{
    return this->m_Sprite;
}

void AEntity::setEntityX(int posX)
{
    this->m_X = posX;
    return;
}
void AEntity::setEntityY(int posY)
{
    this->m_Y = posY;
    return;
}

void AEntity::FlagForDelete()
{
	m_ToDelete = true;
}
