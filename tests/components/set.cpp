/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 01:18:38 by mmoreira          #+#    #+#             */
/*   Updated: 2022/05/20 06:03:07 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef STD
	#include <set>
	#include <vector>
	#include <iostream>
	namespace ft = std;
#else
	#include "vector.hpp"
	#include "set.hpp"
#endif

#include <cstdlib>

typedef ft::set<int>			Set1;
typedef ft::vector<int>			Vec1;
typedef ft::set<std::string>	Set2;
typedef ft::vector<std::string>	Vec2;

static std::string	randomString( int len ) {
	std::string	str;

	while (len--)
		str.push_back('A' + (rand() % 26) + (rand() % 2 ? 32 : 0));
	return (str);
}

static int		randomInt( int max ) {
	return (rand() % max * (rand() % 2? 1: -1));
}

template <class Vec>
static void	vectorSort( Vec& vec ) {

	typename Vec::value_type	temp;
	typename Vec::size_type		i = 0;
	typename Vec::size_type		j = vec.size() - 1;

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

template <class Vec>
static void	vectorUnique( Vec& vec ) {

	vectorSort(vec);

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

template <class Obj1, class Obj2>
static bool compare( Obj1& obj1, Obj2& obj2 ) {
	typename Obj1::iterator it1 = obj1.begin();
	typename Obj1::iterator end = obj1.end();
	typename Obj2::iterator it2 = obj2.begin();

	while (it1 != end)
		if (*it1++ != *it2++)
			return (false);
	return (true);
}

void	test_set( void )
{
	Vec1		vec1;
	Vec2		vec2;

	srand(5);

	for (int i = 0; i < 20; i++)
	{
		vec1.push_back(randomInt(10000));
		vec2.push_back(randomString(rand() % 20));
	}
	vectorUnique(vec1);
	vectorUnique(vec2);

	{
		Set1	set1;
		std::cout << "Default Constructor   |✅" << std::endl;
	}

	{
		Set1			set1(vec1.begin(),vec1.end());
		std::cout << "Range Constructor     |" << (compare(set1, vec1)?"✅":"❌") << std::endl;
	}

	{
		Set1			set1(vec1.begin(),vec1.end());
		Set1			set2(set1);
		std::cout << "Copy Constructor      |" << (compare(set1, set2)?"✅":"❌") << std::endl;
	}

	{
		Set1	set1(vec1.begin(),vec1.end());
		Set1	set2;

		set2 = set1;
		std::cout << "Assignment Operator   |" << (compare(set1, set2)?"✅":"❌") << std::endl;
	}

	std::cout << std::endl;

	{
		Set1	set1(vec1.begin(), vec1.end());
		Set2	set2(vec2.begin(), vec2.end());

		Set1::allocator_type	alloc1 = set1.get_allocator();
		Set2::allocator_type	alloc2 = set2.get_allocator();

		Set1::allocator_type::pointer  p1 = alloc1.allocate(10);
		Set2::allocator_type::pointer  p2 = alloc2.allocate(10);

		for (int i = 0; i < 10; i++)
		{
			alloc1.construct(p1 + i, randomInt(10000));
			alloc2.construct(p2 + i, randomString(rand() % 20));
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
		Set1	set1(vec1.begin(), vec1.end());
		Set2	set2(vec2.begin(), vec2.end());

		std::cout << "begin() & end()           |";
		{
			Set1::iterator	it1;
			Set2::iterator	it2;
			int				i;

			i = 0;
			for (it1 = set1.begin(); it1 != set1.end(); it1++)
			{
				std::cout << (*it1 == vec1[i] ?"✅":"❌");
				i++;
			}
			i = 0;
			for (it2 = set2.begin(); it2 != set2.end(); it2++)
			{
				std::cout << (*it2 == vec2[i] ?"✅":"❌");
				i++;
			}
			std::cout << std::endl;
		}

		std::cout << "rbegin() & rend()         |";
		{
			Set1::reverse_iterator	it1;
			Set2::reverse_iterator	it2;
			int				i;

			i = vec1.size() - 1;
			for (it1 = set1.rbegin(); it1 != set1.rend(); it1++)
			{
				std::cout << (*it1 == vec1[i] ?"✅":"❌");
				i--;
			}
			i = vec2.size() - 1;
			for (it2 = set2.rbegin(); it2 != set2.rend(); it2++)
			{
				std::cout << (*it2 == vec2[i] ?"✅":"❌");
				i--;
			}
			std::cout << std::endl;
		}

		std::cout << "const [begin() & end()]   |";
		{
			Set1::const_iterator	it1;
			Set2::const_iterator	it2;
			int				i;

			i = 0;
			for (it1 = set1.begin(); it1 != set1.end(); it1++)
			{
				std::cout << (*it1 == vec1[i] ?"✅":"❌");
				i++;
			}
			i = 0;
			for (it2 = set2.begin(); it2 != set2.end(); it2++)
			{
				std::cout << (*it2 == vec2[i] ?"✅":"❌");
				i++;
			}
			std::cout << std::endl;
		}

		std::cout << "const [rbegin() & rend()] |";
		{
			Set1::const_reverse_iterator	it1;
			Set2::const_reverse_iterator	it2;
			int				i;

			i = vec1.size() - 1;
			for (it1 = set1.rbegin(); it1 != set1.rend(); it1++)
			{
				std::cout << (*it1 == vec1[i] ?"✅":"❌");
				i--;
			}
			i = vec2.size() - 1;
			for (it2 = set2.rbegin(); it2 != set2.rend(); it2++)
			{
				std::cout << (*it2 == vec2[i] ?"✅":"❌");
				i--;
			}
			std::cout << std::endl;
		}
	}

	std::cout << std::endl;

	Set1	set11(vec1.begin(), (vec1.end() - 5));
	Set1	set12(vec1.begin(), vec1.end());
	Set1	set13((vec1.begin() + 8), (vec1.end() - 3));

	Set2	set21(vec2.begin(), (vec2.end() - 7));
	Set2	set22(vec2.begin(), vec2.end());
	Set2	set23((vec2.begin() + 2), (vec2.end() - 8));


	std::cout << "empty()              |";
	{
		Set1	set14;
		Set2	set24;

		std::cout << (set14.empty() ?"✅":"❌");
		std::cout << (set12.empty() ?"❌":"✅");
		std::cout << (set23.empty() ?"❌":"✅");
		std::cout << (set24.empty() ?"✅":"❌");
		std::cout << (set21.empty() ?"❌":"✅");
		std::cout << (set22.empty() ?"❌":"✅");
		std::cout << (set13.empty() ?"❌":"✅") << std::endl;
	}

	std::cout << "size()               |";
	{
		std::cout << (set11.size() == 15 ?"✅":"❌");
		std::cout << (set12.size() == 20 ?"✅":"❌");
		std::cout << (set13.size() == 9 ?"✅":"❌");
		std::cout << (set21.size() == 13 ?"✅":"❌");
		std::cout << (set22.size() == 20 ?"✅":"❌");
		std::cout << (set23.size() == 10 ?"✅":"❌") << std::endl;
	}

	std::cout << std::endl;

	std::cout << "single insert()      |";
	{
		Set1	seti(set12);
		Set2	sets(set22);
		ft::pair<Set1::iterator, bool>	p1;
		ft::pair<Set2::iterator, bool>	p2;

		p1 = seti.insert(randomInt(10000));
		std::cout << (*p1.first == -3253 && p1.second == true?"✅":"❌");

		p1 = seti.insert(vec1[3]);
		std::cout << (*p1.first == -8052 && p1.second == false?"✅":"❌");

		p1 = seti.insert(randomInt(10000));
		std::cout << (*p1.first == 5920 && p1.second == true?"✅":"❌");

		p1 = seti.insert(vec1[5]);
		std::cout << (*p1.first == -3094 && p1.second == false?"✅":"❌");

		p1 = seti.insert(randomInt(10000));
		std::cout << (*p1.first == -2240 && p1.second == true?"✅":"❌");

		p1 = seti.insert(vec1[7]);
		std::cout << (*p1.first == 135 && p1.second == false?"✅":"❌");

		p2 = sets.insert(randomString(rand() % 20));
		std::cout << (*p2.first == "nRbzJpcrK" && p2.second == true?"✅":"❌");

		p2 = sets.insert(vec2[3]);
		std::cout << (*p2.first == "HDykTVPJPgZIBZDZB" && p2.second == false?"✅":"❌");

		p2 = sets.insert(randomString(rand() % 20));
		std::cout << (*p2.first == "GVQC" && p2.second == true?"✅":"❌");

		p2 = sets.insert(vec2[5]);
		std::cout << (*p2.first == "TFTVcjiQsRJBq" && p2.second == false?"✅":"❌");

		p2 = sets.insert(randomString(rand() % 20));
		std::cout << (*p2.first == "HVPbIuKOjIUAnc" && p2.second == true?"✅":"❌");

		p2 = sets.insert(vec2[7]);
		std::cout << (*p2.first == "UTgEkzQn" && p2.second == false?"✅":"❌") << std::endl;
	}

	std::cout << "hint insert()        |";
	{
		Set1	seti(set12);
		Set2	sets(set22);

		Set1::iterator	it1i;
		Set2::iterator	it1s;

		Set1::iterator	it2i = seti.begin();
		Set2::iterator	it2s = sets.begin();

		it1i = seti.insert(it2i++, randomInt(10000));
		std::cout << (*it1i == 357 && seti.size() == 21 ?"✅":"❌");
		it1i = seti.insert(it2i++, vec1[3]);
		std::cout << (*it1i == -8052 && seti.size() == 21?"✅":"❌");
		it1i = seti.insert(it2i++, randomInt(10000));
		std::cout << (*it1i == -79 && seti.size() == 22 ?"✅":"❌");
		it2i = seti.end();
		it1i = seti.insert(--it2i, vec1[5]);
		std::cout << (*it1i == -3094 && seti.size() == 22 ?"✅":"❌");
		it1i = seti.insert(--it2i, randomInt(10000));
		std::cout << (*it1i == 6071 && seti.size() == 23 ?"✅":"❌");
		it1i = seti.insert(--it2i, vec1[7]);
		std::cout << (*it1i == 135 && seti.size() == 23 ?"✅":"❌");
		it1s = sets.insert(it2s++, randomString(rand() % 20));
		std::cout << (*it1s == "vGBKTjG" && sets.size() == 21 ?"✅":"❌");
		it1s = sets.insert(it2s++, vec2[3]);
		std::cout << (*it1s == "HDykTVPJPgZIBZDZB" && sets.size() == 21 ?"✅":"❌");
		it1s = sets.insert(it2s++, randomString(rand() % 20));
		std::cout << (*it1s == "A" && sets.size() == 22 ?"✅":"❌");
		it2s = sets.end();
		it1s = sets.insert(--it2s, vec2[5]);
		std::cout << (*it1s == "TFTVcjiQsRJBq" && sets.size() == 22 ?"✅":"❌");
		it1s = sets.insert(--it2s, randomString(rand() % 20));
		std::cout << (*it1s == "CwZBjFQIqhEzlfH" && sets.size() == 23 ?"✅":"❌");
		it1s = sets.insert(--it2s, vec2[7]);
		std::cout << (*it1s == "UTgEkzQn" && sets.size() == 23 ?"✅":"❌") << std::endl;
	}

	std::cout << "range insert()       |";
	{
		Set1	seti(set12);
		Set2	sets(set22);

		Vec1		vec3(vec1);
		Vec2		vec4(vec2);

		for (int j = 0; j < 20; j++)
		{
			vec3.push_back(randomInt(10000));
			vec4.push_back(randomString(rand() % 20));
		}
		vectorUnique(vec3);
		vectorUnique(vec4);

		seti.insert(vec3.begin(), vec3.begin() + 5);
		std::cout << (seti.size() == 21?"✅":"❌");
		seti.insert(vec3.begin() + 7, vec3.begin() + 15);
		std::cout << (seti.size() == 27?"✅":"❌");
		seti.insert(vec3.begin() + 30, vec3.begin() + 32);
		std::cout << (seti.size() == 29?"✅":"❌");
		seti.insert(vec3.begin() + 15, vec3.begin() + 30);
		std::cout << (seti.size() == 34?"✅":"❌");
		seti.insert(vec3.begin(), vec3.end());
		std::cout << (seti.size() == 40?"✅":"❌");
		std::cout << (compare(seti, vec3)?"✅":"❌");
		sets.insert(vec4.begin(), vec4.begin() + 5);
		std::cout << (sets.size() == 24?"✅":"❌");
		sets.insert(vec4.begin() + 7, vec4.begin() + 15);
		std::cout << (sets.size() == 28?"✅":"❌");
		sets.insert(vec4.begin() + 30, vec4.begin() + 32);
		std::cout << (sets.size() == 28?"✅":"❌");
		sets.insert(vec4.begin() + 15, vec4.begin() + 30);
		std::cout << (sets.size() == 34?"✅":"❌");
		sets.insert(vec4.begin(), vec4.end());
		std::cout << (sets.size() == 40?"✅":"❌");
		std::cout << (compare(sets, vec4)?"✅":"❌") << std::endl;
	}

	std::cout << "iterator erase()     |";
	{
		Set1	seti(set12);
		Set2	sets(set22);

		Vec1		vec3(vec1);
		Vec2		vec4(vec2);

		Set1::iterator	it1;
		Set2::iterator	it2;

		int		i;

		i = rand() % vec3.size();
		it1 = seti.begin();
		for (int j = 0; j < i; j++) it1++;
		seti.erase(it1);
		vec3.erase(vec3.begin() + i);
		std::cout << ((seti.size() == 19) && compare(seti, vec3)?"✅":"❌");
		i = rand() % vec3.size();
		it1 = seti.begin();
		for (int j = 0; j < i; j++) it1++;
		seti.erase(it1);
		vec3.erase(vec3.begin() + i);
		std::cout << ((seti.size() == 18) && compare(seti, vec3)?"✅":"❌");
		i = rand() % vec3.size();
		it1 = seti.begin();
		for (int j = 0; j < i; j++) it1++;
		seti.erase(it1);
		vec3.erase(vec3.begin() + i);
		std::cout << ((seti.size() == 17) && compare(seti, vec3)?"✅":"❌");
		i = rand() % vec3.size();
		it1 = seti.begin();
		for (int j = 0; j < i; j++) it1++;
		seti.erase(it1);
		vec3.erase(vec3.begin() + i);
		std::cout << ((seti.size() == 16) && compare(seti, vec3)?"✅":"❌");
		i = rand() % vec3.size();
		it1 = seti.begin();
		for (int j = 0; j < i; j++) it1++;
		seti.erase(it1);
		vec3.erase(vec3.begin() + i);
		std::cout << ((seti.size() == 15) && compare(seti, vec3)?"✅":"❌");
		i = rand() % vec3.size();
		it1 = seti.begin();
		for (int j = 0; j < i; j++) it1++;
		seti.erase(it1);
		vec3.erase(vec3.begin() + i);
		std::cout << ((seti.size() == 14) && compare(seti, vec3)?"✅":"❌");
		i = rand() % vec4.size();
		it2 = sets.begin();
		for (int j = 0; j < i; j++) it2++;
		sets.erase(it2);
		vec4.erase(vec4.begin() + i);
		std::cout << ((sets.size() == 19) && compare(sets, vec4)?"✅":"❌");
		i = rand() % vec4.size();
		it2 = sets.begin();
		for (int j = 0; j < i; j++) it2++;
		sets.erase(it2);
		vec4.erase(vec4.begin() + i);
		std::cout << ((sets.size() == 18) && compare(sets, vec4)?"✅":"❌");
		i = rand() % vec4.size();
		it2 = sets.begin();
		for (int j = 0; j < i; j++) it2++;
		sets.erase(it2);
		vec4.erase(vec4.begin() + i);
		std::cout << ((sets.size() == 17) && compare(sets, vec4)?"✅":"❌");
		i = rand() % vec4.size();
		it2 = sets.begin();
		for (int j = 0; j < i; j++) it2++;
		sets.erase(it2);
		vec4.erase(vec4.begin() + i);
		std::cout << ((sets.size() == 16) && compare(sets, vec4)?"✅":"❌");
		i = rand() % vec4.size();
		it2 = sets.begin();
		for (int j = 0; j < i; j++) it2++;
		sets.erase(it2);
		vec4.erase(vec4.begin() + i);
		std::cout << ((sets.size() == 15) && compare(sets, vec4)?"✅":"❌");
		i = rand() % vec4.size();
		it2 = sets.begin();
		for (int j = 0; j < i; j++) it2++;
		sets.erase(it2);
		vec4.erase(vec4.begin() + i);
		std::cout << ((sets.size() == 14) && compare(sets, vec4)?"✅":"❌") << std::endl;

	}

	std::cout << "key erase()          |";
	{
		Set1	seti(set12);
		Set2	sets(set22);

		Vec1	vec3(vec1);
		Vec2	vec4(vec2);

		Set1::size_type		res1;
		Set2::size_type		res2;

		int		i;

		i = rand() % vec3.size();
		res1 = seti.erase(vec3[i]);
		vec3.erase(vec3.begin() + i);
		std::cout << (((res1 == 1) && compare(seti, vec3))?"✅":"❌");
		res1 = seti.erase(randomInt(10000));
		std::cout << (((res1 == 0) && compare(seti, vec3))?"✅":"❌");
		i = rand() % vec3.size();
		res1 = seti.erase(vec3[i]);
		vec3.erase(vec3.begin() + i);
		std::cout << (((res1 == 1) && compare(seti, vec3))?"✅":"❌");
		i = rand() % vec3.size();
		res1 = seti.erase(vec3[i]);
		vec3.erase(vec3.begin() + i);
		std::cout << (((res1 == 1) && compare(seti, vec3))?"✅":"❌");
		res1 = seti.erase(randomInt(10000));
		std::cout << (((res1 == 0) && compare(seti, vec3))?"✅":"❌");
		i = rand() % vec3.size();
		res1 = seti.erase(vec3[i]);
		vec3.erase(vec3.begin() + i);
		std::cout << (((res1 == 1) && compare(seti, vec3))?"✅":"❌");
		i = rand() % vec4.size();
		res2 = sets.erase(vec4[i]);
		vec4.erase(vec4.begin() + i);
		std::cout << (((res2 == 1) && compare(sets, vec4))?"✅":"❌");
		res2 = sets.erase(randomString(10));
		std::cout << (((res2 == 0) && compare(sets, vec4))?"✅":"❌");
		i = rand() % vec4.size();
		res2 = sets.erase(vec4[i]);
		vec4.erase(vec4.begin() + i);
		std::cout << (((res2 == 1) && compare(sets, vec4))?"✅":"❌");
		i = rand() % vec4.size();
		res2 = sets.erase(vec4[i]);
		vec4.erase(vec4.begin() + i);
		std::cout << (((res2 == 1) && compare(sets, vec4))?"✅":"❌");
		res2 = sets.erase(randomString(10));
		std::cout << (((res2 == 0) && compare(sets, vec4))?"✅":"❌");
		i = rand() % vec4.size();
		res2 = sets.erase(vec4[i]);
		vec4.erase(vec4.begin() + i);
		std::cout << (((res2 == 1) && compare(sets, vec4))?"✅":"❌") << std::endl;
	}

	std::cout << "find()               |";
	{
		Set1	seti(set12);
		Set2	sets(set22);

		Vec1		vec3(vec1);
		Vec2		vec4(vec2);

		Set1::iterator	it1;
		Set2::iterator	it2;

		int		i;

		i = rand() % vec3.size();
		it1 = seti.find(vec3[i]);
		std::cout << (*it1 == vec3[i]?"✅":"❌");
		it1 = seti.find(randomInt(10000));
		std::cout << (it1 == seti.end()?"✅":"❌");
		i = rand() % vec3.size();
		it1 = seti.find(vec3[i]);
		std::cout << (*it1 == vec3[i]?"✅":"❌");
		i = rand() % vec3.size();
		it1 = seti.find(vec3[i]);
		std::cout << (*it1 == vec3[i]?"✅":"❌");
		it1 = seti.find(randomInt(10000));
		std::cout << (it1 == seti.end()?"✅":"❌");
		i = rand() % vec3.size();
		it1 = seti.find(vec3[i]);
		std::cout << (*it1 == vec3[i]?"✅":"❌");
		i = rand() % vec4.size();
		it2 = sets.find(vec4[i]);
		std::cout << (*it2 == vec4[i]?"✅":"❌");
		it2 = sets.find(randomString(10000));
		std::cout << (it2 == sets.end()?"✅":"❌");
		i = rand() % vec4.size();
		it2 = sets.find(vec4[i]);
		std::cout << (*it2 == vec4[i]?"✅":"❌");
		i = rand() % vec4.size();
		it2 = sets.find(vec4[i]);
		std::cout << (*it2 == vec4[i]?"✅":"❌");
		it2 = sets.find(randomString(10000));
		std::cout << (it2 == sets.end()?"✅":"❌");
		i = rand() % vec4.size();
		it2 = sets.find(vec4[i]);
		std::cout << (*it2 == vec4[i]?"✅":"❌") << std::endl;
	}

	std::cout << "const find()         |";
	{
		Set1	seti(set12);
		Set2	sets(set22);

		Vec1		vec3(vec1);
		Vec2		vec4(vec2);

		Set1::const_iterator	it1;
		Set2::const_iterator	it2;

		int		i;

		i = rand() % vec3.size();
		it1 = seti.find(vec3[i]);
		std::cout << (*it1 == vec3[i]?"✅":"❌");
		it1 = seti.find(randomInt(10000));
		std::cout << (it1 == seti.end()?"✅":"❌");
		i = rand() % vec3.size();
		it1 = seti.find(vec3[i]);
		std::cout << (*it1 == vec3[i]?"✅":"❌");
		i = rand() % vec3.size();
		it1 = seti.find(vec3[i]);
		std::cout << (*it1 == vec3[i]?"✅":"❌");
		it1 = seti.find(randomInt(10000));
		std::cout << (it1 == seti.end()?"✅":"❌");
		i = rand() % vec3.size();
		it1 = seti.find(vec3[i]);
		std::cout << (*it1 == vec3[i]?"✅":"❌");
		i = rand() % vec4.size();
		it2 = sets.find(vec4[i]);
		std::cout << (*it2 == vec4[i]?"✅":"❌");
		it2 = sets.find(randomString(10000));
		std::cout << (it2 == sets.end()?"✅":"❌");
		i = rand() % vec4.size();
		it2 = sets.find(vec4[i]);
		std::cout << (*it2 == vec4[i]?"✅":"❌");
		i = rand() % vec4.size();
		it2 = sets.find(vec4[i]);
		std::cout << (*it2 == vec4[i]?"✅":"❌");
		it2 = sets.find(randomString(10000));
		std::cout << (it2 == sets.end()?"✅":"❌");
		i = rand() % vec4.size();
		it2 = sets.find(vec4[i]);
		std::cout << (*it2 == vec4[i]?"✅":"❌") << std::endl;
	}

	std::cout << "count()              |";
	{
		std::cout << (set12.count(vec1[rand() % vec1.size()])?"✅":"❌");
		std::cout << (set12.count(randomInt(10000))?"❌":"✅");
		std::cout << (set12.count(vec1[rand() % vec1.size()])?"✅":"❌");
		std::cout << (set12.count(vec1[rand() % vec1.size()])?"✅":"❌");
		std::cout << (set12.count(randomInt(10000))?"❌":"✅");
		std::cout << (set12.count(vec1[rand() % vec1.size()])?"✅":"❌");
		std::cout << (set22.count(vec2[rand() % vec2.size()])?"✅":"❌");
		std::cout << (set22.count(randomString(rand() % 20))?"❌":"✅");
		std::cout << (set22.count(vec2[rand() % vec2.size()])?"✅":"❌");
		std::cout << (set22.count(vec2[rand() % vec2.size()])?"✅":"❌");
		std::cout << (set22.count(randomString(rand() % 20))?"❌":"✅");
		std::cout << (set22.count(vec2[rand() % vec2.size()])?"✅":"❌") << std::endl;
	}

	std::cout << "lower_bound()        |";
	{
		Set1::iterator	it1;
		Set2::iterator	it2;

		it1 = set12.lower_bound(randomInt(10000));
		std::cout << (*it1 == -2899 ?"✅":"❌");
		it1 = set12.lower_bound(randomInt(10000));
		std::cout << (*it1 == 8869 ?"✅":"❌");
		it1 = set12.lower_bound(randomInt(10000));
		std::cout << (*it1 == 135 ?"✅":"❌");
		it1 = set12.lower_bound(randomInt(10000));
		std::cout << (*it1 == 6573 ?"✅":"❌");
		it1 = set12.lower_bound(randomInt(10000));
		std::cout << (*it1 == 8869 ?"✅":"❌");
		it1 = set12.lower_bound(randomInt(10000));
		std::cout << (*it1 == 4108?"✅":"❌");
		it1 = set12.lower_bound(randomInt(10000));
		std::cout << (it1 == set12.end()?"✅":"❌");
		it1 = set12.lower_bound(randomInt(10000));
		std::cout << (*it1 == 8869 ?"✅":"❌");
		it2 = set22.lower_bound(randomString(rand() % 20));
		std::cout << (*it2 == "klmhgLFymJRri" ?"✅":"❌");
		it2 = set22.lower_bound(randomString(rand() % 20));
		std::cout << (*it2 == "TFTVcjiQsRJBq" ?"✅":"❌");
		it2 = set22.lower_bound(randomString(rand() % 20));
		std::cout << (*it2 == "TFTVcjiQsRJBq" ?"✅":"❌");
		it2 = set22.lower_bound(randomString(rand() % 20));
		std::cout << (*it2 == "QOpDUOAWSx" ?"✅":"❌");
		it2 = set22.lower_bound(randomString(rand() % 20));
		std::cout << (*it2 == "YyMaNadhW" ?"✅":"❌");
		it2 = set22.lower_bound(randomString(rand() % 20));
		std::cout << (*it2 == "aYEczpioKOzQjF" ?"✅":"❌");
		it2 = set22.lower_bound(randomString(rand() % 20));
		std::cout << (*it2 == "FNV" ?"✅":"❌");
		it2 = set22.lower_bound(randomString(rand() % 20));
		std::cout << (*it2 == "vPXsBnzcGqqcfhzca" ?"✅":"❌") << std::endl;
	}

	std::cout << "const lower_bound()  |";
	{
		Set1::const_iterator	it1;
		Set2::const_iterator	it2;

		it1 = set12.lower_bound(randomInt(10000));
		std::cout << (*it1 == -4842 ?"✅":"❌");
		it1 = set12.lower_bound(randomInt(10000));
		std::cout << (it1 == set12.end() ?"✅":"❌");
		it1 = set12.lower_bound(randomInt(10000));
		std::cout << (*it1 == 135 ?"✅":"❌");
		it1 = set12.lower_bound(randomInt(10000));
		std::cout << (*it1 == 7014 ?"✅":"❌");
		it1 = set12.lower_bound(randomInt(10000));
		std::cout << (*it1 == 7014 ?"✅":"❌");
		it1 = set12.lower_bound(randomInt(10000));
		std::cout << (*it1 == -4842 ?"✅":"❌");
		it1 = set12.lower_bound(randomInt(10000));
		std::cout << (*it1 == -3094 ?"✅":"❌");
		it1 = set12.lower_bound(randomInt(10000));
		std::cout << (*it1 == 1675 ?"✅":"❌");
		it2 = set22.lower_bound(randomString(rand() % 20));
		std::cout << (*it2 == "qHIswKbUNBGS" ?"✅":"❌");
		it2 = set22.lower_bound(randomString(rand() % 20));
		std::cout << (*it2 == "QOpDUOAWSx" ?"✅":"❌");
		it2 = set22.lower_bound(randomString(rand() % 20));
		std::cout << (*it2 == "QOpDUOAWSx" ?"✅":"❌");
		it2 = set22.lower_bound(randomString(rand() % 20));
		std::cout << (*it2 == "vPXsBnzcGqqcfhzca" ?"✅":"❌");
		it2 = set22.lower_bound(randomString(rand() % 20));
		std::cout << (*it2 == "FNV" ?"✅":"❌");
		it2 = set22.lower_bound(randomString(rand() % 20));
		std::cout << (*it2 == "YyMaNadhW" ?"✅":"❌");
		it2 = set22.lower_bound(randomString(rand() % 20));
		std::cout << (*it2 == "" ?"✅":"❌");
		it2 = set22.lower_bound(randomString(rand() % 20));
		std::cout << (*it2 == "QOpDUOAWSx" ?"✅":"❌") << std::endl;
	}

	std::cout << "upper_bound()        |";
	{
		Set1::iterator	it1;
		Set2::iterator	it2;

		it1 = set12.upper_bound(randomInt(10000));
		std::cout << (*it1 == 1285 ?"✅":"❌");
		it1 = set12.upper_bound(randomInt(10000));
		std::cout << (*it1 == 7265 ?"✅":"❌");
		it1 = set12.upper_bound(randomInt(10000));
		std::cout << (*it1 == 135 ?"✅":"❌");
		it1 = set12.upper_bound(randomInt(10000));
		std::cout << (*it1 == -3094 ?"✅":"❌");
		it1 = set12.upper_bound(randomInt(10000));
		std::cout << (*it1 == 4108 ?"✅":"❌");
		it1 = set12.upper_bound(randomInt(10000));
		std::cout << (*it1 == 4108 ?"✅":"❌");
		it1 = set12.upper_bound(randomInt(10000));
		std::cout << (*it1 == 6573 ?"✅":"❌");
		it1 = set12.upper_bound(randomInt(10000));
		std::cout << (*it1 == 7265 ?"✅":"❌");
		it2 = set22.upper_bound(randomString(rand() % 20));
		std::cout << (*it2 == "TFTVcjiQsRJBq" ?"✅":"❌");
		it2 = set22.upper_bound(randomString(rand() % 20));
		std::cout << (*it2 == "cUUDBPNyctcM" ?"✅":"❌");
		it2 = set22.upper_bound(randomString(rand() % 20));
		std::cout << (*it2 == "FNV" ?"✅":"❌");
		it2 = set22.upper_bound(randomString(rand() % 20));
		std::cout << (*it2 == "FNV" ?"✅":"❌");
		it2 = set22.upper_bound(randomString(rand() % 20));
		std::cout << (*it2 == "QOpDUOAWSx" ?"✅":"❌");
		it2 = set22.upper_bound(randomString(rand() % 20));
		std::cout << (*it2 == "aYEczpioKOzQjF" ?"✅":"❌");
		it2 = set22.upper_bound(randomString(rand() % 20));
		std::cout << (*it2 == "klmhgLFymJRri" ?"✅":"❌");
		it2 = set22.upper_bound(randomString(rand() % 20));
		std::cout << (*it2 == "vPXsBnzcGqqcfhzca" ?"✅":"❌") << std::endl;
	}

	std::cout << "const upper_bound()  |";
	{
		Set1::const_iterator	it1;
		Set2::const_iterator	it2;

		it1 = set12.upper_bound(randomInt(10000));
		std::cout << (*it1 == 135 ?"✅":"❌");
		it1 = set12.upper_bound(randomInt(10000));
		std::cout << (*it1 == -3094 ?"✅":"❌");
		it1 = set12.upper_bound(randomInt(10000));
		std::cout << (*it1 == -3094 ?"✅":"❌");
		it1 = set12.upper_bound(randomInt(10000));
		std::cout << (*it1 == 4108 ?"✅":"❌");
		it1 = set12.upper_bound(randomInt(10000));
		std::cout << (*it1 == -3094 ?"✅":"❌");
		it1 = set12.upper_bound(randomInt(10000));
		std::cout << (*it1 == 7265 ?"✅":"❌");
		it1 = set12.upper_bound(randomInt(10000));
		std::cout << (*it1 == -3094 ?"✅":"❌");
		it1 = set12.upper_bound(randomInt(10000));
		std::cout << (*it1 == -8052 ?"✅":"❌");
		it2 = set22.upper_bound(randomString(rand() % 20));
		std::cout << (*it2 == "FNV" ?"✅":"❌");
		it2 = set22.upper_bound(randomString(rand() % 20));
		std::cout << (*it2 == "qviMocmDPphWtSWdwOG" ?"✅":"❌");
		it2 = set22.upper_bound(randomString(rand() % 20));
		std::cout << (*it2 == "FNV" ?"✅":"❌");
		it2 = set22.upper_bound(randomString(rand() % 20));
		std::cout << (*it2 == "klmhgLFymJRri" ?"✅":"❌");
		it2 = set22.upper_bound(randomString(rand() % 20));
		std::cout << (*it2 == "qHIswKbUNBGS" ?"✅":"❌");
		it2 = set22.upper_bound(randomString(rand() % 20));
		std::cout << (*it2 == "ZxkIHqdwDo" ?"✅":"❌");
		it2 = set22.upper_bound(randomString(rand() % 20));
		std::cout << (*it2 == "qelmtdaYIPAPgPx" ?"✅":"❌");
		it2 = set22.upper_bound(randomString(rand() % 20));
		std::cout << (*it2 == "klmhgLFymJRri" ?"✅":"❌") << std::endl;
	}

	std::cout << "equal_range()        |";
	{
		ft::pair<Set1::iterator, Set1::iterator> p1;
		ft::pair<Set2::iterator, Set2::iterator> p2;

		p1 =set12.equal_range(vec1[rand() % vec1.size()]);
		std::cout << (*p1.first == 6573 && *p1.second == 7014 ?"✅":"❌");
		p1 =set12.equal_range(randomInt(5000));
		std::cout << (*p1.first == -3094 && *p1.second == -3094 ?"✅":"❌");
		p1 =set12.equal_range(vec1[rand() % vec1.size()]);
		std::cout << (*p1.first == 5159 && *p1.second == 6573 ?"✅":"❌");
		p1 =set12.equal_range(randomInt(5000));
		std::cout << (*p1.first == 5110 && *p1.second == 5110 ?"✅":"❌");
		p1 =set12.equal_range(vec1[rand() % vec1.size()]);
		std::cout << (*p1.first == 5159 && *p1.second == 6573 ?"✅":"❌");
		p1 =set12.equal_range(randomInt(5000));
		std::cout << (*p1.first == 135 && *p1.second == 135 ?"✅":"❌");
		p1 =set12.equal_range(vec1[rand() % vec1.size()]);
		std::cout << (*p1.first == 4383 && *p1.second == 5110 ?"✅":"❌");
		p1 =set12.equal_range(randomInt(5000));
		std::cout << (*p1.first == 135  && *p1.second == 135 ?"✅":"❌");
		p2 =set22.equal_range(vec2[rand() % vec2.size()]);
		std::cout << (*p2.first == "HDykTVPJPgZIBZDZB" && *p2.second == "QOpDUOAWSx" ?"✅":"❌");
		p2 =set22.equal_range(randomString(10));
		std::cout << (*p2.first == "QOpDUOAWSx" && *p2.second == "QOpDUOAWSx" ?"✅":"❌");
		p2 =set22.equal_range(vec2[rand() % vec2.size()]);
		std::cout << (*p2.first == "aYEczpioKOzQjF" && *p2.second == "cUUDBPNyctcM" ?"✅":"❌");
		p2 =set22.equal_range(randomString(10));
		std::cout << (*p2.first == "ysxziyZLfSkbsLxA" && *p2.second == "ysxziyZLfSkbsLxA" ?"✅":"❌");
		p2 =set22.equal_range(vec2[rand() % vec2.size()]);
		std::cout << (*p2.first == "qviMocmDPphWtSWdwOG" && *p2.second == "vPXsBnzcGqqcfhzca" ?"✅":"❌");
		p2 =set22.equal_range(randomString(10));
		std::cout << (*p2.first == "HDykTVPJPgZIBZDZB" && *p2.second == "HDykTVPJPgZIBZDZB" ?"✅":"❌");
		p2 =set22.equal_range(vec2[rand() % vec2.size()]);
		std::cout << (*p2.first == "klmhgLFymJRri" && *p2.second == "qHIswKbUNBGS" ?"✅":"❌");
		p2 =set22.equal_range(randomString(10));
		std::cout << (*p2.first == "YyMaNadhW" && *p2.second == "YyMaNadhW" ?"✅":"❌") << std::endl;
	}

	std::cout << "const equal_range()  |";
	{
		ft::pair<Set1::iterator, Set1::iterator> p1;
		ft::pair<Set2::iterator, Set2::iterator> p2;

		p1 =set12.equal_range(vec1[rand() % vec1.size()]);
		std::cout << (*p1.first == -8286 && *p1.second == -8052 ?"✅":"❌");
		p1 =set12.equal_range(randomInt(5000));
		std::cout << (*p1.first == 4108 && *p1.second == 4108 ?"✅":"❌");
		p1 =set12.equal_range(vec1[rand() % vec1.size()]);
		std::cout << (*p1.first == -8286 && *p1.second == -8052 ?"✅":"❌");
		p1 =set12.equal_range(randomInt(5000));
		std::cout << (*p1.first == 4108 && *p1.second == 4108 ?"✅":"❌");
		p1 =set12.equal_range(vec1[rand() % vec1.size()]);
		std::cout << (*p1.first == 7014 && *p1.second == 7265 ?"✅":"❌");
		p1 =set12.equal_range(randomInt(5000));
		std::cout << (*p1.first == 135 && *p1.second == 135 ?"✅":"❌");
		p1 =set12.equal_range(vec1[rand() % vec1.size()]);
		std::cout << (*p1.first == 7265 && *p1.second == 8869 ?"✅":"❌");
		p1 =set12.equal_range(randomInt(5000));
		std::cout << (*p1.first == 135  && *p1.second == 135 ?"✅":"❌");
		p2 =set22.equal_range(vec2[rand() % vec2.size()]);
		std::cout << (*p2.first == "TFgZHdlhbntV" && *p2.second == "UTgEkzQn" ?"✅":"❌");
		p2 =set22.equal_range(randomString(10));
		std::cout << (*p2.first == "vPXsBnzcGqqcfhzca" && *p2.second == "vPXsBnzcGqqcfhzca" ?"✅":"❌");
		p2 =set22.equal_range(vec2[rand() % vec2.size()]);
		std::cout << (*p2.first == "YyMaNadhW" && *p2.second == "ZxkIHqdwDo" ?"✅":"❌");
		p2 =set22.equal_range(randomString(10));
		std::cout << (*p2.first == "qHIswKbUNBGS" && *p2.second == "qHIswKbUNBGS" ?"✅":"❌");
		p2 =set22.equal_range(vec2[rand() % vec2.size()]);
		std::cout << (*p2.first == "qviMocmDPphWtSWdwOG" && *p2.second == "vPXsBnzcGqqcfhzca" ?"✅":"❌");
		p2 =set22.equal_range(randomString(10));
		std::cout << (*p2.first == "ysxziyZLfSkbsLxA" && *p2.second == "ysxziyZLfSkbsLxA" ?"✅":"❌");
		p2 =set22.equal_range(vec2[rand() % vec2.size()]);
		std::cout << (*p2.first == "qviMocmDPphWtSWdwOG" && *p2.second == "vPXsBnzcGqqcfhzca" ?"✅":"❌");
		p2 =set22.equal_range(randomString(10));
		std::cout << (*p2.first == "QOpDUOAWSx" && *p2.second == "QOpDUOAWSx" ?"✅":"❌") << std::endl;
	}

	std::cout << "key_comp()           |";
	{
		Set1::key_compare	comp1 = set11.key_comp();
		Set2::key_compare	comp2 = set21.key_comp();

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
		Set1::value_compare	comp1 = set11.value_comp();
		Set2::value_compare	comp2 = set21.value_comp();

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

	std::cout << "range erase()        |";
	{
		Set1	seti(set12);
		Set2	sets(set22);

		Vec1		vec3(vec1);
		Vec2		vec4(vec2);

		ft::pair<Set1::iterator, Set1::iterator> p1;
		ft::pair<Set2::iterator, Set2::iterator> p2;

		p1 = seti.equal_range( vec3[rand() % vec3.size()] );
		seti.erase(p1.first, p1.second);
		std::cout << (seti.size() == 19?"✅":"❌");
		p1 = seti.equal_range( vec3[rand() % vec3.size()] );
		p1.first--;
		seti.erase(p1.first, p1.second);
		std::cout << (seti.size() == 18?"✅":"❌");
		p1 = seti.equal_range( vec3[rand() % vec3.size()] );
		p1.first--; p1.first--; p1.second++;
		seti.erase(p1.first, p1.second);
		std::cout << (seti.size() == 14?"✅":"❌");
		p1 = seti.equal_range( vec3[rand() % vec3.size()] );
		p1.second++; p1.second++; p1.second++;
		seti.erase(p1.first, p1.second);
		std::cout << (seti.size() == 10?"✅":"❌");
		p1 = seti.equal_range( vec3[rand() % vec3.size()] );
		p1.first--; p1.first--; p1.first--;
		seti.erase(p1.first, p1.second);
		std::cout << (seti.size() == 7?"✅":"❌");
		p1 = seti.equal_range( vec3[rand() % vec3.size()] );
		seti.erase(p1.first, p1.second);
		std::cout << (seti.size() == 7?"✅":"❌");
		p1 = seti.equal_range( vec3[rand() % vec3.size()] );
		seti.erase(p1.first, p1.second);
		std::cout << (seti.size() == 6?"✅":"❌");
		seti.erase(seti.begin(), seti.end());
		std::cout << (seti.size() == 0?"✅":"❌");
		p2 = sets.equal_range( vec4[rand() % vec4.size()] );
		sets.erase(p2.first, p2.second);
		std::cout << (sets.size() == 19?"✅":"❌");
		p2 = sets.equal_range( vec4[rand() % vec4.size()] );
		p2.first--;
		sets.erase(p2.first, p2.second);
		std::cout << (sets.size() == 17?"✅":"❌");
		p2 = sets.equal_range( vec4[rand() % vec4.size()] );
		p2.first--; p2.second++;
		sets.erase(p2.first, p2.second);
		std::cout << (sets.size() == 14?"✅":"❌");
		p2 = sets.equal_range( vec4[rand() % vec4.size()] );
		p2.second++; p2.second++; p2.second++;
		sets.erase(p2.first, p2.second);
		std::cout << (sets.size() == 10?"✅":"❌");
		p2 = sets.equal_range( vec4[rand() % vec4.size()] );
		p2.first--; p2.first--;
		sets.erase(p2.first, p2.second);
		std::cout << (sets.size() == 8?"✅":"❌");
		p2 = sets.equal_range( vec4[rand() % vec4.size()] );
		sets.erase(p2.first, p2.second);
		std::cout << (sets.size() == 7?"✅":"❌");
		p2 = sets.equal_range( vec4[rand() % vec4.size()] );
		sets.erase(p2.first, p2.second);
		std::cout << (sets.size() == 7?"✅":"❌");
		sets.erase(sets.begin(), sets.end());
		std::cout << (sets.size() == 0?"✅":"❌") << std::endl;
	}

	std::cout << "swap()               |";
	{
		Set1	set11o(set11);
		Set1	set12o(set12);
		Set1	set13o(set13);

		Set2	set21o(set21);
		Set2	set22o(set22);
		Set2	set23o(set23);

		set11o.swap(set12o);
		std::cout << ((compare(set11o, set12) && set11o.size() == set12.size())?"✅":"❌");
		std::cout << ((compare(set12o, set11) && set12o.size() == set11.size())?"✅":"❌");
		set11o.swap(set13o);
		std::cout << ((compare(set11o, set13) && set11o.size() == set13.size())?"✅":"❌");
		std::cout << ((compare(set13o, set12) && set13o.size() == set12.size())?"✅":"❌");
		set12o.swap(set13o);
		std::cout << ((compare(set12o, set12) && set12o.size() == set12.size())?"✅":"❌");
		std::cout << ((compare(set13o, set11) && set13o.size() == set11.size())?"✅":"❌");
		set13o.swap(set11o);
		std::cout << ((compare(set13o, set13) && set13o.size() == set13.size())?"✅":"❌");
		std::cout << ((compare(set11o, set11) && set11o.size() == set11.size())?"✅":"❌");
		set21o.swap(set22o);
		std::cout << ((compare(set21o, set22) && set21o.size() == set22.size())?"✅":"❌");
		std::cout << ((compare(set22o, set21) && set22o.size() == set21.size())?"✅":"❌");
		set21o.swap(set23o);
		std::cout << ((compare(set21o, set23) && set21o.size() == set23.size())?"✅":"❌");
		std::cout << ((compare(set23o, set22) && set23o.size() == set22.size())?"✅":"❌");
		set22o.swap(set23o);
		std::cout << ((compare(set22o, set22) && set22o.size() == set22.size())?"✅":"❌");
		std::cout << ((compare(set23o, set21) && set23o.size() == set21.size())?"✅":"❌");
		set23o.swap(set21o);
		std::cout << ((compare(set23o, set23) && set23o.size() == set23.size())?"✅":"❌");
		std::cout << ((compare(set21o, set21) && set21o.size() == set21.size())?"✅":"❌") << std::endl;
	}

	std::cout << "clear()              |";
	{
		set11.clear();
		std::cout << (((set11.begin() == set11.end()) && (set11.size() == 0))?"✅":"❌");
		set11.clear();
		std::cout << (((set11.begin() == set11.end()) && (set11.size() == 0))?"✅":"❌");
		set12.clear();
		std::cout << (((set12.begin() == set12.end()) && (set12.size() == 0))?"✅":"❌");
		set12.clear();
		std::cout << (((set12.begin() == set12.end()) && (set12.size() == 0))?"✅":"❌");
		set13.clear();
		std::cout << (((set13.begin() == set13.end()) && (set13.size() == 0))?"✅":"❌");
		set13.clear();
		std::cout << (((set13.begin() == set13.end()) && (set13.size() == 0))?"✅":"❌");
		set21.clear();
		std::cout << (((set21.begin() == set21.end()) && (set21.size() == 0))?"✅":"❌");
		set21.clear();
		std::cout << (((set21.begin() == set21.end()) && (set21.size() == 0))?"✅":"❌");
		set22.clear();
		std::cout << (((set22.begin() == set22.end()) && (set22.size() == 0))?"✅":"❌");
		set22.clear();
		std::cout << (((set22.begin() == set22.end()) && (set22.size() == 0))?"✅":"❌");
		set23.clear();
		std::cout << (((set23.begin() == set23.end()) && (set23.size() == 0))?"✅":"❌");
		set23.clear();
		std::cout << (((set23.begin() == set23.end()) && (set23.size() == 0))?"✅":"❌") << std::endl;
	}
}
