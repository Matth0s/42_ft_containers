/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:42:22 by mmoreira          #+#    #+#             */
/*   Updated: 2022/04/22 05:20:46 by mmoreira         ###   ########.fr       */
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
		ft::vector<int>::iterator it;
		ft::vector<int> vec1(array, array + 10);
		ft::vector<int> vec2(array + 5, array + 10);
		ft::vector<int> vec3(10, 2);

		for (it = vec1.begin(); it < vec1.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
		for (it = vec2.begin(); it < vec2.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
		for (it = vec3.begin(); it < vec3.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
		std::cout << "begin() & end()        |✅" << std::endl;
	} catch(std::exception& ex) {
		std::cout << "begin() & end()        |❌" << std::endl;
		std::cout << ex.what() << std::endl;
	}

	// std::cout << std::endl;

	// try {
	// 	ft::vector<int>::const_iterator it;
	// 	ft::vector<int> vec1(array, array + 10);
	// 	ft::vector<int> vec2(array + 5, array + 10);
	// 	ft::vector<int> vec3(10, 2);

	// 	for (it = vec1.begin(); it < vec1.end(); it++)
	// 		std::cout << *it << " ";
	// 	std::cout << std::endl;
	// 	for (it = vec2.begin(); it < vec2.end(); it++)
	// 		std::cout << *it << " ";
	// 	std::cout << std::endl;
	// 	for (it = vec3.begin(); it < vec3.end(); it++)
	// 		std::cout << *it << " ";
	// 	std::cout << std::endl;
	// 	std::cout << "const [begin() & end()] |✅" << std::endl;
	// } catch(std::exception& ex) {
	// 	std::cout << "const [begin() & end()] |❌" << std::endl;
	// 	std::cout << ex.what() << std::endl;
	// }

	std::cout << std::endl;

	try {
		ft::vector<int>::reverse_iterator it;
		ft::vector<int> vec1(array, array + 10);
		ft::vector<int> vec2(array + 5, array + 10);
		ft::vector<int> vec3(10, 2);

		for (it = vec1.rbegin(); it < vec1.rend(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
		for (it = vec2.rbegin(); it < vec2.rend(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
		for (it = vec3.rbegin(); it < vec3.rend(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
		std::cout << "rbegin() & rend()       |✅" << std::endl;
	} catch(std::exception& ex) {
		std::cout << "rbegin() & rend()       |❌" << std::endl;
		std::cout << ex.what() << std::endl;
	}

	// std::cout << std::endl;

	// try {
	// 	ft::vector<int>::const_reverse_iterator it;
	// 	ft::vector<int> vec1(array, array + 10);
	// 	ft::vector<int> vec2(array + 5, array + 10);
	// 	ft::vector<int> vec3(10, 2);

	// 	for (it = vec1.rbegin(); it < vec1.rend(); it++)
	// 		std::cout << *it << " ";
	// 	std::cout << std::endl;
	// 	for (it = vec2.rbegin(); it < vec2.rend(); it++)
	// 		std::cout << *it << " ";
	// 	std::cout << std::endl;
	// 	for (it = vec3.rbegin(); it < vec3.rend(); it++)
	// 		std::cout << *it << " ";
	// 	std::cout << std::endl;
	// 	std::cout << "rbegin() & rend()       |✅" << std::endl;
	// } catch(std::exception& ex) {
	// 	std::cout << "rbegin() & rend()       |❌" << std::endl;
	// 	std::cout << ex.what() << std::endl;
	// }

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
			std::cout << ex.what() << std::endl;
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
			std::cout << ex.what() << std::endl;
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

	// assign
	// push_back
	// pop_back
	// insert
	// erase
	// swap
	// clear

	std::cout << std::endl;

	try {
		std::allocator<int> alloc = vec1.get_allocator();
		int* ar = alloc.allocate(5);
		for (int i = 0; i < 5; i++)
			alloc.construct(ar + i, i);
		for (int i = 0; i < 5; i++)
			alloc.destroy(ar + i);
		alloc.deallocate(ar, 5);
		std::cout << "get_allocator()    |✅";
	} catch (std::exception& ex) {
		std::cout << "get_allocator()    |❌";
		std::cout << ex.what() << std::endl;
	}

	std::cout << std::endl;

	// relational operators
	// swap

	return (0);
}
