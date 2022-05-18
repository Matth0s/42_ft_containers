/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 12:42:18 by mmoreira          #+#    #+#             */
/*   Updated: 2022/05/18 17:04:05 by mmoreira         ###   ########.fr       */
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

template <class Obj1, class Obj2>
static bool compare( Obj1& obj1, Obj2& obj2 ) {
	typename Obj1::iterator it1 = obj1.begin();
	typename Obj1::iterator end = obj1.end();
	typename Obj2::iterator it2 = obj2.begin();

	while (it1 != end)
		if (!(ft_equals(*it1++, *it2++)))
			return (false);
	return (true);
}

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

	{
		Map1	map1;
		std::cout << "Default Constructor   |✅" << std::endl;
	}

	{
		Map1			map1(vec1.begin(),vec1.end());
		std::cout << "Range Constructor     |" << (compare(map1, vec1)?"✅":"❌") << std::endl;
	}

	{
		Map1			map1(vec1.begin(),vec1.end());
		Map1			map2(map1);
		std::cout << "Copy Constructor      |" << (compare(map1, map2)?"✅":"❌") << std::endl;
	}

	{
		Map1	map1(vec1.begin(),vec1.end());
		Map1	map2;

		map2 = map1;
		std::cout << "Assignment Operator   |" << (compare(map1, map2)?"✅":"❌") << std::endl;
	}

	std::cout << std::endl;

	{
		Map1	map1(vec1.begin(), vec1.end());
		Map2	map2(vec2.begin(), vec2.end());

		Map1::allocator_type	alloc1 = map1.get_allocator();
		Map2::allocator_type	alloc2 = map2.get_allocator();

		Map1::allocator_type::pointer  p1 = alloc1.allocate(10);
		Map2::allocator_type::pointer  p2 = alloc2.allocate(10);

		for (int i = 0; i < 10; i++)
		{
			alloc1.construct(p1 + i, Pair1());
			alloc2.construct(p2 + i, Pair2());
		}

		for (int i = 0; i < 10; i++)
		{
			alloc1.destroy(p1 + i);
			alloc2.destroy(p2 + i);
		}

		alloc1.deallocate(p1, 10);
		alloc2.deallocate(p2, 10);

		std::cout << "get_allocator()       |✅"  << std::endl;
	}

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

		std::cout << "const [begin() & end()]   |";
		{
			Map1::const_iterator	it1;
			Map2::const_iterator	it2;
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

		std::cout << "const [rbegin() & rend()] |";
		{
			Map1::const_reverse_iterator	it1;
			Map2::const_reverse_iterator	it2;
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
	}

	std::cout << std::endl;

	Map1	map11(vec1.begin(), (vec1.end() - 5));
	Map1	map12(vec1.begin(), vec1.end());
	Map1	map13((vec1.begin() + 8), (vec1.end() - 3));

	Map2	map21(vec2.begin(), (vec2.end() - 7));
	Map2	map22(vec2.begin(), vec2.end());
	Map2	map23((vec2.begin() + 2), (vec2.end() - 8));


	std::cout << "empty()              |";
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

	std::cout << "size()               |";
	{
		std::cout << (map11.size() == 15 ?"✅":"❌");
		std::cout << (map12.size() == 20 ?"✅":"❌");
		std::cout << (map13.size() == 9 ?"✅":"❌");
		std::cout << (map21.size() == 13 ?"✅":"❌");
		std::cout << (map22.size() == 20 ?"✅":"❌");
		std::cout << (map23.size() == 10 ?"✅":"❌") << std::endl;
	}

	std::cout << std::endl;

	std::cout << "operator []          |";
	{
		std::cout << (map11[vec1[10].first] == vec1[10].second ?"✅":"❌");
		std::cout << (map12[vec1[12].first] == vec1[12].second ?"✅":"❌");
		std::cout << (((map13[vec1[0].first] == "") && (map13.size() == 10)) ?"✅":"❌");
		std::cout << (((map21[vec2[13].first] == 0) && (map21.size() == 14)) ?"✅":"❌");
		std::cout << (map22[vec2[7].first] == vec2[7].second ?"✅":"❌");
		std::cout << (((map23[vec2[15].first] == 0) && (map23.size() == 11))?"✅":"❌") << std::endl;
	}

	std::cout << std::endl;

	std::cout << "single insert()      |";
	{
		Map1	mapi(map12);
		Map2	maps(map22);
		ft::pair<Map1::iterator, bool>	p1;
		ft::pair<Map2::iterator, bool>	p2;

		p1 = mapi.insert(makep1());
		std::cout << (((ft_equals(*(p1.first), ft::make_pair(-6367, "swt")) && p1.second == true) && mapi.size() == 21)?"✅":"❌");
		p1 = mapi.insert(vec1[3]);
		std::cout << (((ft_equals(*(p1.first), ft::make_pair(-7438, "pcpxvs")) && p1.second == false) && mapi.size() == 21)?"✅":"❌");
		p1 = mapi.insert(makep1());
		std::cout << (((ft_equals(*(p1.first), ft::make_pair(-8856, "pV")) && p1.second == true) && mapi.size() == 22)?"✅":"❌");
		p1 = mapi.insert(vec1[5]);
		std::cout << (((ft_equals(*(p1.first), ft::make_pair(-5792, "mVlYNz")) && p1.second == false) && mapi.size() == 22)?"✅":"❌");
		p1 = mapi.insert(makep1());
		std::cout << (((ft_equals(*(p1.first), ft::make_pair(-97, "l")) && p1.second == true) && mapi.size() == 23)?"✅":"❌");
		p1 = mapi.insert(vec1[7]);
		std::cout << (((ft_equals(*(p1.first), ft::make_pair(-4724, "cyxbJJYHK")) && p1.second == false) && mapi.size() == 23)?"✅":"❌");
		p2 = maps.insert(makep2());
		std::cout << (((ft_equals(*(p2.first), ft::make_pair("iTwUqCW", 9525)) && p2.second == true) && maps.size() == 21)?"✅":"❌");
		p2 = maps.insert(vec2[3]);
		std::cout << (((ft_equals(*(p2.first), ft::make_pair("HHVFW", 8806)) && p2.second == false) && maps.size() == 21)?"✅":"❌");
		p2 = maps.insert(makep2());
		std::cout << (((ft_equals(*(p2.first), ft::make_pair("mb", 8413)) && p2.second == true) && maps.size() == 22)?"✅":"❌");
		p2 = maps.insert(vec2[5]);
		std::cout << (((ft_equals(*(p2.first), ft::make_pair("NfhMDr", -5946)) && p2.second == false) && maps.size() == 22)?"✅":"❌");
		p2 = maps.insert(makep2());
		std::cout << (((ft_equals(*(p2.first), ft::make_pair("TwVuxWW", 1394)) && p2.second == true) && maps.size() == 23)?"✅":"❌");
		p2 = maps.insert(vec2[7]);
		std::cout << (((ft_equals(*(p2.first), ft::make_pair("R", -8503)) && p2.second == false) && maps.size() == 23)?"✅":"❌") << std::endl;
	}

	std::cout << "hint insert()        |";
	{
		Map1	mapi(map12);
		Map2	maps(map22);

		Map1::iterator	it1i;
		Map2::iterator	it1s;

		Map1::iterator	it2i = mapi.begin();
		Map2::iterator	it2s = maps.begin();

		it1i = mapi.insert(it2i++, makep1());
		std::cout << ((ft_equals(*it1i, ft::make_pair(-9585, "PsTi")) && (mapi.size() == 21))?"✅":"❌");
		it1i = mapi.insert(it2i++, vec1[3]);
		std::cout << ((ft_equals(*it1i, ft::make_pair(-7438, "pcpxvs")) && (mapi.size() == 21))?"✅":"❌");
		it1i = mapi.insert(it2i++, makep1());
		std::cout << ((ft_equals(*it1i, ft::make_pair(2071, "yImIK")) && (mapi.size() == 22))?"✅":"❌");
		it2i = mapi.end();
		it1i = mapi.insert(--it2i, vec1[5]);
		std::cout << ((ft_equals(*it1i, ft::make_pair(-5792, "mVlYNz")) && (mapi.size() == 22))?"✅":"❌");
		it1i = mapi.insert(--it2i, makep1());
		std::cout << ((ft_equals(*it1i, ft::make_pair(-4646, "UwSrtCq")) && (mapi.size() == 23))?"✅":"❌");
		it1i = mapi.insert(--it2i, vec1[7]);
		std::cout << ((ft_equals(*it1i, ft::make_pair(-4724, "cyxbJJYHK")) && (mapi.size() == 23))?"✅":"❌");
		it1s = maps.insert(it2s++, makep2());
		std::cout << ((ft_equals(*it1s, ft::make_pair("HllCAiST", -9809)) && (maps.size() == 21))?"✅":"❌");
		it1s = maps.insert(it2s++, vec2[3]);
		std::cout << ((ft_equals(*it1s, ft::make_pair("HHVFW", 8806)) && (maps.size() == 21))?"✅":"❌");
		it1s = maps.insert(it2s++, makep2());
		std::cout << ((ft_equals(*it1s, ft::make_pair("QjXTq", -5217)) && (maps.size() == 22))?"✅":"❌");
		it2s = maps.end();
		it1s = maps.insert(--it2s, vec2[5]);
		std::cout << ((ft_equals(*it1s, ft::make_pair("NfhMDr", -5946)) && (maps.size() == 22))?"✅":"❌");
		it1s = maps.insert(--it2s, makep2());
		std::cout << ((ft_equals(*it1s, ft::make_pair("naJzowQbK", -2889)) && (maps.size() == 23))?"✅":"❌");
		it1s = maps.insert(--it2s, vec2[7]);
		std::cout << ((ft_equals(*it1s, ft::make_pair("R", -8503)) && (maps.size() == 23))?"✅":"❌") << std::endl;
	}

	std::cout << "range insert()       |";
	{
		Map1	mapi(map12);
		Map2	maps(map22);

		Vec1		vec3(vec1);
		Vec2		vec4(vec2);

		for (int j = 0; j < 20; j++)
		{
			vec3.push_back(makep1());
			vec4.push_back(makep2());
		}
		vectorUnique(vec3, Pair1());
		vectorUnique(vec4, Pair2());

		mapi.insert(vec3.begin(), vec3.begin() + 5);
		std::cout << (mapi.size() == 21?"✅":"❌");
		mapi.insert(vec3.begin() + 7, vec3.begin() + 15);
		std::cout << (mapi.size() == 25?"✅":"❌");
		mapi.insert(vec3.begin() + 30, vec3.begin() + 32);
		std::cout << (mapi.size() == 27?"✅":"❌");
		mapi.insert(vec3.begin() + 15, vec3.begin() + 30);
		std::cout << (mapi.size() == 35?"✅":"❌");
		mapi.insert(vec3.begin(), vec3.end());
		std::cout << (mapi.size() == 40?"✅":"❌");
		std::cout << (compare(mapi, vec3)?"✅":"❌");

		maps.insert(vec4.begin(), vec4.begin() + 5);
		std::cout << (maps.size() == 23?"✅":"❌");
		maps.insert(vec4.begin() + 7, vec4.begin() + 15);
		std::cout << (maps.size() == 27?"✅":"❌");
		maps.insert(vec4.begin() + 30, vec4.begin() + 32);
		std::cout << (maps.size() == 28?"✅":"❌");
		maps.insert(vec4.begin() + 15, vec4.begin() + 30);
		std::cout << (maps.size() == 36?"✅":"❌");
		maps.insert(vec4.begin(), vec4.end());
		std::cout << (maps.size() == 40?"✅":"❌");
		std::cout << (compare(maps, vec4)?"✅":"❌") << std::endl;
	}

	std::cout << "iterator erase()     |";
	{
		Map1	mapi(map12);
		Map2	maps(map22);

		Vec1		vec3(vec1);
		Vec2		vec4(vec2);

		Map1::iterator	it1;
		Map2::iterator	it2;

		int		i;

		i = rand() % vec3.size();
		it1 = mapi.begin();
		for (int j = 0; j < i; j++) it1++;
		mapi.erase(it1);
		vec3.erase(vec3.begin() + i);
		std::cout << ((mapi.size() == 19) && compare(mapi, vec3)?"✅":"❌");
		i = rand() % vec3.size();
		it1 = mapi.begin();
		for (int j = 0; j < i; j++) it1++;
		mapi.erase(it1);
		vec3.erase(vec3.begin() + i);
		std::cout << ((mapi.size() == 18) && compare(mapi, vec3)?"✅":"❌");
		i = rand() % vec3.size();
		it1 = mapi.begin();
		for (int j = 0; j < i; j++) it1++;
		mapi.erase(it1);
		vec3.erase(vec3.begin() + i);
		std::cout << ((mapi.size() == 17) && compare(mapi, vec3)?"✅":"❌");
		i = rand() % vec3.size();
		it1 = mapi.begin();
		for (int j = 0; j < i; j++) it1++;
		mapi.erase(it1);
		vec3.erase(vec3.begin() + i);
		std::cout << ((mapi.size() == 16) && compare(mapi, vec3)?"✅":"❌");
		i = rand() % vec3.size();
		it1 = mapi.begin();
		for (int j = 0; j < i; j++) it1++;
		mapi.erase(it1);
		vec3.erase(vec3.begin() + i);
		std::cout << ((mapi.size() == 15) && compare(mapi, vec3)?"✅":"❌");
		i = rand() % vec3.size();
		it1 = mapi.begin();
		for (int j = 0; j < i; j++) it1++;
		mapi.erase(it1);
		vec3.erase(vec3.begin() + i);
		std::cout << ((mapi.size() == 14) && compare(mapi, vec3)?"✅":"❌");
		i = rand() % vec4.size();
		it2 = maps.begin();
		for (int j = 0; j < i; j++) it2++;
		maps.erase(it2);
		vec4.erase(vec4.begin() + i);
		std::cout << ((maps.size() == 19) && compare(maps, vec4)?"✅":"❌");
		i = rand() % vec4.size();
		it2 = maps.begin();
		for (int j = 0; j < i; j++) it2++;
		maps.erase(it2);
		vec4.erase(vec4.begin() + i);
		std::cout << ((maps.size() == 18) && compare(maps, vec4)?"✅":"❌");
		i = rand() % vec4.size();
		it2 = maps.begin();
		for (int j = 0; j < i; j++) it2++;
		maps.erase(it2);
		vec4.erase(vec4.begin() + i);
		std::cout << ((maps.size() == 17) && compare(maps, vec4)?"✅":"❌");
		i = rand() % vec4.size();
		it2 = maps.begin();
		for (int j = 0; j < i; j++) it2++;
		maps.erase(it2);
		vec4.erase(vec4.begin() + i);
		std::cout << ((maps.size() == 16) && compare(maps, vec4)?"✅":"❌");
		i = rand() % vec4.size();
		it2 = maps.begin();
		for (int j = 0; j < i; j++) it2++;
		maps.erase(it2);
		vec4.erase(vec4.begin() + i);
		std::cout << ((maps.size() == 15) && compare(maps, vec4)?"✅":"❌");
		i = rand() % vec4.size();
		it2 = maps.begin();
		for (int j = 0; j < i; j++) it2++;
		maps.erase(it2);
		vec4.erase(vec4.begin() + i);
		std::cout << ((maps.size() == 14) && compare(maps, vec4)?"✅":"❌") << std::endl;

	}

	std::cout << "key erase()          |";
	{
		Map1	mapi(map12);
		Map2	maps(map22);

		Vec1	vec3(vec1);
		Vec2	vec4(vec2);

		Map1::size_type		res1;
		Map2::size_type		res2;

		int		i;

		i = rand() % vec3.size();
		res1 = mapi.erase(vec3[i].first);
		vec3.erase(vec3.begin() + i);
		std::cout << (((res1 == 1) && compare(mapi, vec3))?"✅":"❌");
		res1 = mapi.erase(randomInt(10000));
		std::cout << (((res1 == 0) && compare(mapi, vec3))?"✅":"❌");
		i = rand() % vec3.size();
		res1 = mapi.erase(vec3[i].first);
		vec3.erase(vec3.begin() + i);
		std::cout << (((res1 == 1) && compare(mapi, vec3))?"✅":"❌");
		i = rand() % vec3.size();
		res1 = mapi.erase(vec3[i].first);
		vec3.erase(vec3.begin() + i);
		std::cout << (((res1 == 1) && compare(mapi, vec3))?"✅":"❌");
		res1 = mapi.erase(randomInt(10000));
		std::cout << (((res1 == 0) && compare(mapi, vec3))?"✅":"❌");
		i = rand() % vec3.size();
		res1 = mapi.erase(vec3[i].first);
		vec3.erase(vec3.begin() + i);
		std::cout << (((res1 == 1) && compare(mapi, vec3))?"✅":"❌");
		i = rand() % vec4.size();
		res2 = maps.erase(vec4[i].first);
		vec4.erase(vec4.begin() + i);
		std::cout << (((res2 == 1) && compare(maps, vec4))?"✅":"❌");
		res2 = maps.erase(randomString(10));
		std::cout << (((res2 == 0) && compare(maps, vec4))?"✅":"❌");
		i = rand() % vec4.size();
		res2 = maps.erase(vec4[i].first);
		vec4.erase(vec4.begin() + i);
		std::cout << (((res2 == 1) && compare(maps, vec4))?"✅":"❌");
		i = rand() % vec4.size();
		res2 = maps.erase(vec4[i].first);
		vec4.erase(vec4.begin() + i);
		std::cout << (((res2 == 1) && compare(maps, vec4))?"✅":"❌");
		res2 = maps.erase(randomString(10));
		std::cout << (((res2 == 0) && compare(maps, vec4))?"✅":"❌");
		i = rand() % vec4.size();
		res2 = maps.erase(vec4[i].first);
		vec4.erase(vec4.begin() + i);
		std::cout << (((res2 == 1) && compare(maps, vec4))?"✅":"❌") << std::endl;
	}

	std::cout << "find()               |";
	{
		Map1	mapi(map12);
		Map2	maps(map22);

		Vec1		vec3(vec1);
		Vec2		vec4(vec2);

		Map1::iterator	it1;
		Map2::iterator	it2;

		int		i;

		i = rand() % vec3.size();
		it1 = mapi.find(vec3[i].first);
		std::cout << (ft_equals(*it1, vec3[i])?"✅":"❌");
		it1 = mapi.find(randomInt(10000));
		std::cout << (it1 == mapi.end()?"✅":"❌");
		i = rand() % vec3.size();
		it1 = mapi.find(vec3[i].first);
		std::cout << (ft_equals(*it1, vec3[i])?"✅":"❌");
		i = rand() % vec3.size();
		it1 = mapi.find(vec3[i].first);
		std::cout << (ft_equals(*it1, vec3[i])?"✅":"❌");
		it1 = mapi.find(randomInt(10000));
		std::cout << (it1 == mapi.end()?"✅":"❌");
		i = rand() % vec3.size();
		it1 = mapi.find(vec3[i].first);
		std::cout << (ft_equals(*it1, vec3[i])?"✅":"❌");
		i = rand() % vec4.size();
		it2 = maps.find(vec4[i].first);
		std::cout << (ft_equals(*it2, vec4[i])?"✅":"❌");
		it2 = maps.find(randomString(10000));
		std::cout << (it2 == maps.end()?"✅":"❌");
		i = rand() % vec4.size();
		it2 = maps.find(vec4[i].first);
		std::cout << (ft_equals(*it2, vec4[i])?"✅":"❌");
		i = rand() % vec4.size();
		it2 = maps.find(vec4[i].first);
		std::cout << (ft_equals(*it2, vec4[i])?"✅":"❌");
		it2 = maps.find(randomString(10000));
		std::cout << (it2 == maps.end()?"✅":"❌");
		i = rand() % vec4.size();
		it2 = maps.find(vec4[i].first);
		std::cout << (ft_equals(*it2, vec4[i])?"✅":"❌") << std::endl;
	}

	std::cout << "const find()         |";
	{
		Map1	mapi(map12);
		Map2	maps(map22);

		Vec1		vec3(vec1);
		Vec2		vec4(vec2);

		Map1::const_iterator	it1;
		Map2::const_iterator	it2;

		int		i;

		i = rand() % vec3.size();
		it1 = mapi.find(vec3[i].first);
		std::cout << (ft_equals(*it1, vec3[i])?"✅":"❌");
		it1 = mapi.find(randomInt(10000));
		std::cout << (it1 == mapi.end()?"✅":"❌");
		i = rand() % vec3.size();
		it1 = mapi.find(vec3[i].first);
		std::cout << (ft_equals(*it1, vec3[i])?"✅":"❌");
		i = rand() % vec3.size();
		it1 = mapi.find(vec3[i].first);
		std::cout << (ft_equals(*it1, vec3[i])?"✅":"❌");
		it1 = mapi.find(randomInt(10000));
		std::cout << (it1 == mapi.end()?"✅":"❌");
		i = rand() % vec3.size();
		it1 = mapi.find(vec3[i].first);
		std::cout << (ft_equals(*it1, vec3[i])?"✅":"❌");
		i = rand() % vec4.size();
		it2 = maps.find(vec4[i].first);
		std::cout << (ft_equals(*it2, vec4[i])?"✅":"❌");
		it2 = maps.find(randomString(10000));
		std::cout << (it2 == maps.end()?"✅":"❌");
		i = rand() % vec4.size();
		it2 = maps.find(vec4[i].first);
		std::cout << (ft_equals(*it2, vec4[i])?"✅":"❌");
		i = rand() % vec4.size();
		it2 = maps.find(vec4[i].first);
		std::cout << (ft_equals(*it2, vec4[i])?"✅":"❌");
		it2 = maps.find(randomString(10000));
		std::cout << (it2 == maps.end()?"✅":"❌");
		i = rand() % vec4.size();
		it2 = maps.find(vec4[i].first);
		std::cout << (ft_equals(*it2, vec4[i])?"✅":"❌") << std::endl;
	}

	std::cout << "count()              |";
	{
		std::cout << (map12.count(vec1[rand() % vec1.size()].first)?"✅":"❌");
		std::cout << (map12.count(randomInt(10000))?"❌":"✅");
		std::cout << (map12.count(vec1[rand() % vec1.size()].first)?"✅":"❌");
		std::cout << (map12.count(vec1[rand() % vec1.size()].first)?"✅":"❌");
		std::cout << (map12.count(randomInt(10000))?"❌":"✅");
		std::cout << (map12.count(vec1[rand() % vec1.size()].first)?"✅":"❌");
		std::cout << (map22.count(vec2[rand() % vec2.size()].first)?"✅":"❌");
		std::cout << (map22.count(randomString(10000))?"❌":"✅");
		std::cout << (map22.count(vec2[rand() % vec2.size()].first)?"✅":"❌");
		std::cout << (map22.count(vec2[rand() % vec2.size()].first)?"✅":"❌");
		std::cout << (map22.count(randomString(10000))?"❌":"✅");
		std::cout << (map22.count(vec2[rand() % vec2.size()].first)?"✅":"❌") << std::endl;
	}

	std::cout << "lower_bound()        |";
	{
		Map1::iterator	it1;
		Map2::iterator	it2;

		it1 = map12.lower_bound(randomInt(50000));
		std::cout << (ft_equals(*it1, ft::make_pair(8677, "zJHrzuYESD"))?"✅":"❌");
		it1 = map12.lower_bound(randomInt(50000));
		std::cout << (ft_equals(*it1, ft::make_pair(-8012, "pI"))?"✅":"❌");
		it1 = map12.lower_bound(randomInt(50000));
		std::cout << (ft_equals(*it1, ft::make_pair(-9666, "loyQZ"))?"✅":"❌");
		it1 = map12.lower_bound(randomInt(50000));
		std::cout << (it1 == map12.end()?"✅":"❌");
		it1 = map12.lower_bound(randomInt(50000));
		std::cout << (ft_equals(*it1, ft::make_pair(-9666, "loyQZ"))?"✅":"❌");
		it1 = map12.lower_bound(randomInt(50000));
		std::cout << (it1 == map12.end()?"✅":"❌");
		it1 = map12.lower_bound(randomInt(50000));
		std::cout << (ft_equals(*it1, ft::make_pair(-2918, "QbxwhO"))?"✅":"❌");
		it1 = map12.lower_bound(randomInt(50000));
		std::cout << (it1 == map12.end()?"✅":"❌");
		it2 = map22.lower_bound(randomString(10));
		std::cout << (ft_equals(*it2, ft::make_pair("lrFpkwQ", 3562))?"✅":"❌");
		it2 = map22.lower_bound(randomString(10));
		std::cout << (ft_equals(*it2, ft::make_pair("o", -3582))?"✅":"❌");
		it2 = map22.lower_bound(randomString(10));
		std::cout << (ft_equals(*it2, ft::make_pair("Exzhgbiu", 8075))?"✅":"❌");
		it2 = map22.lower_bound(randomString(10));
		std::cout << (ft_equals(*it2, ft::make_pair("dhD", -9852))?"✅":"❌");
		it2 = map22.lower_bound(randomString(10));
		std::cout << (ft_equals(*it2, ft::make_pair("ZMBv", -2258))?"✅":"❌");
		it2 = map22.lower_bound(randomString(10));
		std::cout << (ft_equals(*it2, ft::make_pair("PaMsONNxIZ", -2431))?"✅":"❌");
		it2 = map22.lower_bound(randomString(10));
		std::cout << (ft_equals(*it2, ft::make_pair("o", -3582))?"✅":"❌");
		it2 = map22.lower_bound(randomString(10));
		std::cout << (ft_equals(*it2, ft::make_pair("dhD", -9852))?"✅":"❌") << std::endl;
	}

	std::cout << "const lower_bound()  |";
	{
		Map1::const_iterator	it1;
		Map2::const_iterator	it2;

		it1 = map12.lower_bound(randomInt(5000));
		std::cout << (ft_equals(*it1, ft::make_pair(5786, "prrP"))?"✅":"❌");
		it1 = map12.lower_bound(randomInt(5000));
		std::cout << (ft_equals(*it1, ft::make_pair(5786, "prrP"))?"✅":"❌");
		it1 = map12.lower_bound(randomInt(5000));
		std::cout << (ft_equals(*it1, ft::make_pair(5786, "prrP"))?"✅":"❌");
		it1 = map12.lower_bound(randomInt(5000));
		std::cout << (ft_equals(*it1, ft::make_pair(-3907, "koMD"))?"✅":"❌");
		it1 = map12.lower_bound(randomInt(5000));
		std::cout << (ft_equals(*it1, ft::make_pair(5786, "prrP"))?"✅":"❌");
		it1 = map12.lower_bound(randomInt(5000));
		std::cout << (ft_equals(*it1, ft::make_pair(-1944, "WmVNNcxjde"))?"✅":"❌");
		it1 = map12.lower_bound(randomInt(5000));
		std::cout << (ft_equals(*it1, ft::make_pair(-1944, "WmVNNcxjde"))?"✅":"❌");
		it1 = map12.lower_bound(randomInt(5000));
		std::cout << (ft_equals(*it1, ft::make_pair(2506, "i"))?"✅":"❌");
		it2 = map22.lower_bound(randomString(10));
		std::cout << (ft_equals(*it2, ft::make_pair("gqYgIPt", -3987))?"✅":"❌");
		it2 = map22.lower_bound(randomString(10));
		std::cout << (ft_equals(*it2, ft::make_pair("lrFpkwQ", 3562))?"✅":"❌");
		it2 = map22.lower_bound(randomString(10));
		std::cout << (ft_equals(*it2, ft::make_pair("xueiuen", 165))?"✅":"❌");
		it2 = map22.lower_bound(randomString(10));
		std::cout << (it2 == map22.end()?"✅":"❌");
		it2 = map22.lower_bound(randomString(10));
		std::cout << (ft_equals(*it2, ft::make_pair("xueiuen", 165))?"✅":"❌");
		it2 = map22.lower_bound(randomString(10));
		std::cout << (ft_equals(*it2, ft::make_pair("lrFpkwQ", 3562))?"✅":"❌");
		it2 = map22.lower_bound(randomString(10));
		std::cout << (ft_equals(*it2, ft::make_pair("ZygfJeiZkS", -2955))?"✅":"❌");
		it2 = map22.lower_bound(randomString(10));
		std::cout << (ft_equals(*it2, ft::make_pair("dhD", -9852))?"✅":"❌") << std::endl;
	}

	std::cout << "upper_bound()        |";
	{
		Map1::iterator	it1;
		Map2::iterator	it2;

		it1 = map12.upper_bound(randomInt(5000));
		std::cout << (ft_equals(*it1, ft::make_pair(2506, "i"))?"✅":"❌");
		it1 = map12.upper_bound(randomInt(5000));
		std::cout << (ft_equals(*it1, ft::make_pair(-1944, "WmVNNcxjde"))?"✅":"❌");
		it1 = map12.upper_bound(randomInt(5000));
		std::cout << (ft_equals(*it1, ft::make_pair(5786, "prrP"))?"✅":"❌");
		it1 = map12.upper_bound(randomInt(5000));
		std::cout << (ft_equals(*it1, ft::make_pair(5786, "prrP"))?"✅":"❌");
		it1 = map12.upper_bound(randomInt(5000));
		std::cout << (ft_equals(*it1, ft::make_pair(5786, "prrP"))?"✅":"❌");
		it1 = map12.upper_bound(randomInt(5000));
		std::cout << (ft_equals(*it1, ft::make_pair(-2918, "QbxwhO"))?"✅":"❌");
		it1 = map12.upper_bound(randomInt(5000));
		std::cout << (ft_equals(*it1, ft::make_pair(-3907, "koMD"))?"✅":"❌");
		it1 = map12.upper_bound(randomInt(5000));
		std::cout << (ft_equals(*it1, ft::make_pair(2506, "i"))?"✅":"❌");
		it2 = map22.upper_bound(randomString(10));
		std::cout << (ft_equals(*it2, ft::make_pair("lrFpkwQ", 3562))?"✅":"❌");
		it2 = map22.upper_bound(randomString(10));
		std::cout << (ft_equals(*it2, ft::make_pair("PaMsONNxIZ", -2431))?"✅":"❌");
		it2 = map22.upper_bound(randomString(10));
		std::cout << (ft_equals(*it2, ft::make_pair("lrFpkwQ", 3562))?"✅":"❌");
		it2 = map22.upper_bound(randomString(10));
		std::cout << (it2 == map22.end()?"✅":"❌");
		it2 = map22.upper_bound(randomString(10));
		std::cout << (ft_equals(*it2, ft::make_pair("Exzhgbiu", 8075))?"✅":"❌");
		it2 = map22.upper_bound(randomString(10));
		std::cout << (ft_equals(*it2, ft::make_pair("dhD", -9852))?"✅":"❌");
		it2 = map22.upper_bound(randomString(10));
		std::cout << (ft_equals(*it2, ft::make_pair("gqYgIPt", -3987))?"✅":"❌");
		it2 = map22.upper_bound(randomString(10));
		std::cout << (ft_equals(*it2, ft::make_pair("xueiuen", 165))?"✅":"❌") << std::endl;
	}

	std::cout << "const upper_bound()  |";
	{
		Map1::const_iterator	it1;
		Map2::const_iterator	it2;

		it1 = map12.upper_bound(randomInt(5000));
		std::cout << (ft_equals(*it1, ft::make_pair(2506, "i"))?"✅":"❌");
		it1 = map12.upper_bound(randomInt(5000));
		std::cout << (ft_equals(*it1, ft::make_pair(2506, "i"))?"✅":"❌");
		it1 = map12.upper_bound(randomInt(5000));
		std::cout << (ft_equals(*it1, ft::make_pair(-1944, "WmVNNcxjde"))?"✅":"❌");
		it1 = map12.upper_bound(randomInt(5000));
		std::cout << (ft_equals(*it1, ft::make_pair(2506, "i"))?"✅":"❌");
		it1 = map12.upper_bound(randomInt(5000));
		std::cout << (ft_equals(*it1, ft::make_pair(2506, "i"))?"✅":"❌");
		it1 = map12.upper_bound(randomInt(5000));
		std::cout << (ft_equals(*it1, ft::make_pair(-1944, "WmVNNcxjde"))?"✅":"❌");
		it1 = map12.upper_bound(randomInt(5000));
		std::cout << (ft_equals(*it1, ft::make_pair(2506, "i"))?"✅":"❌");
		it1 = map12.upper_bound(randomInt(5000));
		std::cout << (ft_equals(*it1, ft::make_pair(2506, "i"))?"✅":"❌");
		it2 = map22.upper_bound(randomString(10));
		std::cout << (ft_equals(*it2, ft::make_pair("rVGegppk", -48))?"✅":"❌");
		it2 = map22.upper_bound(randomString(10));
		std::cout << (ft_equals(*it2, ft::make_pair("ZMBv", -2258))?"✅":"❌");
		it2 = map22.upper_bound(randomString(10));
		std::cout << (ft_equals(*it2, ft::make_pair("ZMBv", -2258))?"✅":"❌");
		it2 = map22.upper_bound(randomString(10));
		std::cout << (ft_equals(*it2, ft::make_pair("tTws", -4414))?"✅":"❌");
		it2 = map22.upper_bound(randomString(10));
		std::cout << (ft_equals(*it2, ft::make_pair("NfhMDr", -5946))?"✅":"❌");
		it2 = map22.upper_bound(randomString(10));
		std::cout << (ft_equals(*it2, ft::make_pair("R", -8503))?"✅":"❌");
		it2 = map22.upper_bound(randomString(10));
		std::cout << (ft_equals(*it2, ft::make_pair("PaMsONNxIZ", -2431))?"✅":"❌");
		it2 = map22.upper_bound(randomString(10));
		std::cout << (ft_equals(*it2, ft::make_pair("xueiuen", 165))?"✅":"❌") << std::endl;
	}

	std::cout << "equal_range()        |";
	{
		ft::pair<Map1::iterator, Map1::iterator> p1;
		ft::pair<Map2::iterator, Map2::iterator> p2;

		p1 = map12.equal_range(vec1[rand() % vec1.size()].first);
		std::cout << ((ft_equals(*p1.first, ft::make_pair(-7438, "pcpxvs"))
						&& ft_equals(*p1.second, ft::make_pair(-6353, "l"))) ?"✅":"❌");
		p1 = map12.equal_range(randomInt(5000));
		std::cout << ((ft_equals(*p1.first, ft::make_pair(5786, "prrP"))
						&& ft_equals(*p1.second, ft::make_pair(5786, "prrP"))) ?"✅":"❌");
		p1 = map12.equal_range(vec1[rand() % vec1.size()].first);
		std::cout << ((ft_equals(*p1.first, ft::make_pair(-7438, "pcpxvs"))
						&& ft_equals(*p1.second, ft::make_pair(-6353, "l"))) ?"✅":"❌");
		p1 = map12.equal_range(randomInt(5000));
		std::cout << ((ft_equals(*p1.first, ft::make_pair(2506, "i"))
						&& ft_equals(*p1.second, ft::make_pair(2506, "i"))) ?"✅":"❌");
		p1 = map12.equal_range(vec1[rand() % vec1.size()].first);
		std::cout << ((ft_equals(*p1.first, ft::make_pair(-4185, "ujcAo"))
						&& ft_equals(*p1.second, ft::make_pair(-3907, "koMD"))) ?"✅":"❌");
		p1 = map12.equal_range(randomInt(5000));
		std::cout << ((ft_equals(*p1.first, ft::make_pair(2506, "i"))
						&& ft_equals(*p1.second, ft::make_pair(2506, "i"))) ?"✅":"❌");
		p1 = map12.equal_range(vec1[rand() % vec1.size()].first);
		std::cout << ((ft_equals(*p1.first, ft::make_pair(-7438, "pcpxvs"))
						&& ft_equals(*p1.second, ft::make_pair(-6353, "l"))) ?"✅":"❌");
		p1 = map12.equal_range(randomInt(5000));
		std::cout << ((ft_equals(*p1.first, ft::make_pair(5786, "prrP"))
						&& ft_equals(*p1.second, ft::make_pair(5786, "prrP"))) ?"✅":"❌");
		p2 = map22.equal_range(vec2[rand() % vec2.size()].first);
		std::cout << ((ft_equals(*p2.first, ft::make_pair("o", -3582))
						&& ft_equals(*p2.second, ft::make_pair("pGD",5253))) ?"✅":"❌");
		p2 = map22.equal_range(randomString(10));
		std::cout << ((ft_equals(*p2.first, ft::make_pair("gqYgIPt", -3987))
						&& ft_equals(*p2.second, ft::make_pair("gqYgIPt",-3987))) ?"✅":"❌");
		p2 = map22.equal_range(vec2[rand() % vec2.size()].first);
		std::cout << ((ft_equals(*p2.first, ft::make_pair("yup", 1206))
						&& p2.second == map22.end()) ?"✅":"❌");
		p2 = map22.equal_range(randomString(10));
		std::cout << ((ft_equals(*p2.first, ft::make_pair("lrFpkwQ", 3562))
						&& ft_equals(*p2.second, ft::make_pair("lrFpkwQ",3562))) ?"✅":"❌");
		p2 = map22.equal_range(vec2[rand() % vec2.size()].first);
		std::cout << ((ft_equals(*p2.first, ft::make_pair("gwGGYAIa", 3527))
						&& ft_equals(*p2.second, ft::make_pair("lrFpkwQ", 3562))) ?"✅":"❌");
		p2 = map22.equal_range(randomString(10));
		std::cout << ((ft_equals(*p2.first, ft::make_pair("DSVHYT", -4958))
						&& ft_equals(*p2.second, ft::make_pair("DSVHYT",-4958))) ?"✅":"❌");
		p2 = map22.equal_range(vec2[rand() % vec2.size()].first);
		std::cout << ((ft_equals(*p2.first, ft::make_pair("gqYgIPt", -3987))
						&& ft_equals(*p2.second, ft::make_pair("gwGGYAIa", 3527))) ?"✅":"❌");
		p2 = map22.equal_range(randomString(10));
		std::cout << ((ft_equals(*p2.first, ft::make_pair("R", -8503))
						&& ft_equals(*p2.second, ft::make_pair("R",-8503))) ?"✅":"❌") << std::endl;
	}

	// std::cout << "const equal_range()  |" << std::endl;
	{
		// ft::pair<Map1::const_iterator, Map1::const_iterator> p1;
		// ft::pair<Map2::const_iterator, Map2::const_iterator> p2;

		// p1 = map12.equal_range(vec1[rand() % vec1.size()].first);
		// std::cout << ((ft_equals(*p1.first, ft::make_pair(-5792, "mVlYNz"))
		// 				&& ft_equals(*p1.second, ft::make_pair(-5715, "rHIFM"))) ?"✅":"❌");
		// p1 = map12.equal_range(randomInt(5000));
		// std::cout << ((ft_equals(*p1.first, ft::make_pair(2506, "i"))
		// 				&& ft_equals(*p1.second, ft::make_pair(2506, "i"))) ?"✅":"❌");
		// p1 = map12.equal_range(vec1[rand() % vec1.size()].first);
		// std::cout << ((ft_equals(*p1.first, ft::make_pair(5786, "prrP"))
		// 				&& ft_equals(*p1.second, ft::make_pair(7884, "HKn"))) ?"✅":"❌");
		// p1 = map12.equal_range(randomInt(5000));
		// std::cout << ((ft_equals(*p1.first, ft::make_pair(2506, "i"))
		// 				&& ft_equals(*p1.second, ft::make_pair(2506, "i"))) ?"✅":"❌");
		// p1 = map12.equal_range(vec1[rand() % vec1.size()].first);
		// std::cout << ((ft_equals(*p1.first, ft::make_pair(-5715, "rHIFM"))
		// 				&& ft_equals(*p1.second, ft::make_pair(-4724, "cyxbJJYHK"))) ?"✅":"❌");
		// p1 = map12.equal_range(randomInt(5000));
		// std::cout << ((ft_equals(*p1.first, ft::make_pair(5786, "prrP"))
		// 				&& ft_equals(*p1.second, ft::make_pair(5786, "prrP"))) ?"✅":"❌");
		// p1 = map12.equal_range(vec1[rand() % vec1.size()].first);
		// std::cout << ((ft_equals(*p1.first, ft::make_pair(-5715, "rHIFM"))
		// 				&& ft_equals(*p1.second, ft::make_pair(-4724, "cyxbJJYHK"))) ?"✅":"❌");
		// p1 = map12.equal_range(randomInt(5000));
		// std::cout << ((ft_equals(*p1.first, ft::make_pair(2506, "i"))
		// 				&& ft_equals(*p1.second, ft::make_pair(2506, "i"))) ?"✅":"❌");
		// p2 = map22.equal_range(vec2[rand() % vec2.size()].first);
		// std::cout << ((ft_equals(*p2.first, ft::make_pair("lrFpkwQ", 3562))
		// 				&& ft_equals(*p2.second, ft::make_pair("o", -3582))) ?"✅":"❌");
		// p2 = map22.equal_range(randomString(10));
		// std::cout << ((ft_equals(*p2.first, ft::make_pair("PaMsONNxIZ", -2431))
		// 				&& ft_equals(*p2.second, ft::make_pair("PaMsONNxIZ",-2431))) ?"✅":"❌");
		// p2 = map22.equal_range(vec2[rand() % vec2.size()].first);
		// std::cout << ((ft_equals(*p2.first, ft::make_pair("DSVHYT", -4958))
		// 				&& ft_equals(*p2.second, ft::make_pair("Exzhgbiu", 8075))) ?"✅":"❌");
		// p2 = map22.equal_range(randomString(10));
		// std::cout << ((ft_equals(*p2.first, ft::make_pair("o", -3582))
		// 				&& ft_equals(*p2.second, ft::make_pair("o", -3582))) ?"✅":"❌");
		// p2 = map22.equal_range(vec2[rand() % vec2.size()].first);
		// std::cout << ((ft_equals(*p2.first, ft::make_pair("DSVHYT", -4958))
		// 				&& ft_equals(*p2.second, ft::make_pair("Exzhgbiu", 8075))) ?"✅":"❌");
		// p2 = map22.equal_range(randomString(10));
		// std::cout << ((ft_equals(*p2.first, ft::make_pair("Exzhgbiu", 8075))
		// 				&& ft_equals(*p2.second, ft::make_pair("Exzhgbiu",8075))) ?"✅":"❌");
		// p2 = map22.equal_range(vec2[rand() % vec2.size()].first);
		// std::cout << ((ft_equals(*p2.first, ft::make_pair("xueiuen", 165))
		// 				&& ft_equals(*p2.second, ft::make_pair("yup", 1206))) ?"✅":"❌");
		// p2 = map22.equal_range(randomString(10));
		// std::cout << ((ft_equals(*p2.first, ft::make_pair("ZMBv", -2258))
		// 				&& ft_equals(*p2.second, ft::make_pair("ZMBv",-2258))) ?"✅":"❌") << std::endl;
	}

	std::cout << "key_comp()           |";
	{
		Map1::key_compare	comp1 = map11.key_comp();
		Map2::key_compare	comp2 = map21.key_comp();

		srand(4);

		std::cout << (comp1(randomInt(10000), randomInt(10000)) ?"❌":"✅");
		std::cout << (comp1(randomInt(10000), randomInt(10000)) ?"❌":"✅");
		std::cout << (comp1(randomInt(10000), randomInt(10000)) ?"❌":"✅");
		std::cout << (comp1(randomInt(10000), randomInt(10000)) ?"✅":"❌");
		std::cout << (comp1(randomInt(10000), randomInt(10000)) ?"✅":"❌");
		std::cout << (comp1(randomInt(10000), randomInt(10000)) ?"✅":"❌");
		std::cout << (comp1(randomInt(10000), randomInt(10000)) ?"✅":"❌");
		std::cout << (comp1(randomInt(10000), randomInt(10000)) ?"✅":"❌");
		std::cout << (comp2(randomString(1 + rand() % 20), randomString(1 + rand() % 20)) ?"✅":"❌");
		std::cout << (comp2(randomString(1 + rand() % 20), randomString(1 + rand() % 20)) ?"✅":"❌");
		std::cout << (comp2(randomString(1 + rand() % 20), randomString(1 + rand() % 20)) ?"❌":"✅");
		std::cout << (comp2(randomString(1 + rand() % 20), randomString(1 + rand() % 20)) ?"❌":"✅");
		std::cout << (comp2(randomString(1 + rand() % 20), randomString(1 + rand() % 20)) ?"❌":"✅");
		std::cout << (comp2(randomString(1 + rand() % 20), randomString(1 + rand() % 20)) ?"✅":"❌");
		std::cout << (comp2(randomString(1 + rand() % 20), randomString(1 + rand() % 20)) ?"✅":"❌");
		std::cout << (comp2(randomString(1 + rand() % 20), randomString(1 + rand() % 20)) ?"❌":"✅") << std::endl;
	}

	std::cout << "value_comp()         |";
	{
		Map1::value_compare	comp1 = map11.value_comp();
		Map2::value_compare	comp2 = map21.value_comp();

		srand(4);

		std::cout << (comp1(ft::make_pair(randomInt(10000),randomString(1 + rand() % 20)), ft::make_pair(randomInt(10000),randomString(1 + rand() % 20))) ?"❌":"✅");
		std::cout << (comp1(ft::make_pair(randomInt(10000),randomString(1 + rand() % 20)), ft::make_pair(randomInt(10000),randomString(1 + rand() % 20))) ?"✅":"❌");
		std::cout << (comp1(ft::make_pair(randomInt(10000),randomString(1 + rand() % 20)), ft::make_pair(randomInt(10000),randomString(1 + rand() % 20))) ?"✅":"❌");
		std::cout << (comp1(ft::make_pair(randomInt(10000),randomString(1 + rand() % 20)), ft::make_pair(randomInt(10000),randomString(1 + rand() % 20))) ?"✅":"❌");
		std::cout << (comp1(ft::make_pair(randomInt(10000),randomString(1 + rand() % 20)), ft::make_pair(randomInt(10000),randomString(1 + rand() % 20))) ?"❌":"✅");
		std::cout << (comp1(ft::make_pair(randomInt(10000),randomString(1 + rand() % 20)), ft::make_pair(randomInt(10000),randomString(1 + rand() % 20))) ?"❌":"✅");
		std::cout << (comp1(ft::make_pair(randomInt(10000),randomString(1 + rand() % 20)), ft::make_pair(randomInt(10000),randomString(1 + rand() % 20))) ?"✅":"❌");
		std::cout << (comp1(ft::make_pair(randomInt(10000),randomString(1 + rand() % 20)), ft::make_pair(randomInt(10000),randomString(1 + rand() % 20))) ?"❌":"✅");
		std::cout << (comp2(ft::make_pair(randomString(1 + rand() % 20), randomInt(10000)), ft::make_pair(randomString(1 + rand() % 20), randomInt(10000))) ?"✅":"❌");
		std::cout << (comp2(ft::make_pair(randomString(1 + rand() % 20), randomInt(10000)), ft::make_pair(randomString(1 + rand() % 20), randomInt(10000))) ?"❌":"✅");
		std::cout << (comp2(ft::make_pair(randomString(1 + rand() % 20), randomInt(10000)), ft::make_pair(randomString(1 + rand() % 20), randomInt(10000))) ?"✅":"❌");
		std::cout << (comp2(ft::make_pair(randomString(1 + rand() % 20), randomInt(10000)), ft::make_pair(randomString(1 + rand() % 20), randomInt(10000))) ?"❌":"✅");
		std::cout << (comp2(ft::make_pair(randomString(1 + rand() % 20), randomInt(10000)), ft::make_pair(randomString(1 + rand() % 20), randomInt(10000))) ?"✅":"❌");
		std::cout << (comp2(ft::make_pair(randomString(1 + rand() % 20), randomInt(10000)), ft::make_pair(randomString(1 + rand() % 20), randomInt(10000))) ?"❌":"✅");
		std::cout << (comp2(ft::make_pair(randomString(1 + rand() % 20), randomInt(10000)), ft::make_pair(randomString(1 + rand() % 20), randomInt(10000))) ?"✅":"❌");
		std::cout << (comp2(ft::make_pair(randomString(1 + rand() % 20), randomInt(10000)), ft::make_pair(randomString(1 + rand() % 20), randomInt(10000))) ?"❌":"✅") << std::endl;
	}

	std::cout << "range erase()        |";
	{
		Map1	mapi(map12);
		Map2	maps(map22);

		Vec1		vec3(vec1);
		Vec2		vec4(vec2);

		ft::pair<Map1::iterator, Map1::iterator> p1;
		ft::pair<Map2::iterator, Map2::iterator> p2;

		p1 = mapi.equal_range( vec3[rand() % vec3.size()].first );
		mapi.erase(p1.first, p1.second);
		std::cout << (mapi.size() == 19?"✅":"❌");
		p1 = mapi.equal_range( vec3[rand() % vec3.size()].first );
		p1.first--;
		mapi.erase(p1.first, p1.second);
		std::cout << (mapi.size() == 17?"✅":"❌");
		p1 = mapi.equal_range( vec3[rand() % vec3.size()].first );
		p1.first--; p1.first--; p1.second++;
		mapi.erase(p1.first, p1.second);
		std::cout << (mapi.size() == 13?"✅":"❌");
		p1 = mapi.equal_range( vec3[rand() % vec3.size()].first );
		p1.second++; p1.second++; p1.second++;
		mapi.erase(p1.first, p1.second);
		std::cout << (mapi.size() == 11?"✅":"❌");
		p1 = mapi.equal_range( vec3[rand() % vec3.size()].first );
		p1.first--; p1.first--; p1.first--;
		mapi.erase(p1.first, p1.second);
		std::cout << (mapi.size() == 7?"✅":"❌");
		p1 = mapi.equal_range( vec3[rand() % vec3.size()].first );
		mapi.erase(p1.first, p1.second);
		std::cout << (mapi.size() == 7?"✅":"❌");
		p1 = mapi.equal_range( vec3[rand() % vec3.size()].first );
		mapi.erase(p1.first, p1.second);
		std::cout << (mapi.size() == 6?"✅":"❌");
		mapi.erase(mapi.begin(), mapi.end());
		std::cout << (mapi.size() == 0?"✅":"❌");
		p2 = maps.equal_range( vec4[rand() % vec4.size()].first );
		maps.erase(p2.first, p2.second);
		std::cout << (maps.size() == 19?"✅":"❌");
		p2 = maps.equal_range( vec4[rand() % vec4.size()].first );
		p2.first--;
		maps.erase(p2.first, p2.second);
		std::cout << (maps.size() == 17?"✅":"❌");
		p2 = maps.equal_range( vec4[rand() % vec4.size()].first );
		p2.first--; p2.second++;
		maps.erase(p2.first, p2.second);
		std::cout << (maps.size() == 15?"✅":"❌");
		p2 = maps.equal_range( vec4[rand() % vec4.size()].first );
		p2.second++; p2.second++; p2.second++;
		maps.erase(p2.first, p2.second);
		std::cout << (maps.size() == 11?"✅":"❌");
		p2 = maps.equal_range( vec4[rand() % vec4.size()].first );
		p2.first--; p2.first--; p2.first--;
		maps.erase(p2.first, p2.second);
		std::cout << (maps.size() == 7?"✅":"❌");
		p2 = maps.equal_range( vec4[rand() % vec4.size()].first );
		maps.erase(p2.first, p2.second);
		std::cout << (maps.size() == 7?"✅":"❌");
		p2 = maps.equal_range( vec4[rand() % vec4.size()].first );
		maps.erase(p2.first, p2.second);
		std::cout << (maps.size() == 7?"✅":"❌");
		maps.erase(maps.begin(), maps.end());
		std::cout << (maps.size() == 0?"✅":"❌") << std::endl;
	}

	std::cout << "swap()               |";
	{
		Map1	map11o(map11);
		Map1	map12o(map12);
		Map1	map13o(map13);

		Map2	map21o(map21);
		Map2	map22o(map22);
		Map2	map23o(map23);

		map11o.swap(map12o);
		std::cout << ((compare(map11o, map12) && map11o.size() == map12.size())?"✅":"❌");
		std::cout << ((compare(map12o, map11) && map12o.size() == map11.size())?"✅":"❌");
		map11o.swap(map13o);
		std::cout << ((compare(map11o, map13) && map11o.size() == map13.size())?"✅":"❌");
		std::cout << ((compare(map13o, map12) && map13o.size() == map12.size())?"✅":"❌");
		map12o.swap(map13o);
		std::cout << ((compare(map12o, map12) && map12o.size() == map12.size())?"✅":"❌");
		std::cout << ((compare(map13o, map11) && map13o.size() == map11.size())?"✅":"❌");
		map13o.swap(map11o);
		std::cout << ((compare(map13o, map13) && map13o.size() == map13.size())?"✅":"❌");
		std::cout << ((compare(map11o, map11) && map11o.size() == map11.size())?"✅":"❌");
		map21o.swap(map22o);
		std::cout << ((compare(map21o, map22) && map21o.size() == map22.size())?"✅":"❌");
		std::cout << ((compare(map22o, map21) && map22o.size() == map21.size())?"✅":"❌");
		map21o.swap(map23o);
		std::cout << ((compare(map21o, map23) && map21o.size() == map23.size())?"✅":"❌");
		std::cout << ((compare(map23o, map22) && map23o.size() == map22.size())?"✅":"❌");
		map22o.swap(map23o);
		std::cout << ((compare(map22o, map22) && map22o.size() == map22.size())?"✅":"❌");
		std::cout << ((compare(map23o, map21) && map23o.size() == map21.size())?"✅":"❌");
		map23o.swap(map21o);
		std::cout << ((compare(map23o, map23) && map23o.size() == map23.size())?"✅":"❌");
		std::cout << ((compare(map21o, map21) && map21o.size() == map21.size())?"✅":"❌") << std::endl;
	}

	std::cout << "clear()              |";
	{
		map11.clear();
		std::cout << (((map11.begin() == map11.end()) && (map11.size() == 0))?"✅":"❌");
		map11.clear();
		std::cout << (((map11.begin() == map11.end()) && (map11.size() == 0))?"✅":"❌");
		map12.clear();
		std::cout << (((map12.begin() == map12.end()) && (map12.size() == 0))?"✅":"❌");
		map12.clear();
		std::cout << (((map12.begin() == map12.end()) && (map12.size() == 0))?"✅":"❌");
		map13.clear();
		std::cout << (((map13.begin() == map13.end()) && (map13.size() == 0))?"✅":"❌");
		map13.clear();
		std::cout << (((map13.begin() == map13.end()) && (map13.size() == 0))?"✅":"❌");
		map21.clear();
		std::cout << (((map21.begin() == map21.end()) && (map21.size() == 0))?"✅":"❌");
		map21.clear();
		std::cout << (((map21.begin() == map21.end()) && (map21.size() == 0))?"✅":"❌");
		map22.clear();
		std::cout << (((map22.begin() == map22.end()) && (map22.size() == 0))?"✅":"❌");
		map22.clear();
		std::cout << (((map22.begin() == map22.end()) && (map22.size() == 0))?"✅":"❌");
		map23.clear();
		std::cout << (((map23.begin() == map23.end()) && (map23.size() == 0))?"✅":"❌");
		map23.clear();
		std::cout << (((map23.begin() == map23.end()) && (map23.size() == 0))?"✅":"❌") << std::endl;
	}
}
