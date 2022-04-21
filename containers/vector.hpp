/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:58:30 by mmoreira          #+#    #+#             */
/*   Updated: 2022/04/20 23:38:42 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

#include <memory>
#include <exception>
#include "vector_iterator.hpp"
#include "reverse_iterator.hpp"
#include "type_traits.hpp"

namespace ft
{
	template<typename T, class Alloc = std::allocator<T> >
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
			size_type		_size;
			size_type		_capacity;
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
			vector( InputIterator first,
					InputIterator last,
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
						for (size_type i = 0; i < this->_size; i++)
							this->_alloc.destroy(this->_data + i);
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

			/* Iterators: */

			// begin
			iterator	begin( void ) {
				return (iterator(this->_data));
			};
			const_iterator	begin( void ) const {
				return (const_iterator(this->_data));
			};

			// end
			iterator	end( void ) {
				return (iterator(this->_data + this->_size));
			};
			const_iterator	end( void ) const {
				return (const_iterator(this->_data + this->_size));
			};

			// rbegin
			reverse_iterator	rbegin( void ) {
				return (reverse_iterator(this->end()));
			};
			const_reverse_iterator	rbegin( void ) const {
				return (const_reverse_iterator(this->end()));
			};

			// rend
			reverse_iterator	rend( void ) {
				return (reverse_iterator(this->begin()));
			};
			const_reverse_iterator	rend( void ) const {
				return (const_reverse_iterator(this->begin()));
			};


			/* Capacity: */

			// size
			// size_type	size( void ) const {
			// 	return (this->_size);
			// };

			// max_size
			// size_type	max_size( void ) const {
				// return (this->_alloc.max_size());
			// };

			// resize
			// void	resize( size_type n, value_type val = value_type() );

			// capacity
			// size_type	capacity( void ) const {
				// return (this->_capacity);
			// };

			// empty
			// bool	empty( void ) const {
				// return (this->_size == 0);
			// };
			// reserve
			// void reserve (size_type n);


			/* Element access: */

			// operator[]
			reference	operator[]( size_type n ) {
				return (*(this->_data + n));
			};
			const_reference	operator[]( size_type n ) const {
				return (*(this->_data + n));
			};

			// at
			// reference	at( size_type n ) {
			// 	if (n < 0 || n >= this->_size)
			// 		throw std::out_of_range();
			// 	return (*(this->_data + n));
			// };
			// const_reference	at( size_type n ) const {
			// 	if (n < 0 || n >= this->_size)
			// 		throw std::out_of_range();
			// 	return (*(this->_data + n));
			// };

			// front
			// reference	front( void ) {
				// return (*this->_data);
			// };
			// const_reference	front( void ) const {
				// return (*this->_data);
			// };

			// back
			// reference	back( void ) {
				// return (*(this->_data + this->_size - 1));
			// };
			// const_reference	back( void ) const {
				// return (*(this->_data + this->_size - 1));
			// };


			// assign
			// push_back
			// pop_back
			// insert
			// erase
			// swap
			// clear

			// get_allocator
			// allocator_type get_allocator( void ) const {
			// 	return (allocator_type(this->_alloc));
			// };

			// relational operators
			// swap
	};
}


// (construtor) ^^
// (destruidor) ^^
// operador= ----------------

// begin ^^
// end ^^
// rbegin ^^
// rend ^^

// size ^^
// max_size ^^
// resize ----------------
// capacity ^^
// empty ^^
// reserve ----------------

// operator[] ^^
// at ----------------
// front ^^
// back ^^

// assign ----------------
// push_back ----------------
// pop_back ----------------
// insert ----------------
// erase ----------------
// swap ----------------
// clear ----------------

// get_allocator ^^

// relational operators ----------------
// swap ----------------


#endif
