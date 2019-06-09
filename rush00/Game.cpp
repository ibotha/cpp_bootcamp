/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 12:20:28 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/09 16:35:17 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"
#include "Enemy.hpp"
#include <sstream>
#include <chrono>
#include <ctime>
#include <unistd.h>

Game *Game::s_Instance = new Game();

Game::Game()
{
	m_Running = true;
	m_Paused = false;
	m_Window = initscr();
	curs_set(0);
	noecho();
	keypad(m_Window, true);
	start_color();
	init_pair(0, COLOR_RED, COLOR_BLACK);
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	init_pair(2, COLOR_BLACK, COLOR_WHITE);
}

Game::~Game()
{
	delete m_Player;
	endwin();
}

Game &Game::operator=(Game const &src)
{
	if (this != &src)
	{
		*this = src;
	}
	return (*this);
}

void Game::run()
{
	std::chrono::system_clock::time_point t1 = std::chrono::system_clock::now();
	std::chrono::system_clock::time_point t2 = std::chrono::system_clock::now();
	m_Player = new Player();
	long mspf = 1000 / 30;
	while (m_Running)
	{
		t1 = std::chrono::system_clock::now();
		getInput();
		Update();
		render();
		t2 = std::chrono::system_clock::now();
		long elapsed_microseconds = std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count();
		usleep((1000 * mspf)  - elapsed_microseconds);
	}
}

void Game::getInput()
{
	int c;
	bzero((void *)m_Keyboard, sizeof(m_Keyboard));

	timeout(0);
	while ((c = wgetch(m_Window)) != -1)
	{
		m_Keyboard[c] = true;
	}
	timeout(-1);
	flushinp();
}

void Game::Update()
{
	if (m_Keyboard[(int)'p'])
		m_Paused = !m_Paused;
	// here you will loop through all the objects and update them
	if (!m_Paused)
	{
		m_Player->Update(m_Keyboard);
		if (m_Keyboard[(int)'e'])
			m_Enemies.Push(new Enemy());
		for (unsigned int i = 0; i < m_Enemies.getSize(); i++)
		{
			if (m_Player->checkIfOverlay(m_Enemies[i]))
			{
				m_Enemies.Remove(i);
			}
		}
		m_Enemies.Update(m_Keyboard);
		if (m_Keyboard[27])
			m_Running = false;
	}
}

void Game::render()
{
	clear();
	// here you will loop through all the objects and render them
	attron(COLOR_PAIR(0));
	m_Enemies.Render();
	attroff(COLOR_PAIR(0));
	attron(COLOR_PAIR(1));
	m_Player->Render();
	attroff(COLOR_PAIR(1));
	std::stringstream ss;
	ss << m_Enemies.getSize();
	mvaddstr(2, 2, ss.str().c_str());
	attron(COLOR_PAIR(2));
	box(m_Window, 0, 0);
	attroff(COLOR_PAIR(2));
	if(m_Paused)
	{
		mvaddstr(getmaxy(m_Window) / 2, getmaxx(m_Window) / 2 - 3, "Paused");
	}
	refresh();
}

WINDOW *Game::getWindow()
{
	return m_Window;
}

Game * Game::getInstance()
{
	return s_Instance;
}
