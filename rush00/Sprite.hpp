/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sprite.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 12:20:05 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/09 12:20:12 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_HPP
# define SPRITE_HPP


/*
 *  ___
 * {000}
 *  \_/
 */

class Sprite {
	private:
		std::ifstream m_File;
		int m_Height;
		int width;
		bool valid;
	public:
		Sprite(std::string filename);
		~Sprite();
		Sprite(Sprite const &src);
		
		// Needed
		void Draw(int x, int y, WINDOW *win);
		bool isValid();
}		

#endif
