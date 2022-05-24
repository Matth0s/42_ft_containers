

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 03:18:05 by mmoreira          #+#    #+#             */
/*   Updated: 2022/05/24 22:08:59 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <fstream>
#include <ctime>
#include <deque>
#include <list>

#ifdef STD
	#include <vector>
	#include <stack>
	#include <map>
	#include <set>
	namespace ft = std;
#else
	#include "vector.hpp"
	#include "stack.hpp"
	#include "map.hpp"
	#include "set.hpp"
#endif

#include <stdlib.h>

typedef ft::vector<std::string>				vecStr;
typedef ft::vector<int>						vecInt;
typedef ft::map<int, int>					mapInt;
typedef ft::map<std::string, std::string>	mapStr;
typedef ft::set<int>						setInt;
typedef ft::set<std::string>				setStr;


int main(int argc, char** argv)
{

	std::stringstream	ss;
	std::string			str;
	std::string			teste;

	if (argc != 1)
		teste = *(argv + 1);
	else
		teste = "all";

	srand(3);

	std::ofstream		fileOut;
	fileOut.open("log_time", std::ofstream::out | std::fstream::app);
	clock_t	t = clock();

	if (teste == "all" || teste == "vector")
	{
		std::cout << "**************  Vector Tests  *************" << std::endl;
		{
			int		array1[10] = {1,2,3,4,5,6,7,8,9,10};
			int		array2[10] = {-1,-2,-3,-4,-5,-6,-7,-8,-9,-10};

			vecInt	vec1(array1, array1 + 10);
			vecInt	vec2(array2, array2 + 10);

			std::cout << "teste iterator vec1: ";
			vecInt::iterator	it1;
			for (it1 = vec1.begin(); it1 != (vec1.end() - 5); it1++) {
				std::cout << *it1 << "  ";
			}
			vecInt::const_iterator	cit1;
			for (cit1 = it1; cit1 != vec1.end(); cit1++) {
				std::cout << *cit1 << "  ";
			}
			std::cout << std::endl;

			std::cout << "teste iterator vec2: ";
			vecInt::iterator	it2;
			for (it2 = vec2.begin(); it2 != (vec2.end() - 5); it2++) {
				std::cout << *it2 << "  ";
			}
			vecInt::const_iterator	cit2;
			for (cit2 = it2; cit2 != vec2.end(); cit2++) {
				std::cout << *cit2 << "  ";
			}
			std::cout << std::endl;


			it1 = vec1.begin();
			it2 = vec2.begin();
			vec1.swap(vec2);

			std::cout << std::endl;
			std::cout << "teste it1: " << *it1++ << "  " << *it1++ << "  " << *it1++ << std::endl;
			std::cout << "teste it2: " << *it2++ << "  " << *it2++ << "  " << *it2++ << std::endl;

			it1 = vec1.begin();
			it2 = vec2.begin();

			std::cout << std::endl;
			std::cout << "teste it1 pos swap: " << *it1++ << "  " << *it1++ << "  " << *it1++ << std::endl;
			std::cout << "teste it2 pos swap: " << *it2++ << "  " << *it2++ << "  " << *it2++ << std::endl;
		}

		std::cout << std::endl;

		{
			std::cout << "teste de desempenho: ";

			int	i = 5;

			while (i--)
			{
				{
					vecInt	vector_int;

					for (int i = 0; i < 10000; i++)
						vector_int.insert(vector_int.begin(), i);
					while (vector_int.size())
						vector_int.erase(vector_int.begin() + rand() % vector_int.size());
				}
				{
					vecStr	vector_str;

					for (int i = 0; i < 10000; i++) {
						ss << i << " ";
						ss >> str;
						vector_str.insert(vector_str.begin(), str);
					}
					while (vector_str.size())
						vector_str.erase(vector_str.begin() + rand() % vector_str.size());
				}
				std::cout << 5 - i;
				if (i)
					std::cout << ", ";
				else
					std::cout << std::endl;
			}
		}
		std::cout << "*******************************************" << std::endl;
	}

	if (teste == "all" || teste == "stack")
	{
		std::cout << "**************  Stack Tests  *************" << std::endl;
		{
			ft::stack<int>						vec_stack;
			ft::stack<int, std::deque<int> >	deque_stack;
			ft::stack<int, std::list<int> >		list_stack;
			int									number;

			number = 0;
			while (number++ < 10)
			{
				vec_stack.push(number);
				deque_stack.push(number);
				list_stack.push(number);
			}

			std::cout << "tamanho de vec_stack: " << vec_stack.size() << std::endl;
			std::cout << "tamanho de deque_stack: " << deque_stack.size() << std::endl;
			std::cout << "tamanho de list_stack: " << list_stack.size() << std::endl;

			std::cout << std::endl;

			std::cout << "elementos de vec_stack: ";
			number = 0;
			while (number++ < 10)
			{
				std::cout << vec_stack.top();
				vec_stack.pop();
				if (number != 10)
					std::cout << "  ";
				else
					std::cout << std::endl;
			}

			std::cout << "elementos de deque_stack: ";
			number = 0;
			while (number++ < 10)
			{
				std::cout << deque_stack.top();
				deque_stack.pop();
				if (number != 10)
					std::cout << "  ";
				else
					std::cout << std::endl;
			}

			std::cout << "elementos de list_stack: ";
			number = 0;
			while (number++ < 10)
			{
				std::cout << list_stack.top();
				list_stack.pop();
				if (number != 10)
					std::cout << "  ";
				else
					std::cout << std::endl;
			}

			std::cout << std::endl;

			std::cout << "tamanho de vec_stack: " << vec_stack.size() << std::endl;
			std::cout << "tamanho de deque_stack: " << deque_stack.size() << std::endl;
			std::cout << "tamanho de list_stack: " << list_stack.size() << std::endl;

		}

		std::cout << std::endl;

		{
			std::cout << "teste de desempenho: ";

			int	i = 5;

			while (i--)
			{
				{
					ft::stack<int>	stack_int;

					for (int i = 0; i < 100000; i++)
						stack_int.push(i);
					while (stack_int.size())
						stack_int.pop();
				}

				{
					ft::stack<std::string>	stack_str;

					for (int i = 0; i < 100000; i++) {
						ss << i << " ";
						ss >> str;
						stack_str.push(str);
					}
					while (stack_str.size())
						stack_str.pop();
				}
				std::cout << 5 - i;
				if (i)
					std::cout << ", ";
				else
					std::cout << std::endl;
			}
		}
		std::cout << "*******************************************" << std::endl;
	}

	if (teste == "all" || teste == "map")
	{
		std::cout << "***************  Map Tests  **************" << std::endl;
		{
			mapInt	map1;

			std::cout << "tamanho map: " << map1.size() << std::endl;

			map1.insert(ft::make_pair(1,1));
			map1.insert(ft::make_pair(1,1));
			map1.insert(ft::make_pair(1,1));

			std::cout << "tamanho map: " << map1.size() << std::endl;
		}

		std::cout << std::endl;

		{
			mapInt	map1;

			for (int i = 0; i < 10; i++) {
				map1.insert(ft::make_pair(rand() % 1000, i));
			}

			std::cout << "ordenação: ";
			for (mapInt::iterator it = map1.begin(); it != map1.end(); it++)
			{
				std::cout << it->first << "  ";
			}
			std::cout << std::endl;

			mapInt::value_compare	comp = map1.value_comp();

			std::cout << "value_compare: " ;
			try {
				mapInt::iterator	it = map1.begin();
				mapInt::iterator	end = --map1.end();
				while (it != end)
					if (!comp(*it,*++it))
						throw "Não Esta Ordenado!";
				std::cout << "Esta Ordenado" << std::endl;
			} catch( const char* msg ) {
				std::cout << msg << std::endl;
			}

			std::cout << std::endl;

			mapInt::iterator	it = map1.begin();
			it++; it++; it++; it++;

			std::cout << "it antes: " << it-> first << " _ " << it->second << std::endl;

			map1.erase(map1.begin());
			map1.erase(map1.begin());
			map1.insert(ft::make_pair(rand() % 1000, rand() % 1000));

			std::cout << "it depois: " << it-> first << " _ " << it->second << std::endl;
		}

		{
			mapInt	map1;
			mapInt	map2;

			for (int i = 0; i < 10; i++)
			{
				map1.insert(ft::make_pair(i,i));
				map2.insert(ft::make_pair(-i,-i));
			}

			mapInt::iterator	it1 = map1.begin();
			mapInt::iterator	it2 = map2.begin();
			std::cout << std::endl;
			std::cout << "teste it1: " << (it1++)->first << "  " << (it1++)->first << "  " << (it1++)->first << std::endl;
			std::cout << "teste it2: " << (it2++)->first << "  " << (it2++)->first << "  " << (it2++)->first << std::endl;

			it1 = map1.begin();
			it2 = map2.begin();
			map1.swap(map2);

			std::cout << std::endl;
			std::cout << "teste it1: " << (it1++)->first << "  " << (it1++)->first << "  " << (it1++)->first << std::endl;
			std::cout << "teste it2: " << (it2++)->first << "  " << (it2++)->first << "  " << (it2++)->first << std::endl;

			it1 = map1.begin();
			it2 = map2.begin();

			std::cout << std::endl;
			std::cout << "teste it1 pos swap: " << (it1++)->first << "  " << (it1++)->first << "  " << (it1++)->first << std::endl;
			std::cout << "teste it2 pos swap: " << (it2++)->first << "  " << (it2++)->first << "  " << (it2++)->first << std::endl;
		}

		std::cout << std::endl;

		{
			std::cout << "teste de desempenho: ";

			int	i = 5;

			while (i--)
			{
				{
					mapInt		map_int;

					for (int i = 0; i < 100000; i++)
						map_int.insert(ft::make_pair(i, i));
					while (map_int.size())
						map_int.erase(map_int.begin());
				}
				{
					mapStr		map_str;

					for (int i = 0; i < 100000; i++) {
						ss << i << " ";
						ss >> str;
						map_str.insert(ft::make_pair(str, str));
					}
					while (map_str.size())
						map_str.erase(map_str.begin());
				}
				std::cout << 5 - i;
				if (i)
					std::cout << ", ";
				else
					std::cout << std::endl;
			}
		}
		std::cout << "*******************************************" << std::endl;
	}

	if (teste == "all" || teste == "set")
	{
		std::cout << "***************  Set Tests  **************" << std::endl;
		{
			setInt	set1;

			std::cout << "tamanho set: " << set1.size() << std::endl;

			set1.insert(1);
			set1.insert(1);
			set1.insert(1);

			std::cout << "tamanho set: " << set1.size() << std::endl;
		}

		std::cout << std::endl;

		{
			setInt	set1;

			for (int i = 0; i < 10; i++) {
				set1.insert(rand() % 1000);
			}

			std::cout << "ordenação: ";
			for (setInt::iterator it = set1.begin(); it != set1.end(); it++)
			{
				std::cout << *it << "  ";
			}
			std::cout << std::endl;

			setInt::value_compare	comp = set1.value_comp();

			std::cout << "value_compare: " ;
			try {
				setInt::iterator	it = set1.begin();
				setInt::iterator	end = --set1.end();
				while (it != end)
					if (!comp(*it,*++it))
						throw "Não Esta Ordenado!";
				std::cout << "Esta Ordenado" << std::endl;
			} catch( const char* msg ) {
				std::cout << msg << std::endl;
			}

			std::cout << std::endl;

			setInt::iterator	it = set1.begin();
			it++; it++; it++; it++;

			std::cout << "it antes: " << *it << std::endl;

			set1.erase(set1.begin());
			set1.erase(set1.begin());
			set1.insert(rand() % 1000);

			std::cout << "it depois: " << *it << std::endl;
		}

		{
			setInt	set1;
			setInt	set2;

			for (int i = 0; i < 10; i++)
			{
				set1.insert(i);
				set2.insert(-i);
			}

			setInt::iterator	it1 = set1.begin();
			setInt::iterator	it2 = set2.begin();
			std::cout << std::endl;
			std::cout << "teste it1: " << *it1++ << "  " << *it1++ << "  " << *it1++ << std::endl;
			std::cout << "teste it2: " << *it2++ << "  " << *it2++ << "  " << *it2++ << std::endl;

			it1 = set1.begin();
			it2 = set2.begin();
			set1.swap(set2);

			std::cout << std::endl;
			std::cout << "teste it1: " << *it1++ << "  " << *it1++ << "  " << *it1++ << std::endl;
			std::cout << "teste it2: " << *it2++ << "  " << *it2++ << "  " << *it2++ << std::endl;

			it1 = set1.begin();
			it2 = set2.begin();

			std::cout << std::endl;
			std::cout << "teste it1 pos swap: " << *it1++ << "  " << *it1++ << "  " << *it1++ << std::endl;
			std::cout << "teste it2 pos swap: " << *it2++ << "  " << *it2++ << "  " << *it2++ << std::endl;
		}

		std::cout << std::endl;

		{
			std::cout << "teste de desempenho: ";

			int	i = 5;

			while (i--)
			{
				{
					setInt		set_int;

					for (int i = 0; i < 100000; i++)
						set_int.insert(i);
					while (set_int.size())
						set_int.erase(set_int.begin());
				}
				{
					setStr		set_str;

					for (int i = 0; i < 100000; i++) {
						ss << i << " ";
						ss >> str;
						set_str.insert(str);
					}
					while (set_str.size())
						set_str.erase(set_str.begin());
				}
				std::cout << 5 - i;
				if (i)
					std::cout << ", ";
				else
					std::cout << std::endl;
			}
		}
		std::cout << "*******************************************" << std::endl;
	}

	std::cout << std::endl;

	t = clock() - t;
	fileOut << argv[0] << " " << teste << " --> " << static_cast<int>(t) << "\n";
	fileOut.close();

	return (0);
}
