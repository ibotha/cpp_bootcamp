/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 12:20:28 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/10 14:48:28 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"
#include "Enemy.hpp"
#include "Projectile.hpp"

Game *Game::s_Instance = new Game();

Game::Game()
{
	m_Running = true;
	m_Paused = false;
	m_State = MENU;
	m_Selection = 0;
	m_Window = initscr();
	curs_set(0);
	noecho();
	keypad(m_Window, true);
	start_color();
	init_pair(ENEMY_INDEX, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(PLAYER_INDEX, COLOR_CYAN, COLOR_BLACK);
	init_pair(BORDER_INDEX, COLOR_BLACK, COLOR_WHITE);
	init_pair(PROJECTILE_INDEX, COLOR_YELLOW, COLOR_BLACK);
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

Sprite const &Game::getSprite(int i)
{
	return m_Sprites[i];
}

void Game::run()
{
	std::chrono::system_clock::time_point t1 = std::chrono::system_clock::now();
	std::chrono::system_clock::time_point t2 = std::chrono::system_clock::now();
	m_Player = new Player();
	m_Sprites[0] = Sprite("avetorA.avt");
	m_Sprites[1] = Sprite("avetorBa.avt");
	m_Sprites[2] = Sprite("avetorBb.avt");
	m_Sprites[3] = Sprite("avetorC.avt");
	m_Sprites[4] = Sprite("avetorCa.avt");
	// FrameRate       \/
	long mspf = 1000 / 30;
	while (m_Running)
	{
		clear();
		t1 = std::chrono::system_clock::now();
		getInput();
		Update();
		Render();
		t2 = std::chrono::system_clock::now();
		long elapsed_microseconds = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
		usleep((1000 * mspf) - elapsed_microseconds);
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
	if (m_Keyboard[(int)'q'])
	{
		SetMenu();
		return;
	}
	switch (m_State)
	{
	case MENU:
		UpdateMenu();
		break;
	case RUNNING:
		UpdateRunning();
		break;
	case POST:
		UpdatePost();
		break;
	default:
		break;
	}
}

void Game::Render()
{
	clear();
	switch (m_State)
	{
	case MENU:
		RenderMenu();
		break;
	case RUNNING:
		RenderRunning();
		break;
	case POST:
		RenderPost();
		break;
	default:
		break;
	}
	// here you will loop through all the objects and render them
	
	BORDERSTART;
	box(m_Window, 0, 0);
	BORDEREND;
	refresh();
}

void Game::SetMenu()
{
	m_State = MENU;
	m_Selection = 0;
}

void Game::UpdateMenu()
{
	if (m_Keyboard[KEY_UP] && m_Selection > 0)
		m_Selection--;
	if (m_Keyboard[KEY_DOWN] && m_Selection < 1)
		m_Selection++;
	if (m_Keyboard[(int)' '])
	{
		if (m_Selection == 0)
			SetRunning();
		else if (m_Selection == 1)
			m_Running = false;
	}
}

void Game::RenderMenu()
{
	mvaddstr(getmaxy(m_Window) / 3, getmaxx(m_Window) / 2 - 4, m_Selection == 0 ? "*Play Game" : "Play Game");
	mvaddstr((getmaxy(m_Window) / 3) * 2, getmaxx(m_Window) / 2 - 2, m_Selection == 1 ? "*Exit" : "Exit");
}

void Game::SetRunning()
{
	m_State = RUNNING;
	m_Selection = 0;
	m_Frame = 0;
	m_Score = 0;
	m_Health = 100;
	m_Enemies.Clear();
	m_Projectiles.Clear();
}

void Game::UpdateRunning()
{
	if (m_Keyboard[(int)'p'])
		m_Paused = !m_Paused;
	// here you will loop through all the objects and update them
	if (!m_Paused)
	{
		m_Frame++;
		if (m_Frame >= 10)
			m_Frame = 0;
		m_Score++;
		if ((rand() % 1000) < 50)
			m_Enemies.Push(new Enemy());
		for (unsigned int i = 0; i < m_Enemies.getSize(); i++)
		{
			if (m_Player->checkIfOverlay(m_Enemies[i]))
			{
				m_Health -= 5;
				m_Enemies[i]->FlagForDelete();
				if (m_Health < 0)
					SetPost();
			}
		}
		m_Enemies.Clean();
		CheckProjectiles();
		m_Enemies.Update(m_Keyboard);
		CheckProjectiles();
		m_Projectiles.Update(m_Keyboard);
		int check = m_Enemies.getSize();
		m_Enemies.Clean();
		int check2 = m_Enemies.getSize();
		m_Score += 200 * (check - check2);
		m_Projectiles.Clean();
		m_Player->Update(m_Keyboard);
	}
}

void Game::RenderRunning()
{
	std::stringstream ss;
	int mx = getmaxx(m_Window);
	int my = getmaxy(m_Window);
	for (int i = 0; i < my; i += 5)
	{
		for (int j = 0; j < mx; j += 10)
		{
			mvaddstr(i, j - m_Frame, "=====     ");
		}
	}
	
	PROJECTILESTART;
	m_Projectiles.Render();
	PROJECTILEEND;

	ENEMYSTART;
	m_Enemies.Render();
	ENEMYEND;
	
	PLAYERSTART;
	m_Player->Render();
	PLAYEREND;

	ss << "Score: " << m_Score << " | Health: " << m_Health;
	mvaddstr(2, 2, ss.str().c_str());
	mvaddnstr(3, 2, "==========", m_Health / 10);
	if(m_Paused)
	attron(COLOR_PAIR(2));
	box(m_Window, 0, 0);
	attroff(COLOR_PAIR(2));
	if (m_Paused)
	{
		mvaddstr(getmaxy(m_Window) / 2, getmaxx(m_Window) / 2 - 3, "Paused");
	}

}

void Game::SetPost()
{
	m_State = POST;
}

void Game::UpdatePost()
{
	if (m_Keyboard[(int)'b'])
		SetMenu();
}

void Game::RenderPost()
{
	std::stringstream ss;
	ss << m_Score;
	mvaddstr(getmaxy(m_Window) / 2, getmaxx(m_Window) / 2 - 3, "Game over");
	mvaddstr(getmaxy(m_Window) / 2 + 2, getmaxx(m_Window) / 2 - 3, ss.str().c_str());
}

void Game::CheckProjectiles()
{
	for (unsigned int i = 0; i < m_Projectiles.getSize(); i++)
	{
		for (unsigned int j = 0; j < m_Enemies.getSize(); j++)
		{
			if (m_Enemies[j]->checkIfOverlay(m_Projectiles[i]))
			{
				m_Enemies[j]->FlagForDelete();
				m_Projectiles[i]->FlagForDelete();
			}
		}
	}
}

WINDOW *Game::getWindow()
{
	return m_Window;
}

Game *Game::getInstance()
{
	return s_Instance;
}

EntityList &Game::getProjectileList()
{
	return this->m_Projectiles;
}

EntityList &Game::getEnemyList()
{
	return this->m_Enemies;
}