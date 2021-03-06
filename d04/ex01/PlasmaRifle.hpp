/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 10:22:39 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/08 16:50:27 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		PLASMARIFLE_HPP
# define	PLASMARIFLE_HPP

#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon {
	public:
		PlasmaRifle();
		PlasmaRifle(PlasmaRifle const & src);
		virtual ~PlasmaRifle();
		PlasmaRifle & operator=(PlasmaRifle const & src);
		virtual void attack() const;
	private:
	protected:

};

#endif
