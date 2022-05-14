/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_reverse_iterator.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:23:03 by mmoreira          #+#    #+#             */
/*   Updated: 2022/05/14 00:24:33 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef STD
	#include <vector>
	typedef std::vector<int>::iterator	iterator;
#else
	#include "normal_iterator.hpp"
	typedef ft::normal_iterator<int*> iterator;
#endif

#include "reverse_iterator.hpp"

void	test_normal_reverse_iterator( void )
{
	int			array1[] = {1,2,3,4,5,6,7,8,9,10};
	iterator	it1(array1);

	{
		ft::reverse_iterator<iterator> rev_it;
		std::cout << "Default Constructor   |✅" << std::endl;
	}

	{
		ft::reverse_iterator<iterator> rev_it(it1);
		std::cout << "Iterator Constructor  |✅" << std::endl;
	}

	{
		ft::reverse_iterator<iterator> rev_it1(it1 + 1);
		ft::reverse_iterator<iterator> rev_it2(rev_it1);
		std::cout << "Copy Constructor      |✅" << std::endl;
	}

	{
		ft::reverse_iterator<iterator> rev_it1(it1 + 1);
		ft::reverse_iterator<iterator> rev_it2;
		rev_it2 = rev_it1;
		if (*rev_it1 == *rev_it2)
			std::cout << "Assignment Operator   |✅" << std::endl;
	}

	ft::reverse_iterator<iterator> rev_it1(it1 + 1);
	ft::reverse_iterator<iterator> rev_it2(it1 + 5);
	ft::reverse_iterator<iterator> rev_it3(it1 + 10);

	std::cout << "operator *   |";
	{
		std::cout << (*rev_it1 == 1 ?"✅":"❌");
		std::cout << (*rev_it2 == 5 ?"✅":"❌");
		std::cout << (*rev_it3 == 10 ?"✅":"❌") << std::endl;
	}

	std::cout << "operator + n |";
	std::cout << (*(rev_it3 + 1) == 9 ?"✅":"❌");
	std::cout << (*(rev_it3 + 3) == 7 ?"✅":"❌");
	std::cout << (*(rev_it3 + 5) == 5 ?"✅":"❌") << std::endl;


	std::cout << "operator ++  |";
	std::cout << (*++rev_it3 == 9 ?"✅":"❌");
	std::cout << (*rev_it3++ == 9 ?"✅":"❌" );
	std::cout << (*rev_it3 == 8 ?"✅":"❌") << std::endl;

	std::cout << "operator +=  |";
	std::cout << (*(rev_it3 += 1 == 7) ?"✅":"❌");
	std::cout << (*(rev_it3 += 3 == 5) ?"✅":"❌");
	std::cout << (*(rev_it3 += 5 == 3) ?"✅":"❌") << std::endl;

	std::cout << "operator -   |";
	std::cout << (*(rev_it1 - 1) == 2 ?"✅":"❌");
	std::cout << (*(rev_it1 - 3) == 4 ?"✅":"❌");
	std::cout << (*(rev_it1 - 5) == 6 ?"✅":"❌") << std::endl;

	std::cout << "operator --  |";
	std::cout << (*--rev_it1 == 2 ?"✅":"❌");
	std::cout << (*rev_it1-- == 2 ?"✅":"❌");
	std::cout << (*rev_it1 == 3 ?"✅":"❌") << std::endl;

	std::cout << "operator -=  |";
	std::cout << (*(rev_it1 -= 1 == 4) ?"✅":"❌");
	std::cout << (*(rev_it1 -= 3 == 6) ?"✅":"❌");
	std::cout << (*(rev_it1 -= 5 == 8) ?"✅":"❌") << std::endl;

	std::cout << "operator []  |";
	std::cout << (rev_it3[0] == 8 ?"✅":"❌");
	std::cout << (rev_it3[3] == 5 ?"✅":"❌");
	std::cout << (rev_it3[7] == 1 ?"✅":"❌") << std::endl;

	std::cout << "operator n + |";
	std::cout << (*(1 + rev_it3) == 7 ?"✅":"❌");
	std::cout << (*(3 + rev_it3) == 5 ?"✅":"❌");
	std::cout << (*(5 + rev_it3) == 3 ?"✅":"❌") << std::endl;

	std::cout << "operator - b |";
	std::cout << (rev_it1 - rev_it2 == 2 ?"✅":"❌");
	std::cout << (rev_it2 - rev_it1 == -2 ?"✅":"❌");
	std::cout << (rev_it3 - rev_it1 == -5 ?"✅":"❌") << std::endl;

	std::cout << "operator ==  |";
	std::cout << (rev_it1 == rev_it1 ?"✅":"❌");
	std::cout << (rev_it1 == rev_it2 ?"❌":"✅");
	std::cout << (rev_it1 == rev_it3 ?"❌":"✅") << std::endl;

	std::cout << "operator !=  |";
	std::cout << (rev_it1 != rev_it1 ?"❌":"✅");
	std::cout << (rev_it1 != rev_it2 ?"✅":"❌");
	std::cout << (rev_it1 != rev_it3 ?"✅":"❌") << std::endl;

	std::cout << "operator <   |";
	std::cout << (rev_it1 < rev_it1 ?"❌":"✅");
	std::cout << (rev_it1 < rev_it2 ?"❌":"✅");
	std::cout << (rev_it2 < rev_it1 ?"✅":"❌") << std::endl;

	std::cout << "operator <=  |";
	std::cout << (rev_it1 <= rev_it1 ?"✅":"❌");
	std::cout << (rev_it1 <= rev_it2 ?"❌":"✅");
	std::cout << (rev_it2 <= rev_it1 ?"✅":"❌") << std::endl;

	std::cout << "operator >   |";
	std::cout << (rev_it1 > rev_it1 ?"❌":"✅");
	std::cout << (rev_it1 > rev_it2 ?"✅":"❌");
	std::cout << (rev_it2 > rev_it1 ?"❌":"✅") << std::endl;

	std::cout << "operator >=  |";
	std::cout << (rev_it1 >= rev_it1 ?"✅":"❌");
	std::cout << (rev_it1 >= rev_it2 ?"✅":"❌");
	std::cout << (rev_it2 >= rev_it1 ?"❌":"✅") << std::endl;
}
