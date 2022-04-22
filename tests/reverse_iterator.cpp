/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:23:03 by mmoreira          #+#    #+#             */
/*   Updated: 2022/04/22 19:50:43 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reverse_iterator.hpp"
#include "vector_iterator.hpp"

int	main( void )
{
	int	array1[] = {1,2,3,4,5,6,7,8,9,10};
	ft::random_access_iterator<int> it1(array1);

	try {
		ft::reverse_iterator<ft::random_access_iterator<int> > rev_it;
		std::cout << "Default Constructor   |✅" << std::endl;
	} catch(std::exception& ex)	{
		std::cout << "Default Constructor   |❌" << std::endl;
		std::cout << ex.what() << std::endl;
	}

	try {
		ft::reverse_iterator<ft::random_access_iterator<int> > rev_it(it1);
		std::cout << "Iterator Constructor  |✅" << std::endl;
	} catch(std::exception& ex) {
		std::cout << "Iterator Constructor  |❌" << std::endl;
		std::cout << ex.what() << std::endl;
	}

	try {
		ft::reverse_iterator<ft::random_access_iterator<int> > rev_it1(it1 + 1);
		ft::reverse_iterator<ft::random_access_iterator<int> > rev_it2(rev_it1);
		std::cout << "Copy Constructor      |✅" << std::endl;
	} catch(std::exception& ex) {
		std::cout << "Copy Constructor      |❌" << std::endl;
		std::cout << ex.what() << std::endl;
	}

	try {
		ft::reverse_iterator<ft::random_access_iterator<int> > rev_it1(it1 + 1);
		ft::reverse_iterator<ft::random_access_iterator<int> > rev_it2;
		rev_it2 = rev_it1;
		if (*rev_it1 == *rev_it2)
			std::cout << "Assignment Operator   |✅" << std::endl;
	} catch(std::exception& ex) {
		std::cout << "Assignment Operator   |❌" << std::endl;
		std::cout << ex.what() << std::endl;
	}

	ft::reverse_iterator<ft::random_access_iterator<int> > rev_it1(it1 + 1);
	ft::reverse_iterator<ft::random_access_iterator<int> > rev_it2(it1 + 5);
	ft::reverse_iterator<ft::random_access_iterator<int> > rev_it3(it1 + 10);

	std::cout << "operator *   |";
	try {
		std::cout << (*rev_it1 == 1 ?"✅":"❌");
		std::cout << (*rev_it2 == 5 ?"✅":"❌");
		std::cout << (*rev_it3 == 10 ?"✅":"❌") << std::endl;
	} catch(std::exception& ex) {
		std::cout << "❌" << std::endl;
		std::cout << ex.what() << std::endl;
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

	return (0);
}
