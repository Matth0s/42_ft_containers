/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:34:09 by mmoreira          #+#    #+#             */
/*   Updated: 2022/05/12 19:36:53 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rb_tree.hpp"
#include "utility.hpp"
#include "vector.hpp"
#include <cstdlib>

template <class KeyOfValue, class Node>
void	printRbTree( Node node, Node null, int level) {
	if (node != null)
	{
		printRbTree<KeyOfValue, Node>(node->left, null, level + 1);
		if (node->left != null) std::cout << "  <";

		if (node->color == RED) std::cout << "\033[31m";
		std::cout << "({" << level << "} " << KeyOfValue()(node->data) << ")";
		std::cout << "\033[0m";

		if (node->right != null) std::cout << ">  ";
		printRbTree<KeyOfValue, Node>(node->right, null, level + 1);
	}
};

template <class Node>
void	checkDoubleRed( Node node, Node null,	bool& doubleRed ) {
	if (node != null)
	{
		if (node->color == RED && node->parent->color == RED)
			doubleRed = true;
		checkDoubleRed(node->left, null, doubleRed);
		checkDoubleRed(node->right, null, doubleRed);
	}
};

template <class Node>
void	checkBlackNodes( Node node, Node null, int* nullNodes,
							int branchBlackNodes, int* totalBlackNodes ) {
	if (node != null)
	{
		if (node->color == BLACK)
			branchBlackNodes++;
		checkBlackNodes(node->left, null, nullNodes,
						branchBlackNodes, totalBlackNodes);
		checkBlackNodes(node->right, null, nullNodes,
						branchBlackNodes, totalBlackNodes);
	}
	else
	{
		(*totalBlackNodes) += branchBlackNodes;
		(*nullNodes)++;
	}
};

template <class Node>
bool	checkRbTree( Node root, Node null ) {
	Node	node = NULL;
	bool	doubleRed = false;
	int		height = 0;
	int		nullNodes = 0;
	int		totalBlackNodes = 0;

	if (root->color != BLACK)
		return (false);

	checkDoubleRed(root, null, doubleRed);
	if (doubleRed)
		return (false);

	node = root;
	while (node != null)
	{
		if (node->color == BLACK)
			height++;
		node = node->left;
	}
	checkBlackNodes(root, null, &nullNodes, 0, &totalBlackNodes);
	if (totalBlackNodes / nullNodes != height)
		return (false);
	return (true);
};

namespace setSpace
{
	template <typename T>
	struct identity
	{
		T&	operator()(T& __x) const { return __x; };
		const T&	operator()(const T& __x) const { return __x; };
	};

	template <class Arg1, class Arg2, class Result>
	struct binary_function
	{
		typedef Arg1	first_argument_type;
		typedef Arg2	second_argument_type;
		typedef Result	result_type;
	};

	template <class T>
	struct less: binary_function<T, T, bool>
	{
		bool	operator()(const T& x, const T& y) const {
			return (x < y);
		}
	};
}

typedef	ft::rb_tree<int, int,
		setSpace::identity<int>,
		setSpace::less<int> >				setRbTree;
typedef ft::rb_node<int>					setRbNode;
typedef ft::vector<int>						setFtVec;


namespace mapSpace
{
	template<class Arg, class Result>
	struct unary_function
	{
		typedef Arg		argument_type;
		typedef Result	result_type;
	};

	template <class Pair>
	struct select1st: public unary_function<Pair, typename Pair::first_type>
	{
		typename Pair::first_type&	operator()( Pair& __x ) const {
			return __x.first;
		};

		const typename Pair::first_type&	operator()( const Pair& __x) const {
			return __x.first;
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
}

typedef	ft::pair<std::string, int>				mapPair;

typedef	ft::rb_tree<std::string, mapPair,
		mapSpace::select1st<mapPair>,
		mapSpace::less<std::string> >			mapRbTree;
typedef ft::rb_node<mapPair>					mapRbNode;
typedef ft::vector<mapPair>						mapFtVec;

std::string	randomString( int len ) {
	std::string	str;

	while (len--)
		str.push_back('A' + (rand() % 26) + (rand() % 2 ? 32 : 0));
	return (str);
}

int		randomInt( int max ) {
	return (rand() % max * (rand() % 2? 1: -1));
}

int	main( void )
{
	std::cout << "set tests" << std::endl;
	{
		int		size = 50;
		std::cout << "   (1)" << std::endl;
		{
			srand(1);
			setFtVec	vec;
			setRbTree	tree;
			int		index;

			std::cout << "   insert()           |";
			for (int i = 0; i < size; i++)
			{
				vec.push_back(randomInt(34523));
				tree.insert(vec[i]);
				std::cout << (checkRbTree(tree.root(), tree.null())?"✅":"❌");
			}
			std::cout << std::endl;

			std::cout << "   serach()           |";
			for (int i = 0; i < size; i++)
			{
				index = rand() % size;
				std::cout << (tree.search(vec[index])->data == vec[index]?"✅":"❌");
			}
			std::cout << std::endl;

			std::cout << "   delete()           |";
			for (int i = 0; i < size; i++)
			{
				tree.erase(tree.root()->data);
				std::cout << (checkRbTree(tree.root(), tree.null())?"✅":"❌");
			}
			std::cout << std::endl;
		}

		std::cout << std::endl;

		std::cout << "   (2)";
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
				std::cout << (checkRbTree(tree.root(), tree.null())?"✅":"❌");
			}
			std::cout << std::endl;

			std::cout << "   delete()           |";
			for (int i = 0; i < size; i++)
			{
				tree.erase(setRbNode::min(tree.root(), tree.null())->data);
				std::cout << (checkRbTree(tree.root(), tree.null())?"✅":"❌");
			}
			std::cout << std::endl;
		}

		std::cout << std::endl;

		std::cout << "   (3)";
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
				std::cout << (checkRbTree(tree.root(), tree.null())?"✅":"❌");
			}
			std::cout << std::endl;

			std::cout << "   delete()           |";
			for (int i = 0; i < size; i++)
			{
				tree.erase(setRbNode::max(tree.root(), tree.null())->data);
				std::cout << (checkRbTree(tree.root(), tree.null())?"✅":"❌");
			}
			std::cout << std::endl;
		}

		std::cout << std::endl;

		std::cout << "   (4)";
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
				std::cout << (checkRbTree(tree.root(), tree.null())?"✅":"❌");
			}
			std::cout << std::endl;

			std::cout << "   delete()           |";
			vec2 = vec1;
			while (vec2.size())
			{
				it = vec2.begin() + rand() % vec2.size();
				tree.erase(*it);
				vec2.erase(it);
				std::cout << (checkRbTree(tree.root(), tree.null())?"✅":"❌");
			}
			std::cout << std::endl;
		}

		std::cout << std::endl;

		std::cout << "   Print Tree" << std::endl;
		{
			srand(6);
			int	lenght = 10;
			setRbTree	tree;

			for (int i = 0; i < lenght; i++)
				tree.insert(randomInt(20));
			printRbTree<setSpace::identity<int>, setRbNode*>(tree.root(), tree.null(), 0);
			std::cout << std::endl;
		}
	}

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "map tests" << std::endl;
	{
		int		size = 50;

		mapRbTree	tree;
		mapFtVec	vec;

		tree.insert(mapPair(randomString(10),randomInt(21574)));
		vec.push_back(mapPair(randomString(10),randomInt(21574)));
		std::cout << (checkRbTree(tree.root(), tree.null())?"✅":"❌");
		std::cout << std::endl;

		std::cout << "   (1)" << std::endl;
		{
			srand(7);
			mapFtVec	vec;
			mapRbTree	tree;
			int			index;

			std::cout << "   insert()           |";
			for (int i = 0; i < size; i++)
			{
				vec.push_back(mapPair(randomString(1 + (rand()%10)),randomInt(453534)));
				tree.insert(vec[i]);
				std::cout << (checkRbTree(tree.root(), tree.null())?"✅":"❌");
			}
			std::cout << std::endl;

			std::cout << "   serach()           |";
			for (int i = 0; i < size; i++)
			{
				index = rand() % size;
				std::cout << (tree.search(vec[index].first)->data == vec[index]?"✅":"❌");
			}
			std::cout << std::endl;

			std::cout << "   delete()           |";
			for (int i = 0; i < size; i++)
			{
				tree.erase(tree.root()->data);
				std::cout << (checkRbTree(tree.root(), tree.null())?"✅":"❌");
			}
			std::cout << std::endl;
		}

		std::cout << std::endl;

		std::cout << "   (2)";
		{
			srand(8);
			mapFtVec			vec1;
			mapFtVec			vec2;
			mapRbTree			tree;
			mapFtVec::iterator	it;

			for (int i = 0; i < size; i++)
				vec1.push_back(mapPair(randomString(1 + (rand()%10)),randomInt(2543245)));
			std::cout << std::endl;

			std::cout << "   insert()           |";
			vec2 = vec1;
			while (vec2.size())
			{
				it = vec2.begin() + rand() % vec2.size();
				tree.insert(*it);
				vec2.erase(it);
				std::cout << (checkRbTree(tree.root(), tree.null())?"✅":"❌");
			}
			std::cout << std::endl;

			std::cout << "   delete()           |";
			for (int i = 0; i < size; i++)
			{
				tree.erase(mapRbNode::min(tree.root(), tree.null())->data);
				std::cout << (checkRbTree(tree.root(), tree.null())?"✅":"❌");
			}
			std::cout << std::endl;
		}

		std::cout << std::endl;

		std::cout << "   (3)";
		{
			srand(9);
			mapFtVec			vec1;
			mapFtVec			vec2;
			mapRbTree			tree;
			mapFtVec::iterator	it;

			for (int i = 0; i < size; i++)
				vec1.push_back(mapPair(randomString(1 + (rand()%10)),randomInt(735345)));
			std::cout << std::endl;

			std::cout << "   insert()           |";
			vec2 = vec1;
			while (vec2.size())
			{
				it = vec2.begin() + rand() % vec2.size();
				tree.insert(*it);
				vec2.erase(it);
				std::cout << (checkRbTree(tree.root(), tree.null())?"✅":"❌");
			}
			std::cout << std::endl;

			std::cout << "   delete()           |";
			for (int i = 0; i < size; i++)
			{
				tree.erase(mapRbNode::max(tree.root(), tree.null())->data);
				std::cout << (checkRbTree(tree.root(), tree.null())?"✅":"❌");
			}
			std::cout << std::endl;
		}

		std::cout << std::endl;

		std::cout << "   (4)";
		{
			srand(10);
			mapFtVec			vec1;
			mapFtVec			vec2;
			mapRbTree			tree;
			mapFtVec::iterator	it;

			for (int i = 0; i < size; i++)
				vec1.push_back(mapPair(randomString(1 + (rand()%10)),randomInt(6546435)));
			std::cout << std::endl;

			std::cout << "   insert()           |";
			vec2 = vec1;
			while (vec2.size())
			{
				it = vec2.begin() + rand() % vec2.size();
				tree.insert(*it);
				vec2.erase(it);
				std::cout << (checkRbTree(tree.root(), tree.null())?"✅":"❌");
			}
			std::cout << std::endl;

			std::cout << "   delete()           |";
			vec2 = vec1;
			while (vec2.size())
			{
				it = vec2.begin() + rand() % vec2.size();
				tree.erase(*it);
				vec2.erase(it);
				std::cout << (checkRbTree(tree.root(), tree.null())?"✅":"❌");
			}
			std::cout << std::endl;
		}

		std::cout << std::endl;

		std::cout << "   Print Tree" << std::endl;
		{
			srand(12);
			int	lenght = 10;
			mapRbTree	tree;

			for (int i = 0; i < lenght; i++)
				tree.insert(mapPair(randomString(1 + (rand()%10)),randomInt(964565)));
			printRbTree<mapSpace::select1st<mapPair>, mapRbNode*>(tree.root(), tree.null(), 0);
			std::cout << std::endl;
		}
	}

	return (0);
}
