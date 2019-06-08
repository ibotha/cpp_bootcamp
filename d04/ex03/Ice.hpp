/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 23:40:07 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/08 23:58:16 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		ICE_HPP
# define	ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(Ice const & src);
		~Ice();
		Ice & operator=(Ice const & src);
		virtual void use(ICharacter& target);
	private:

	protected:

};

#endif
