/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 13:30:06 by ibotha            #+#    #+#             */
/*   Updated: 2019/06/12 13:56:30 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <memory>

template<typename T>
class Array
{
public:
	Array()
		:m_Data(nullptr), m_Size(0)
	{
	}

	Array(unsigned int size)
		:m_Data(new T[size]), m_Size(size)
	{
		for (unsigned int i = 0; i < m_Size; i++)
		{
			m_Data[i] = 0;
		}
	}

	~Array()
	{
		if (m_Data)
			delete[] m_Data;
	}

	Array(Array const & a)
	{
		m_Data = new T[a.m_Size];
		m_Size = a.m_Size;
		for (unsigned int i = 0; i < m_Size; i++)
		{
			m_Data[i] = a.m_Data[i];
		}
	}

	Array &operator=(Array const & a)
	{
		if (m_Data)
			delete[] m_Data;
		m_Data = new T[a.m_Size];
		m_Size = a.m_Size;
		for (int i = 0; i < m_Size; i++)
		{
			m_Data[i] = a.m_Data[i];
		}
	}

	T &operator[](int i)
	{
		if (i < 0 || static_cast<unsigned int>(i) >= m_Size)
			throw std::exception();
		return m_Data[i];
	}

	unsigned int size() const
	{
		return m_Size;
	}

private:

	T *m_Data;
	unsigned int m_Size;
	
protected:

};