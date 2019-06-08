/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 16:49:44 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/08 16:55:16 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		ENEMY_HPP
# define	ENEMY_HPP

# include <string>

class Enemy {
	public:
		Enemy(Enemy const & src);
		Enemy & operator=(Enemy const & src);

		Enemy(int hp, std::string const & type);
		virtual ~Enemy();
		std::string const &getType() const;
		int getHP() const;

		virtual void takeDamage(int amount);
	private:
		std::string m_Type;
		int m_HP;
		Enemy();

	protected:

};

#endif
