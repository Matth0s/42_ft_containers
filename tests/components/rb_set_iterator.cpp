/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_set_iterator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 19:57:59 by mmoreira          #+#    #+#             */
/*   Updated: 2022/05/20 06:02:31 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rb_tree.hpp"
#include "functional.hpp"
#include "vector.hpp"
#include <cstdlib>

typedef	ft::rb_tree<int, int,
		ft::identity<int>,
		ft::less<int> >			setRbTree;
typedef ft::rb_node<int>		setRbNode;
typedef ft::vector<int>			setFtVec;
typedef setRbTree::iterator		iterator;

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

void	test_rb_set_iterator( void )
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

	{
		iterator it;
		std::cout << "Default Constructor  |✅" << std::endl;
	}

	{
		iterator it1(setRbNode::min(tree.root(), tree.null()), tree.null());
		std::cout << "Node Constructor     |✅" << std::endl;
	}

	{
		iterator it1(setRbNode::min(tree.root(), tree.null()), tree.null());
		iterator it2(it1);
		(void) it2;
		std::cout << "Copy Constructor     |✅" << std::endl;
	}

	{
		iterator it1(setRbNode::min(tree.root(), tree.null()), tree.null());
		iterator it2;
		it2 = it1;
		if (*it1 == *it2)
			std::cout << "Assignment Operator  |✅" << std::endl;
	}

	iterator it1(setRbNode::min(tree.root(), tree.null()), tree.null());
	iterator it2(setRbNode::min(tree.root(), tree.null()), tree.null());
	iterator it3(tree.root(), tree.null());

	std::cout << std::endl;

	std::cout << "operator *   |";
	{
		std::cout << (*it1 == -18 ?"✅":"❌");
		std::cout << (*it2 == -18 ?"✅":"❌");
		std::cout << (*it3 == -2 ?"✅":"❌") << std::endl;
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
	for (setFtVec::size_type i = 0; i < vec.size(); i++)
	{
		std::cout << (*it1 == vec[i] ?"✅":"❌");
		it1++;
	}
	std::cout << std::endl;
	it1--;
	std::cout << "operator --  |";
	for (setFtVec::size_type i = vec.size() - 1; i > 0; i--)
	{
		std::cout << (*it1 == vec[i] ?"✅":"❌");
		it1--;
	}
	std::cout << (*it1 == vec[0] ?"✅":"❌");
	std::cout << std::endl;
}
