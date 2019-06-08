/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 10:07:42 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/08 10:07:43 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		VICTIM_HPP
# define	VICTIM_HPP

#include <string>

class Victim {
	public:
		Victim(Victim const & src);
		~Victim();
		Victim & operator=(Victim const & src);
		Victim (std::string name);

		void getPolymorphed() const;
		std::string const &getName() const;
	private:
	protected:
		Victim();
		std::string m_Name;

};

std::ostream &operator<<(std::ostream &out, Victim const &v);

#endif
