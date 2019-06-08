/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 17:02:06 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/08 17:07:00 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		SUPERMUTANT_HPP
# define	SUPERMUTANT_HPP

#include "Enemy.hpp"

class SuperMutant : public Enemy {
	public:
		SuperMutant();
		SuperMutant(SuperMutant const & src);
		~SuperMutant();
		SuperMutant & operator=(SuperMutant const & src);

		virtual void takeDamage(int amount);
	private:

	protected:

};

#endif
