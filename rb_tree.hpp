/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 20:11:57 by mmoreira          #+#    #+#             */
/*   Updated: 2022/05/04 00:16:28 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RB_TREE_HPP
# define FT_RB_TREE_HPP

# define RED true
# define BLACK false

#include <iostream>

namespace ft
{
	typedef struct s_node
	{
		int				value;
		bool			color;

		struct s_node	*parent;
		struct s_node	*left;
		struct s_node	*right;

		s_node( int val )
		: value(val), color(RED), parent(NULL), left(NULL), right(NULL) {};
	}				t_node;

	class rb_tree
	{
		private:
			t_node	*_root;

		public:
			rb_tree( void ): _root(NULL) {};
			~rb_tree( void ) {
				this->_destroy(this->_root);
				delete this->_root;
			};

		private:
			void	_leftRotate( t_node* nodeX ) {
				t_node*	nodeY = nodeX->right;

				nodeX->right = nodeY->left;
				if (nodeY->left)
					nodeY->left->parent = nodeX;

				nodeY->parent = nodeX->parent;
				if(!(nodeX->parent))
					this->_root = nodeY;
				else if (nodeX->parent->left == nodeX)
					nodeX->parent->left = nodeY;
				else
					nodeX->parent->right = nodeY;

				nodeY->left = nodeX;
				nodeX->parent = nodeY;
			};

			void	_rightRotate( t_node* nodeX ) {
				t_node*	nodeY = nodeX->left;

				nodeX->left = nodeY->right;
				if (nodeY->right)
					nodeY->right->parent = nodeX;

				nodeY->parent = nodeX->parent;
				if(!(nodeX->parent))
					this->_root = nodeY;
				else if (nodeX->parent->left == nodeX)
					nodeX->parent->left = nodeY;
				else
					nodeX->parent->right = nodeY;

				nodeY->right = nodeX;
				nodeX->parent = nodeY;
			};

			void	_insertFix( t_node* nodeX ) {
				t_node*	nodeY;

				while (nodeX->parent && nodeX->parent->color)
				{
					if (nodeX->parent == nodeX->parent->parent->left)
					{
						nodeY = nodeX->parent->parent->right;
						if (nodeY && nodeY->color)
						{
							nodeX->parent->color = BLACK;
							nodeY->color = BLACK;
							nodeX->parent->parent->color = RED;
							nodeX = nodeX->parent->parent;
						}
						else
						{
							if (nodeX == nodeX->parent->right)
							{
								nodeX = nodeX->parent;
								this->_leftRotate(nodeX);
							}
							nodeX->parent->color = BLACK;
							nodeX->parent->parent->color = RED;
							this->_rightRotate(nodeX->parent->parent);
						}
					}
					else
					{
						nodeY = nodeX->parent->parent->left;
						if (nodeY && nodeY->color)
						{
							nodeX->parent->color = BLACK;
							nodeY->color = BLACK;
							nodeX->parent->parent->color = RED;
							nodeX = nodeX->parent->parent;
						}
						else
						{
							if (nodeX == nodeX->parent->left)
							{
								nodeX = nodeX->parent;
								this->_rightRotate(nodeX);
							}
							nodeX->parent->color = BLACK;
							nodeX->parent->parent->color = RED;
							this->_leftRotate(nodeX->parent->parent);
						}
					}
				}
				this->_root->color = BLACK;
			};

			void	_transplant( t_node* nodeU, t_node* nodeV ) {
				if (!(nodeU->parent))
					this->_root = nodeV;
				else if (nodeU == nodeU->parent->left)
					nodeU->parent->left = nodeV;
				else
					nodeU->parent->right = nodeV;
			};

			void	_print( t_node* node, int level ) {
				if (node) {
					this->_print(node->left, level + 1);
					if (node->color)
						std::cout << "\033[31m";
					std::cout << "[{" << level << "} " << node->value << "] ";
					std::cout << "\033[0m";
					this->_print(node->right, level + 1);
				}
			};

			void	_destroy( t_node* node ) {
				if (node->left)
					_destroy(node->left);
				delete node->left;
				if (node->right)
					_destroy(node->right);
				delete node->right;
			};

		public:
			void	insert( int value ) {
				t_node*	nodeZ = new t_node(value);
				t_node* nodeX = this->_root;
				t_node* nodeY = NULL;

				while (nodeX)
				{
					nodeY = nodeX;
					if (nodeX->value > nodeZ->value)
						nodeX = nodeX->left;
					else
						nodeX = nodeX->right;
				}
				nodeZ->parent = nodeY;

				if (!(nodeY))
					this->_root = nodeZ;
				else if (nodeY->value > nodeZ->value)
					nodeY->left = nodeZ;
				else
					nodeY->right = nodeZ;

				_insertFix(nodeZ);
			};

			// void		erase( int value ) {};

			// t_node*	search( int value ) {};

			// t_node*	minimum( t_node* root ) {};
			// t_node*	maximum( t_node* root ) {};

			void	print( void ) {
				this->_print(this->_root, 0);
			}
	};
}

#endif
