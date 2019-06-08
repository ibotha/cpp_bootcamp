/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Invader.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 16/26/22 by ibotha          #+#    #+#             */
/*   Updated: 2019/06/07 16/26/22 by ibotha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Invader.hpp"
#include <sstream>

Invader *Invader::s_Instance = NULL;

Invader::Invader()
{
	if (s_Instance)
	{
		*this = *s_Instance;
	}
	else
	{
		m_X = 0;
		m_Y = 0;
		m_Running = true;
		m_Window = initscr();
		noecho();
		keypad(m_Window, true);
		clear();
		refresh();
		s_Instance = this;
	}
}

Invader::~Invader()
{
	if (s_Instance == this) {
		s_Instance = NULL;
		endwin();
	}
}

Invader &Invader::operator=(Invader const & src) {
	if (this != &src)
	{
		*this = src;
	}
	return (*this);
}


void Invader::run()
{
	while (m_Running)
	{
		getInput();
		update();
		render();
	}
}

void Invader::getInput()
{
	int c;
	bzero((void*)m_Keyboard, sizeof(m_Keyboard));

	timeout(0);
	while((c = wgetch(m_Window)) != -1)
	{
		m_Keyboard[c] = true;
	}
	timeout(-1);
	flushinp();
}

void Invader::update()
{
	if (m_Keyboard[KEY_UP])
		m_Y--;
	if (m_Keyboard[KEY_DOWN])
		m_Y++;
	if (m_Keyboard[KEY_LEFT])
		m_X--;
	if (m_Keyboard[KEY_RIGHT])
		m_X++;
	if (m_Keyboard[27])
		m_Running = false;
}

void Invader::render()
{
	clear();
	mvaddch(m_Y, m_X, 'a');
	refresh();
}
