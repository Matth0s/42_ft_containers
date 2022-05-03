/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:34:09 by mmoreira          #+#    #+#             */
/*   Updated: 2022/05/03 22:58:17 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rb_tree.hpp"

#include <cstdlib>

int	main( int argc, char* argv[] )
{
	(void) argv;
	ft::rb_tree	arvore;
	srand(0);

	for (int i = 0; i < argc; i++)
	{
		arvore.insert(rand() % 50);
		arvore.print();	std::cout << std::endl << std::flush;
	}

	return (0);
}
