/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:42:22 by mmoreira          #+#    #+#             */
/*   Updated: 2022/04/22 21:56:27 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if 0
	#include <vector>
	namespace ft = std;
#else
	#include "vector.hpp"
#endif

#include <iostream>

int	main( void )
{
	int	array[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

	try {
		ft::vector<int> vec;
		std::cout << "Default Constructor   |✅" << std::endl;
	} catch(std::exception& ex)	{
		std::cout << "Default Constructor   |❌" << std::endl;
		std::cout << ex.what() << std::endl;
	}

	try {
		ft::vector<int> vec(10, 10);
		std::cout << "Fill Constructor      |✅" << std::endl;
	} catch(std::exception& ex) {
		std::cout << "Fill Constructor      |❌" << std::endl;
		std::cout << ex.what() << std::endl;
	}

	try {
		ft::vector<int> vec(array, array + 10);
		std::cout << "Range Constructor     |✅" << std::endl;
	} catch(std::exception& ex) {
		std::cout << "Range Constructor     |❌" << std::endl;
		std::cout << ex.what() << std::endl;
	}

	try {
		ft::vector<int> vec1(array, array + 10);
		ft::vector<int> vec2(vec1);
		std::cout << "Copy Constructor      |✅" << std::endl;
	} catch(std::exception& ex) {
		std::cout << "Copy Constructor      |❌" << std::endl;
		std::cout << ex.what() << std::endl;
	}

	try {
		ft::vector<int> vec1(array, array + 10);
		ft::vector<int>	vec2;
		vec1 = vec2;
		std::cout << "Assignment Operator   |✅" << std::endl;
	} catch(std::exception& ex) {
		std::cout << "Assignment Operator   |❌" << std::endl;
		std::cout << ex.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		ft::vector<int> vec(array, array + 10);
		std::allocator<int> alloc = vec.get_allocator();
		int* ar = alloc.allocate(5);
		for (int i = 0; i < 5; i++)
			alloc.construct(ar + i, i);
		for (int i = 0; i < 5; i++)
			alloc.destroy(ar + i);
		alloc.deallocate(ar, 5);
		std::cout << "get_allocator()       |✅"  << std::endl;
	} catch (std::exception& ex) {
		std::cout << "get_allocator()       |❌"  << std::endl;
		std::cout << ex.what() << std::endl;
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

		// std::cout << "const [begin() & end()]   |";
		// {
		// 	ft::vector<int>::const_iterator it;
		// 	ft::vector<int>::const_iterator i;

		// 	i = vec1.begin();
		// 	cont = 0;
		// 	for (it = vec1.begin(); it < vec1.end(); it++)
		// 		cont += (*it == array[it - i]? 1: 0);
		// 	std::cout << (cont == 10 ?"✅":"❌");

		// 	i = vec2.begin();
		// 	cont = 0;
		// 	for (it = vec2.begin(); it < vec2.end(); it++)
		// 		cont += (*it == array[it - i + 5]? 1: 0);
		// 	std::cout << (cont == 5 ?"✅":"❌");

		// 	i = vec3.begin();
		// 	cont = 0;
		// 	for (it = vec3.begin(); it < vec3.end(); it++)
		// 		cont += (*it == ar[it - i]? 1: 0);
		// 	std::cout << (cont == 10 ?"✅":"❌") << std::endl;
		// }

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

		// std::cout << "const [rbegin() & rend()] |";
		// {
		// 	ft::vector<int>::reverse_iterator it;
		// 	ft::vector<int>::reverse_iterator i;

		// 	i = vec1.rbegin();
		// 	cont = 0;
		// 	for (it = vec1.rbegin(); it < vec1.rend(); it++)
		// 		cont += (*it == array[10 - (it - i + 1)]? 1: 0);
		// 	std::cout << (cont == 10 ?"✅":"❌");

		// 	i = vec2.rbegin();
		// 	cont = 0;
		// 	for (it = vec2.rbegin(); it < vec2.rend(); it++)
		// 		cont += (*it == array[10 - (it - i + 1)]? 1: 0);
		// 	std::cout << (cont == 5 ?"✅":"❌");

		// 	i = vec3.rbegin();
		// 	cont = 0;
		// 	for (it = vec3.rbegin(); it < vec3.rend(); it++)
		// 		cont += (*it == ar[it - i]? 1: 0);
		// 	std::cout << (cont == 10 ?"✅":"❌")<< std::endl;
		// }
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
		ft::vector<int>::size_type	size = 0;

		vec4.pop_back();
		vec4.pop_back();
		std::cout << (((vec4.back() == 8) && (vec4.size() == 3))?"✅":"❌");
		vec4.pop_back();
		vec4.pop_back();
		std::cout << (((vec4.back() == 6) && (vec4.size() == 1))?"✅":"❌");
		vec4.pop_back();
		vec4.pop_back();
		vec4.pop_back();
		std::cout << ((vec4.size() == (size - 2))?"✅":"❌") << std::endl;
	}

	// insert

	std::cout << "erase()            |";
	{
		ft::vector<int>				vec4(vec1);
		vec4.erase(vec4.begin());
		vec4.erase(vec4.begin() + 5);
		{
			int	ar[] = {2, 3, 4, 5, 6, 2, 2, 2, 2, 2, 2, 2, 2};
			int cont = 0;
			cont += (vec4.size() == 13? 1: 0);
			for (std::size_t i = 0; i < vec4.size(); i++)
				cont += (vec4[i] == ar[i]? 1: 0);
			cont += (vec4.capacity() == 15? 1: 0);
			std::cout << (cont == (2 + 13) ?"✅":"❌");
		}
		vec4.erase(vec4.begin() + 4, vec4.begin() + 9);
		{
			int	ar[] = {2, 3, 4, 5, 2, 2, 2, 2};
			int cont = 0;
			cont += (vec4.size() == 8? 1: 0);
			for (std::size_t i = 0; i < vec4.size(); i++)
				cont += (vec4[i] == ar[i]? 1: 0);
			cont += (vec4.capacity() == 15? 1: 0);
			std::cout << (cont == (2 + 8) ?"✅":"❌");
		}
		vec4.erase(vec4.begin(), vec4.end());
		{
			int cont = 0;
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


	// {
	// 	std::cout << "operator ==  |";
	// 	std::cout << (rev_it1 == rev_it1 ?"✅":"❌");
	// 	std::cout << (rev_it1 == rev_it2 ?"❌":"✅");
	// 	std::cout << (rev_it1 == rev_it3 ?"❌":"✅") << std::endl;

	// 	std::cout << "operator !=  |";
	// 	std::cout << (rev_it1 != rev_it1 ?"❌":"✅");
	// 	std::cout << (rev_it1 != rev_it2 ?"✅":"❌");
	// 	std::cout << (rev_it1 != rev_it3 ?"✅":"❌") << std::endl;

	// 	std::cout << "operator <   |";
	// 	std::cout << (rev_it1 < rev_it1 ?"❌":"✅");
	// 	std::cout << (rev_it1 < rev_it2 ?"❌":"✅");
	// 	std::cout << (rev_it2 < rev_it1 ?"✅":"❌") << std::endl;

	// 	std::cout << "operator <=  |";
	// 	std::cout << (rev_it1 <= rev_it1 ?"✅":"❌");
	// 	std::cout << (rev_it1 <= rev_it2 ?"❌":"✅");
	// 	std::cout << (rev_it2 <= rev_it1 ?"✅":"❌") << std::endl;

	// 	std::cout << "operator >   |";
	// 	std::cout << (rev_it1 > rev_it1 ?"❌":"✅");
	// 	std::cout << (rev_it1 > rev_it2 ?"✅":"❌");
	// 	std::cout << (rev_it2 > rev_it1 ?"❌":"✅") << std::endl;

	// 	std::cout << "operator >=  |";
	// 	std::cout << (rev_it1 >= rev_it1 ?"✅":"❌");
	// 	std::cout << (rev_it1 >= rev_it2 ?"✅":"❌");
	// 	std::cout << (rev_it2 >= rev_it1 ?"❌":"✅") << std::endl;

	// }

	return (0);
}
