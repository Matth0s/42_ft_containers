/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_set.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 20:05:17 by mmoreira          #+#    #+#             */
/*   Updated: 2022/05/25 14:17:58 by mmoreira         ###   ########.fr       */
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

void	test_rb_set( void )
{
	int		size = 50;

	std::cout << "(1)" << std::endl;
	{
		srand(1);
		setFtVec	vec;
		setRbTree	tree;

		std::cout << "   insert()           |";
		for (int i = 0; i < size; i++)
		{
			vec.push_back(randomInt(34523));
			tree.insert(vec[i]);
			std::cout << (ft::checkRbTree(tree.root(), tree.null())?"✅":"❌");
		}
		std::cout << std::endl;

		std::cout << "   delete()           |";
		for (int i = 0; i < size; i++)
		{
			tree.erase(tree.root()->data);
			std::cout << (ft::checkRbTree(tree.root(), tree.null())?"✅":"❌");
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	std::cout << "(2)";
	{
		srand(2);
		setFtVec			vec1;
		setFtVec			vec2;
		setRbTree			tree;
		setFtVec::iterator	it;

		for (int i = 0; i < size; i++)
			vec1.push_back(randomInt(21574));
		std::cout << std::endl;

		std::cout << "   insert()           |";
		vec2 = vec1;
		while (vec2.size())
		{
			it = vec2.begin() + rand() % vec2.size();
			tree.insert(*it);
			vec2.erase(it);
			std::cout << (ft::checkRbTree(tree.root(), tree.null())?"✅":"❌");
		}
		std::cout << std::endl;

		std::cout << "   delete()           |";
		for (int i = 0; i < size; i++)
		{
			tree.erase(setRbNode::min(tree.root(), tree.null())->data);
			std::cout << (ft::checkRbTree(tree.root(), tree.null())?"✅":"❌");
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	std::cout << "(3)";
	{
		srand(3);
		setFtVec			vec1;
		setFtVec			vec2;
		setRbTree			tree;
		setFtVec::iterator	it;

		for (int i = 0; i < size; i++)
			vec1.push_back(randomInt(134234));
		std::cout << std::endl;

		std::cout << "   insert()           |";
		vec2 = vec1;
		while (vec2.size())
		{
			it = vec2.begin() + rand() % vec2.size();
			tree.insert(*it);
			vec2.erase(it);
			std::cout << (ft::checkRbTree(tree.root(), tree.null())?"✅":"❌");
		}
		std::cout << std::endl;

		std::cout << "   delete()           |";
		for (int i = 0; i < size; i++)
		{
			tree.erase(setRbNode::max(tree.root(), tree.null())->data);
			std::cout << (ft::checkRbTree(tree.root(), tree.null())?"✅":"❌");
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	std::cout << "(4)";
	{
		srand(4);
		setFtVec			vec1;
		setFtVec			vec2;
		setRbTree			tree;
		setFtVec::iterator	it;

		for (int i = 0; i < size; i++)
			vec1.push_back(randomInt(357977));
		std::cout << std::endl;

		std::cout << "   insert()           |";
		vec2 = vec1;
		while (vec2.size())
		{
			it = vec2.begin() + rand() % vec2.size();
			tree.insert(*it);
			vec2.erase(it);
			std::cout << (ft::checkRbTree(tree.root(), tree.null())?"✅":"❌");
		}
		std::cout << std::endl;

		std::cout << "   delete()           |";
		vec2 = vec1;
		while (vec2.size())
		{
			it = vec2.begin() + rand() % vec2.size();
			tree.erase(*it);
			vec2.erase(it);
			std::cout << (ft::checkRbTree(tree.root(), tree.null())?"✅":"❌");
		}
		std::cout << std::endl;
	}

	// std::cout << std::endl;

	// std::cout << "   Print Tree" << std::endl;
	// {
	// 	srand(6);
	// 	int	lenght = 10;
	// 	setRbTree	tree;

	// 	for (int i = 0; i < lenght; i++)
	// 		tree.insert(randomInt(20));
	// 	ft::printRbTree<ft::identity<int>, setRbNode*>(tree.root(), tree.null(), 0);
	// 	std::cout << std::endl;
	// }
}
