/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 03:17:30 by mmoreira          #+#    #+#             */
/*   Updated: 2022/04/21 18:27:03 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ALGORITHM_HPP
# define FT_ALGORITHM_HPP

namespace ft
{
	template <class InputIterator1, class InputIterator2>
	bool	equal( InputIterator1 first1, InputIterator1 last1,
					InputIterator2 first2 ) {
		while (first1 != last1)
		{
			if (!(*first1 == *first2))
				return (false);
			first1++;
			first2++;
		}
		return (true);
	};

	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
	bool	equal( InputIterator1 first1, InputIterator1 last1,
					InputIterator2 first2, BinaryPredicate pred) {
		while (first1 != last1)
		{
			if (!(pred(*first1,*first2)))
				return (false);
			first1++;
			first2++;
		}
		return (true);
	};

	template <class InputIterator1, class InputIterator2>
	bool	lexicographical_compare( InputIterator1 first1, InputIterator1 last1,
									InputIterator2 first2, InputIterator2 last2 ) {
		while ((first1 != last1) && (first2 != last2))
		{
			if (*first2 < *first1)
				return (false);
			if (*first1 < *first2)
				return (true);
			first1++;
			first2++;
		}
		return ((first1 == last1) && (first2 != last2));
	};

	template <class InputIterator1, class InputIterator2, class Compare>
	bool	lexicographical_compare( InputIterator1 first1, InputIterator1 last1,
									InputIterator2 first2, InputIterator2 last2,
									Compare comp) {
		while ((first1 != last1) && (first2 != last2))
		{
			if (comp(*first2, *first1))
				return (false);
			if (comp(*first1, *first2))
				return (true);
			first1++;
			first2++;
		}
		return ((first1 == last1) && (first2 != last2));
	};
}

#endif
