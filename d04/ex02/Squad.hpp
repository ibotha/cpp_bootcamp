/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 20:03:28 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/08 20:23:22 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		SQUAD_HPP
# define	SQUAD_HPP

#include "ISquad.hpp"

class Squad : public ISquad {
	public:
		Squad();
		Squad(Squad const & src);
		~Squad();
		Squad & operator=(Squad const & src);

		virtual int getCount() const;
		virtual ISpaceMarine* getUnit(int) const;
		virtual int push(ISpaceMarine*);
	private:
		typedef struct Link
		{
			ISpaceMarine *marine;
			struct Link *next;
		} s_Link;

		s_Link *m_Marines;
		unsigned int m_Count;

		void deleteList(s_Link *s);
		
	protected:

};

#endif
