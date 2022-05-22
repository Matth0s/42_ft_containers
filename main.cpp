/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 03:18:05 by mmoreira          #+#    #+#             */
/*   Updated: 2022/05/22 06:56:35 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <fstream>
#include <ctime>

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

typedef ft::vector<std::string>				vectorStr;
typedef ft::vector<int>						vectorInt;
typedef ft::stack<int>						stackInt;
typedef ft::stack<std::string>				stackStr;
typedef ft::map<int, int>					mapInt;
typedef ft::map<std::string, std::string>	mapStr;
typedef ft::set<int>						setInt;
typedef ft::set<std::string>				setStr;


int main(int argc, char** argv) {
	srand(argc);

	std::ofstream	fileOut;
	fileOut.open("log_time", std::ofstream::out | std::fstream::app);
	clock_t	t = clock();

	std::stringstream	ss;
	std::string			str;

	{
		vectorInt	vector_int;

		for (int i = 0; i < 10000; i++)
			vector_int.insert(vector_int.begin(), i);
		while (vector_int.size())
			vector_int.erase(vector_int.begin() + rand() % vector_int.size());
	}

	{
		vectorStr	vector_str;

		for (int i = 0; i < 10000; i++) {
			ss << i << " ";
			ss >> str;
			vector_str.insert(vector_str.begin(), str);
		}
		while (vector_str.size())
			vector_str.erase(vector_str.begin() + rand() % vector_str.size());
	}

	{
		stackInt	stack_int;

		for (int i = 0; i < 100000; i++)
			stack_int.push(i);
		while (stack_int.size())
			stack_int.pop();
	}

	{
		stackStr	stack_str;

		for (int i = 0; i < 100000; i++) {
			ss << i << " ";
			ss >> str;
			stack_str.push(str);
		}
		while (stack_str.size())
			stack_str.pop();
	}

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

	t = clock() - t;
	fileOut << argv[0] << " --> " << static_cast<int>(t) << "\n";
	fileOut.close();

	return (0);
}
