/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 10:22:39 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/08 16:41:20 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		POWERFIST_HPP
# define	POWERFIST_HPP

#include "AWeapon.hpp"

class PowerFist : public AWeapon {
	public:
		PowerFist();
		PowerFist(PowerFist const & src);
		virtual ~PowerFist();
		PowerFist & operator=(PowerFist const & src);
		virtual void attack() const;
	private:
	protected:

};

#endif
