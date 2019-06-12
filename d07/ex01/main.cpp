/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 10:07:24 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/12 13:28:15 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template<typename T>
void iter(T *data, size_t length, void (*f)(T &item))
{
	for (size_t i = 0; i < length; i++)
	{
		f(data[i]);
	}
}

void change(char &item)
{
	item++;
}

int main( void ) {
	char a[] = "Hello";
	iter(static_cast<char *>(a), sizeof(a) - 1, &change);
	std::cout << a;
}

