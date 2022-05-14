/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_map_reverse_iterator.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 02:42:19 by mmoreira          #+#    #+#             */
/*   Updated: 2022/05/14 04:33:19 by mmoreira         ###   ########.fr       */
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
typedef ft::vector<mapPair>						mapFtVec;
typedef mapRbTree::iterator						iterator;
typedef mapRbTree::reverse_iterator				reviterator;


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
			if (vec[i] < vec[i + 1])
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
	vectorSort(vec);

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
	for (int i = 0; i < size; i++)
	{
		std::cout << (*revit1 == vec[i] ?"✅":"❌");
		revit1++;
	}
	std::cout << std::endl;
	revit1--;
	std::cout << "operator --  |";
	for (int i = size - 1; i > 0; i--)
	{
		std::cout << (*revit1 == vec[i] ?"✅":"❌");
		revit1--;
	}
	std::cout << (*revit1 == vec[0] ?"✅":"❌");
	std::cout << std::endl;
}
