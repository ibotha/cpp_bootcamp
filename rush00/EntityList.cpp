/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EntityList.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 09:42:17 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/09 12:27:08 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EntityList.hpp"
#include <string>

EntityList::EntityList()
	:m_Data(nullptr), m_Size(0)
{

}

EntityList::EntityList(EntityList const &src)
{
	s_Link *cur = src.m_Data;
	while(cur)
	{
		Push(cur->e->clone());
		cur = cur->next;
	}
}

EntityList::~EntityList()
{
	DeleteLink(m_Data);
}

EntityList &EntityList::operator=(EntityList const &src)
{
	if (this != &src)
	{
		DeleteLink(m_Data);

		s_Link *cur = src.m_Data;
		while(cur)
		{
			Push(cur->e->clone());
			cur = cur->next;
		}
	}
	return *this;
}


void EntityList::Push(AEntity *e)
{
	// If list is empty then create list
	if (m_Data == nullptr)
	{
		m_Data = new s_Link;
		m_Data->e = e;
		m_Data->next = nullptr;
		m_Data->prev = nullptr;
		m_Size++;
		return;
	}

	// Otherwise Loop until the end checking for duplicates
	s_Link *cur = m_Data;
	if (cur->e == e)
		return;
	while(cur->next)
	{
		if (cur->e == e)
			return;
		cur = cur->next;
	}
	// Add the entity to the end if no duplicates wee found
	cur->next = new s_Link;
	cur->next->e = e;
	cur->next->next = nullptr;
	cur->next->prev = cur;
	m_Size++;
}

AEntity *EntityList::Pop()
{
	if (!m_Data)
		return nullptr;
	s_Link *cur = m_Data;
	while (cur->next)
	{
		cur = cur->next;
	}
	if (cur->prev)
	{
		cur->prev->next = cur->next;
	}
	else
	{
		m_Data = cur->next;
	}
	if (cur->next)
		cur->next->prev = cur->prev;
	AEntity * ret = cur->e;
	delete cur;
	m_Size--;
	return ret;
}

void EntityList::Remove(AEntity *e)
{
	if (!m_Data)
		return;
	s_Link *cur = m_Data;
	while (cur->next && cur->e != e)
	{
		cur = cur->next;
	}
	if (cur->prev)
	{
		cur->prev->next = cur->next;
	}
	else
	{
		m_Data = cur->next;
	}
	if (cur->next)
		cur->next->prev = cur->prev;
	delete cur->e;
	delete cur;
	m_Size--;
}

void EntityList::Remove(unsigned int i)
{
	s_Link *cur = m_Data;
	AEntity * e = (*this)[i];
	if (!cur || !e)
		return;
	Remove(e);
}

AEntity *EntityList::operator[](unsigned int i)
{
	if (i < 0 || i >= m_Size)
		return nullptr;
	s_Link *cur = m_Data;
	while (i--) {
		cur = cur->next;
	}
	return (cur->e);
}

unsigned int EntityList::getSize()
{
	return m_Size;
}


void EntityList::DeleteLink(EntityList::s_Link *& a)
{
	if (!a)
		return;
	DeleteLink(a->next);
	delete a->e;
	a = nullptr;
}

void EntityList::Update(bool keystate[KEY_MAX])
{
	s_Link *cur = m_Data;
	while(cur)
	{
		cur->e->Update(keystate);
		cur = cur->next;
	}
}

void EntityList::Render()
{
	s_Link *cur = m_Data;
	while(cur)
	{
		cur->e->Render();
		cur = cur->next;
	}
}

