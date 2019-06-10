/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 16:26:22 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/10 14:47:08 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
#define GAME_HPP

#include <ncurses.h>
#include <sstream>
#include <iostream>
#include <string>
#include <sstream>
#include <chrono>
#include <ctime>
#include <unistd.h>

#include "EntityList.hpp"
#include "Player.hpp"

#define ENEMY_INDEX 3
#define BORDER_INDEX 1
#define PLAYER_INDEX 2
#define PROJECTILE_INDEX 4
#define ENEMY_COLOR COLOR_PAIR(ENEMY_INDEX)
#define BORDER_COLOR COLOR_PAIR(BORDER_INDEX)
#define PLAYER_COLOR COLOR_PAIR(PLAYER_INDEX)
#define PROJECTILE_COLOR COLOR_PAIR(PROJECTILE_INDEX)
#define ENEMYSTART attron(ENEMY_COLOR)
#define ENEMYEND attroff(ENEMY_COLOR)
#define BORDERSTART attron(BORDER_COLOR)
#define BORDEREND attroff(BORDER_COLOR)
#define PLAYERSTART attron(PLAYER_COLOR)
#define PLAYEREND attroff(PLAYER_COLOR)
#define PROJECTILESTART attron(PROJECTILE_COLOR)
#define PROJECTILEEND attroff(PROJECTILE_COLOR)

class Game
{
	public:
		~Game();

		void run();
		void CheckProjectiles();

		EntityList &getProjectileList();
		EntityList &getEnemyList();

		void getInput();
		WINDOW *getWindow();
		static Game *getInstance();
		static void Restart();
		void Update();
		void Render();

		void SetRunning();
		void UpdateRunning();
		void RenderRunning();

		void SetMenu();
		void UpdateMenu();
		void RenderMenu();

		void SetPost();
		void UpdatePost();
		void RenderPost();

		Sprite const &getSprite(int i);

	private:
		Game();
		Game(Game const &src);
		Sprite m_Sprites[8];
		
		Game &operator=(Game const &src);
		
		static Game *s_Instance;

		WINDOW *m_Window;	

		enum State {
			MENU,
			RUNNING,
			POST
		};

		int m_Selection;
		State m_State;

		bool m_Running;
		int m_Frame;
		int m_Health;
		bool m_Paused;
		bool m_Keyboard[KEY_MAX];
		
		Player *m_Player;
		EntityList m_Enemies;
		EntityList m_Projectiles;

		size_t m_Score;

	protected:
};

#endif
