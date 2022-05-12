/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 21:27:13 by mmoreira          #+#    #+#             */
/*   Updated: 2022/05/12 13:35:02 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RB_ITERATOR_HPP
# define FT_RB_ITERATOR_HPP

#include "iterator_traits.hpp"
#include "rb_node.hpp"

namespace ft
{
	template <typename T>
	class rb_iterator
	{
		private:
			typedef typename ft::rb_node<T>						node_base;
			typedef typename ft::iterator_traits<node_base*>	traits_type;

		public:
			typedef node_base*									iterator_type;
			typedef ft::bidirectional_iterator_tag				iterator_category;
			typedef typename traits_type::value_type			value_type;
			typedef typename traits_type::difference_type		difference_type;
			typedef typename traits_type::pointer				pointer;
			typedef typename traits_type::reference				reference;

		protected:
			iterator_type	_ptr;
			iterator_type	_null;

		public:
			rb_iterator( void ): _ptr(NULL), _null(NULL) {};
			explicit rb_iterator( const iterator_type& ptr,
									const iterator_type& null )
			: _ptr(ptr), _null(null) {};
			rb_iterator( const rb_iterator& src )
			: _ptr(src.base()), _null(src.baseNull()) {};
			~rb_iterator( void ) {};

			template <typename Iter>
			rb_iterator&	operator=( const rb_iterator<Iter>& rhs ) {
				this->_ptr = rhs.base();
				this->_null = rhs.baseNull();
				return (*this);
			};

			const iterator_type&	base( void ) const {
				return (this->_ptr);
			};

			const iterator_type&	baseNull( void ) const {
				return (this->_null);
			};

			reference	operator*( void ) const {
				return (this->base()->data);
			};

			pointer	operator->( void ) const {
				return (&(this->operator*()));
			};

			rb_iterator&	operator++( void ) {
				this->_ptr = node_base::next(this->_ptr, this->_null);
				return (*this);
			};

			rb_iterator	operator++( int ) {
				rb_iterator	temp(*this);
				this->_ptr = node_base::next(this->_ptr, this->_null);
				return (temp);
			};

			rb_iterator&	operator--( void ) {
				this->_ptr = node_base::prev(this->_ptr, this->_null);
				return (*this);
			};

			rb_iterator	operator--( int ) {
				rb_iterator	temp(*this);
				this->_ptr = node_base::prev(this->_ptr, this->_null);
				return (temp);
			};
	};

	template <typename T, typename U>
	bool	operator==( const rb_iterator<T>& lhs,
						const rb_iterator<U>& rhs ) {
		return (lhs.base() == rhs.base());
	};

	template <typename T, typename U>
	bool	operator!=( const rb_iterator<T>& lhs,
						const rb_iterator<U>& rhs ) {
		return (!(lhs.base() == rhs.base()));
	};
}

#endif
