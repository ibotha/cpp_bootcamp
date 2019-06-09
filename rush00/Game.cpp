/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 12:20:28 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/09 12:58:39 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"
#include "Enemy.hpp"
#include <string>

Game *Game::s_Instance = new Game();

Game::Game()
{
	m_Running = true;
	m_Window = initscr();
	curs_set(0);
	noecho();
	keypad(m_Window, true);
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
	m_Player = new Player();
	while (m_Running)
	{
		getInput();
		Update();
		render();
		system("usleep 500");
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
	// here you will loop through all the objects and update them
	m_Player->Update(m_Keyboard);
	//m_Enemies.Update(m_Keyboard);
	if (m_Keyboard[27])
		m_Running = false;
}

void Game::render()
{
	clear();
	// here you will loop through all the objects and render them
	//m_Enemies.Render();
	m_Player->Render();
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
