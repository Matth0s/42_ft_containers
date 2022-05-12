/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:23:50 by mmoreira          #+#    #+#             */
/*   Updated: 2022/05/09 19:38:10 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_REVERSE_ITERATOR_HPP
# define FT_REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{
	template <class Iterator>
	class reverse_iterator
	{
		private:
			typedef typename ft::iterator_traits<Iterator>	traits_type;

		public:
			typedef Iterator								iterator_type;
			typedef typename traits_type::iterator_category	iterator_category;
			typedef typename traits_type::value_type		value_type;
			typedef typename traits_type::difference_type	difference_type;
			typedef typename traits_type::pointer			pointer;
			typedef typename traits_type::reference			reference;

		protected:
			iterator_type	_it;

		public:
			reverse_iterator( void ): _it() {};
			explicit reverse_iterator( const iterator_type it ): _it(it) {};
			reverse_iterator( const reverse_iterator& src ): _it(src.base()) {};
			~reverse_iterator( void ) {};

			template <class Iter>
			reverse_iterator&	operator=( const reverse_iterator<Iter>& rhs ) {
				if (this != &rhs)
					this->_it = rhs.base();
				return (*this);
			};

			iterator_type base( void ) const {
				return (this->_it);
			};

			reference operator*( void ) const {
				return (*(--this->base()));
			};

			pointer operator->( void ) const {
  				return (&(this->operator*()));
			}

			reference operator[]( difference_type n ) const {
				return (*(this->_it - n - 1));
			};

			reverse_iterator operator+( difference_type n ) const {
				return (reverse_iterator(this->_it - n));
			};

			reverse_iterator& operator++( void ) {
				--this->_it;
				return (*this);
			};

			reverse_iterator  operator++( int ) {
				return (reverse_iterator(this->_it--));
			};

			reverse_iterator& operator+=( difference_type n ) {
				this->_it -= n;
				return (*this);
			};

			reverse_iterator operator-( difference_type n ) const {
				return (reverse_iterator(this->_it + n));
			};

			reverse_iterator& operator--( void ) {
				++this->_it;
				return (*this);
			};

			reverse_iterator  operator--( int ) {
				return (reverse_iterator(this->_it++));
			};

			reverse_iterator& operator-=( difference_type n ) {
				this->_it += n;
				return (*this);
			};
	};

	template <class Iterator>
	reverse_iterator<Iterator>	operator+(
			typename reverse_iterator<Iterator>::difference_type n,
			const reverse_iterator<Iterator>& rev_it ) {
		return (rev_it + n);
	};

	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type	operator-(
		const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<Iterator>& rhs ) {
		return (rhs.base() - lhs.base());
	};

	template <class Iterator1, class Iterator2>
	bool	operator==( const reverse_iterator<Iterator1>& lhs,
						const reverse_iterator<Iterator2>& rhs ) {
		return (lhs.base() == rhs.base());
	};

	template <class Iterator1, class Iterator2>
	bool	operator!=( const reverse_iterator<Iterator1>& lhs,
						const reverse_iterator<Iterator2>& rhs ) {
		return (lhs.base() != rhs.base());
	};

	template <class Iterator1, class Iterator2>
	bool	operator<( const reverse_iterator<Iterator1>& lhs,
						const reverse_iterator<Iterator2>& rhs ) {
		return (lhs.base() > rhs.base());
	};

	template <class Iterator1, class Iterator2>
	bool	operator<=( const reverse_iterator<Iterator1>& lhs,
						const reverse_iterator<Iterator2>& rhs ) {
		return (lhs.base() >= rhs.base());
	};

	template <class Iterator1, class Iterator2>
	bool	operator>( const reverse_iterator<Iterator1>& lhs,
						const reverse_iterator<Iterator2>& rhs ) {
		return (lhs.base() < rhs.base());
	};

	template <class Iterator1, class Iterator2>
	bool	operator>=( const reverse_iterator<Iterator1>& lhs,
						const reverse_iterator<Iterator2>& rhs ) {
		return (lhs.base() <= rhs.base());
	};
}

#endif
