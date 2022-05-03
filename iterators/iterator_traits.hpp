/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:20:54 by mmoreira          #+#    #+#             */
/*   Updated: 2022/05/03 17:05:25 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ITERATOR_TRAITS_HPP
# define FT_ITERATOR_TRAITS_HPP

#include <iostream>

namespace ft
{
	struct bidirectional_iterator_tag {};
	struct random_access_iterator_tag: public bidirectional_iterator_tag {};

	template< class Iter >
	struct iterator_traits
	{
		typedef typename Iter::iterator_category	iterator_category;
		typedef typename Iter::value_type			value_type;
		typedef typename Iter::difference_type		difference_type;
		typedef typename Iter::pointer				pointer;
		typedef typename Iter::reference			reference;
	};

	template< typename T >
	struct iterator_traits< T* >
	{
		typedef ft::random_access_iterator_tag		iterator_category;
		typedef T									value_type;
		typedef std::ptrdiff_t						difference_type;
		typedef T*									pointer;
		typedef T&									reference;
	};

	template< typename T >
	struct iterator_traits< const T* >
	{
		typedef ft::random_access_iterator_tag		iterator_category;
		typedef T									value_type;
		typedef std::ptrdiff_t						difference_type;
		typedef const T*							pointer;
		typedef const T&							reference;
	};
}

#endif
