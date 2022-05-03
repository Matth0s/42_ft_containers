/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 23:36:32 by mmoreira          #+#    #+#             */
/*   Updated: 2022/04/28 13:31:08 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if 0
	#include <stack>
	namespace ft = std;
#else
	#include "stack.hpp"
#endif

#include <deque>
#include <list>

#include <iostream>
#include <cstdlib>

int	main ( void )
{
	try {
		ft::stack<int>						st1;
		ft::stack<int, std::list<int> >		st2;
		ft::stack<int, std::deque<int> >	st3;

		std::cout << "Default Constructor   |✅" << std::endl;
	} catch(std::exception& ex)	{
		std::cout << "Default Constructor   |❌" << std::endl;
		std::cout << ex.what() << std::endl;
	}
	return (0);

	ft::stack<int>						st1;
	ft::stack<int, std::list<int> >		st2;
	ft::stack<int, std::deque<int> >	st3;

	st1.empty();
	st2.empty();
	st3.empty();

	st1.push(rand() % 100);
	st2.push(rand() % 100);
	st3.push(rand() % 100);

	st1.size();
	st2.size();
	st3.size();

	st1.push(rand() % 100);
	st2.push(rand() % 100);
	st3.push(rand() % 100);

	st1.size();
	st2.size();
	st3.size();

	st1.pop();
	st2.pop();
	st3.pop();

	st1.size();
	st2.size();
	st3.size();

	st1.push(rand() % 100);
	st2.push(rand() % 100);
	st3.push(rand() % 100);

	st1.top();
	st2.top();
	st3.top();

	st1.push(rand() % 100);
	st2.push(rand() % 100);
	st3.push(rand() % 100);

	st1.size();
	st2.size();
	st3.size();

	st1.push(rand() % 100);
	st2.push(rand() % 100);
	st3.push(rand() % 100);

	st1.top();
	st2.top();
	st3.top();

	st1.push(rand() % 100);
	st2.push(rand() % 100);
	st3.push(rand() % 100);

	st1.size();
	st2.size();
	st3.size();

	st1.top();
	st2.top();
	st3.top();

	st1.pop();
	st2.pop();
	st3.pop();

	st1.pop();
	st2.pop();
	st3.pop();

	st1.pop();
	st2.pop();
	st3.pop();

	st1.pop();
	st2.pop();
	st3.pop();

	st1.size();
	st2.size();
	st3.size();
}
