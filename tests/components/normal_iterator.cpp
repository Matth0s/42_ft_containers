/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_iterator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:35:48 by mmoreira          #+#    #+#             */
/*   Updated: 2022/05/14 00:44:07 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef STD
	#include <vector>
	#include <iostream>
	typedef std::vector<int>::iterator	iterator;
#else
	#include "normal_iterator.hpp"
	typedef ft::normal_iterator<int*>	iterator;
#endif

void	test_normal_iterator( void )
{
	int	array1[] = {1,2,3,4,5,6,7,8,9,10};
	int	array2[] = {11,12,13,14,15,16,17,18,19,20};

	{
		iterator it3;
		std::cout << "Default Constructor  |✅" << std::endl;
	}

	{
		iterator it1(array1);
		std::cout << "Pointer Constructor  |✅" << std::endl;
	}

	{
		iterator it1(array1);
		iterator it2(it1);
		(void) it2;
		std::cout << "Copy Constructor     |✅" << std::endl;
	}

	{
		iterator it1(array1);
		iterator it2;
		it2 = it1;
		if (*it1 == *it2)
			std::cout << "Assignment Operator  |✅" << std::endl;
	}

	iterator it1(array1);
	iterator it2(array1);
	iterator it3(array2);

	std::cout << "operator *   |";
	{
		std::cout << (*it1 == 1 ?"✅":"❌");
		std::cout << (*it2 == 1 ?"✅":"❌");
		std::cout << (*it3 == 11 ?"✅":"❌");
	}

	std::cout << std::endl;
	std::cout << "operator ==  |";
	std::cout << (it1 == it1 ?"✅":"❌");
	std::cout << (it1 == it2 ?"✅":"❌");
	std::cout << (it1 == it3 ?"❌":"✅") << std::endl;

	std::cout << "operator !=  |";
	std::cout << (it1 != it1 ?"❌":"✅");
	std::cout << (it1 != it2 ?"❌":"✅");
	std::cout << (it1 != it3 ?"✅":"❌") << std::endl;

	std::cout << "operator ++  |";
	std::cout << (*++it1 == 2 ?"✅":"❌");
	std::cout << (*it1++ == 2 ?"✅":"❌" );
	std::cout << (*it1 == 3 ?"✅":"❌") << std::endl;

	std::cout << "operator --  |";
	std::cout << (*--it1 == 2 ?"✅":"❌");
	std::cout << (*it1-- == 2 ?"✅":"❌");
	std::cout << (*it1 == 1 ?"✅":"❌") << std::endl;

	std::cout << "operator + n |";
	std::cout << (*(it1 + 3) == 4 ?"✅":"❌");
	std::cout << (*(it1 + 5) == 6 ?"✅":"❌");
	std::cout << (*(it1 + 7) == 8 ?"✅":"❌") << std::endl;

	std::cout << "operator n + |";
	std::cout << (*(3 + it1) == 4 ?"✅":"❌");
	std::cout << (*(5 + it1) == 6 ?"✅":"❌");
	std::cout << (*(7 + it1) == 8 ?"✅":"❌") << std::endl;

	it1 = it1 + 9;
	std::cout << "operator - n |";
	std::cout << (*(it1 - 3) == 7 ?"✅":"❌");
	std::cout << (*(it1 - 5) == 5 ?"✅":"❌");
	std::cout << (*(it1 - 7) == 3 ?"✅":"❌") << std::endl;

	it3 = it2 + 5;
	std::cout << "operator - b |";
	std::cout << (it1 - it2 == 9 ?"✅":"❌");
	std::cout << (it2 - it1 == -9 ?"✅":"❌");
	std::cout << (it3 - it1 == -4 ?"✅":"❌") << std::endl;

	std::cout << "operator >   |";
	std::cout << (it1 > it1 ?"❌":"✅");
	std::cout << (it1 > it2 ?"✅":"❌");
	std::cout << (it2 > it1 ?"❌":"✅") << std::endl;

	std::cout << "operator <   |";
	std::cout << (it1 < it1 ?"❌":"✅");
	std::cout << (it1 < it2 ?"❌":"✅");
	std::cout << (it2 < it1 ?"✅":"❌") << std::endl;

	std::cout << "operator >=  |";
	std::cout << (it1 >= it1 ?"✅":"❌");
	std::cout << (it1 >= it2 ?"✅":"❌");
	std::cout << (it2 >= it1 ?"❌":"✅") << std::endl;

	std::cout << "operator <=  |";
	std::cout << (it1 <= it1 ?"✅":"❌");
	std::cout << (it1 <= it2 ?"❌":"✅");
	std::cout << (it2 <= it1 ?"✅":"❌") << std::endl;

	std::cout << "operator +=  |";
	std::cout << (*(it2 += 1 == 2) ?"✅":"❌");
	std::cout << (*(it2 += 3 == 5) ?"✅":"❌");
	std::cout << (*(it2 += 5 == 10) ?"✅":"❌") << std::endl;

	std::cout << "operator -=  |";
	std::cout << (*(it2 -= 1 == 9) ?"✅":"❌");
	std::cout << (*(it2 -= 3 == 6) ?"✅":"❌");
	std::cout << (*(it2 -= 5 == 1) ?"✅":"❌") << std::endl;

	std::cout << "operator []  |";
	std::cout << (it2[0] == 1 ?"✅":"❌");
	std::cout << (it2[4] == 5 ?"✅":"❌");
	std::cout << (it2[9] == 10 ?"✅":"❌") << std::endl;
}
