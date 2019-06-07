/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Invader.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 16/26/22 by ibotha          #+#    #+#             */
/*   Updated: 2019/06/07 16/26/22 by ibotha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		INVADER_HPP
# define	INVADER_HPP

# include <ncurses.h>


class Invader {
	public:
		Invader();
		~Invader();

		void run();

		void getInput();
		void update();
		void render();

	private:
		static Invader *s_Instance;
		Invader & operator=(Invader const & src);
		Invader(Invader const & src);
		WINDOW *m_Window;

		bool m_Running;
		bool m_Keyboard[KEY_MAX];

		int m_X, m_Y;
	protected:

};

#endif
