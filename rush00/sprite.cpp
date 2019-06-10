/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 16:26:22 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/10 14:40:11 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "Invader.hpp"
#include "Sprite.hpp"
#include "Game.hpp"

Sprite::Sprite(){
	valid = false;
}

std::string open_file(char avetor_type){
	switch(avetor_type){
		case 'X':
			return("avetorA.avt");
		break;
		case '=':
			return("avetorBa.avt");
		break;
		case '+':
			return("avetorBb.avt");
		break;
		case  '-':
			return("avetorCa.avt");
		break;
		case  '_':
			return("avetorCb.avt");
		break;
	}
	return ("what the fuck");
}

Sprite::Sprite(char file_name)
{
	*this = Sprite(open_file(file_name));
}

Sprite::Sprite(std::string filename){
    std::string temp_avetor;
	std::ifstream file(filename);
	if (!file.is_open() || !file.is_open()) exit(0);
	a_width = 0;
	a_height = 0;
	while(std::getline(file, temp_avetor)){
		int width = temp_avetor.length();
		if (a_width < width)a_width = width;
	 	a_height++;
		avetor += temp_avetor;
	}
    m_width = getmaxx(Game::getInstance()->getWindow());
    m_height = getmaxy(Game::getInstance()->getWindow());
    file.close();
}

Sprite::~Sprite(){
}

Sprite::Sprite(Sprite const& src){
    avetor = src.avetor;
	a_height = src.a_height;
	a_width = src.a_width;
	m_height = src.m_height;
    m_width = src.m_width;
	valid = src.valid;
}

void Sprite::operator=(Sprite const& intance){
    avetor = intance.avetor;
	a_height = intance.a_height;
	a_width = intance.a_width;
	m_height = intance.m_height;
    m_width = intance.m_width;
	valid = intance.valid;
}

bool  Sprite::getValid() const{return (valid);}
int Sprite::getWidth() const{return (a_width);}
int Sprite::getHeight() const{return (a_height);}

void Sprite::Draw(int x, int y, WINDOW *win) const{
	char avetor_map[a_height][a_width];
	int avetor_index = 0;
	for(int i = 0; i < a_height; i++)
		for(int j = 0; j < a_width; j++){
			avetor_map[i][j] = avetor[avetor_index++];
		}
	for(int i = 0; i < a_height; i++)
		for (int j = 0; j < -1+a_width; j++)
			if ((i + x) < getmaxy(win) && (j + y) < getmaxx(win) && avetor_map[i][j] != ' '){
				mvwaddch(win, i + x, j + y, avetor_map[i][j]);
			}
}
