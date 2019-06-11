/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CentralBureaucracy.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 16:31:58 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/11 16:49:19 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		CENTRALBUREAUCRACY_HPP
# define	CENTRALBUREAUCRACY_HPP

#include "OfficeBlock.hpp"

class CentralBureaucracy {
	public:
		struct Queue {
			std::string form;
			std::string target;
			struct Queue *next;
		};
		CentralBureaucracy();
		CentralBureaucracy(CentralBureaucracy const & src);
		~CentralBureaucracy();
		CentralBureaucracy & operator=(CentralBureaucracy const & src);

		void queueUp(std::string const &form, std::string const &target);
		void doBureaucracy();
		void beBureaucratic(Queue *q, int level);
		void addBureaucrat(Bureaucrat &b);
		
	private:
		OfficeBlock m_OfficeBlock[20];
		Intern m_I[20];
		int m_Fill;
		Queue *m_Queue;
	protected:

};

#endif
