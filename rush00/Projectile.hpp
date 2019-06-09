/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 16:00:36 by cletinic          #+#    #+#             */
/*   Updated: 2019/06/09 13:09:31 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include "AEntity.hpp"

class Projectile : public AEntity 
{
    public:
        Projectile(int x, int y, int vx, int vy);
        Projectile(Projectile const &p);
        ~Projectile();

        Projectile &operator=(Projectile const &rhs);

        virtual void Update(bool keyboard[]);
        virtual void Render();
        virtual AEntity *clone();
    private:
		Projectile();
		int m_VX;
		int m_VY;
    protected:
};

#endif

