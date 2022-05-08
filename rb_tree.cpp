/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:34:09 by mmoreira          #+#    #+#             */
/*   Updated: 2022/05/08 23:02:04 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if 0
	#include <vector>
	namespace ft = std;
#else
	#include "vector.hpp"
#endif

#include "rb_tree.hpp"
#include <cstdlib>

int	main( void )
{
	{
		srand(0);
		ft::rb_tree	arvore;
		ft::rb_tree	tree;

		ft::vector<
		for (int i = 0; i < argc; i++)
		{
			arvore.print();
			std::cout << (arvore.checkRB()?"  ✅": "  ❌") << std::endl << std::flush;
			arvore.insert(rand() % 50);
		}

		std::cout << std::endl;
		arvore.print();	std::cout << (arvore.checkRB()?"  ✅": "  ❌") << std::endl << std::flush;
		arvore.print();	std::cout << (arvore.checkRB()?"  ✅": "  ❌") << std::endl << std::flush;
		std::cout << std::endl;

		for (int i = 0; i < argc; i++)
		{
			arvore.erase(arvore.rootValue());
			arvore.print();
			std::cout << (arvore.checkRB()?"  ✅": "  ❌") << std::endl << std::flush;
		}
	}

	{
		srand(1);
		ft::rb_tree	tree;
	}

	{
		srand(2);
		ft::rb_tree	tree;
	}
	return (0);
}
