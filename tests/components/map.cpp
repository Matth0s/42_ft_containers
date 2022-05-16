/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 12:42:18 by mmoreira          #+#    #+#             */
/*   Updated: 2022/05/16 18:18:02 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// # define STD 1

#ifdef STD
	#include <map>
	#include <iostream>
	#include <vector>
	namespace ft = std;
#else
	#include "vector.hpp"
	#include "map.hpp"
#endif

#include <cstdlib>

typedef	ft::pair<int, std::string>	Pair1;
typedef ft::map<int, std::string>	Map1;
typedef ft::vector<Pair1>			Vec1;
typedef	ft::pair<std::string, int>	Pair2;
typedef ft::map<std::string, int>	Map2;
typedef ft::vector<Pair2>			Vec2;

static std::string	randomString( int len ) {
	std::string	str;

	while (len--)
		str.push_back('A' + (rand() % 26) + (rand() % 2 ? 32 : 0));
	return (str);
}

static int		randomInt( int max ) {
	return (rand() % max * (rand() % 2? 1: -1));
}

template <class Vec, class Pair>
static void	vectorSort( Vec& vec, Pair temp ) {

	typename Vec::size_type	i = 0;
	typename Vec::size_type	j = vec.size() - 1;

	while (j > 0)
	{
		while (i < j)
		{
			if (vec[i] > vec[i + 1])
			{
				temp = vec[i];
				vec[i] = vec[i + 1];
				vec[i + 1] = temp;
			}
			i++;
		}
		i = 0; j--;
	}
};

template <class Vec, class Pair>
static void	vectorUnique( Vec& vec, Pair temp ) {

	vectorSort(vec, temp);

	typename Vec::iterator	it = vec.begin();

	while (++it != vec.end())
	{
		if (*it == *(it - 1))
		{
			vec.erase(it);
			it = vec.begin();
		}
	}
};

Pair1	makep1( void ) {
	return (ft::make_pair(randomInt(10000), randomString(1 + (rand()%10))));
}

Pair2	makep2( void ) {
	return (ft::make_pair(randomString(1 + (rand()%10)), randomInt(10000)));
}

template <class Pair1, class Pair2>
static bool	ft_equals( const Pair1& x, const Pair2& y ) {
	return ((x.first == y.first) && (x.second == y.second));
};


void	test_map( void )
{
	Vec1		vec1;
	Vec2		vec2;

	srand(7);

	for (int i = 0; i < 20; i++)
	{
		vec1.push_back(makep1());
		vec2.push_back(makep2());
	}
	vectorUnique(vec1, Pair1());
	vectorUnique(vec2, Pair2());

	// for (Vec1::size_type i = 0; i < vec1.size(); i++)
	// 	std::cout << vec1[i].first << "  ";
	// std::cout << std::endl;

	// for (Vec2::size_type i = 0; i < vec2.size(); i++)
	// 	std::cout << vec2[i].first << "  ";
	// std::cout << std::endl;

	{
		Map1	map1;
		std::cout << "Default Constructor   |✅" << std::endl;
	}

	{
		Map1			map1(vec1.begin(),vec1.end());
		Map1::iterator	itp = map1.begin();
		Vec1::size_type	i = 0;

		for (Vec1::iterator itv = vec1.begin(); itv != vec1.end(); itv++)
			if (ft_equals(*itv, *itp++))
				i++;
		std::cout << "Range Constructor     |" << (i == vec1.size()?"✅":"❌") << std::endl;
	}

	{
		Map1			map1(vec1.begin(),vec1.end());
		Map1			map2(map1);
		Vec1::size_type	i = 0;

		Map1::iterator	itm2 = map2.begin();
		for (Map1::iterator itm1 = map1.begin(); itm1 != map1.end(); itm1++)
			if (ft_equals(*itm1,*itm2++))
				i++;
		std::cout << "Copy Constructor      |" << (i == vec1.size()?"✅":"❌") << std::endl;
	}

	{
		Map1	map1(vec1.begin(),vec1.end());
		Map1	map2;
		Vec1::size_type	i = 0;

		map2 = map1;
		Map1::iterator	itm2 = map2.begin();
		for (Map1::iterator itm1 = map1.begin(); itm1 != map1.end(); itm1++)
			if (ft_equals(*itm1,*itm2++))
				i++;
		std::cout << "Assignment Operator   |" << (i == vec1.size()?"✅":"❌") << std::endl;
	}

	// std::cout << std::endl;

	// {
	// 	ft::vector<int> vec(array, array + 10);
	// 	std::allocator<int> alloc = vec.get_allocator();
	// 	int* ar = alloc.allocate(5);
	// 	for (int i = 0; i < 5; i++)
	// 		alloc.construct(ar + i, i);
	// 	for (int i = 0; i < 5; i++)
	// 		alloc.destroy(ar + i);
	// 	alloc.deallocate(ar, 5);
	// 	std::cout << "get_allocator()       |✅"  << std::endl;
	// }

	std::cout << std::endl;

	{
		Map1	map1(vec1.begin(), vec1.end());
		Map2	map2(vec2.begin(), vec2.end());

		std::cout << "begin() & end()           |";
		{
			Map1::iterator	it1;
			Map2::iterator	it2;
			int				i;

			i = 0;
			for (it1 = map1.begin(); it1 != map1.end(); it1++)
			{
				std::cout << (ft_equals(*it1, vec1[i]) ?"✅":"❌");
				i++;
			}
			i = 0;
			for (it2 = map2.begin(); it2 != map2.end(); it2++)
			{
				std::cout << (ft_equals(*it2, vec2[i]) ?"✅":"❌");
				i++;
			}
			std::cout << std::endl;
		}

		std::cout << "rbegin() & rend()         |";
		{
			Map1::reverse_iterator	it1;
			Map2::reverse_iterator	it2;
			int				i;

			i = vec1.size() - 1;
			for (it1 = map1.rbegin(); it1 != map1.rend(); it1++)
			{
				std::cout << (ft_equals(*it1, vec1[i]) ?"✅":"❌");
				i--;
			}
			i = vec2.size() - 1;
			for (it2 = map2.rbegin(); it2 != map2.rend(); it2++)
			{
				std::cout << (ft_equals(*it2, vec2[i]) ?"✅":"❌");
				i--;
			}
			std::cout << std::endl;
		}

		// std::cout << "const [begin() & end()]   |";
		// {
		// 	Map1::const_iterator	it1;
		// 	Map2::const_iterator	it2;
		// 	int				i;

		// 	i = 0;
		// 	for (it1 = map1.begin(); it1 != map1.end(); it1++)
		// 	{
		// 		std::cout << (ft_equals(*it1, vec1[i]) ?"✅":"❌");
		// 		i++;
		// 	}
		// 	i = 0;
		// 	for (it2 = map2.begin(); it2 != map2.end(); it2++)
		// 	{
		// 		std::cout << (ft_equals(*it2, vec2[i]) ?"✅":"❌");
		// 		i++;
		// 	}
		// 	std::cout << std::endl;
		// }

		// std::cout << "const [rbegin() & rend()] |";
		// {
		// 	Map1::const_reverse_iterator	it1;
		// 	Map2::const_reverse_iterator	it2;
		// 	int				i;

		// 	i = vec1.size() - 1;
		// 	for (it1 = map1.rbegin(); it1 != map1.rend(); it1++)
		// 	{
		// 		std::cout << (ft_equals(*it1, vec1[i]) ?"✅":"❌");
		// 		i--;
		// 	}
		// 	i = vec2.size() - 1;
		// 	for (it2 = map2.rbegin(); it2 != map2.rend(); it2++)
		// 	{
		// 		std::cout << (ft_equals(*it2, vec2[i]) ?"✅":"❌");
		// 		i--;
		// 	}
		// 	std::cout << std::endl;
		// }
	}

	std::cout << std::endl;

	Map1	map11(vec1.begin(), (vec1.end() - 5));
	Map1	map12(vec1.begin(), vec1.end());
	Map1	map13((vec1.begin() + 8), (vec1.end() - 3));

	Map2	map21(vec2.begin(), (vec2.end() - 7));
	Map2	map22(vec2.begin(), vec2.end());
	Map2	map23((vec2.begin() + 2), (vec2.end() - 8));


	std::cout << "empty()            |";
	{
		Map1	map14;
		Map2	map24;

		std::cout << (map14.empty() ?"✅":"❌");
		std::cout << (map12.empty() ?"❌":"✅");
		std::cout << (map23.empty() ?"❌":"✅");
		std::cout << (map24.empty() ?"✅":"❌");
		std::cout << (map21.empty() ?"❌":"✅");
		std::cout << (map22.empty() ?"❌":"✅");
		std::cout << (map13.empty() ?"❌":"✅") << std::endl;
	}

	std::cout << "size()             |";
	{
		std::cout << (map11.size() == 15 ?"✅":"❌");
		std::cout << (map12.size() == 20 ?"✅":"❌");
		std::cout << (map13.size() == 9 ?"✅":"❌");
		std::cout << (map21.size() == 13 ?"✅":"❌");
		std::cout << (map22.size() == 20 ?"✅":"❌");
		std::cout << (map23.size() == 10 ?"✅":"❌") << std::endl;
	}

	std::cout << std::endl;

	std::cout << "operator []        |";
	{
		std::cout << (map11[vec1[10].first] == vec1[10].second ?"✅":"❌");
		std::cout << (map12[vec1[12].first] == vec1[12].second ?"✅":"❌");
		std::cout << (((map13[vec1[0].first] == "") && (map13.size() == 10)) ?"✅":"❌");
		std::cout << (((map21[vec2[13].first] == 0) && (map21.size() == 14)) ?"✅":"❌");
		std::cout << (map22[vec2[7].first] == vec2[7].second ?"✅":"❌");
		std::cout << (((map23[vec2[15].first] == 0) && (map23.size() == 11))?"✅":"❌") << std::endl;
	}

	std::cout << std::endl;

	// std::cout << "single insert()    |";
	// {
	// 	Map1	mapi(map12);
	// 	Map2	maps(map22);
	// 	ft::pair<Map1::iterator, bool>	p1;
	// 	ft::pair<Map2::iterator, bool>	p2;

	// 	p1 = mapi.insert(makep1());
	// 	std::cout << (((ft_equals(*(p1.first), ft::make_pair(-6367, "swt")) && p1.second == true) && mapi.size() == 21)?"✅":"❌");
	// 	p1 = mapi.insert(vec1[3]);
	// 	std::cout << (((ft_equals(*(p1.first), ft::make_pair(-7438, "pcpxvs")) && p1.second == false) && mapi.size() == 21)?"✅":"❌");
	// 	p1 = mapi.insert(makep1());
	// 	std::cout << (((ft_equals(*(p1.first), ft::make_pair(-8856, "pV")) && p1.second == true) && mapi.size() == 22)?"✅":"❌");
	// 	p1 = mapi.insert(vec1[5]);
	// 	std::cout << (((ft_equals(*(p1.first), ft::make_pair(-5792, "mVlYNz")) && p1.second == false) && mapi.size() == 22)?"✅":"❌");
	// 	p1 = mapi.insert(makep1());
	// 	std::cout << (((ft_equals(*(p1.first), ft::make_pair(-97, "l")) && p1.second == true) && mapi.size() == 23)?"✅":"❌");
	// 	p1 = mapi.insert(vec1[7]);
	// 	std::cout << (((ft_equals(*(p1.first), ft::make_pair(-4724, "cyxbJJYHK")) && p1.second == false) && mapi.size() == 23)?"✅":"❌");
	// 	p2 = maps.insert(makep2());
	// 	std::cout << (((ft_equals(*(p2.first), ft::make_pair("iTwUqCW", 9525)) && p2.second == true) && maps.size() == 21)?"✅":"❌");
	// 	p2 = maps.insert(vec2[3]);
	// 	std::cout << (((ft_equals(*(p2.first), ft::make_pair("HHVFW", 8806)) && p2.second == false) && maps.size() == 21)?"✅":"❌");
	// 	p2 = maps.insert(makep2());
	// 	std::cout << (((ft_equals(*(p2.first), ft::make_pair("mb", 8413)) && p2.second == true) && maps.size() == 22)?"✅":"❌");
	// 	p2 = maps.insert(vec2[5]);
	// 	std::cout << (((ft_equals(*(p2.first), ft::make_pair("NfhMDr", -5946)) && p2.second == false) && maps.size() == 22)?"✅":"❌");
	// 	p2 = maps.insert(makep2());
	// 	std::cout << (((ft_equals(*(p2.first), ft::make_pair("TwVuxWW", 1394)) && p2.second == true) && maps.size() == 23)?"✅":"❌");
	// 	p2 = maps.insert(vec2[7]);
	// 	std::cout << (((ft_equals(*(p2.first), ft::make_pair("R", -8503)) && p2.second == false) && maps.size() == 23)?"✅":"❌") << std::endl;
	// }

	// std::cout << "hint insert()      |";
	// {
	// 	Map1	mapi(map12);
	// 	Map2	maps(map22);

	// 	Map1::iterator	it1i;
	// 	Map2::iterator	it1s;

	// 	Map1::iterator	it2i = mapi.begin();
	// 	Map2::iterator	it2s = maps.begin();

	// 	it1i = mapi.insert(it2i++, makep1());
	// 	std::cout << ((ft_equals(*it1i, ft::make_pair(-9585, "PsTi")) && (mapi.size() == 21))?"✅":"❌");
	// 	it1i = mapi.insert(it2i++, vec1[3]);
	// 	std::cout << ((ft_equals(*it1i, ft::make_pair(-7438, "pcpxvs")) && (mapi.size() == 21))?"✅":"❌");
	// 	it1i = mapi.insert(it2i++, makep1());
	// 	std::cout << ((ft_equals(*it1i, ft::make_pair(2071, "yImIK")) && (mapi.size() == 22))?"✅":"❌");
	// 	it2i = mapi.end();
	// 	it1i = mapi.insert(--it2i, vec1[5]);
	// 	std::cout << ((ft_equals(*it1i, ft::make_pair(-5792, "mVlYNz")) && (mapi.size() == 22))?"✅":"❌");
	// 	it1i = mapi.insert(--it2i, makep1());
	// 	std::cout << ((ft_equals(*it1i, ft::make_pair(-4646, "UwSrtCq")) && (mapi.size() == 23))?"✅":"❌");
	// 	it1i = mapi.insert(--it2i, vec1[7]);
	// 	std::cout << ((ft_equals(*it1i, ft::make_pair(-4724, "cyxbJJYHK")) && (mapi.size() == 23))?"✅":"❌");
	// 	it1s = maps.insert(it2s++, makep2());
	// 	std::cout << ((ft_equals(*it1s, ft::make_pair("HllCAiST", -9809)) && (maps.size() == 21))?"✅":"❌");
	// 	it1s = maps.insert(it2s++, vec2[3]);
	// 	std::cout << ((ft_equals(*it1s, ft::make_pair("HHVFW", 8806)) && (maps.size() == 21))?"✅":"❌");
	// 	it1s = maps.insert(it2s++, makep2());
	// 	std::cout << ((ft_equals(*it1s, ft::make_pair("QjXTq", -5217)) && (maps.size() == 22))?"✅":"❌");
	// 	it2s = maps.end();
	// 	it1s = maps.insert(--it2s, vec2[5]);
	// 	std::cout << ((ft_equals(*it1s, ft::make_pair("NfhMDr", -5946)) && (maps.size() == 22))?"✅":"❌");
	// 	it1s = maps.insert(--it2s, makep2());
	// 	std::cout << ((ft_equals(*it1s, ft::make_pair("naJzowQbK", -2889)) && (maps.size() == 23))?"✅":"❌");
	// 	it1s = maps.insert(--it2s, vec2[7]);
	// 	std::cout << ((ft_equals(*it1s, ft::make_pair("R", -8503)) && (maps.size() == 23))?"✅":"❌") << std::endl;
	// }

	// std::cout << "range insert()     |";
	// {
	// 	Map1	mapi(map12);
	// 	Map2	maps(map22);





	// }


	// {
	// 	ft::vector<int> vec4(vec3);
	// 	int				cont;
	// 	vec4.insert(vec4.begin() + 2, 55);
	// 	{
	// 		int	ar[] = {6, 7, 55, 8, 9, 10,};
	// 		cont = 0;
	// 		cont += (vec4.size() == 6? 1: 0);
	// 		for (std::size_t i = 0; i < vec4.size(); i++)
	// 			cont += (vec4[i] == ar[i]? 1: 0);
	// 		cont += (vec4.capacity() == 10? 1: 0);
	// 		std::cout << (cont == (2 + 6) ?"✅":"❌");
	// 	}
	// 	vec4.insert(vec4.begin() + 5, 0);
	// 	{
	// 		int	ar[] = {6, 7, 55, 8, 9, 0, 10};
	// 		cont = 0;
	// 		cont += (vec4.size() == 7? 1: 0);
	// 		for (std::size_t i = 0; i < vec4.size(); i++)
	// 			cont += (vec4[i] == ar[i]? 1: 0);
	// 		cont += (vec4.capacity() == 10? 1: 0);
	// 		std::cout << (cont == (2 + 7) ?"✅":"❌");
	// 	}
	// 	vec4.insert(vec4.end() - 2, -100);
	// 	vec4.insert(vec4.end() - 2, -100);
	// 	vec4.insert(vec4.end() - 2, -100);
	// 	vec4.insert(vec4.end() - 2, -100);
	// 	{
	// 		int	ar[] = {6, 7, 55, 8, 9, -100, -100, -100, -100, 0, 10};
	// 		cont = 0;
	// 		cont += (vec4.size() == 11? 1: 0);
	// 		for (std::size_t i = 0; i < vec4.size(); i++)
	// 			cont += (vec4[i] == ar[i]? 1: 0);
	// 		cont += (vec4.capacity() == 20? 1: 0);
	// 		std::cout << (cont == (2 + 11) ?"✅":"❌") << std::endl;
	// 	}
	// }

	// std::cout << "fill insert()      |";
	// {
	// 	ft::vector<int> vec4(vec3);
	// 	int				cont;
	// 	{
	// 		vec4.insert(vec4.begin() + 4, 1,55);
	// 		int	ar1[] = {6, 7, 8, 9, 55, 10};
	// 		cont = 0;
	// 		cont += (vec4.size() == 6? 1: 0);
	// 		for (std::size_t i = 0; i < vec4.size(); i++)
	// 			cont += (vec4[i] == ar1[i]? 1: 0);
	// 		cont += (vec4.capacity() == 10? 1: 0);

 	// 		vec4.insert(vec4.begin() + 4, 7,55);
	// 		int	ar2[] = {6, 7, 8, 9, 55, 55, 55, 55, 55, 55, 55, 55, 10};
	// 		cont += (vec4.size() == 13? 1: 0);
	// 		for (std::size_t i = 0; i < vec4.size(); i++)
	// 			cont += (vec4[i] == ar2[i]? 1: 0);
	// 		cont += (vec4.capacity() == 13? 1: 0);
	// 		std::cout << (cont == (2 + 13 + 2 + 6) ?"✅":"❌");
	// 	}
	// 	{
	// 		vec4.insert(vec4.begin() + 4, 8,55);
	// 		int	ar1[] = {6, 7, 8, 9, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 10};
	// 		cont = 0;
	// 		cont += (vec4.size() == 21? 1: 0);
	// 		for (std::size_t i = 0; i < vec4.size(); i++)
	// 			cont += (vec4[i] == ar1[i]? 1: 0);
	// 		cont += (vec4.capacity() == 26? 1: 0);

	// 		vec4.insert(vec4.begin() + 10, 20, -15);
	// 		int	ar2[] = {6, 7, 8, 9, 55, 55, 55, 55, 55, 55, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 10};
	// 		cont += (vec4.size() == 41? 1: 0);
	// 		for (std::size_t i = 0; i < vec4.size(); i++)
	// 			cont += (vec4[i] == ar2[i]? 1: 0);
	// 		cont += (vec4.capacity() == 42? 1: 0);
	// 		std::cout << (cont == (2 + 41 + 2 + 21) ?"✅":"❌");
	// 	}
	// 	{
	// 		vec4.insert(vec4.begin() + 10, 50, -15);
	// 		int	ar1[] = {6, 7, 8, 9, 55, 55, 55, 55, 55, 55, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 10};
	// 		cont = 0;
	// 		cont += (vec4.size() == 91? 1: 0);
	// 		for (std::size_t i = 0; i < vec4.size(); i++)
	// 			cont += (vec4[i] == ar1[i]? 1: 0);
	// 		cont += (vec4.capacity() == 91? 1: 0);

	// 		vec4.insert(vec4.begin() + 10, 10, 2);
	// 		int	ar2[] = {6, 7, 8, 9, 55, 55, 55, 55, 55, 55, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 10};
	// 		cont += (vec4.size() == 101? 1: 0);
	// 		for (std::size_t i = 0; i < vec4.size(); i++)
	// 			cont += (vec4[i] == ar2[i]? 1: 0);
	// 		cont += (vec4.capacity() == 182? 1: 0);
	// 		std::cout << (cont == (2 + 101 + 2 + 91) ?"✅":"❌") << std::endl;
	// 	}
	// }

	// std::cout << "range insert()     |";
	// {

	// 	int	ar[] = {6, 7, 55, 8, 55, 55, 55, 55, 55, 1, 2, 3, 4, 5, 6, 0, 2, 55, 55, 55, 1, 2, 3, 4, 5, 6, 0, 2, 9, 10};
	// 	ft::vector<int>	vec4(vec1);
	// 	ft::vector<int> vec5(ar, ar + 30);
	// 	vec4.reserve(20);
	// 	int				cont;
	// 	{
	// 		vec4.insert(vec4.begin() + 9, vec5.begin(), vec5.begin() + 1);
	// 		int	ar1[] = {1, 2, 3, 4, 5, 6, 0, 2, 2, 6, 2, 2, 2, 2, 2, 2};
	// 		cont = 0;
	// 		cont += (vec4.size() == 16? 1: 0);
	// 		for (std::size_t i = 0; i < vec4.size(); i++)
	// 			cont += (vec4[i] == ar1[i]? 1: 0);
	// 		cont += (vec4.capacity() == 20? 1: 0);

	// 		vec4.insert(vec4.begin() + 15, vec5.begin(), vec5.begin() + 5);
	// 		int	ar2[] = {1, 2, 3, 4, 5, 6, 0, 2, 2, 6, 2, 2, 2, 2, 2, 6, 7, 55, 8, 55, 2};
	// 		cont += (vec4.size() == 21? 1: 0);
	// 		for (std::size_t i = 0; i < vec4.size(); i++)
	// 			cont += (vec4[i] == ar2[i]? 1: 0);
	// 		cont += (vec4.capacity() == 32? 1: 0);
	// 		std::cout << (cont == (2 + 21 + 2 + 16) ?"✅":"❌");
	// 	}
	// 	{
	// 		vec4.insert(vec4.begin() + 13, vec5.begin(), vec5.end());
	// 		int	ar1[] = {1, 2, 3, 4, 5, 6, 0, 2, 2, 6, 2, 2, 2, 6, 7, 55, 8, 55, 55, 55, 55, 55, 1, 2, 3, 4, 5, 6, 0, 2, 55, 55, 55, 1, 2, 3, 4, 5, 6, 0, 2, 9, 10, 2, 2, 6, 7, 55, 8, 55, 2};
	// 		cont = 0;
	// 		cont += (vec4.size() == 51? 1: 0);
	// 		for (std::size_t i = 0; i < vec4.size(); i++)
	// 			cont += (vec4[i] == ar1[i]? 1: 0);
	// 		cont += (vec4.capacity() == 51? 1: 0);

	// 		vec4.insert(vec4.begin() + 32, vec5.begin(), vec5.end());
	// 		int	ar2[] = {1, 2, 3, 4, 5, 6, 0, 2, 2, 6, 2, 2, 2, 6, 7, 55, 8, 55, 55, 55, 55, 55, 1, 2, 3, 4, 5, 6, 0, 2, 55, 55, 6, 7, 55, 8, 55, 55, 55, 55, 55, 1, 2, 3, 4, 5, 6, 0, 2, 55, 55, 55, 1, 2, 3, 4, 5, 6, 0, 2, 9, 10, 55, 1, 2, 3, 4, 5, 6, 0, 2, 9, 10, 2, 2, 6, 7, 55, 8, 55, 2 };
	// 		cont += (vec4.size() == 81? 1: 0);
	// 		for (std::size_t i = 0; i < vec4.size(); i++)
	// 			cont += (vec4[i] == ar2[i]? 1: 0);
	// 		cont += (vec4.capacity() == 102? 1: 0);
	// 		std::cout << (cont == (2 + 81 + 2 + 51) ?"✅":"❌");
	// 	}
	// 	{
	// 		ft::vector<int>	vec6(vec4);
	// 		vec6.insert(vec6.begin() + 60, vec4.begin(), vec4.end());

	// 		vec4.insert(vec4.begin() + 32, vec6.begin(), vec6.end());
	// 		int	ar1[] = {1, 2, 3, 4, 5, 6, 0, 2, 2, 6, 2, 2, 2, 6, 7, 55, 8, 55, 55, 55, 55, 55, 1, 2, 3, 4, 5, 6, 0, 2, 55, 55, 1, 2, 3, 4, 5, 6, 0, 2, 2, 6, 2, 2, 2, 6, 7, 55, 8, 55, 55, 55, 55, 55, 1, 2, 3, 4, 5, 6, 0, 2, 55, 55, 6, 7, 55, 8, 55, 55, 55, 55, 55, 1, 2, 3, 4, 5, 6, 0, 2, 55, 55, 55, 1, 2, 3, 4, 5, 6, 0, 2, 1, 2, 3, 4, 5, 6, 0, 2, 2, 6, 2, 2, 2, 6, 7, 55, 8, 55, 55, 55, 55, 55, 1, 2, 3, 4, 5, 6, 0, 2, 55, 55, 6, 7, 55, 8, 55, 55, 55, 55, 55, 1, 2, 3, 4, 5, 6, 0, 2, 55, 55, 55, 1, 2, 3, 4, 5, 6, 0, 2, 9, 10, 55, 1, 2, 3, 4, 5, 6, 0, 2, 9, 10, 2, 2, 6, 7, 55, 8, 55, 2, 9, 10, 55, 1, 2, 3, 4, 5, 6, 0, 2, 9, 10, 2, 2, 6, 7, 55, 8, 55, 2, 6, 7, 55, 8, 55, 55, 55, 55, 55, 1, 2, 3, 4, 5, 6, 0, 2, 55, 55, 55, 1, 2, 3, 4, 5, 6, 0, 2, 9, 10, 55, 1, 2, 3, 4, 5, 6, 0, 2, 9, 10, 2, 2, 6, 7, 55, 8, 55, 2};
	// 		cont = 0;
	// 		cont += (vec4.size() == 243? 1: 0);
	// 		for (std::size_t i = 0; i < vec4.size(); i++)
	// 			cont += (vec4[i] == ar1[i]? 1: 0);
	// 		cont += (vec4.capacity() == 243? 1: 0);
	// 		std::cout << (cont == (2 + 243) ?"✅":"❌") << std::endl;
	// 	}
	// }

	// std::cout << "single erase()     |";
	// {
	// 	ft::vector<int>	vec4(vec1);
	// 	int				cont;
	// 	vec4.erase(vec4.begin());
	// 	{
	// 		int	ar[] = {2, 3, 4, 5, 6, 0, 2, 2, 2, 2, 2, 2, 2, 2};
	// 		cont = 0;
	// 		cont += (vec4.size() == 14? 1: 0);
	// 		for (std::size_t i = 0; i < vec4.size(); i++)
	// 			cont += (vec4[i] == ar[i]? 1: 0);
	// 		cont += (vec4.capacity() == 15? 1: 0);
	// 		std::cout << (cont == (2 + 14) ?"✅":"❌");
	// 	}
	// 	vec4.erase(vec4.begin() + 5);
	// 	{
	// 		int	ar[] = {2, 3, 4, 5, 6, 2, 2, 2, 2, 2, 2, 2, 2};
	// 		cont = 0;
	// 		cont += (vec4.size() == 13? 1: 0);
	// 		for (std::size_t i = 0; i < vec4.size(); i++)
	// 			cont += (vec4[i] == ar[i]? 1: 0);
	// 		cont += (vec4.capacity() == 15? 1: 0);
	// 		std::cout << (cont == (2 + 13) ?"✅":"❌");
	// 	}
	// 	vec4.erase(vec4.begin() + 9);
	// 	{
	// 		int	ar[] = {2, 3, 4, 5, 6, 2, 2, 2, 2, 2, 2, 2};
	// 		cont = 0;
	// 		cont += (vec4.size() == 12? 1: 0);
	// 		for (std::size_t i = 0; i < vec4.size(); i++)
	// 			cont += (vec4[i] == ar[i]? 1: 0);
	// 		cont += (vec4.capacity() == 15? 1: 0);
	// 		std::cout << (cont == (2 + 12) ?"✅":"❌") << std::endl;
	// 	}
	// }

	// std::cout << "range erase()      |";
	// {
	// 	ft::vector<int>	vec4(vec1);
	// 	int				cont;
	// 	vec4.erase(vec4.begin() + 2, vec4.end() - 8);
	// 	{
	// 		int	ar[] = {1, 2, 2, 2, 2, 2, 2, 2, 2, 2};
	// 		cont = 0;
	// 		cont += (vec4.size() == 10? 1: 0);
	// 		for (std::size_t i = 0; i < vec4.size(); i++)
	// 			cont += (vec4[i] == ar[i]? 1: 0);
	// 		cont += (vec4.capacity() == 15? 1: 0);
	// 		std::cout << (cont == (2 + 10) ?"✅":"❌");
	// 	}
	// 	vec4.erase(vec4.begin() + 4, vec4.begin() + 9);
	// 	{
	// 		int	ar[] = {1, 2, 2, 2, 2};
	// 		cont = 0;
	// 		cont += (vec4.size() == 5? 1: 0);
	// 		for (std::size_t i = 0; i < vec4.size(); i++)
	// 			cont += (vec4[i] == ar[i]? 1: 0);
	// 		cont += (vec4.capacity() == 15? 1: 0);
	// 		std::cout << (cont == (2 + 5) ?"✅":"❌");
	// 	}
	// 	vec4.erase(vec4.begin(), vec4.end());
	// 	{
	// 		cont = 0;
	// 		cont += (vec4.size() == 0? 1: 0);
	// 		cont += (vec4.capacity() == 15? 1: 0);
	// 		std::cout << (cont == 2 ?"✅":"❌") << std::endl;
	// 	}
	// }

	// std::cout << "symmetric swap()   |";
	// {
	// 	ft::vector<int>	vec4(8,10);
	// 	ft::vector<int>	vec5(26,-50);

	// 	ft::vector<int>::value_type*	ptr4 = vec4.begin().base();
	// 	ft::vector<int>::value_type*	ptr5 = vec5.begin().base();

	// 	ft::vector<int>::size_type		size4 = vec4.size();
	// 	ft::vector<int>::size_type		size5 = vec5.size();

	// 	ft::vector<int>::size_type		cap4 = vec4.capacity();
	// 	ft::vector<int>::size_type		cap5 = vec5.capacity();

	// 	swap(vec4, vec5);

	// 	std::cout << (((ptr4 == vec5.begin().base()) && (ptr5 == vec4.begin().base()))?"✅":"❌");
	// 	std::cout << (((size4 == vec5.size()) && (size5 == vec4.size()))?"✅":"❌");
	// 	std::cout << (((cap4 == vec5.capacity()) && (cap5 == vec4.capacity()))?"✅":"❌") << std::endl;
	// }

	// std::cout << "clear()            |";
	// {
	// 	vec1.clear();
	// 	vec2.clear();
	// 	vec3.clear();
	// 	std::cout << (((vec1.size() == 0) && (vec1.capacity() == 25))?"✅":"❌");
	// 	std::cout << (((vec2.size() == 0) && (vec2.capacity() == 15))?"✅":"❌");
	// 	std::cout << (((vec3.size() == 0) && (vec3.capacity() == 5))?"✅":"❌") << std::endl;
	// }

	// std::cout << std::endl;

}
