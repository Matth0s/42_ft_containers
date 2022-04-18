/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:20:54 by mmoreira          #+#    #+#             */
/*   Updated: 2022/04/18 15:21:43 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

#include <iostream>

namespace ft
{
	template< class Iter >
	struct iterator_traits
	{
		typedef typename Iter::iterator_category	iterator_category;
		typedef typename Iter::value_type			value_type;
		typedef typename Iter::pointer				pointer;
		typedef typename Iter::reference			reference;
		typedef typename Iter::difference_type		difference_type;
	};

	template< typename T >
	struct iterator_traits< T* >
	{
		typedef std::random_access_iterator_tag		iterator_category;
		typedef T									value_type;
		typedef T*									pointer;
		typedef T&									reference;
		typedef std::ptrdiff_t						difference_type;
	};

	template< typename T >
	struct iterator_traits< const T* >
	{
		typedef std::random_access_iterator_tag		iterator_category;
		typedef T									value_type;
		typedef const T*							pointer;
		typedef const T&							reference;
		typedef std::ptrdiff_t						difference_type;
	};
}

#endif
