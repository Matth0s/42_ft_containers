/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 23:36:32 by mmoreira          #+#    #+#             */
/*   Updated: 2022/05/14 00:50:50 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef STD
	#include <stack>
	#include <iostream>
	namespace ft = std;
#else
	#include "stack.hpp"
#endif

#include <deque>
#include <list>
#include <cstdlib>

void	test_stack( void )
{
	{
		ft::stack<int>						st1;
		ft::stack<int, std::list<int> >		st2;
		ft::stack<int, std::deque<int> >	st3;

		std::cout << "Default Constructor   |✅" << std::endl;
	}

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
