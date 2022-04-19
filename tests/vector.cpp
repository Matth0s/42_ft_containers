/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:42:22 by mmoreira          #+#    #+#             */
/*   Updated: 2022/04/19 13:29:22 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if 0 //CREATE A REAL STL EXAMPLE
	#include <vector>
	namespace ft = std;
#else
	#include "vector.hpp"
#endif

#include <iostream>

int	main( void )
{
	int	array[] = {1,2,3,4,5,6,7,8,9,10};

	try {
		ft::vector<int> vec;
		std::cout << "Default Constructor   |✅" << std::endl;
	} catch(std::exception& ex)	{
		std::cout << "Default Constructor   |❌" << std::endl;
		std::cout << ex.what() << std::endl;
	}

	try {
		ft::vector<int> vec(static_cast<std::size_t>(10), 10);
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

	// try {
	// 	ft::vector<int>::iterator it;
	// 	ft::vector<int>::const_iterator cit;
	// 	ft::vector<int> vec(array, array + 10);

	// 	for (it = vec.begin(); it < vec.end(); it++)
	// 		std::cout << *it << " ";
	// 	std::cout << std::endl;

	// 	for (cit = vec.begin(); cit < vec.end(); cit++)
	// 		std::cout << *cit << " ";
	// 	std::cout << std::endl;

	// 	std::cout << "begin() & end()       |✅" << std::endl;
	// } catch(std::exception& ex) {
	// 	std::cout << "begin() & end()       |❌" << std::endl;
	// 	std::cout << ex.what() << std::endl;
	// }


	// int	array2[] = {11,12,13,14,15,16,17,18,19,20,21,23,24,25};
	// ft::vector<int> vec1(array,array+10);
	// ft::vector<int> vec2(array2,array2+14);

	// std::cout << vec1.size() << " " << vec1.capacity() << std::endl;
	// std::cout << vec2.size() << " " << vec2.capacity() << std::endl;

	// vec2 = vec1;
	// std::cout << vec1.size() << " " << vec1.capacity() << std::endl;
	// std::cout << vec2.size() << " " << vec2.capacity() << std::endl;

	// std::cout << vec2[11] << std::endl;

	return (0);
}
