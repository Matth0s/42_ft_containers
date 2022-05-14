/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 23:31:59 by mmoreira          #+#    #+#             */
/*   Updated: 2022/05/14 01:51:00 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "teste.hpp"
#include <ctime>

int	main( int argc, char *argv[] )
{
	std::string	str;
	clock_t	t = clock();

	if (argc != 1)
		str = *(argv + 1);
	else
		str = "all";

	std::cout << std::endl << std::endl << std::endl;
	if (str == "all" || str == "normiter")
	{
		std::cout << "*****  Normal Iterator Tests  *******" << std::endl;
		test_normal_iterator();
		std::cout << "*************************************" << std::endl;
		std::cout << std::endl << std::endl << std::endl;
	}

	if (str == "all" || str == "normreviter")
	{
		std::cout << "**  Normal Reverse Iterator Tests  **" << std::endl;
		test_normal_reverse_iterator();
		std::cout << "*************************************" << std::endl;
		std::cout << std::endl << std::endl << std::endl;
	}

	if (str == "all" || str == "typetraits")
	{
		std::cout << "*******  Type Traits Tests  ********" << std::endl;
		test_type_traits();
		std::cout << "*************************************" << std::endl;
		std::cout << std::endl << std::endl << std::endl;
	}

	if (str == "all" || str == "utility")
	{
		std::cout << "**********  Utility Tests  **********" << std::endl;
		test_utility();
		std::cout << "*************************************" << std::endl;
		std::cout << std::endl << std::endl << std::endl;
	}

	if (str == "all" || str == "algorithm")
	{
		std::cout << "*********  Algorithm Tests  *********" << std::endl;
		test_algorithm();
		std::cout << "*************************************" << std::endl;
		std::cout << std::endl << std::endl << std::endl;
	}

	if (str == "all" || str == "vector")
	{
		std::cout << "***********  Vector Tests  **********" << std::endl;
		test_vector();
		std::cout << "*************************************" << std::endl;
		std::cout << std::endl << std::endl << std::endl;
	}

	if (str == "all" || str == "stack")
	{
		std::cout << "***********  Stack Tests  ***********" << std::endl;
		test_stack();
		std::cout << "*************************************" << std::endl;
		std::cout << std::endl << std::endl << std::endl;
	}

	if (str == "all" || str == "rbmap")
	{
		std::cout << "**********  RB Map Tests  ***********" << std::endl;
		test_rb_map();
		std::cout << "*************************************" << std::endl;
		std::cout << std::endl << std::endl << std::endl;
	}

	if (str == "all" || str == "rbset")
	{
		std::cout << "**********  RB Set Tests  ***********" << std::endl;
		test_rb_set();
		std::cout << "*************************************" << std::endl;
		std::cout << std::endl << std::endl << std::endl;
	}

	if (str == "all" || str == "rbmapiter")
	{
		std::cout << "*****  RB Map Iterator Tests  *******" << std::endl;
		test_rb_map_iterator();
		std::cout << "*************************************" << std::endl;
		std::cout << std::endl << std::endl << std::endl;
	}

	if (str == "all" || str == "rbsetiter")
	{
		std::cout << "*****  RB Set Iterator Tests  *******" << std::endl;
		test_rb_set_iterator();
		std::cout << "*************************************" << std::endl;
		std::cout << std::endl << std::endl << std::endl;
	}

	t = clock() - t;
	std::cout << static_cast<double>(t) << std::endl;
}
