/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntity.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 10:16:06 by cletinic          #+#    #+#             */
/*   Updated: 2019/06/09 16:12:55 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AENTITY_HPP
#define AENTITY_HPP

# include <ncurses.h>

// #include "Game.hpp"
// #include "Sprite.hpp"

class AEntity {
	private:
		int m_X;
		int m_Y;
		//Sprite m_Sprite;
		char m_Sprite;
		bool m_ToDelete;
	protected:
		AEntity();
		AEntity(int xPos, int yPos, char sprite);
		AEntity(AEntity const & src);
	public:
        virtual ~AEntity(void);

        AEntity &operator=(AEntity const &rhs);

		virtual void Update(bool keyboard[]) = 0;
		virtual void Render() = 0;
		virtual AEntity *clone() = 0;

        bool checkIfOverlay(AEntity *instance); // for now just check the position otherwise take position and and size
		bool checkToDelete(void);
		void FlagForDelete();

		//accessors
		int getEntityX(void) const;
		int getEntityY(void) const;
		char getEntitySprite(void) const;

		void setEntityX(int posX);
        void setEntityY(int posY);
        void setEntitySprite(char sprite);
};

#endif

