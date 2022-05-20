/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_map_reverse_iterator.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 02:42:19 by mmoreira          #+#    #+#             */
/*   Updated: 2022/05/20 06:01:49 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rb_tree.hpp"
#include "functional.hpp"
#include "utility.hpp"
#include "vector.hpp"
#include <cstdlib>

typedef	ft::pair<std::string, int>			mapPair;
typedef	ft::rb_tree<std::string, mapPair,
		ft::select1st<mapPair>,
		ft::less<std::string> >				mapRbTree;
typedef ft::rb_node<mapPair>				mapRbNode;
typedef ft::vector<mapPair>					mapFtVec;
typedef mapRbTree::iterator					iterator;
typedef mapRbTree::reverse_iterator			reviterator;


static std::string	randomString( int len ) {
	std::string	str;

	while (len--)
		str.push_back('A' + (rand() % 26) + (rand() % 2 ? 32 : 0));
	return (str);
}

static int		randomInt( int max ) {
	return (rand() % max * (rand() % 2? 1: -1));
}

template <class Vec, typename T>
static void	vectorSort( Vec& vec, T temp ) {

	typename Vec::size_type	i = 0;
	typename Vec::size_type	j = vec.size() - 1;

	while (j > 0)
	{
		while (i < j)
		{
			if (vec[i] < vec[i + 1])
			{
				temp = vec[i];
				vec[i] = vec[i + 1];
				vec[i + 1] = temp;
			}
			i++;
		}
		i = 0; j--;
	}
};

template <class Vec, typename T>
static void	vectorUnique( Vec& vec, T temp ) {

	vectorSort(vec, temp);

	typename Vec::iterator	it = vec.begin();

	while (++it != vec.end())
	{
		if (*it == *(it - 1))
		{
			vec.erase(it);
			it = vec.begin();
		}
	}
};

void	test_rb_map_reverse_iterator( void )
{
	srand(18);
	mapRbTree	tree;
	mapFtVec	vec;
	int			size = 20;

	for (int i = 0; i < size; i++)
	{
		vec.push_back(mapPair(randomString(1 + (rand()%10)),randomInt(453534)));
		tree.insert(vec[i]);
	}
	vectorUnique(vec, mapPair());

	iterator	it1(tree.null(), tree.null());
	{
		reviterator revit;
		std::cout << "Default Constructor  |✅" << std::endl;
	}

	{
		reviterator	revit1(it1);
		std::cout << "Iterator Constructor |✅" << std::endl;
	}

	{
		reviterator	revit1(it1);
		reviterator revit2(revit1);
		(void) revit2;
		std::cout << "Copy Constructor     |✅" << std::endl;
	}

	{
		reviterator	revit1(it1);
		reviterator revit2;
		revit2 = revit1;
		if (*revit1 == *revit2)
			std::cout << "Assignment Operator  |✅" << std::endl;
	}

	reviterator revit1(it1);
	reviterator revit2(it1);
	reviterator revit3(iterator(tree.root(), tree.null()));

	std::cout << std::endl;

	std::cout << "operator *   |";
	{
		std::cout << ((*revit1).first == "zAU" ?"✅":"❌");
		std::cout << ((*revit1).second == -55875 ?"✅":"❌");
		std::cout << ((*revit2).first == "zAU" ?"✅":"❌");
		std::cout << ((*revit2).second == -55875 ?"✅":"❌");
		std::cout << ((*revit3).first == "boxUyV" ?"✅":"❌");
		std::cout << ((*revit3).second == 202048 ?"✅":"❌") << std::endl;
	}

	std::cout << "operator ->  |";
	{
		std::cout << (revit1->first == "zAU" ?"✅":"❌");
		std::cout << (revit1->second == -55875 ?"✅":"❌");
		std::cout << (revit2->first == "zAU" ?"✅":"❌");
		std::cout << (revit2->second == -55875 ?"✅":"❌");
		std::cout << (revit3->first == "boxUyV" ?"✅":"❌");
		std::cout << (revit3->second == 202048 ?"✅":"❌") << std::endl;
	}

	std::cout << "operator ==  |";
	std::cout << (revit1 == revit1 ?"✅":"❌");
	std::cout << (revit1 == revit2 ?"✅":"❌");
	std::cout << (revit1 == revit3 ?"❌":"✅") << std::endl;

	std::cout << "operator !=  |";
	std::cout << (revit1 != revit1 ?"❌":"✅");
	std::cout << (revit1 != revit2 ?"❌":"✅");
	std::cout << (revit1 != revit3 ?"✅":"❌") << std::endl;

	std::cout << "operator ++  |";
	std::cout << (*++revit1 == vec[1] ?"✅":"❌");
	std::cout << (*revit1++ == vec[1] ?"✅":"❌" );
	std::cout << (*revit1 == vec[2] ?"✅":"❌") << std::endl;

	std::cout << "operator --  |";
	std::cout << (*--revit1 == vec[1] ?"✅":"❌");
	std::cout << (*revit1-- == vec[1] ?"✅":"❌");
	std::cout << (*revit1 == vec[0] ?"✅":"❌") << std::endl;

	std::cout << "operator ++  |";
	for (mapFtVec::size_type i = 0; i < vec.size(); i++)
	{
		std::cout << (*revit1 == vec[i] ?"✅":"❌");
		revit1++;
	}
	std::cout << std::endl;
	revit1--;
	std::cout << "operator --  |";
	for (mapFtVec::size_type i = vec.size() - 1; i > 0; i--)
	{
		std::cout << (*revit1 == vec[i] ?"✅":"❌");
		revit1--;
	}
	std::cout << (*revit1 == vec[0] ?"✅":"❌");
	std::cout << std::endl;
}
