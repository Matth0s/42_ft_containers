/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:58:30 by mmoreira          #+#    #+#             */
/*   Updated: 2022/04/18 15:21:25 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

#include <memory>
#include "iterator_traits.hpp"
#include "vector_iterator.hpp"

namespace ft
{
	template<class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef T												value_type;
			typedef Alloc											allocator_type;
			typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;
			typedef ft::random_access_iterator<value_type>			iterator
			typedef ft::random_access_iterator<const value_type>	const_iterator;
			typedef ft::reverse_iterator<iterator>					reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef std::ptrdiff_t									difference_type;
			typedef std::size_t										size_type;

		private:
			size_t			_size;
			size_t			_capacity;
			value_type*		_data;
			allocator_type	_alloc;

		public:
			// (constructor)
			explicit vector( const allocator_type& alloc = allocator_type() )
			:	_size(0), _capacity(0), _alloc(alloc), _data(NULL) {};

			explicit vector ( size_type n, const value_type& val = value_type(),
							const allocator_type& alloc = allocator_type() )
			:	_data(NULL), _alloc(alloc), _size(n), _capacity(n) {
				this._data = this._alloc.allocator(this._size)
			};
			range (3) template <class InputIterator>
         					vector (InputIterator first, InputIterator last,
                 			const allocator_type& alloc = allocator_type());
			copy (4) vector (const vector& x);

			// (destructor)
			// operator=

			// begin
			// end
			// rbegin
			// rend

			// size
			// max_size
			// resize
			// capacity
			// empty
			// reserve

			// operator[]
			// at
			// front
			// back

			// assign
			// push_back
			// pop_back
			// insert
			// erase
			// swap
			// clear

			// get_allocator

			// relational operators
			// swap
	};
}

#endif
