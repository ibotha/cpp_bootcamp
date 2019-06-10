/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntity.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 10:16:06 by cletinic          #+#    #+#             */
/*   Updated: 2019/06/10 13:10:24 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AENTITY_HPP
#define AENTITY_HPP

# include <ncurses.h>

//#include "Game.hpp"
#include "Sprite.hpp"

class AEntity {
	private:
		int m_X;
		int m_Y;
		Sprite const &m_Sprite;
		Sprite const &m_Aux;
		bool m_ToDelete;
		int m_Frame;
	protected:
		AEntity();
		AEntity(int xPos, int yPos, Sprite const &sprite);
		AEntity(int xPos, int yPos, Sprite const &sprite, Sprite const &sprite2);
		AEntity(AEntity const & src);
	public:
        virtual ~AEntity(void);

        AEntity &operator=(AEntity const &rhs);

		virtual void Update(bool keyboard[]) = 0;
		void Render();
		virtual AEntity *clone() = 0;

        bool checkIfOverlay(AEntity *instance); // for now just check the position otherwise take position and and size
		bool checkToDelete(void);
		void FlagForDelete();

		//accessors
		int getEntityX(void) const;
		int getEntityY(void) const;
		Sprite const & getEntitySprite(void) const;

		void setEntityX(int posX);
        void setEntityY(int posY);
};

#endif

