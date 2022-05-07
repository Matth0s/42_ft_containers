/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:34:09 by mmoreira          #+#    #+#             */
/*   Updated: 2022/05/07 14:13:48 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rb_tree.hpp"

#include <cstdlib>

int	main( int argc, char* argv[] )
{
	(void) argv;
	(void) argc;
	ft::rb_tree	arvore;
	srand(0);

	for (int i = 0; i < argc; i++)
	{
		arvore.print();	std::cout << (arvore.checkRB()?"  ✅": "  ❌") << std::endl << std::flush;
		arvore.insert(rand() % 50);
	}
	std::cout << std::endl;
arvore.print();	std::cout << (arvore.checkRB()?"  ✅": "  ❌") << std::endl << std::flush;	arvore.print();	std::cout << std::endl << std::flush;
arvore.print();	std::cout << (arvore.checkRB()?"  ✅": "  ❌") << std::endl << std::flush;	for (int i = 0; i < argc-10; i++)
	{
		arvore.erase(arvore.rootValue());
		arvore.print();	std::cout << (arvore.checkRB()?"  ✅": "  ❌") << std::endl << std::flush;
	}
	return (0);
}
