/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:58:30 by mmoreira          #+#    #+#             */
/*   Updated: 2022/04/18 23:21:35 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

#include <memory>
#include "vector_iterator.hpp"
#include "reverse_iterator.hpp"

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
			typedef ft::random_access_iterator<value_type>			iterator;
			typedef ft::random_access_iterator<const value_type>	const_iterator;
			typedef ft::reverse_iterator<iterator>					reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef std::ptrdiff_t									difference_type;
			typedef std::size_t										size_type;

		private:
			size_t			_size;
			size_t			_capacity;
			allocator_type	_alloc;
			value_type*		_data;

		public:
			explicit vector( const allocator_type& alloc = allocator_type() )
			:	_size(0), _capacity(0), _alloc(alloc), _data(NULL) {};

			explicit vector( size_type n, const value_type& val = value_type(),
							const allocator_type& alloc = allocator_type() )
			:	_size(n), _capacity(n), _alloc(alloc),
				_data(this->_alloc.allocate(this->_capacity)) {
				for (size_type i = 0; i < this->_size; i++)
					this->_alloc.construct(this->_data + i, val);
			};

			template <class InputIterator>
			vector( InputIterator first, InputIterator last,
							const allocator_type& alloc = allocator_type() )
			:	_size(last - first), _capacity(last - first), _alloc(alloc),
				_data(this->_alloc.allocate(this->_capacity)) {
				for (size_type i = 0; i < this->_size; i++) {
					this->_alloc.construct(this->_data + i, *first);
					first++;
				}
			};

			vector( const vector& src )
			:	_size(0), _capacity(0), _alloc(src._alloc), _data(NULL) {
				this->operator=( src );
			};

			~vector( void ) {
				this->_alloc.deallocate(this->_data, this->_capacity);
			};

			vector&	operator=( const vector& rhs ) {
				if (this != &rhs) {
					if (this->_capacity < rhs._size) {
						this->_alloc.deallocate(this->_data, this->_capacity);
						this->_capacity = rhs._capacity;
						this->_data = this->_alloc.allocate(this->_capacity);
					}
					this->_size = rhs._size;
					for (size_type i = 0; i < this->_size; i++)
						this->_alloc.construct(this->_data + i, rhs[i]);
				}
				return (*this);
			};

			// begin
			iterator begin( void ) {
				return (iterator(this->_data));
			};
			const_iterator begin( void ) const {
				return (const_iterator(this->_data));
			};

			// end
			iterator end( void ) {
				return (iterator(this->_data + this->_size));
			};
			const_iterator end( void ) const {
				return (const_iterator(this->_data + this->_size));
			};

			// // rbegin
			// reverse_iterator rbegin( void ) {
			// 	return (reverse_iterator(this->end() - 1));
			// };
			// const_reverse_iterator rbegin( void ) const {
			// 	return (const_reverse_iterator(this->end() - 1));
			// };

			// // rend
			// reverse_iterator rend( void ) {
			// 	return (reverse_iterator(this->begin() - 1));
			// };
			// const_reverse_iterator rend( void ) const {
			// 	return (const_reverse_iterator(this->begin() - 1));
			// };


			// // size
			// size_type size() const {
			// 	return (this->_size);
			// };

			// // max_size
			// size_type max_size() const {
			// 	return (this->_alloc.max_size());
			// };

			// // resize
			// // capacity
			// size_type	capacity( void ) const {
			// 	return (this->_capacity);
			// };
			// empty
			// reserve

			// operator[]
			reference	operator[]( size_type n ) {
				return (this->_data[n]);
			};
			const_reference	operator[]( size_type n ) const {
				return (this->_data[n]);
			};

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
			allocator_type get_allocator( void ) const {
				return (allocator_type(this->_alloc));
			};

			// relational operators
			// swap
	};
}

#endif
