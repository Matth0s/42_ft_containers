/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_node.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:08:02 by mmoreira          #+#    #+#             */
/*   Updated: 2022/05/12 19:47:33 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RB_NODE_HPP
# define FT_RB_NODE_HPP

namespace ft
{
	template <typename T>
	struct rb_node
	{
		typedef rb_node<T>		base;
		typedef rb_node<T>*		base_ptr;

		T			data;
		base_ptr	parent;
		base_ptr	left;
		base_ptr	right;
		bool		color;

		rb_node( T value , base_ptr null , bool color = RED )
		:	data(value), parent(null), left(null), right(null), color(color) {};
		~rb_node( void ) {};

		static base_ptr	min( base_ptr node, base_ptr null ) {
			while (node->left != null)
				node = node->left;
			return (node);
		};

		static base_ptr	max( base_ptr node, base_ptr null ) {
			while (node->right != null)
				node = node->right;
			return (node);
		};

		static base_ptr	prev( base_ptr nodeX, base_ptr null ) {
			base_ptr	nodeY;

			if (nodeX->left != null)
				return (base::max(nodeX->left, null));
			else
			{
				nodeY = nodeX->parent;
				while (nodeY != null && nodeX == nodeY->left)
				{
					nodeX = nodeY;
					nodeY = nodeY->parent;
				}
				return (nodeY);
			}
		};

		static base_ptr	next( base_ptr nodeX, base_ptr null ) {
			base_ptr	nodeY;

			if (nodeX->right != null)
				return (base::min(nodeX->right, null));
			else
			{
				nodeY = nodeX->parent;
				while (nodeY != null && nodeX == nodeY->right)
				{
					nodeX = nodeY;
					nodeY = nodeY->parent;
				}
				return (nodeY);
			}
		};
	};
}

#endif
