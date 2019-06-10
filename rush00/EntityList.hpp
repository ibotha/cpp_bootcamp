/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EntityList.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 09:42:17 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/10 13:27:26 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITYLIST_HPP
#define ENTITYLIST_HPP

#include "AEntity.hpp"

class EntityList {
	public:
		EntityList();
		EntityList(EntityList const &src);
		~EntityList();
		EntityList &operator=(EntityList const &src);

		void Push(AEntity *e);
		AEntity *Pop();
		void Remove(AEntity *e);
		void Remove(unsigned int i);
		void Update(bool keystate[KEY_MAX]);
		void Render();
		void Clean();
		void Clear();
		AEntity *operator[](unsigned int i);
		unsigned int getSize();

	private:
		typedef struct Link {
			struct Link *prev;
			AEntity *e;
			struct Link *next;
		} s_Link;

		void DeleteLink(s_Link *&);
		s_Link *m_Data;
		unsigned int m_Size;
};

#endif