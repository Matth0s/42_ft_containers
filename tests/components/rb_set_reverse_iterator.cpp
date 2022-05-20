/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_set_reverse_iterator.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 04:35:42 by mmoreira          #+#    #+#             */
/*   Updated: 2022/05/20 06:02:43 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rb_tree.hpp"
#include "functional.hpp"
#include "vector.hpp"
#include <cstdlib>

typedef	ft::rb_tree<int, int,
		ft::identity<int>,
		ft::less<int> >				setRbTree;
typedef ft::rb_node<int>			setRbNode;
typedef ft::vector<int>				setFtVec;
typedef setRbTree::iterator			iterator;
typedef setRbTree::reverse_iterator	reviterator;

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
	vectorUnique(vec, int());

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
	for (setFtVec::size_type i = 0; i < vec.size(); i++)
	{
		std::cout << (*revit1 == vec[i] ?"✅":"❌");
		revit1++;
	}
	std::cout << std::endl;
	revit1--;
	std::cout << "operator --  |";
	for (setFtVec::size_type i = vec.size() - 1; i > 0; i--)
	{
		std::cout << (*revit1 == vec[i] ?"✅":"❌");
		revit1--;
	}
	std::cout << (*revit1 == vec[0] ?"✅":"❌");
	std::cout << std::endl;
}

