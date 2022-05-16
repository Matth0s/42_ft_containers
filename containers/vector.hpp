/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:58:30 by mmoreira          #+#    #+#             */
/*   Updated: 2022/05/14 05:33:31 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

#include <memory>
#include <exception>
#include "normal_iterator.hpp"
#include "reverse_iterator.hpp"
#include "type_traits.hpp"
#include "algorithm.hpp"

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
			typedef ft::normal_iterator<pointer>					iterator;
			typedef ft::normal_iterator<const_pointer>				const_iterator;
			typedef ft::reverse_iterator<iterator>					reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef std::ptrdiff_t									difference_type;
			typedef std::size_t										size_type;

		private:
			class _out_of_range : public std::exception
			{
				public:
					virtual const char* what() const throw() {
						return ("vector::out_of_range: n >= this->_size()");
				};
			};

		protected:
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
			vector( typename ft::enable_if<!(ft::is_integral<InputIterator>::value), InputIterator>::type
					first, InputIterator last, const allocator_type& alloc = allocator_type() )
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
				if (this != &rhs)
				{
					if (this->_capacity < rhs._size)
						this->reserve(rhs._size);
					for (size_type i = 0; i < rhs._size; i++)
						this->_alloc.construct(this->_data + i, rhs[i]);
					this->_size = rhs._size;
				}
				return (*this);
			};


			iterator	begin( void ) {
				return (iterator(this->_data));
			};

			const_iterator	begin( void ) const {
				return (const_iterator(this->_data));
			};

			iterator	end( void ) {
				return (iterator(this->_data + this->_size));
			};

			const_iterator	end( void ) const {
				return (const_iterator(this->_data + this->_size));
			};

			reverse_iterator	rbegin( void ) {
				return (reverse_iterator(this->end()));
			};

			const_reverse_iterator	rbegin( void ) const {
				return (const_reverse_iterator(this->end()));
			};

			reverse_iterator	rend( void ) {
				return (reverse_iterator(this->begin()));
			};

			const_reverse_iterator	rend( void ) const {
				return (const_reverse_iterator(this->begin()));
			};


			size_type	size( void ) const {
				return (this->_size);
			};

			size_type	max_size( void ) const {
				return (this->_alloc.max_size());
			};

			void	resize( size_type n, value_type val = value_type() ) {
				if (this->_capacity < n)
				{
					this->reserve(n);
					for (size_type i = this->_size; i < n; i++)
						this->_alloc.construct(this->_data + i, val);
				}
				else
				{
					for (size_type i = this->_size; i < n; i++)
						this->_alloc.construct(this->_data + i, val);
					for (size_type i = n; i < this->_size; i++)
						this->_alloc.destroy(this->_data + i);
				}
				this->_size = n;
			};

			size_type	capacity( void ) const {
				return (this->_capacity);
			};

			bool	empty( void ) const {
				return (this->_size == 0);
			};

			void reserve( size_type n ) {
				if (this->_capacity < n)
				{
					value_type*	data = this->_alloc.allocate(n);
					for (size_type i = 0; i < this->_size; i++) {
						this->_alloc.construct(data + i, *(this->_data + i));
						this->_alloc.destroy(this->_data + i);
					}
					this->_alloc.deallocate(this->_data, this->_capacity);
					this->_data = data;
					this->_capacity = n;
				}
			};


			reference	operator[]( size_type n ) {
				return (*(this->_data + n));
			};

			const_reference	operator[]( size_type n ) const {
				return (*(this->_data + n));
			};

			reference	at( size_type n ) {
				if (n >= this->_size)
					throw vector::_out_of_range();
				return (*(this->_data + n));
			};

			const_reference	at( size_type n ) const {
				if (n >= this->_size)
					throw vector::_out_of_range();
				return (*(this->_data + n));
			};

			reference	front( void ) {
				return (*this->_data);
			};

			const_reference	front( void ) const {
				return (*this->_data);
			};

			reference	back( void ) {
				return (*(this->_data + this->_size - 1));
			};

			const_reference	back( void ) const {
				return (*(this->_data + this->_size - 1));
			};

			void	assign( size_type n, const value_type& val ) {
				if (this->_capacity < n)
				{
					ft::vector<value_type, allocator_type> temp(n, val, this->_alloc);
					temp.swap(*this);
				}
				else
				{
					this->_size = n;
					for (size_type i = 0; i < this->_size; i++)
						this->_alloc.construct(this->_data + i, val);
				}
			}

			template <class InputIterator>
			void	assign( typename ft::enable_if<!(ft::is_integral<InputIterator>::value), InputIterator>::type
							first, InputIterator last ) {
				size_type	size = last - first;
				if (this->_capacity < size)
				{
					ft::vector<value_type, allocator_type> temp(first, last, this->_alloc);
					temp.swap(*this);
				}
				else
				{
					this->_size = size;
					for (size_type i = 0; i < size; i++)
						this->_alloc.construct(this->_data + i, *(first + i));
				}
			};

			void	push_back( const value_type& val ) {
				if (this->_size == this->_capacity)
				{
					if (this->_size == 0)
						this->reserve(1);
					else
						this->reserve(this->_size * 2);
				}
				this->_alloc.construct(this->_data + this->_size++, val);
			};

			void	pop_back( void ) {
				this->_alloc.destroy(this->_data + --this->_size);
			};

			iterator	insert( iterator position, const value_type& val ) {
				difference_type	diff = position - this->begin();
				if (this->_size == this->_capacity)
					this->reserve(this->_capacity * 2);
				position = this->begin() + diff;
				for (iterator it = this->end(); it != position; it--)
					this->_alloc.construct(&(*it), *(it - 1));
				this->_alloc.construct(&(*(position)), val);
				this->_size++;
				return (position);
			};

			void	insert( iterator position, size_type n, const value_type& val ) {
				difference_type	diff = position - this->begin();
				if ((this->_size + n > this->_capacity)
					&& (this->_size + n > this->_size * 2))
					this->reserve(this->_size + n);
				else if (this->_size + n > this->_capacity)
					this->reserve(this->_size * 2);
				position = this->begin() + diff;
				for (iterator it = this->end(); it != position; it--)
					this->_alloc.construct(&(*(it + n - 1)), *(it - 1));
				for (iterator it = position; it != position + n; it++)
					this->_alloc.construct(&(*it), val);
				this->_size += n;
			};

			template <class InputIterator>
			void	insert( iterator position, typename ft::enable_if<!(ft::is_integral<InputIterator>::value), InputIterator>::type
							 first, InputIterator last ) {
				difference_type	diff = position - this->begin();
				size_type		n  = last - first;
				if ((this->_size + n > this->_capacity)
					&& (this->_size + n > this->_size * 2))
					this->reserve(this->_size + n);
				else if (this->_size + n > this->_capacity)
					this->reserve(this->_size * 2);
				position = this->begin() + diff;
				for (iterator it = this->end(); it != position; it--)
					this->_alloc.construct(&(*(it + n - 1)), *(it - 1));
				for (iterator it = position; it != position + n; it++)
					this->_alloc.construct(&(*it), *(first++));
				this->_size += n;
			};

			iterator	erase( iterator position ) {
				for (iterator it = position + 1; it < this->end(); it++)
					this->_alloc.construct(&(*(it - 1)), *it);
				this->_alloc.destroy(this->_data + --this->_size);
				return (position);
			};

			iterator	erase( iterator first, iterator last) {

				for (iterator it = last; it < this->end(); it++)
					this->_alloc.construct(&(*(first - last	+ it)), *it);
				this->_size -= (last - first);
				return (first);
			};

			void	swap( vector& src ) {
				size_type		size = this->_size;
				size_type		capacity = this->_capacity;
				allocator_type	alloc = this->_alloc;
				value_type*		data = this->_data;

				this->_size = src._size;
				this->_capacity = src._capacity;
				this->_alloc = src._alloc;
				this->_data = src._data;

				src._size = size;
				src._capacity = capacity;
				src._alloc = alloc;
				src._data = data;
			}

			void	clear( void ) {
				for (size_type i = 0; i < this->_size; i++)
					this->_alloc.destroy(this->_data + i);
				this->_size= 0;
			};

			allocator_type get_allocator( void ) const {
				return (allocator_type(this->_alloc));
			};

	};

	template <class T, class Alloc>
	void	swap( vector<T,Alloc>& lhs, vector<T,Alloc>& rhs ) {
		lhs.swap(rhs);
	};

	template <class T, class Alloc>
	bool	operator==( const vector<T,Alloc>& lhs,
						const vector<T,Alloc>& rhs ) {
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin())
				&& (lhs.size() == rhs.size()));
	};

	template <class T, class Alloc>
	bool	operator!=( const vector<T,Alloc>& lhs,
						const vector<T,Alloc>& rhs ) {
		return (!(lhs == rhs));
	};

	template <class T, class Alloc>
	bool	operator<( const vector<T,Alloc>& lhs,
						const vector<T,Alloc>& rhs ) {
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(),
											rhs.begin(), rhs.end()));
	};

	template <class T, class Alloc>
	bool	operator<=( const vector<T,Alloc>& lhs,
						const vector<T,Alloc>& rhs) {
		return (!(rhs < lhs));
	};

	template <class T, class Alloc>
	bool	operator>( const vector<T,Alloc>& lhs,
						const vector<T,Alloc>& rhs ) {
		return (!(lhs <= rhs));
	};

	template <class T, class Alloc>
	bool	operator>=( const vector<T,Alloc>& lhs,
						const vector<T,Alloc>& rhs ) {
		return (!(lhs < rhs));
	};
}

#endif
