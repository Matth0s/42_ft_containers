/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_map_iterator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 06:08:28 by mmoreira          #+#    #+#             */
/*   Updated: 2022/05/15 16:41:16 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rb_tree.hpp"
#include "utility.hpp"
#include "vector.hpp"
#include "functional.hpp"
#include <cstdlib>

typedef	ft::pair<std::string, int>			mapPair;
typedef	ft::rb_tree<std::string, mapPair,
		ft::select1st<mapPair>,
		ft::less<std::string> >				mapRbTree;
typedef ft::rb_node<mapPair>				mapRbNode;
typedef ft::vector<mapPair>					mapFtVec;
typedef mapRbTree::iterator					iterator;


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
			if (vec[i] > vec[i + 1])
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


void	test_rb_map_iterator( void )
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

	{
		iterator it;
		std::cout << "Default Constructor  |✅" << std::endl;
	}

	{
		iterator it1(mapRbNode::min(tree.root(), tree.null()), tree.null());
		std::cout << "Node Constructor     |✅" << std::endl;
	}

	{
		iterator it1(mapRbNode::min(tree.root(), tree.null()), tree.null());
		iterator it2(it1);
		(void) it2;
		std::cout << "Copy Constructor     |✅" << std::endl;
	}

	{
		iterator it1(mapRbNode::min(tree.root(), tree.null()),tree.null());
		iterator it2;
		it2 = it1;
		if (*it1 == *it2)
			std::cout << "Assignment Operator  |✅" << std::endl;
	}

	iterator it1(mapRbNode::min(tree.root(), tree.null()), tree.null());
	iterator it2(mapRbNode::min(tree.root(), tree.null()), tree.null());
	iterator it3(tree.root(), tree.null());

	std::cout << std::endl;

	std::cout << "operator *   |";
	{
		std::cout << ((*it1).first == "As" ?"✅":"❌");
		std::cout << ((*it1).second == -215354 ?"✅":"❌");
		std::cout << ((*it2).first == "As" ?"✅":"❌");
		std::cout << ((*it2).second == -215354 ?"✅":"❌");
		std::cout << ((*it3).first == "dO" ?"✅":"❌");
		std::cout << ((*it3).second == 296255 ?"✅":"❌") << std::endl;
	}

	std::cout << "operator ->  |";
	{
		std::cout << (it1->first == "As" ?"✅":"❌");
		std::cout << (it1->second == -215354 ?"✅":"❌");
		std::cout << (it2->first == "As" ?"✅":"❌");
		std::cout << (it2->second == -215354 ?"✅":"❌");
		std::cout << (it3->first == "dO" ?"✅":"❌");
		std::cout << (it3->second == 296255 ?"✅":"❌") << std::endl;
	}

	std::cout << "operator ==  |";
	std::cout << (it1 == it1 ?"✅":"❌");
	std::cout << (it1 == it2 ?"✅":"❌");
	std::cout << (it1 == it3 ?"❌":"✅") << std::endl;

	std::cout << "operator !=  |";
	std::cout << (it1 != it1 ?"❌":"✅");
	std::cout << (it1 != it2 ?"❌":"✅");
	std::cout << (it1 != it3 ?"✅":"❌") << std::endl;

	std::cout << "operator ++  |";
	std::cout << (*++it1 == vec[1] ?"✅":"❌");
	std::cout << (*it1++ == vec[1] ?"✅":"❌" );
	std::cout << (*it1 == vec[2] ?"✅":"❌") << std::endl;

	std::cout << "operator --  |";
	std::cout << (*--it1 == vec[1] ?"✅":"❌");
	std::cout << (*it1-- == vec[1] ?"✅":"❌");
	std::cout << (*it1 == vec[0] ?"✅":"❌") << std::endl;

	std::cout << "operator ++  |";
	for (mapFtVec::size_type i = 0; i < vec.size(); i++)
	{
		std::cout << (*it1 == vec[i] ?"✅":"❌");
		it1++;
	}
	std::cout << std::endl;
	it1--;
	std::cout << "operator --  |";
	for (mapFtVec::size_type i = vec.size() - 1; i > 0; i--)
	{
		std::cout << (*it1 == vec[i] ?"✅":"❌");
		it1--;
	}
	std::cout << (*it1 == vec[0] ?"✅":"❌");
	std::cout << std::endl;
}
