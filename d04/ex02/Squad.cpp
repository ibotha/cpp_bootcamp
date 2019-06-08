/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 20:03:33 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/08 21:01:23 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"
#include <iostream>

Squad::Squad()
	:m_Marines(nullptr), m_Count(0)
{
}

Squad::Squad(Squad const & src) {
	*this = src;	
}

Squad::~Squad()
{
	deleteList(m_Marines);
}

Squad & Squad::operator=(Squad const & src) {
	if (this != &src)
    {
	*this = src;
    }
	return (*this);
}

int Squad::getCount() const
{
	return m_Count;
}

ISpaceMarine* Squad::getUnit(int i) const
{
	if (i < 0)
		return nullptr;
	s_Link *cur = m_Marines;
	for (int j = 0; j < i; j++)
	{
		if (!cur)
			return nullptr;
		cur = cur->next;
	}
	return cur->marine;
}

int Squad::push(ISpaceMarine* s)
{
	if (m_Marines == nullptr)
	{
		m_Marines = new s_Link;
		m_Marines->marine = s;
		m_Marines->next = nullptr;
		m_Count++;
		return m_Count;
	}
	s_Link *cur = m_Marines;
	if (cur->marine == s)
	{
		return m_Count;
	}
	while (cur->next)
	{
		if (cur->marine == s)
		{
			return m_Count;
		}
		cur = cur->next;
	}
	cur->next = new s_Link;
	cur->next->marine = s;
	cur->next->next = nullptr;
	m_Count++;
	return m_Count;
}

void Squad::deleteList(Squad::s_Link *s)
{
	if (s)
	{
		deleteList(s->next);
		delete s->marine;
		delete s;
	}
}
