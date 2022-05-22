/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 22:43:13 by mmoreira          #+#    #+#             */
/*   Updated: 2022/05/21 23:24:06 by mmoreira         ###   ########.fr       */
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
			container_type	c;

		public:
			explicit stack( const container_type& ctnr = container_type())
			:	c(ctnr) {};

			stack( const stack& src ): c(src) {};

			~stack( void ) {};

			stack&	operator=( const stack& rhs) {
				this->c = rhs.c;
				return (*this);
			};

			bool	empty( void ) const {
				return (this->c.empty());
			};

			size_type	size( void ) const {
				return (this->c.size());
			};

			reference	top( void ) {
				return (this->c.back());
			};

			const_reference	top( void ) const {
				return (this->c.back());
			};

			void	push( const value_type& val ) {
				this->c.push_back(val);
			};

			void	pop( void ) {
				this->c.pop_back();
			};

			template <typename Tp, typename Cts>
			friend bool operator==( const stack<Tp, Cts>&, const stack<Tp, Cts>& );

			template <typename Tp, typename Cts>
			friend bool operator<( const stack<Tp, Cts>&, const stack<Tp, Cts>& );
	};

	template <class T, class Container>
	bool	operator==( const stack<T,Container>& lhs,
						const stack<T,Container>& rhs ) {
		return (lhs.c == rhs.c);
	};

	template <class T, class Container>
	bool	operator!=( const stack<T,Container>& lhs,
						const stack<T,Container>& rhs ) {
		return (!(lhs.c == rhs.c));
	};

	template <class T, class Container>
	bool	operator<( const stack<T,Container>& lhs,
						const stack<T,Container>& rhs ) {
		return (lhs.c < rhs.c);
	};

	template <class T, class Container>
	bool	operator<=( const stack<T,Container>& lhs,
						const stack<T,Container>& rhs ) {
		return (!(rhs.c < lhs.c));
	};

	template <class T, class Container>
	bool	operator>( const stack<T,Container>& lhs,
						const stack<T,Container>& rhs ) {
		return (!(lhs.c <= rhs.c));
	};

	template <class T, class Container>
	bool	operator>=( const stack<T,Container>& lhs,
						const stack<T,Container>& rhs ) {
		return (!(lhs.c < rhs.c));
	};
}

#endif
