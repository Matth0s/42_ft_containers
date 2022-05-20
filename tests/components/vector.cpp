/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:42:22 by mmoreira          #+#    #+#             */
/*   Updated: 2022/05/20 03:22:05 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// # define STD 1
#ifdef STD
	#include <vector>
	#include <iostream>
	namespace ft = std;
#else
	#include "vector.hpp"
#endif

void	test_vector( void )
{
	int	array[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

	{
		ft::vector<int> vec;
		std::cout << "Default Constructor   |✅" << std::endl;
	}

	{
		ft::vector<int> vec(10, 10);
		std::cout << "Fill Constructor      |✅" << std::endl;
	}

	{
		ft::vector<int> vec(array, array + 10);
		std::cout << "Range Constructor     |✅" << std::endl;
	}

	{
		ft::vector<int> vec1(array, array + 10);
		ft::vector<int> vec2(vec1);
		std::cout << "Copy Constructor      |✅" << std::endl;
	}

	{
		ft::vector<int> vec1(array, array + 10);
		ft::vector<int>	vec2;
		vec1 = vec2;
		std::cout << "Assignment Operator   |✅" << std::endl;
	}

	std::cout << std::endl;

	{
		ft::vector<int> vec(array, array + 10);
		std::allocator<int> alloc = vec.get_allocator();
		int* ar = alloc.allocate(5);
		for (int i = 0; i < 5; i++)
			alloc.construct(ar + i, i);
		for (int i = 0; i < 5; i++)
			alloc.destroy(ar + i);
		alloc.deallocate(ar, 5);
		std::cout << "get_allocator()       |✅"  << std::endl;
	}

	std::cout << std::endl;

	{
		int	ar[] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
		int cont;
		ft::vector<int> vec1(array, array + 10);
		ft::vector<int> vec2(array + 5, array + 10);
		ft::vector<int> vec3(10, 2);

		std::cout << "begin() & end()           |";
		{
			ft::vector<int>::iterator it;
			ft::vector<int>::iterator i;

			i = vec1.begin();
			cont = 0;
			for (it = vec1.begin(); it < vec1.end(); it++)
				cont += (*it == array[it - i]? 1: 0);
			std::cout << (cont == 10 ?"✅":"❌");

			i = vec2.begin();
			cont = 0;
			for (it = vec2.begin(); it < vec2.end(); it++)
				cont += (*it == array[it - i + 5]? 1: 0);
			std::cout << (cont == 5 ?"✅":"❌");

			i = vec3.begin();
			cont = 0;
			for (it = vec3.begin(); it < vec3.end(); it++)
				cont += (*it == ar[it - i]? 1: 0);
			std::cout << (cont == 10 ?"✅":"❌") << std::endl;
		}

		std::cout << "rbegin() & rend()         |";
		{
			ft::vector<int>::reverse_iterator it;
			ft::vector<int>::reverse_iterator i;

			i = vec1.rbegin();
			cont = 0;
			for (it = vec1.rbegin(); it != vec1.rend(); it++)
				cont += (*it == array[10 - (it - i + 1)]? 1: 0);
			std::cout << (cont == 10 ?"✅":"❌");

			i = vec2.rbegin();
			cont = 0;
			for (it = vec2.rbegin(); it != vec2.rend(); it++)
				cont += (*it == array[10 - (it - i + 1)]? 1: 0);
			std::cout << (cont == 5 ?"✅":"❌");

			i = vec3.rbegin();
			cont = 0;
			for (it = vec3.rbegin(); it != vec3.rend(); it++)
				cont += (*it == ar[it - i]? 1: 0);
			std::cout << (cont == 10 ?"✅":"❌")<< std::endl;
		}

		{
			std::cout << "const [begin() & end()]   |";
			{
				ft::vector<int>::const_iterator it;
				ft::vector<int>::const_iterator i;

				i = vec1.begin();
				cont = 0;
				for (it = vec1.begin(); it < vec1.end(); it++)
					cont += (*it == array[it - i]? 1: 0);
				std::cout << (cont == 10 ?"✅":"❌");

				i = vec2.begin();
				cont = 0;
				for (it = vec2.begin(); it < vec2.end(); it++)
					cont += (*it == array[it - i + 5]? 1: 0);
				std::cout << (cont == 5 ?"✅":"❌");

				i = vec3.begin();
				cont = 0;
				for (it = vec3.begin(); it < vec3.end(); it++)
					cont += (*it == ar[it - i]? 1: 0);
				std::cout << (cont == 10 ?"✅":"❌") << std::endl;
			}

			std::cout << "const [rbegin() & rend()] |";
			{
				ft::vector<int>::reverse_iterator it;
				ft::vector<int>::reverse_iterator i;

				i = vec1.rbegin();
				cont = 0;
				for (it = vec1.rbegin(); it < vec1.rend(); it++)
					cont += (*it == array[10 - (it - i + 1)]? 1: 0);
				std::cout << (cont == 10 ?"✅":"❌");

				i = vec2.rbegin();
				cont = 0;
				for (it = vec2.rbegin(); it < vec2.rend(); it++)
					cont += (*it == array[10 - (it - i + 1)]? 1: 0);
				std::cout << (cont == 5 ?"✅":"❌");

				i = vec3.rbegin();
				cont = 0;
				for (it = vec3.rbegin(); it < vec3.rend(); it++)
					cont += (*it == ar[it - i]? 1: 0);
				std::cout << (cont == 10 ?"✅":"❌")<< std::endl;
			}
		}
	}

	std::cout << std::endl;

	ft::vector<int> vec1(array, array + 10);
	ft::vector<int> vec2(array, array + 15);
	ft::vector<int> vec3(array + 5, array + 10);

	std::cout << "size()             |";
	std::cout << (vec1.size() == 10 ?"✅":"❌");
	std::cout << (vec2.size() == 15 ?"✅":"❌");
	std::cout << (vec3.size() == 5 ?"✅":"❌") << std::endl;

	std::cout << "capacity()         |";
	std::cout << (vec1.capacity() == 10 ?"✅":"❌");
	std::cout << (vec2.capacity() == 15 ?"✅":"❌");
	std::cout << (vec3.capacity() == 5 ?"✅":"❌") << std::endl;

	std::cout << "resize()           |";
	{
		int	ar[] = {1, 2, 3, 4, 5, 6};
		int cont = 0;
		vec1.resize(6);
		cont += (vec1.size() == 6? 1: 0);
		for (std::size_t i = 0; i < vec1.size(); i++)
			cont += (vec1[i] == ar[i]? 1: 0);
		cont += (vec1.capacity() == 10? 1: 0);
		std::cout << (cont == (2 + 6) ?"✅":"❌");
	}
	{
		int	ar[] = {1, 2, 3, 4, 5, 6, 0};
		int cont = 0;
		vec1.resize(7);
		cont += (vec1.size() == 7? 1: 0);
		for (std::size_t i = 0; i < vec1.size(); i++)
			cont += (vec1[i] == ar[i]? 1: 0);
		cont += (vec1.capacity() == 10? 1: 0);
		std::cout << (cont == (2 + 7) ?"✅":"❌");
	}
	{
		int	ar[] = {1, 2, 3, 4, 5, 6, 0, 2, 2, 2, 2, 2, 2, 2, 2};
		int cont = 0;
		vec1.resize(15,2);
		cont += (vec1.size() == 15? 1: 0);
		for (std::size_t i = 0; i < vec1.size(); i++)
			cont += (vec1[i] == ar[i]? 1: 0);
		cont += (vec1.capacity() == 15? 1: 0);
		std::cout << (cont == (2 + 15) ?"✅":"❌") << std::endl;
	}

	std::cout << "empty()            |";
	{
		ft::vector<int> vec3(array, array + 10);
		ft::vector<int> vec4;

		std::cout << (vec3.empty() ?"❌":"✅");
		vec3.resize(0);
		std::cout << (vec3.empty() ?"✅":"❌");
		std::cout << (vec4.empty() ?"✅":"❌") << std::endl;
	}

	std::cout << "reserve()          |";
	{
		vec1.reserve(10);
		std::cout << (vec1.capacity() == 15 ?"✅":"❌");
		vec1.reserve(20);
		std::cout << (vec1.capacity() == 20 ?"✅":"❌");
		vec1.reserve(25);
		std::cout << (vec1.capacity() == 25 ?"✅":"❌") << std::endl;
	}

	std::cout << std::endl;

	std::cout << "operator []        |";
	{
		int	value1 = vec1[0];
		std::cout << (value1 == 1 ?"✅":"❌");
		int	value2 = vec1[4];
		std::cout << (value2 == 5 ?"✅":"❌");
		int	value3 = vec1[8];
		std::cout << (value3 == 2 ?"✅":"❌") << std::endl;
	}

	std::cout << "const operator []  |";
	{
		const int	value1 = vec1[0];
		std::cout << (value1 == 1 ?"✅":"❌");
		const int	value2 = vec1[4];
		std::cout << (value2 == 5 ?"✅":"❌");
		const int	value3 = vec1[8];
		std::cout << (value3 == 2 ?"✅":"❌") << std::endl;
	}

	std::cout << "at()               |";
	{
		int	value1 = vec1.at(0);
		std::cout << (value1 == 1 ?"✅":"❌");
		int	value2 = vec1.at(4);
		std::cout << (value2 == 5 ?"✅":"❌");
		try {
			int	value3 = vec1.at(20);
			(void) value3;
			std::cout << "❌" << std::endl;
		} catch (std::exception& ex) {
			std::cout << "✅" << std::endl;
			// std::cout << ex.what() << std::endl;
		}
	}

	std::cout << "const at()         |";
	{
		const int	value1 = vec1.at(0);
		std::cout << (value1 == 1 ?"✅":"❌");
		const int	value2 = vec1.at(4);
		std::cout << (value2 == 5 ?"✅":"❌");
		try {
			const int	value3 = vec1.at(-20);
			(void) value3;
			std::cout << "❌" << std::endl;
		} catch (std::exception& ex) {
			std::cout << "✅" << std::endl;
			// std::cout << ex.what() << std::endl;
		}
	}

	std::cout << "front()            |";
	{
		int	value1 = vec1.front();
		std::cout << (value1 == 1 ?"✅":"❌");
		int	value2 = vec2.front();
		std::cout << (value2 == 1 ?"✅":"❌");
		int	value3 = vec3.front();
		std::cout << (value3 == 6 ?"✅":"❌") << std::endl;
	}

	std::cout << "const front()      |";
	{
		const int	value1 = vec1.front();
		std::cout << (value1 == 1 ?"✅":"❌");
		const int	value2 = vec2.front();
		std::cout << (value2 == 1 ?"✅":"❌");
		const int	value3 = vec3.front();
		std::cout << (value3 == 6 ?"✅":"❌") << std::endl;
	}

	std::cout << "back()             |";
	{
		int	value1 = vec1.back();
		std::cout << (value1 == 2 ?"✅":"❌");
		int	value2 = vec2.back();
		std::cout << (value2 == 15 ?"✅":"❌");
		int	value3 = vec3.back();
		std::cout << (value3 == 10 ?"✅":"❌") << std::endl;
	}

	std::cout << "const back()       |";
	{
		const int	value1 = vec1.back();
		std::cout << (value1 == 2 ?"✅":"❌");
		const int	value2 = vec2.back();
		std::cout << (value2 == 15 ?"✅":"❌");
		const int	value3 = vec3.back();
		std::cout << (value3 == 10 ?"✅":"❌") << std::endl;
	}

	std::cout << std::endl;

	std::cout << "fill assign()      |";
	{
		ft::vector<int>	vec4(vec3);
		{
			int	ar[] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
			int cont = 0;
			vec4.assign(11, 3);
			cont += (vec4.size() == 11? 1: 0);
			for (std::size_t i = 0; i < vec4.size(); i++)
				cont += (vec4[i] == ar[i]? 1: 0);
			cont += (vec4.capacity() == 11? 1: 0);
			std::cout << (cont == (2 + 11) ?"✅":"❌");
		}
		{
			int	ar[] = {5, 5, 5, 5, 5, 5};
			int cont = 0;
			vec4.assign(6,5);
			cont += (vec4.size() == 6? 1: 0);
			for (std::size_t i = 0; i < vec4.size(); i++)
				cont += (vec4[i] == ar[i]? 1: 0);
			cont += (vec4.capacity() == 11? 1: 0);
			std::cout << (cont == (2 + 6) ?"✅":"❌");
		}
		{
			int	ar[] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
			int cont = 0;
			vec4.assign(20, -1);
			cont += (vec4.size() == 20? 1: 0);
			for (std::size_t i = 0; i < vec4.size(); i++)
				cont += (vec4[i] == ar[i]? 1: 0);
			cont += (vec4.capacity() == 20? 1: 0);
			std::cout << (cont == (2 + 20) ?"✅":"❌") << std::endl;
		}
	}

	std::cout << "range assign()     |";
	{
		ft::vector<int>	vec4(vec3);
		{
			int	ar[] = {6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4};
			int cont = 0;
			vec4.assign(ar, ar + 11);
			cont += (vec4.size() == 11? 1: 0);
			for (std::size_t i = 0; i < vec4.size(); i++)
				cont += (vec4[i] == ar[i]? 1: 0);
			cont += (vec4.capacity() == 11? 1: 0);
			std::cout << (cont == (2 + 11) ?"✅":"❌");
		}
		{
			int	ar[] = {1, 2, 3, 4, 5, 6};
			int cont = 0;
			vec4.assign(ar, ar + 6);
			cont += (vec4.size() == 6? 1: 0);
			for (std::size_t i = 0; i < vec4.size(); i++)
				cont += (vec4[i] == ar[i]? 1: 0);
			cont += (vec4.capacity() == 11? 1: 0);
			std::cout << (cont == (2 + 6) ?"✅":"❌");
		}
		{
			int	ar[] = {1, 2, 3, 4, 5, 6, 0, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3};
			int cont = 0;
			vec4.assign(ar, ar + 20);
			cont += (vec4.size() == 20? 1: 0);
			for (std::size_t i = 0; i < vec4.size(); i++)
				cont += (vec4[i] == ar[i]? 1: 0);
			cont += (vec4.capacity() == 20? 1: 0);
			std::cout << (cont == (2 + 20) ?"✅":"❌") << std::endl;
		}
	}

	std::cout << "push_back()        |";
	{
		ft::vector<int>	vec4(array, array + 3);
		vec4.reserve(5);

		vec4.push_back(2);
		std::cout << (((vec4.back() == 2) && (vec4.size() == 4) && vec4.capacity() == 5)?"✅":"❌");
		vec4.push_back(3);
		vec4.push_back(4);
		std::cout << (((vec4.back() == 4) && (vec4.size() == 6) && vec4.capacity() == 10)?"✅":"❌");
		vec4.push_back(5);
		vec4.push_back(6);
		vec4.push_back(7);
		vec4.push_back(8);
		vec4.push_back(9);
		std::cout << (((vec4.back() == 9) && (vec4.size() == 11) && vec4.capacity() == 20)?"✅":"❌")  << std::endl;
	}

	std::cout << "pop_back()         |";
	{
		ft::vector<int>				vec4(vec3);

		vec4.pop_back();
		vec4.pop_back();
		std::cout << (((vec4.back() == 8) && (vec4.size() == 3))?"✅":"❌");
		vec4.pop_back();
		vec4.pop_back();
		std::cout << (((vec4.back() == 6) && (vec4.size() == 1))?"✅":"❌");
		vec4.pop_back();
		std::cout << ((vec4.size() == 0)?"✅":"❌") << std::endl;
	}

	std::cout << "single insert()    |";
	{
		ft::vector<int> vec4(vec3);
		int				cont;
		vec4.insert(vec4.begin() + 2, 55);
		{
			int	ar[] = {6, 7, 55, 8, 9, 10,};
			cont = 0;
			cont += (vec4.size() == 6? 1: 0);
			for (std::size_t i = 0; i < vec4.size(); i++)
				cont += (vec4[i] == ar[i]? 1: 0);
			cont += (vec4.capacity() == 10? 1: 0);
			std::cout << (cont == (2 + 6) ?"✅":"❌");
		}
		vec4.insert(vec4.begin() + 5, 0);
		{
			int	ar[] = {6, 7, 55, 8, 9, 0, 10};
			cont = 0;
			cont += (vec4.size() == 7? 1: 0);
			for (std::size_t i = 0; i < vec4.size(); i++)
				cont += (vec4[i] == ar[i]? 1: 0);
			cont += (vec4.capacity() == 10? 1: 0);
			std::cout << (cont == (2 + 7) ?"✅":"❌");
		}
		vec4.insert(vec4.end() - 2, -100);
		vec4.insert(vec4.end() - 2, -100);
		vec4.insert(vec4.end() - 2, -100);
		vec4.insert(vec4.end() - 2, -100);
		{
			int	ar[] = {6, 7, 55, 8, 9, -100, -100, -100, -100, 0, 10};
			cont = 0;
			cont += (vec4.size() == 11? 1: 0);
			for (std::size_t i = 0; i < vec4.size(); i++)
				cont += (vec4[i] == ar[i]? 1: 0);
			cont += (vec4.capacity() == 20? 1: 0);
			std::cout << (cont == (2 + 11) ?"✅":"❌") << std::endl;
		}
	}

	std::cout << "fill insert()      |";
	{
		ft::vector<int> vec4(vec3);
		int				cont;
		{
			vec4.insert(vec4.begin() + 4, 1,55);
			int	ar1[] = {6, 7, 8, 9, 55, 10};
			cont = 0;
			cont += (vec4.size() == 6? 1: 0);
			for (std::size_t i = 0; i < vec4.size(); i++)
				cont += (vec4[i] == ar1[i]? 1: 0);
			cont += (vec4.capacity() == 10? 1: 0);

 			vec4.insert(vec4.begin() + 4, 7,55);
			int	ar2[] = {6, 7, 8, 9, 55, 55, 55, 55, 55, 55, 55, 55, 10};
			cont += (vec4.size() == 13? 1: 0);
			for (std::size_t i = 0; i < vec4.size(); i++)
				cont += (vec4[i] == ar2[i]? 1: 0);
			cont += (vec4.capacity() == 13? 1: 0);
			std::cout << (cont == (2 + 13 + 2 + 6) ?"✅":"❌");
		}
		{
			vec4.insert(vec4.begin() + 4, 8,55);
			int	ar1[] = {6, 7, 8, 9, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 10};
			cont = 0;
			cont += (vec4.size() == 21? 1: 0);
			for (std::size_t i = 0; i < vec4.size(); i++)
				cont += (vec4[i] == ar1[i]? 1: 0);
			cont += (vec4.capacity() == 26? 1: 0);

			vec4.insert(vec4.begin() + 10, 20, -15);
			int	ar2[] = {6, 7, 8, 9, 55, 55, 55, 55, 55, 55, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 10};
			cont += (vec4.size() == 41? 1: 0);
			for (std::size_t i = 0; i < vec4.size(); i++)
				cont += (vec4[i] == ar2[i]? 1: 0);
			cont += (vec4.capacity() == 42? 1: 0);
			std::cout << (cont == (2 + 41 + 2 + 21) ?"✅":"❌");
		}
		{
			vec4.insert(vec4.begin() + 10, 50, -15);
			int	ar1[] = {6, 7, 8, 9, 55, 55, 55, 55, 55, 55, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 10};
			cont = 0;
			cont += (vec4.size() == 91? 1: 0);
			for (std::size_t i = 0; i < vec4.size(); i++)
				cont += (vec4[i] == ar1[i]? 1: 0);
			cont += (vec4.capacity() == 91? 1: 0);

			vec4.insert(vec4.begin() + 10, 10, 2);
			int	ar2[] = {6, 7, 8, 9, 55, 55, 55, 55, 55, 55, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 10};
			cont += (vec4.size() == 101? 1: 0);
			for (std::size_t i = 0; i < vec4.size(); i++)
				cont += (vec4[i] == ar2[i]? 1: 0);
			cont += (vec4.capacity() == 182? 1: 0);
			std::cout << (cont == (2 + 101 + 2 + 91) ?"✅":"❌") << std::endl;
		}
	}

	std::cout << "range insert()     |";
	{

		int	ar[] = {6, 7, 55, 8, 55, 55, 55, 55, 55, 1, 2, 3, 4, 5, 6, 0, 2, 55, 55, 55, 1, 2, 3, 4, 5, 6, 0, 2, 9, 10};
		ft::vector<int>	vec4(vec1);
		ft::vector<int> vec5(ar, ar + 30);
		vec4.reserve(20);
		int				cont;
		{
			vec4.insert(vec4.begin() + 9, vec5.begin(), vec5.begin() + 1);
			int	ar1[] = {1, 2, 3, 4, 5, 6, 0, 2, 2, 6, 2, 2, 2, 2, 2, 2};
			cont = 0;
			cont += (vec4.size() == 16? 1: 0);
			for (std::size_t i = 0; i < vec4.size(); i++)
				cont += (vec4[i] == ar1[i]? 1: 0);
			cont += (vec4.capacity() == 20? 1: 0);

			vec4.insert(vec4.begin() + 15, vec5.begin(), vec5.begin() + 5);
			int	ar2[] = {1, 2, 3, 4, 5, 6, 0, 2, 2, 6, 2, 2, 2, 2, 2, 6, 7, 55, 8, 55, 2};
			cont += (vec4.size() == 21? 1: 0);
			for (std::size_t i = 0; i < vec4.size(); i++)
				cont += (vec4[i] == ar2[i]? 1: 0);
			cont += (vec4.capacity() == 32? 1: 0);
			std::cout << (cont == (2 + 21 + 2 + 16) ?"✅":"❌");
		}
		{
			vec4.insert(vec4.begin() + 13, vec5.begin(), vec5.end());
			int	ar1[] = {1, 2, 3, 4, 5, 6, 0, 2, 2, 6, 2, 2, 2, 6, 7, 55, 8, 55, 55, 55, 55, 55, 1, 2, 3, 4, 5, 6, 0, 2, 55, 55, 55, 1, 2, 3, 4, 5, 6, 0, 2, 9, 10, 2, 2, 6, 7, 55, 8, 55, 2};
			cont = 0;
			cont += (vec4.size() == 51? 1: 0);
			for (std::size_t i = 0; i < vec4.size(); i++)
				cont += (vec4[i] == ar1[i]? 1: 0);
			cont += (vec4.capacity() == 51? 1: 0);

			vec4.insert(vec4.begin() + 32, vec5.begin(), vec5.end());
			int	ar2[] = {1, 2, 3, 4, 5, 6, 0, 2, 2, 6, 2, 2, 2, 6, 7, 55, 8, 55, 55, 55, 55, 55, 1, 2, 3, 4, 5, 6, 0, 2, 55, 55, 6, 7, 55, 8, 55, 55, 55, 55, 55, 1, 2, 3, 4, 5, 6, 0, 2, 55, 55, 55, 1, 2, 3, 4, 5, 6, 0, 2, 9, 10, 55, 1, 2, 3, 4, 5, 6, 0, 2, 9, 10, 2, 2, 6, 7, 55, 8, 55, 2 };
			cont += (vec4.size() == 81? 1: 0);
			for (std::size_t i = 0; i < vec4.size(); i++)
				cont += (vec4[i] == ar2[i]? 1: 0);
			cont += (vec4.capacity() == 102? 1: 0);
			std::cout << (cont == (2 + 81 + 2 + 51) ?"✅":"❌");
		}
		{
			ft::vector<int>	vec6(vec4);
			vec6.insert(vec6.begin() + 60, vec4.begin(), vec4.end());

			vec4.insert(vec4.begin() + 32, vec6.begin(), vec6.end());
			int	ar1[] = {1, 2, 3, 4, 5, 6, 0, 2, 2, 6, 2, 2, 2, 6, 7, 55, 8, 55, 55, 55, 55, 55, 1, 2, 3, 4, 5, 6, 0, 2, 55, 55, 1, 2, 3, 4, 5, 6, 0, 2, 2, 6, 2, 2, 2, 6, 7, 55, 8, 55, 55, 55, 55, 55, 1, 2, 3, 4, 5, 6, 0, 2, 55, 55, 6, 7, 55, 8, 55, 55, 55, 55, 55, 1, 2, 3, 4, 5, 6, 0, 2, 55, 55, 55, 1, 2, 3, 4, 5, 6, 0, 2, 1, 2, 3, 4, 5, 6, 0, 2, 2, 6, 2, 2, 2, 6, 7, 55, 8, 55, 55, 55, 55, 55, 1, 2, 3, 4, 5, 6, 0, 2, 55, 55, 6, 7, 55, 8, 55, 55, 55, 55, 55, 1, 2, 3, 4, 5, 6, 0, 2, 55, 55, 55, 1, 2, 3, 4, 5, 6, 0, 2, 9, 10, 55, 1, 2, 3, 4, 5, 6, 0, 2, 9, 10, 2, 2, 6, 7, 55, 8, 55, 2, 9, 10, 55, 1, 2, 3, 4, 5, 6, 0, 2, 9, 10, 2, 2, 6, 7, 55, 8, 55, 2, 6, 7, 55, 8, 55, 55, 55, 55, 55, 1, 2, 3, 4, 5, 6, 0, 2, 55, 55, 55, 1, 2, 3, 4, 5, 6, 0, 2, 9, 10, 55, 1, 2, 3, 4, 5, 6, 0, 2, 9, 10, 2, 2, 6, 7, 55, 8, 55, 2};
			cont = 0;
			cont += (vec4.size() == 243? 1: 0);
			for (std::size_t i = 0; i < vec4.size(); i++)
				cont += (vec4[i] == ar1[i]? 1: 0);
			cont += (vec4.capacity() == 243? 1: 0);
			std::cout << (cont == (2 + 243) ?"✅":"❌") << std::endl;
		}
	}

	std::cout << "single erase()     |";
	{
		ft::vector<int>	vec4(vec1);
		int				cont;
		vec4.erase(vec4.begin());
		{
			int	ar[] = {2, 3, 4, 5, 6, 0, 2, 2, 2, 2, 2, 2, 2, 2};
			cont = 0;
			cont += (vec4.size() == 14? 1: 0);
			for (std::size_t i = 0; i < vec4.size(); i++)
				cont += (vec4[i] == ar[i]? 1: 0);
			cont += (vec4.capacity() == 15? 1: 0);
			std::cout << (cont == (2 + 14) ?"✅":"❌");
		}
		vec4.erase(vec4.begin() + 5);
		{
			int	ar[] = {2, 3, 4, 5, 6, 2, 2, 2, 2, 2, 2, 2, 2};
			cont = 0;
			cont += (vec4.size() == 13? 1: 0);
			for (std::size_t i = 0; i < vec4.size(); i++)
				cont += (vec4[i] == ar[i]? 1: 0);
			cont += (vec4.capacity() == 15? 1: 0);
			std::cout << (cont == (2 + 13) ?"✅":"❌");
		}
		vec4.erase(vec4.begin() + 9);
		{
			int	ar[] = {2, 3, 4, 5, 6, 2, 2, 2, 2, 2, 2, 2};
			cont = 0;
			cont += (vec4.size() == 12? 1: 0);
			for (std::size_t i = 0; i < vec4.size(); i++)
				cont += (vec4[i] == ar[i]? 1: 0);
			cont += (vec4.capacity() == 15? 1: 0);
			std::cout << (cont == (2 + 12) ?"✅":"❌") << std::endl;
		}
	}

	std::cout << "range erase()      |";
	{
		ft::vector<int>	vec4(vec1);
		int				cont;
		vec4.erase(vec4.begin() + 2, vec4.end() - 8);
		{
			int	ar[] = {1, 2, 2, 2, 2, 2, 2, 2, 2, 2};
			cont = 0;
			cont += (vec4.size() == 10? 1: 0);
			for (std::size_t i = 0; i < vec4.size(); i++)
				cont += (vec4[i] == ar[i]? 1: 0);
			cont += (vec4.capacity() == 15? 1: 0);
			std::cout << (cont == (2 + 10) ?"✅":"❌");
		}
		vec4.erase(vec4.begin() + 4, vec4.begin() + 9);
		{
			int	ar[] = {1, 2, 2, 2, 2};
			cont = 0;
			cont += (vec4.size() == 5? 1: 0);
			for (std::size_t i = 0; i < vec4.size(); i++)
				cont += (vec4[i] == ar[i]? 1: 0);
			cont += (vec4.capacity() == 15? 1: 0);
			std::cout << (cont == (2 + 5) ?"✅":"❌");
		}
		vec4.erase(vec4.begin(), vec4.end());
		{
			cont = 0;
			cont += (vec4.size() == 0? 1: 0);
			cont += (vec4.capacity() == 15? 1: 0);
			std::cout << (cont == 2 ?"✅":"❌") << std::endl;
		}
	}

	std::cout << "asymmetric swap()  |";
	{
		ft::vector<int>	vec4(8,10);
		ft::vector<int>	vec5(26,-50);

		ft::vector<int>::value_type*	ptr4 = vec4.begin().base();
		ft::vector<int>::value_type*	ptr5 = vec5.begin().base();

		ft::vector<int>::size_type		size4 = vec4.size();
		ft::vector<int>::size_type		size5 = vec5.size();

		ft::vector<int>::size_type		cap4 = vec4.capacity();
		ft::vector<int>::size_type		cap5 = vec5.capacity();

		vec4.swap(vec5);

		std::cout << (((ptr4 == vec5.begin().base()) && (ptr5 == vec4.begin().base()))?"✅":"❌");
		std::cout << (((size4 == vec5.size()) && (size5 == vec4.size()))?"✅":"❌");
		std::cout << (((cap4 == vec5.capacity()) && (cap5 == vec4.capacity()))?"✅":"❌") << std::endl;
	}

	std::cout << "symmetric swap()   |";
	{
		ft::vector<int>	vec4(8,10);
		ft::vector<int>	vec5(26,-50);

		ft::vector<int>::value_type*	ptr4 = vec4.begin().base();
		ft::vector<int>::value_type*	ptr5 = vec5.begin().base();

		ft::vector<int>::size_type		size4 = vec4.size();
		ft::vector<int>::size_type		size5 = vec5.size();

		ft::vector<int>::size_type		cap4 = vec4.capacity();
		ft::vector<int>::size_type		cap5 = vec5.capacity();

		swap(vec4, vec5);

		std::cout << (((ptr4 == vec5.begin().base()) && (ptr5 == vec4.begin().base()))?"✅":"❌");
		std::cout << (((size4 == vec5.size()) && (size5 == vec4.size()))?"✅":"❌");
		std::cout << (((cap4 == vec5.capacity()) && (cap5 == vec4.capacity()))?"✅":"❌") << std::endl;
	}

	std::cout << "clear()            |";
	{
		vec1.clear();
		vec2.clear();
		vec3.clear();
		std::cout << (((vec1.size() == 0) && (vec1.capacity() == 25))?"✅":"❌");
		std::cout << (((vec2.size() == 0) && (vec2.capacity() == 15))?"✅":"❌");
		std::cout << (((vec3.size() == 0) && (vec3.capacity() == 5))?"✅":"❌") << std::endl;
	}

	std::cout << std::endl;

	{
		std::cout << "operator ==        |";
		std::cout << (vec1 == vec1 ?"✅":"❌");
		std::cout << (vec2 == vec1 ?"✅":"❌");
		std::cout << (vec1 == vec3 ?"✅":"❌") << std::endl;

		std::cout << "operator !=        |";
		std::cout << (vec1 != vec1 ?"❌":"✅");
		std::cout << (vec1 != vec2 ?"❌":"✅");
		std::cout << (vec1 != vec3 ?"❌":"✅") << std::endl;

		std::cout << "operator <         |";
		std::cout << (vec1 < vec1 ?"❌":"✅");
		std::cout << (vec1 < vec2 ?"❌":"✅");
		std::cout << (vec2 < vec1 ?"❌":"✅") << std::endl;

		std::cout << "operator <=        |";
		std::cout << (vec1 <= vec1 ?"✅":"❌");
		std::cout << (vec1 <= vec2 ?"✅":"❌");
		std::cout << (vec2 <= vec1 ?"✅":"❌") << std::endl;

		std::cout << "operator >         |";
		std::cout << (vec1 > vec1 ?"❌":"✅");
		std::cout << (vec1 > vec2 ?"❌":"✅");
		std::cout << (vec2 > vec1 ?"❌":"✅") << std::endl;

		std::cout << "operator >=        |";
		std::cout << (vec1 >= vec1 ?"✅":"❌");
		std::cout << (vec1 >= vec2 ?"✅":"❌");
		std::cout << (vec2 >= vec1 ?"✅":"❌") << std::endl;
	}
}
