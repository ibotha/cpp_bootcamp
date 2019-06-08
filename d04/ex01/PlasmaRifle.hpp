/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 10:22:39 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/08 10:32:42 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		PlasmaRifle_HPP
# define	PlasmaRifle_HPP

#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon {
	public:
		PlasmaRifle();
		PlasmaRifle(PlasmaRifle const & src);
		virtual ~PlasmaRifle();
		PlasmaRifle & operator=(PlasmaRifle const & src);
		virtual void attack() const override;
	private:
	protected:

};

#endif
