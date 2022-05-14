/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_map.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 20:19:41 by mmoreira          #+#    #+#             */
/*   Updated: 2022/05/14 01:04:56 by mmoreira         ###   ########.fr       */
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

static std::string	randomString( int len ) {
	std::string	str;

	while (len--)
		str.push_back('A' + (rand() % 26) + (rand() % 2 ? 32 : 0));
	return (str);
}

static int		randomInt( int max ) {
	return (rand() % max * (rand() % 2? 1: -1));
}

void	test_rb_map( void )
{
	{
		int		size = 50;

		std::cout << "(1)" << std::endl;
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
				std::cout << (ft::checkRbTree(tree.root(), tree.null())?"✅":"❌");
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
				std::cout << (ft::checkRbTree(tree.root(), tree.null())?"✅":"❌");
			}
			std::cout << std::endl;
		}

		std::cout << std::endl;

		std::cout << "(2)";
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
				std::cout << (ft::checkRbTree(tree.root(), tree.null())?"✅":"❌");
			}
			std::cout << std::endl;

			std::cout << "   delete()           |";
			for (int i = 0; i < size; i++)
			{
				tree.erase(mapRbNode::min(tree.root(), tree.null())->data);
				std::cout << (ft::checkRbTree(tree.root(), tree.null())?"✅":"❌");
			}
			std::cout << std::endl;
		}

		std::cout << std::endl;

		std::cout << "(3)";
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
				std::cout << (ft::checkRbTree(tree.root(), tree.null())?"✅":"❌");
			}
			std::cout << std::endl;

			std::cout << "   delete()           |";
			for (int i = 0; i < size; i++)
			{
				tree.erase(mapRbNode::max(tree.root(), tree.null())->data);
				std::cout << (ft::checkRbTree(tree.root(), tree.null())?"✅":"❌");
			}
			std::cout << std::endl;
		}

		std::cout << std::endl;

		std::cout << "(4)";
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

		std::cout << std::endl;

		std::cout << "   Print Tree" << std::endl;
		{
			srand(12);
			int	lenght = 10;
			mapRbTree	tree;

			for (int i = 0; i < lenght; i++)
				tree.insert(mapPair(randomString(1 + (rand()%10)),randomInt(964565)));
			ft::printRbTree<select1st<mapPair>, mapRbNode*>(tree.root(), tree.null(), 0);
			std::cout << std::endl;
		}
	}
}
