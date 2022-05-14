/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 04:53:49 by mmoreira          #+#    #+#             */
/*   Updated: 2022/05/14 00:40:07 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef STD
	#include <algorithm>
	namespace ft = std;
#else
	#include "algorithm.hpp"
#endif

#include <iostream>

bool	compi( int& x, int&y ) {
	return ( x < y);
};

bool	comps( char& x, char&y ) {
	return ( x < y);
};

bool	predi( int& x, int& y ) {
	return ( x == y);
}

bool	preds( char& x, char& y ) {
	return ( x == y);
}

void	test_algorithm( void )
{
	int			ar1[] = {1,2,3,4,5,6,7,8,9,10};
	int			ar2[] = {1,2,3,4,5,16,17,18,19,20};
	int			ar3[] = {17,18,19,20,1,2,3,4,5,6};
	std::string	s1 = "abcdefff";
	std::string	s2 = "abcfffaaaa";
	std::string	s3 = "fffabc";

	std::cout << "equal  -teste 1      |" << (ft::equal(ar1, ar1 + 5, ar2)?"✅": "❌") << std::endl;
	std::cout << "equal  -teste 2      |" << (ft::equal(ar1, ar1 + 7, ar2, predi)?"❌": "✅") << std::endl;
	std::cout << "equal  -teste 3      |" << (ft::equal(ar1, ar1 + 2, ar3)?"❌": "✅") << std::endl;
	std::cout << "equal  -teste 4      |" << (ft::equal(ar2 + 6, ar2 + 9, ar3, predi)?"✅": "❌") << std::endl;
	std::cout << "equal  -teste 5      |" << (ft::equal(ar3 + 4, ar3 + 4, ar1)?"✅": "❌") << std::endl;
	std::cout << "equal  -teste 6      |" << (ft::equal(s1.begin(), s1.begin() + 3, s2.begin(), preds)?"✅": "❌") << std::endl;
	std::cout << "equal  -teste 7      |" << (ft::equal(s1.begin(), s1.begin() + 7, s2.begin())?"❌": "✅") << std::endl;
	std::cout << "equal  -teste 8      |" << (ft::equal(s3.begin(), s3.begin() + 4, s2.begin() + 3, preds)?"✅": "❌") << std::endl;
	std::cout << "equal  -teste 9      |" << (ft::equal(s3.begin(), s3.begin() + 6, s2.begin() + 3)?"❌": "✅") << std::endl;
	std::cout << "equal  -teste 10     |" << (ft::equal(s3.begin() + 3, s3.begin() + 6, s1.begin(), preds)?"✅": "❌") << std::endl;
	std::cout << "lexicographical_compare  -teste 1   |" << (ft::lexicographical_compare(ar1, ar1 + 6, ar2, ar2 + 6, compi)?"✅": "❌") << std::endl;
	std::cout << "lexicographical_compare  -teste 2   |" << (ft::lexicographical_compare(ar1, ar1 + 5, ar2, ar2 + 5)?"❌": "✅") << std::endl;
	std::cout << "lexicographical_compare  -teste 3   |" << (ft::lexicographical_compare(ar1, ar1 + 5, ar2, ar2 + 3, compi)?"❌": "✅") << std::endl;
	std::cout << "lexicographical_compare  -teste 4   |" << (ft::lexicographical_compare(ar2 + 6, ar2 + 10, ar3, ar3 + 5)?"✅": "❌") << std::endl;
	std::cout << "lexicographical_compare  -teste 5   |" << (ft::lexicographical_compare(ar3 + 4, ar3 + 10, ar1, ar1 + 7, compi)?"✅": "❌") << std::endl;
	std::cout << "lexicographical_compare  -teste 6   |" << (ft::lexicographical_compare(s1.begin(), s1.begin() + 4, s2.begin(), s2.begin() + 4)?"✅": "❌") << std::endl;
	std::cout << "lexicographical_compare  -teste 7   |" << (ft::lexicographical_compare(s1.begin(), s1.begin() + 3, s2.begin(), s2.begin() + 3, comps)?"❌": "✅") << std::endl;
	std::cout << "lexicographical_compare  -teste 8   |" << (ft::lexicographical_compare(s2.begin() + 3, s2.begin() + 8, s3.begin(), s3.begin() + 5)?"✅": "❌") << std::endl;
	std::cout << "lexicographical_compare  -teste 9   |" << (ft::lexicographical_compare(s2.begin(), s2.begin() + 5, s1.begin(), s1.begin() + 5, comps)?"❌": "✅") << std::endl;
	std::cout << "lexicographical_compare  -teste 10  |" << (ft::lexicographical_compare(s3.begin(), s3.begin(), s1.begin(), s1.begin() + 1)?"✅": "❌") << std::endl;
}
