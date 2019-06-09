/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 16:00:36 by cletinic          #+#    #+#             */
/*   Updated: 2019/06/09 13:04:55 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "AEntity.hpp"

class Player : public AEntity 
{
    public:
        Player();
        ~Player(); 


        virtual void Update(bool keyboard[]);
        virtual void Render();
    private:
        virtual AEntity *clone();
        Player &operator=(Player const &rhs);
		Player(Player const &player);
    protected:
};

#endif

