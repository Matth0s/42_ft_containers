/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functional.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 21:09:51 by mmoreira          #+#    #+#             */
/*   Updated: 2022/05/14 21:36:19 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FUNCTIONAL_HPP
# define FT_FUNCTIONAL_HPP

namespace ft
{
	template<class Arg, class Result>
	struct unary_function
	{
		typedef Arg		argument_type;
		typedef Result	result_type;
	};

	template <class Arg1, class Arg2, class Result>
	struct binary_function
	{
		typedef Arg1	first_argument_type;
		typedef Arg2	second_argument_type;
		typedef Result	result_type;
	};

	template <class T>
	struct less: public binary_function<T, T, bool>
	{
		bool	operator()( const T& x, const T& y ) const {
			return (x < y);
		}
	};

	template <typename T>
	struct identity: public unary_function<T, T>
	{
		T&	operator()( T& x ) const {
			return (x);
		}

		const T&	operator()( const T& x) const {
			return (x);
		}
	};

	template <typename T>
	struct identity<const T>: identity<T> {};


	template <typename Pair>
	struct select1st: public unary_function<Pair, typename Pair::first_type>
	{
		typename Pair::first_type&	operator()( Pair& x ) const {
			return (x.first);
		}

		const typename Pair::first_type&	operator()( const Pair& x ) const {
			return (x.first);
		}
	};

	template <typename Pair>
	struct select2nd: public unary_function<Pair, typename Pair::second_type>
	{
		typename Pair::second_type&	operator()( Pair& x ) const {
			return (x.second);
		}

		const typename Pair::second_type&	operator()( const Pair& x ) const {
			return (x.second);
		}
	};
}

#endif
