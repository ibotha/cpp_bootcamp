/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 23:40:07 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/09 00:01:32 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		ICE_HPP
# define	ICE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(Cure const & src);
		~Cure();
		Cure & operator=(Cure const & src);
		virtual void use(ICharacter& target);
	private:

	protected:

};

#endif
