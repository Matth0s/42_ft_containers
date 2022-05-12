/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 21:27:13 by mmoreira          #+#    #+#             */
/*   Updated: 2022/05/12 00:33:45 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_ITERATOR_HPP
# define FT_VECTOR_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{
	template <typename Iterator>
	class vector_iterator
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
			vector_iterator( void ): _ptr(NULL) {};
			explicit vector_iterator( const iterator_type& ptr ): _ptr(ptr) {};
			vector_iterator( const vector_iterator& src ): _ptr(src.base()) {};
			~vector_iterator( void ) {};

			template <typename Iter>
			vector_iterator&	operator=( const vector_iterator<Iter>& rhs ) {
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

			vector_iterator	operator+( difference_type n ) const {
				return (vector_iterator(this->_ptr + n));
			};

			vector_iterator&	operator++( void ) {
				++this->_ptr;
				return (*this);
			};

			vector_iterator	operator++( int ) {
				return (vector_iterator(this->_ptr++));
			};

			vector_iterator&	operator+=( difference_type n) {
				this->_ptr += n;
				return (*this);
			};

			vector_iterator	operator-( difference_type n ) const {
				return (vector_iterator(this->_ptr - n));
			};

			vector_iterator&	operator--( void ) {
				--this->_ptr;
				return (*this);
			};

			vector_iterator	operator--( int ) {
				return (vector_iterator(this->_ptr--));
			};

			vector_iterator&	operator-=( difference_type n ) {
				this->_ptr -= n;
				return (*this);
			};
	};

	template <typename T>
	vector_iterator<T> operator+(
			typename vector_iterator<T>::difference_type n,
			const vector_iterator<T>& it ) {
		return (it + n);
	};

	template <typename T>
	typename vector_iterator<T>::difference_type	operator-(
		const vector_iterator<T>& lhs,
		const vector_iterator<T>& rhs ) {
		return (lhs.base() - rhs.base());
	};

	template <typename T, typename U>
	bool	operator==( const vector_iterator<T>& lhs,
						const vector_iterator<U>& rhs ) {
		return (lhs.base() == rhs.base());
	};

	template <typename T, typename U>
	bool	operator!=( const vector_iterator<T>& lhs,
						const vector_iterator<U>& rhs ) {
		return (lhs.base() != rhs.base());
	};

	template <typename T, typename U>
	bool	operator<( const vector_iterator<T>& lhs,
						const vector_iterator<U>& rhs ) {
		return (lhs.base() < rhs.base());
	};

	template <typename T, typename U>
	bool	operator<=( const vector_iterator<T>& lhs,
						const vector_iterator<U>& rhs ) {
		return (lhs.base() <= rhs.base());
	};

	template <typename T, typename U>
	bool	operator>( const vector_iterator<T>& lhs,
						const vector_iterator<U>& rhs ) {
		return (lhs.base() > rhs.base());
	};

	template <typename T, typename U>
	bool	operator>=( const vector_iterator<T>& lhs,
						const vector_iterator<U>& rhs ) {
		return (lhs.base() >= rhs.base());
	};
}

#endif
