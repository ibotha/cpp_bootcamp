/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 16:00:09 by cletinic          #+#    #+#             */
/*   Updated: 2019/06/09 12:21:22 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "AEntity.hpp"
#include "ncurses.h"

class Enemy : public AEntity 
{
    public:
        Enemy();
        Enemy(int xPos, int yPos, char sprite);
        Enemy(Enemy const & src);
        ~Enemy(void);
		Enemy &operator=(Enemy const &e);

		virtual void Update(bool keystate[KEY_MAX]);
		virtual void Render();
		virtual AEntity *clone();
    private:

        //         bool checkIfOverlay(Entity &e); // for now just check the position otherwise take position and and size
    private:
    protected:
};

#endif
