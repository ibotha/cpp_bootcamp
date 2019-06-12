/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 10:07:24 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/12 12:21:37 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <random>
#include <ctime>
#define ITERMAX 10000

struct Data {
	std::string s1;
	int n;
	std::string s2;
};

void * serialize()
{
	char * ret;
	ret = new char[8 + 8 + 4];
	for (int i = 0; i < 8; i++)
	{
		ret[i] = (std::rand() % 26) + 'A';
		ret[i + 12] = (std::rand() % 26) + 'A';
	}
	*reinterpret_cast<int *>(reinterpret_cast<char *>(ret) + 8) = std::rand();
	return reinterpret_cast<void *>(ret);
}

Data * deserialize(void * data)
{
	Data * d;
	d = new Data;
	d->n = *reinterpret_cast<int *>(reinterpret_cast<char *>(data) + 8);
	for (int i = 0; i < 8; i++)
	{
		d->s1 += *reinterpret_cast<char *>(reinterpret_cast<char *>(data) + i);
		d->s2 += *reinterpret_cast<char *>(reinterpret_cast<char *>(data) + i + 12);
	}
	return d;
}

int main()
{
	std::srand(std::time(0));
	void * raw = serialize();
	Data * data = deserialize(raw);
	std::cout << data->s1 << ", " << data->n << ", " << data->s2 << std::endl;
	delete reinterpret_cast<char *>(raw);
	delete data;
}


