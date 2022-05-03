/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 22:43:13 by mmoreira          #+#    #+#             */
/*   Updated: 2022/04/28 13:32:08 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_HPP
# define FT_STACK_HPP

#include "vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef typename Container::value_type			value_type;
			typedef typename Container::reference			reference;
			typedef typename Container::const_reference		const_reference;
			typedef typename Container::size_type			size_type;
			typedef Container								container_type;

		protected:
			container_type	_c;

		public:
			explicit stack( const container_type& ctnr = container_type())
			:	_c(ctnr) {};

			stack( const stack& src ): _c(src) {};

			~stack( void ) {};

			stack&	operator=( const stack& rhs) {
				this->_c = rhs._c;
				return (*this);
			};

			bool	empty( void ) const {
				return (_c.empty());
			};

			size_type	size( void ) const {
				return (_c.size());
			};

			reference	top( void ) {
				return (_c.back());
			};

			const_reference	top( void ) const {
				return (_c.back());
			};

			void	push( const value_type& val ) {
				_c.push_back(val);
			};

			void	pop( void ) {
				_c.pop_back();
			};

			template <typename Tp, typename Cts>
			friend bool operator==( const stack<Tp, Cts>&, const stack<Tp, Cts>& );

			template <typename Tp, typename Cts>
			friend bool operator<( const stack<Tp, Cts>&, const stack<Tp, Cts>& );
	};

	template <class T, class Container>
	bool	operator==( const stack<T,Container>& lhs,
						const stack<T,Container>& rhs ) {
		return (lhs._c == rhs._c);
	};

	template <class T, class Container>
	bool	operator!=( const stack<T,Container>& lhs,
						const stack<T,Container>& rhs ) {
		return (!(lhs._c == rhs._c));
	};

	template <class T, class Container>
	bool	operator<( const stack<T,Container>& lhs,
						const stack<T,Container>& rhs ) {
		return (lhs._c < rhs._c);
	};

	template <class T, class Container>
	bool	operator<=( const stack<T,Container>& lhs,
						const stack<T,Container>& rhs ) {
		return (!(rhs._c < lhs._c));
	};

	template <class T, class Container>
	bool	operator>( const stack<T,Container>& lhs,
						const stack<T,Container>& rhs ) {
		return (!(lhs._c <= rhs._c));
	};

	template <class T, class Container>
	bool	operator>=( const stack<T,Container>& lhs,
						const stack<T,Container>& rhs ) {
		return (!(lhs._c < rhs._c));
	};
}

#endif
