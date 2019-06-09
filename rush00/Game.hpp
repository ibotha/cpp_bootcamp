/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 16:26:22 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/09 16:29:16 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
#define GAME_HPP

#include <ncurses.h>
#include "EntityList.hpp"
#include "Player.hpp"

class Game
{
public:
	~Game();

	void run();

	void getInput();
	WINDOW *getWindow();
	static Game *getInstance();
	void Update();
	void render();

private:
	static Game *s_Instance;
	Game &operator=(Game const &src);
	Game(Game const &src);
	WINDOW *m_Window;
	Game();

	bool m_Running;
	bool m_Paused;
	bool m_Keyboard[KEY_MAX];

	EntityList m_Enemies;

	Player *m_Player;

	int m_X, m_Y;

protected:
};

#endif
