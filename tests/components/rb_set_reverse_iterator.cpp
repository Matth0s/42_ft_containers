/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_set_reverse_iterator.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 04:35:42 by mmoreira          #+#    #+#             */
/*   Updated: 2022/05/14 04:50:46 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rb_tree.hpp"
#include "vector.hpp"
#include <cstdlib>

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

template <typename T>
struct identity
{
	T&	operator()(T& x) const { return (x); };
	const T&	operator()(const T& x) const { return (x); };
};

typedef	ft::rb_tree<int, int, identity<int>, less<int> >	setRbTree;
typedef ft::rb_node<int>									setRbNode;
typedef ft::vector<int>										setFtVec;
typedef setRbTree::iterator									iterator;
typedef setRbTree::reverse_iterator							reviterator;

static int		randomInt( int max ) {
	return (rand() % max * (rand() % 2? 1: -1));
}

static void	vectorSort( setFtVec& vec ) {

	setFtVec::size_type	temp = 0;
	setFtVec::size_type	i = 0;
	setFtVec::size_type	j = vec.size() - 1;

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

void	test_rb_set_reverse_iterator( void )
{
	srand(18);
	setRbTree	tree;
	setFtVec	vec;
	int			size = 20;

	for (int i = 0; i < size; i++)
	{
		vec.push_back(randomInt(20));
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
		std::cout << "Node Constructor     |✅" << std::endl;
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
		std::cout << (*revit1 == 19 ?"✅":"❌");
		std::cout << (*revit2 == 19 ?"✅":"❌");
		std::cout << (*revit3 == -3 ?"✅":"❌") << std::endl;
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

