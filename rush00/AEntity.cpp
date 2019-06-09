/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntity.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 10:15:57 by cletinic          #+#    #+#             */
/*   Updated: 2019/06/09 13:08:44 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AEntity.hpp"

AEntity::AEntity()
	:m_X(0), m_Y(0), m_Sprite('*'), m_ToDelete(false)
{
    return;
}

AEntity::AEntity(int xPos, int yPos, char sprite) : m_X(xPos), m_Y(yPos), m_Sprite(sprite), m_ToDelete(false)
{
    return;
}

AEntity::AEntity(AEntity const &src)
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
        this->m_X = rhs.m_X;
        this->m_Y = rhs.m_Y;
        this->m_Sprite = rhs.m_Sprite;
    }

    return *this;
}

// void AEntity::Update(bool keyboard[KEY_MAX])
// {
//     if (keyboard[KEY_UP])
// 		m_Y--;
// 	if (keyboard[KEY_DOWN])
// 		m_Y++;
// 	if (keyboard[KEY_LEFT])
// 		m_X--;
// 	if (keyboard[KEY_RIGHT])
// 		m_X++;
//     return;
// }

// // cannot have multiple renders within each Entity
// // rather render once a movement has been made.
void AEntity::Render() // for now let renderer take in the base class- should be done through inheritance? / friend?
{ 
	mvaddch(this->m_Y, this->m_X, this->m_Sprite);
    return;
}

//if the enemies move within a predictable manner, then the only collision to be concerned with is the player colliding witht the enemy
bool AEntity::checkIfOverlay(AEntity *instance)
{
    if (instance->getEntityX() == this->m_X && instance->getEntityY() == this->m_Y)
    {
        return true;
    }
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

char AEntity::getEntitySprite(void) const
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
void AEntity::setEntitySprite(char sprite)
{
    this->m_Sprite = sprite;
    return;
}

void AEntity::FlagForDelete()
{
	m_ToDelete = true;
}
