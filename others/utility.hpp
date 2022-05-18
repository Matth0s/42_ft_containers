/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 03:17:45 by mmoreira          #+#    #+#             */
/*   Updated: 2022/05/18 16:34:47 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILITY_HPP
# define FT_UTILITY_HPP

namespace ft
{
	template <class T1, class T2>
	struct pair
	{
		public:
			typedef T1	first_type;
			typedef T2	second_type;

		public:
			first_type	first;
			second_type	second;

		public:
			pair( void ): first(T1()), second(T2()) {};

			pair( const first_type& a, const second_type& b): first(a), second(b) {};

			template<class U, class V>
			pair( const pair<U, V>& src ): first(src.first), second(src.second) {};

			pair&	operator=( const pair& rhs )
			{
				this->first = rhs.first;
				this->second = rhs.second;
				return (*this);
			};
	};

	template <class T1, class T2>
	bool	operator==( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ) {
		return ((lhs.first == rhs.first) && (lhs.second == rhs.second));
	};

	template <class T1, class T2>
	bool	operator!=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ) {
		return (!(lhs == rhs));
	};

	template <class T1, class T2>
	bool	operator<( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ) {
		return ((lhs.first < rhs.first) ||
				(!(rhs.first < lhs.first) && (lhs.second < rhs.second)));
	};

	template <class T1, class T2>
	bool	operator<=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ) {
		return (!(rhs < lhs));
	};

	template <class T1, class T2>
	bool	operator>( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ) {
		return (rhs < lhs);
	};

	template <class T1, class T2>
	bool	operator>=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ) {
		return (!(lhs < rhs));
	};

	template <class T1, class T2>
	pair<T1, T2>	make_pair( T1 x, T2 y ) {
		return (pair<T1,T2>(x, y));
	}
}

#endif
