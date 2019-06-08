/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 17:02:06 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/08 17:10:22 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		RADSCORPION_HPP
# define	RADSCORPION_HPP

#include "Enemy.hpp"

class RadScorpion : public Enemy {
	public:
		RadScorpion();
		RadScorpion(RadScorpion const & src);
		~RadScorpion();
		RadScorpion & operator=(RadScorpion const & src);
	private:

	protected:

};

#endif
