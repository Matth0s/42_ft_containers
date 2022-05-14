/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 21:27:13 by mmoreira          #+#    #+#             */
/*   Updated: 2022/05/13 23:56:10 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_ITERATOR_HPP
# define FT_VECTOR_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{
	template <typename Iterator>
	class normal_iterator
	{
		private:
			typedef typename ft::iterator_traits<Iterator>	traits_type;

		public:
			typedef Iterator								iterator_type;
			typedef ft::random_access_iterator_tag			iterator_category;
			typedef typename traits_type::value_type		value_type;
			typedef typename traits_type::difference_type	difference_type;
			typedef typename traits_type::pointer			pointer;
			typedef typename traits_type::reference			reference;

		protected:
			iterator_type	_ptr;

		public:
			normal_iterator( void ): _ptr(NULL) {};
			explicit normal_iterator( const iterator_type& ptr ): _ptr(ptr) {};
			normal_iterator( const normal_iterator& src ): _ptr(src.base()) {};
			~normal_iterator( void ) {};

			template <typename Iter>
			normal_iterator&	operator=( const normal_iterator<Iter>& rhs ) {
				this->_ptr = rhs.base();
				return (*this);
			};

			const iterator_type&	base( void ) const {
				return (this->_ptr);
			};

			reference	operator*( void ) const {
				return (*(this->base()));
			};

			pointer	operator->( void ) const {
				return (&(this->operator*()));
			};

			reference	operator[]( difference_type n ) const {
				return (*(this->_ptr + n));
			};

			normal_iterator	operator+( difference_type n ) const {
				return (normal_iterator(this->_ptr + n));
			};

			normal_iterator&	operator++( void ) {
				++this->_ptr;
				return (*this);
			};

			normal_iterator	operator++( int ) {
				return (normal_iterator(this->_ptr++));
			};

			normal_iterator&	operator+=( difference_type n) {
				this->_ptr += n;
				return (*this);
			};

			normal_iterator	operator-( difference_type n ) const {
				return (normal_iterator(this->_ptr - n));
			};

			normal_iterator&	operator--( void ) {
				--this->_ptr;
				return (*this);
			};

			normal_iterator	operator--( int ) {
				return (normal_iterator(this->_ptr--));
			};

			normal_iterator&	operator-=( difference_type n ) {
				this->_ptr -= n;
				return (*this);
			};
	};

	template <typename T>
	normal_iterator<T> operator+(
			typename normal_iterator<T>::difference_type n,
			const normal_iterator<T>& it ) {
		return (it + n);
	};

	template <typename T>
	typename normal_iterator<T>::difference_type	operator-(
		const normal_iterator<T>& lhs,
		const normal_iterator<T>& rhs ) {
		return (lhs.base() - rhs.base());
	};

	template <typename T, typename U>
	bool	operator==( const normal_iterator<T>& lhs,
						const normal_iterator<U>& rhs ) {
		return (lhs.base() == rhs.base());
	};

	template <typename T, typename U>
	bool	operator!=( const normal_iterator<T>& lhs,
						const normal_iterator<U>& rhs ) {
		return (lhs.base() != rhs.base());
	};

	template <typename T, typename U>
	bool	operator<( const normal_iterator<T>& lhs,
						const normal_iterator<U>& rhs ) {
		return (lhs.base() < rhs.base());
	};

	template <typename T, typename U>
	bool	operator<=( const normal_iterator<T>& lhs,
						const normal_iterator<U>& rhs ) {
		return (lhs.base() <= rhs.base());
	};

	template <typename T, typename U>
	bool	operator>( const normal_iterator<T>& lhs,
						const normal_iterator<U>& rhs ) {
		return (lhs.base() > rhs.base());
	};

	template <typename T, typename U>
	bool	operator>=( const normal_iterator<T>& lhs,
						const normal_iterator<U>& rhs ) {
		return (lhs.base() >= rhs.base());
	};
}

#endif
