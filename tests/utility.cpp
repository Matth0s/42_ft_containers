/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 04:53:00 by mmoreira          #+#    #+#             */
/*   Updated: 2022/04/21 18:27:59 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if 0
	#include <utility>
	namespace ft = std;
#else
	#include "utility.hpp"
#endif

#include <iostream>

int	main( void )
{
	try {
		ft::pair<int, std::string> pr;
		std::cout << "Default Constructor         |✅" << std::endl;
	} catch(std::exception& ex)	{
		std::cout << "Default Constructor         |❌" << std::endl;
		std::cout << ex.what() << std::endl;
	}

	try {
		ft::pair<int, std::string> pr(8, "olha");
		std::cout << "Initialization Constructor  |✅" << std::endl;
	} catch(std::exception& ex) {
		std::cout << "Initialization Constructor  |❌" << std::endl;
		std::cout << ex.what() << std::endl;
	}

	try {
		ft::pair<int, std::string> pr1(8, "olha");
		ft::pair<int, std::string> pr2(pr1);
		std::cout << "Copy Constructor            |✅" << std::endl;
	} catch(std::exception& ex) {
		std::cout << "Copy Constructor            |❌" << std::endl;
		std::cout << ex.what() << std::endl;
	}

	try {
		ft::pair<int, std::string> pr1(8, "olha");
		ft::pair<int, std::string> pr2;
		pr2 = pr1;
		if ((pr1.first == pr2.first) && (pr1.second == pr2.second))
			std::cout << "Assignment Operator         |✅" << std::endl;
	} catch(std::exception& ex) {
		std::cout << "Assignment Operator         |❌" << std::endl;
		std::cout << ex.what() << std::endl;
	}


	try {
		ft::pair<double, std::string> pr1 = ft::make_pair(18.33, "a");
		pr1 = ft::make_pair(23.33, "adasdad");
		ft::pair<int, int> pr2 = ft::make_pair(33, 22);
		pr2 = ft::make_pair(4, 3242342);
		ft::pair<std::string, float> pr3 = ft::make_pair("avasa", 2.7f);
		pr3 = ft::make_pair("ppefds", 4324.2342f);
		ft::pair<unsigned char, unsigned int> pr4 = ft::make_pair('m', 0);
		pr4 = ft::make_pair('n', 342342342);
		std::cout << "ft::make_pair               |✅" << std::endl;
	} catch(std::exception& ex) {
		std::cout << "ft::make_pair               |❌" << std::endl;
		std::cout << ex.what() << std::endl;
	}

	std::cout << std::endl;

	ft::pair<int, std::string> pr1(5, "a");
	ft::pair<int, std::string> pr2(5, "a");
	ft::pair<int, std::string> pr3(8, "a");
	ft::pair<int, std::string> pr4(8, "b");

	std::cout << "operator ==  |";
	std::cout << (pr1 == pr1 ?"✅":"❌");
	std::cout << (pr1 == pr2 ?"✅":"❌");
	std::cout << (pr2 == pr3 ?"❌":"✅") << std::endl;

	std::cout << "operator !=  |";
	std::cout << (pr1 != pr1 ?"❌":"✅");
	std::cout << (pr1 != pr2 ?"❌":"✅");
	std::cout << (pr2 != pr3 ?"✅":"❌") << std::endl;

	std::cout << "operator <   |";
	std::cout << (pr1 < pr1 ?"❌":"✅");
	std::cout << (pr1 < pr2 ?"❌":"✅");
	std::cout << (pr2 < pr3 ?"✅":"❌") << std::endl;

	std::cout << "operator <=  |";
	std::cout << (pr1 <= pr2 ?"✅":"❌");
	std::cout << (pr3 <= pr2 ?"❌":"✅");
	std::cout << (pr4 <= pr3 ?"❌":"✅") << std::endl;

	std::cout << "operator >   |";
	std::cout << (pr1 > pr2 ?"❌":"✅");
	std::cout << (pr3 > pr2 ?"✅":"❌");
	std::cout << (pr3 > pr4 ?"❌":"✅") << std::endl;

	std::cout << "operator >=  |";
	std::cout << (pr1 >= pr1 ?"✅":"❌");
	std::cout << (pr2 >= pr3 ?"❌":"✅");
	std::cout << (pr4 >= pr3 ?"✅":"❌") << std::endl;

	return (0);
}
