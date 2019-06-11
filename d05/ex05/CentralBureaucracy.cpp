/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CentralBureaucracy.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 16:31:27 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/11 17:02:21 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CentralBureaucracy.hpp"

CentralBureaucracy::CentralBureaucracy()
	:m_Fill(0), m_Queue(nullptr)
{
	for (int i = 0; i < 20; i++)
	{
		m_OfficeBlock[i].setIntern(m_I[i]);
	}
}

CentralBureaucracy::CentralBureaucracy(CentralBureaucracy const & src) {
	*this = src;	
}

CentralBureaucracy::~CentralBureaucracy() {}

CentralBureaucracy & CentralBureaucracy::operator=(CentralBureaucracy const & src) {
	if (this != &src)
	{
	*this = src;
	}
	return (*this);
}

void CentralBureaucracy::queueUp(std::string const &form, std::string const &target)
{
	Queue *n = new Queue;
	n->form = form;
	n->target = target;
	n->next = m_Queue;
	m_Queue = n;
}

void CentralBureaucracy::doBureaucracy()
{
	beBureaucratic(m_Queue, 0);
	m_Queue = nullptr;
}
#include <iostream>

void CentralBureaucracy::beBureaucratic(Queue *q, int level)
{
	if (q)
	{
		beBureaucratic(q->next, level + 1);
		std::cout << q->form << q->target << (level % 20) << std::endl;
		m_OfficeBlock[level % 20].doBureaucracy(q->form, q->target);
		delete q;
	}
}

void CentralBureaucracy::addBureaucrat(Bureaucrat &b)
{
	if (m_Fill >39)
		return;
	if (m_Fill % 2)
		m_OfficeBlock[m_Fill / 2].setExecutor(b);
	else
		m_OfficeBlock[m_Fill / 2].setSigner(b);
	m_Fill++;
}

