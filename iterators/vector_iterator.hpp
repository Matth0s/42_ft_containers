/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 21:27:13 by mmoreira          #+#    #+#             */
/*   Updated: 2022/04/21 22:07:04 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_ITERATOR_HPP
# define FT_VECTOR_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{
	template <typename T>
	class random_access_iterator
	{
		public:
			typedef random_access_iterator<T>							iterator;
			typedef std::random_access_iterator_tag						iterator_category;
			typedef typename ft::iterator_traits<T*>::value_type		value_type;
			typedef typename ft::iterator_traits<T*>::difference_type	difference_type;
			typedef typename ft::iterator_traits<T*>::pointer			pointer;
			typedef typename ft::iterator_traits<T*>::reference			reference;

		protected:
			pointer	_ptr;

		public:
			random_access_iterator( void ): _ptr(NULL) {};
			explicit random_access_iterator( pointer ptr ): _ptr(ptr) {};
			random_access_iterator( const iterator& src ): _ptr(src.base()) {};
			~random_access_iterator( void ) {};

			iterator&	operator=( const iterator& rhs ) {
				if (this != &rhs)
					this->_ptr = rhs._ptr;
				return (*this);
			};

			pointer	base( void ) const {
				return (this->_ptr);
			};

			reference	operator*( void ) const {
				return (*(this->base()));
			};

			pointer		operator->( void ) const {
				return (&(this->operator*()));
			};

			reference	operator[]( difference_type n ) const {
				return (*(this->_ptr + n));
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
	};

	template <typename T>
	random_access_iterator<T> operator+(
			typename random_access_iterator<T>::difference_type n,
			const random_access_iterator<T>& it ) {
		return (it + n);
	};

	template <typename T>
	typename random_access_iterator<T>::difference_type	operator-(
		const random_access_iterator<T>& lhs,
		const random_access_iterator<T>& rhs ) {
		return (lhs.base() - rhs.base());
	};

	template <typename T>
	bool	operator==( const random_access_iterator<T>& lhs,
						const random_access_iterator<T>& rhs ) {
		return (lhs.base() == rhs.base());
	};

	template <typename T>
	bool	operator!=( const random_access_iterator<T>& lhs,
						const random_access_iterator<T>& rhs ) {
		return (lhs.base() != rhs.base());
	};

	template <typename T>
	bool	operator<( const random_access_iterator<T>& lhs,
						const random_access_iterator<T>& rhs ) {
		return (lhs.base() < rhs.base());
	};

	template <typename T>
	bool	operator<=( const random_access_iterator<T>& lhs,
						const random_access_iterator<T>& rhs ) {
		return (lhs.base() <= rhs.base());
	};

	template <typename T>
	bool	operator>( const random_access_iterator<T>& lhs,
						const random_access_iterator<T>& rhs ) {
		return (lhs.base() > rhs.base());
	};

	template <typename T>
	bool	operator>=( const random_access_iterator<T>& lhs,
						const random_access_iterator<T>& rhs ) {
		return (lhs.base() >= rhs.base());
	};
}

#endif
