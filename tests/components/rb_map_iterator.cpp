/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_map_iterator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 06:08:28 by mmoreira          #+#    #+#             */
/*   Updated: 2022/05/14 01:07:55 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rb_tree.hpp"
#include "utility.hpp"
#include "vector.hpp"
#include <cstdlib>

template<class Arg, class Result>
struct unary_function
{
	typedef Arg		argument_type;
	typedef Result	result_type;
};

template <class Pair>
struct select1st: public unary_function<Pair, typename Pair::first_type>
{
	typename Pair::first_type&	operator()( Pair& x ) const {
		return x.first;
	};

	const typename Pair::first_type&	operator()( const Pair& x) const {
		return x.first;
	};
};

template <class Arg1, class Arg2, class Result>
struct binary_function
{
	typedef Arg1	first_argument_type;
	typedef Arg2	second_argument_type;
	typedef Result	result_type;
};

template <class T>
struct less: public binary_function<T, T, bool>
{
	bool	operator()(const T& x, const T& y) const {
		return (x < y);
	}
};

typedef	ft::pair<std::string, int>				mapPair;
typedef	ft::rb_tree<std::string, mapPair,
		select1st<mapPair>,
		less<std::string> >						mapRbTree;
typedef ft::rb_node<mapPair>					mapRbNode;
typedef ft::vector<mapPair>					mapFtVec;
typedef mapRbTree::iterator						iterator;


static std::string	randomString( int len ) {
	std::string	str;

	while (len--)
		str.push_back('A' + (rand() % 26) + (rand() % 2 ? 32 : 0));
	return (str);
}

static int		randomInt( int max ) {
	return (rand() % max * (rand() % 2? 1: -1));
}

static void	vectorSort( mapFtVec& vec ) {

	mapPair			temp;
	mapFtVec::size_type	i = 0;
	mapFtVec::size_type	j = vec.size() - 1;

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
		i = 0;
		j--;
	}
}

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
	vectorSort(vec);

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
	for (int i = 0; i < size; i++)
	{
		std::cout << (*it1 == vec[i] ?"✅":"❌");
		it1++;
	}
	std::cout << std::endl;
	it1--;
	std::cout << "operator --  |";
	for (int i = size - 1; i > 0; i--)
	{
		std::cout << (*it1 == vec[i] ?"✅":"❌");
		it1--;
	}
	std::cout << (*it1 == vec[0] ?"✅":"❌");
	std::cout << std::endl;
}
