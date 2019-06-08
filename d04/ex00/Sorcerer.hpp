/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 10:07:49 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/08 10:07:49 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		SORCERER_HPP
# define	SORCERER_HPP

# include "Victim.hpp"
# include <string>

class Sorcerer {
	public:
		Sorcerer(std::string name, std::string title);
		Sorcerer(Sorcerer const & src);
		~Sorcerer();
		Sorcerer & operator=(Sorcerer const & src);

		std::string const &getName() const;
		std::string const &getTitle() const;

		void polymorph(Victim const &v);
	private:
		Sorcerer();
		std::string m_Name;
		std::string m_Title;

	protected:

};

std::ostream &operator<<(std::ostream &out, Sorcerer const &s);

#endif
