/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 13:33:05 by mmoreira          #+#    #+#             */
/*   Updated: 2022/05/16 02:02:31 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_HPP
# define FT_MAP_HPP

#include "rb_tree.hpp"
#include "functional.hpp"

namespace ft
{
	template <class Key, class T, class Compare = ft::less<Key>,
			class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map
	{
		public:
			typedef Key								key_type;
			typedef T								mapped_type;
			typedef ft::pair<const Key, T>			value_type;
			typedef Compare							key_compare;
			typedef Alloc							allocator_type;

			class value_compare
			: public ft::binary_function<value_type, value_type, bool>
			{
				private:
					friend class map;

				protected:
					Compare	_comp;
					value_compare( Compare c ): _comp(c) {};

				public:
					bool	operator()( const value_type& x, const value_type& y ) const {
						return (_comp(x.first, y.first));
					};
			};

		private:
			typedef typename Alloc::template rebind<value_type>::other
				pair_alloc_type;
			typedef ft::rb_tree<key_type, value_type, ft::select1st<value_type>,
				key_compare, allocator_type>	tree_type;

		public:
			typedef typename pair_alloc_type::pointer			pointer;
			typedef typename pair_alloc_type::const_pointer		const_pointer;
			typedef typename pair_alloc_type::reference			reference;
			typedef typename pair_alloc_type::const_reference	const_reference;
			typedef typename tree_type::iterator				iterator;
			typedef typename tree_type::const_iterator			const_iterator;
			typedef typename tree_type::reverse_iterator		reverse_iterator;
			typedef typename tree_type::const_reverse_iterator	const_reverse_iterator;
			typedef typename tree_type::difference_type			difference_type;
			typedef typename tree_type::size_type				size_type;

		private:
			tree_type	_tree;

		public:
			//construtores
			explicit	map( const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type() )
			: _tree(comp, alloc) {};

			template <class InputIterator>
			map( InputIterator first, InputIterator last,
			const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type())
			: _tree(comp, alloc) {
				while (first != last)
					this->_tree.insert(*first++);
			};

			map( const map& src ): _tree(src._tree) {};

			~map( void ) {};

			map&	operator=( const map& rhs ) {
				if (this != &rhs)
					this->_tree = rhs._tree;
				return (*this);
			};

			iterator	begin( void ) {
				return (this->_tree.begin());
			};

			const_iterator	begin( void ) const {
				return (this->_tree.cbegin());
			};

			iterator	end( void ) {
				return (this->_tree.end());
			};

			const_iterator end( void ) const {
				return (this->_tree.end());
			};

			reverse_iterator	rbegin( void ) {
				return (this->_tree.rbegin());
			};

			const_reverse_iterator	rbegin( void ) const {
				return (this->_tree.rend());
			};

			reverse_iterator	rend( void ) {
				return (this->_tree.rend());
			};

			const_reverse_iterator	rend( void ) const {
				return (this->_tree.rend());
			};


			bool	empty( void ) const {
				return (this->_tree.empty());
			};

			size_type	size( void ) const {
				return (this->_tree.size());
			};

			size_type	max_size( void ) const {
				return (this->_tree.max_size());
			};


			mapped_type&	operator[]( const key_type& key ) {
				this->_tree.insert(ft::make_pair(key, mapped_type()));
				return ((*(this->_tree.find(key))).second);
			};


			pair<iterator, bool>	insert( const value_type& val ) {
				key_type	key = ft::select1st<value_type>()(val);
				this->_tree.insert(val);
				return (ft::make_pair<iterator, bool>(this->_tree.find(key), this->_tree.count(key)));
			};

			iterator	insert( iterator position, const value_type& val ) {
				(void) position;
				return ((this->insert(val))->first);
			};

			template <class InputIterator>
			void	insert( InputIterator first, InputIterator last ) {
				while (first != last)
					this->_tree.insert(*first++);
			};

			void	erase( iterator position ) {
				this->_tree.erase(*position);
			};

			size_type	erase( const key_type& key ) {
				size_type	ret = this->_tree.count(key);
				this->_tree.erase(*(this->_tree.find(key)));
				return (ret);
			};

			void	erase( iterator first, iterator last ) {
				while (first != last)
					this->_tree.erase(*first++);
			};

			void	swap( map& x ) {
				tree_type	temp = x._tree;
				x._tree	= this->_tree;
				this->_tree = temp;
			};

			void	clear( void ) {
				return (this->_tree.clear());
			};


			key_compare	key_comp( void ) const {
				return (this->_tree.key_comp());
			};

			value_compare	value_comp( void ) const {
				return (value_compare(this->key_comp));
			};


			iterator	find( const key_type& key ) {
				return (this->_tree.find(key));
			};
			const_iterator	find( const key_type& key ) const {
				return (this->_tree.find(key));
			};

			size_type	count( const key_type& key ) const {
				return (this->_tree.count(key));
			};

			iterator	lower_bound( const key_type& key ) {
				return (this->_tree.lower_bound(key));
			};

			const_iterator	lower_bound( const key_type& key ) const {
				return (this->_tree.lower_bound(key));
			};

			iterator	upper_bound( const key_type& key ) {
				return (this->_tree.upper_bound(key));
			};

			const_iterator	upper_bound( const key_type& key ) const {
				return (this->_tree.upper_bound(key));
			};

			pair<iterator, iterator>	equal_range( const key_type& key ) {
				return (this->_tree.equal_range(key));
			};

			pair<const_iterator, const_iterator>	equal_range( const key_type& key ) const {
				return (this->_tree.equal_rande(key));
			};


			allocator_type	get_allocator( void ) const {
				return (this->_tree.get_allocator());
			};
	};
}

#endif
