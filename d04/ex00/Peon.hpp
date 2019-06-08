/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 10:06:56 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/08 10:06:57 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		PEON_HPP
# define	PEON_HPP

#include "Victim.hpp"

class Peon : public Victim {
	public:
		Peon(std::string name);
		Peon(Peon const & src);
		~Peon();

		void getPolymorphed() const;
		Peon & operator=(Peon const & src);
	private:
		Peon();

	protected:

};

#endif
