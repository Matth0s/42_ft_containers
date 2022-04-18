/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 21:27:13 by mmoreira          #+#    #+#             */
/*   Updated: 2022/04/15 22:47:52 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

#include <iostream>

namespace ft
{
	template< typename T >
	class random_access_iterator
	{
		public:
			typedef random_access_iterator<T>			iterator;
			typedef std::random_access_iterator_tag		iterator_category;
			typedef T									value_type;
			typedef T*									pointer;
			typedef T&									reference;
			typedef std::ptrdiff_t						difference_type;

		private:
			pointer	_ptr;

		public:
			random_access_iterator( void ): _ptr(NULL) {};
			explicit random_access_iterator( pointer ptr ): _ptr(ptr) {};
			random_access_iterator( const iterator& src ) { this->operator=( src ); };
			~random_access_iterator( void ) {};

			iterator& operator=( const iterator& rhs ) {
				if (this != &rhs)
					this->_ptr = rhs._ptr;
				return (*this);
			};

			reference	operator*( void ) const {
				return (*this->_ptr);
			};

			pointer		operator->( void ) const {
				return (this->_ptr);
			};

			reference	operator[]( difference_type n ) const {
				return (this->_ptr[n]);
			};

			iterator	operator+( difference_type n ) const {
				return (iterator(this->_ptr + n));
			};

			iterator&	operator++( void ) {
				++this->_ptr;
				return (*this);
			};

			iterator	operator++( int ) {
				iterator it(*this);
				this->_ptr++;
				return (it);
			};
			iterator&	operator+=( difference_type n) {
				this->_ptr += n;
				return (*this);
			};

			iterator	operator-( difference_type n ) const {
				return (iterator(this->_ptr - n));
			};

			iterator&	operator--( void ) {
				--this->_ptr;
				return (*this);
			};

			iterator	operator--( int ) {
				iterator it(*this);
				this->_ptr--;
				return (it);
			};

			iterator&	operator-=( difference_type n ) {
				this->_ptr -= n;
				return (*this);
			};

			difference_type	operator-( const iterator& rhs ) {
				return (this->_ptr - rhs._ptr);
			};

			bool	operator==( const iterator& rhs ) {
				return (this->_ptr == rhs._ptr);
			};

			bool	operator!=( const iterator& rhs ) {
				return (this->_ptr != rhs._ptr);
			};

			bool	operator<( const iterator& rhs ) {
				return (this->_ptr < rhs._ptr);
			};

			bool	operator<=( const iterator& rhs ) {
				return (this->_ptr <= rhs._ptr);
			};

			bool	operator>( const iterator& rhs ) {
				return (this->_ptr > rhs._ptr);
			};

			bool	operator>=( const iterator& rhs ) {
				return (this->_ptr >= rhs._ptr);
			};
	};

	template <typename T>
	random_access_iterator<T> operator+(
			typename random_access_iterator<T>::difference_type n,
			const random_access_iterator<T>& it) {
		return (it + n);
	};
}

#endif
