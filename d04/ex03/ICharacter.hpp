/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 23:38:19 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/09 00:05:30 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		ICHARACTER_HPP
# define	ICHARACTER_HPP

# include <string>
# include "AMateria.hpp"

class ICharacter {
	public:
		ICharacter();
		ICharacter(ICharacter const & src);
		ICharacter & operator=(ICharacter const & src);

		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
	private:

	protected:

};

#endif
