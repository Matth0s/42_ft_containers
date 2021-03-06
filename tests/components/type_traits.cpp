/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 23:39:49 by mmoreira          #+#    #+#             */
/*   Updated: 2022/05/14 00:30:48 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type_traits.hpp"
#include "normal_iterator.hpp"

void	test_type_traits( void )
{
	std::cout << "bool                       |" << (ft::is_integral<bool>::value? "✅": "❌") << std::endl;
	std::cout << "char                       |" << (ft::is_integral<char>::value? "✅": "❌") << std::endl;
	std::cout << "wchar_t                    |" << (ft::is_integral<wchar_t>::value? "✅": "❌") << std::endl;
	std::cout << "signed char                |" << (ft::is_integral<signed char>::value? "✅": "❌") << std::endl;
	std::cout << "short int                  |" << (ft::is_integral<short int>::value? "✅": "❌") << std::endl;
	std::cout << "int                        |" << (ft::is_integral<int>::value? "✅": "❌") << std::endl;
	std::cout << "long int                   |" << (ft::is_integral<long int>::value? "✅": "❌") << std::endl;
	std::cout << "long long int              |" << (ft::is_integral<long long int>::value? "✅": "❌") << std::endl;
	std::cout << "unsigned char              |" << (ft::is_integral<signed char>::value? "✅": "❌") << std::endl;
	std::cout << "unsigned short int         |" << (ft::is_integral<short int>::value? "✅": "❌") << std::endl;
	std::cout << "unsigned int               |" << (ft::is_integral<int>::value? "✅": "❌") << std::endl;
	std::cout << "unsigned long int          |" << (ft::is_integral<long int>::value? "✅": "❌") << std::endl;
	std::cout << "unsigned long long int     |" << (ft::is_integral<long long int>::value? "✅": "❌") << std::endl;
	std::cout << "std::string                |" << (ft::is_integral<std::string>::value? "❌": "✅") << std::endl;
	std::cout << "ft::normal_iterator<int>   |" << (ft::is_integral<ft::normal_iterator<int*> >::value? "❌": "✅") << std::endl;
}
