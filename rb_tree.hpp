/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 20:11:57 by mmoreira          #+#    #+#             */
/*   Updated: 2022/05/07 14:46:32 by mmoreira         ###   ########.fr       */
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

		s_node( int val , struct s_node* null , bool color = RED )
		: value(val), color(color), parent(null), left(null), right(null) {};
	}				t_node;


	class rb_tree
	{
		private:
			t_node*	_root;
			t_node*	_null;

		public:
			rb_tree( void ): _root(NULL), _null(NULL) {
				this->_null = new t_node(0, NULL, BLACK);
				this->_null->parent = this->_null;
				this->_null->left = this->_null;
				this->_null->right = this->_null;
				this->_root = this->_null;
			};

			~rb_tree( void ) {
				this->_destroy(this->_root);
				if (this->_root != this->_null)
					delete this->_root;
				delete this->_null;
			};

		private:

			void	_destroy( t_node* node ) {
				if (node->left != this->_null)
					_destroy(node->left);
				if (node->left != this->_null)
					delete node->left;
				if (node->right != this->_null)
					_destroy(node->right);
				if (node->right != this->_null)
					delete node->right;
			};


			t_node*	_minimum( t_node* node ) {
				while (node->left != this->_null)
					node = node->left;
				return node;
			};

			t_node*	_maximum( t_node* node ) {
				while (node->right != this->_null)
					node = node->right;
				return node;
			};

			void	_leftRotate( t_node* nodeX ) {
				t_node*	nodeY = nodeX->right;

				nodeX->right = nodeY->left;
				if (nodeY->left != this->_null)
					nodeY->left->parent = nodeX;

				nodeY->parent = nodeX->parent;
				if (nodeX->parent == this->_null)
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
				if (nodeY->right != this->_null)
					nodeY->right->parent = nodeX;

				nodeY->parent = nodeX->parent;
				if (nodeX->parent == this->_null)
					this->_root = nodeY;
				else if (nodeX->parent->left == nodeX)
					nodeX->parent->left = nodeY;
				else
					nodeX->parent->right = nodeY;

				nodeY->right = nodeX;
				nodeX->parent = nodeY;
			};

			void	_transplant( t_node* nodeU, t_node* nodeV ) {
				if (nodeU->parent == this->_null)
					this->_root = nodeV;
				else if (nodeU == nodeU->parent->left)
					nodeU->parent->left = nodeV;
				else
					nodeU->parent->right = nodeV;
				if (nodeV != this->_null)
					nodeV->parent = nodeU->parent;
			};


			void	_print( t_node* node, int level ) {
				if (node != this->_null)
				{
					this->_print(node->left, level + 1);
					if (node->left != this->_null)
						std::cout << "  <";
					if (node->color == RED)
						std::cout << "\033[31m";
					std::cout << "({" << level << "} " << node->value << ")";
					std::cout << "\033[0m";
					if (node->right != this->_null)
					std::cout << ">  ";
					this->_print(node->right, level + 1);
				}
			};

			void	_insertFix( t_node* nodeX ) {
				t_node*	nodeY;

				while (nodeX->parent->color == RED)
				{
					if (nodeX->parent == nodeX->parent->parent->left)
					{
						nodeY = nodeX->parent->parent->right;
						if (nodeY->color == RED)
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
						if (nodeY->color == RED)
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

			void	_eraseFix( t_node* nodeX , int i) {
				t_node*	nodeW;

				while (nodeX != this->_root && nodeX->color == BLACK)
				{
					if (i)
						std::cout << "**** " << nodeX->value << " ****" << std::endl;
					if (nodeX == nodeX->parent->left)
					{
						nodeW = nodeX->parent->right;
						if (i)
							std::cout << "**** " << nodeW->value << " ****" << std::endl;
						if (nodeW->color == RED)
						{
							nodeW->color = BLACK;
							nodeX->parent->color = RED;
							this->_leftRotate(nodeX->parent);
							nodeW = nodeX->parent->right;
						}
						if (nodeW->left->color == BLACK && nodeW->right->color == BLACK)
						{

							nodeW->color = RED;
							nodeX = nodeX->parent;
							if (i)
							std::cout << "**** " << nodeX->value << " ****" << std::endl;
							if (i)
							std::cout << "**** " << (nodeW->color?"red":"black") << " ****" << std::endl;
						}
						else
						{
							if (nodeW->right->color == BLACK)
							{
								nodeW->left->color = BLACK;
								nodeW->color = RED;
								this->_rightRotate(nodeW);
								nodeW = nodeX->parent->right;
							}
							nodeW->color = nodeX->parent->color;
							nodeX->parent->color = BLACK;
							nodeW->right->color = BLACK;
							this->_leftRotate(nodeX->parent);
							nodeX = this->_root;
						}
					}
					else
					{
						nodeW = nodeX->parent->left;
						// if (i)
						// 	std::cout << "**** " << nodeW->value << " ****" << std::endl;
						if (nodeW->color == RED)
						{
							nodeW->color = BLACK;
							nodeX->parent->color = RED;
							this->_rightRotate(nodeX->parent);
							nodeW = nodeX->parent->left;
							// if (i)
							// std::cout << "**** " << nodeW->value << " ****" << std::endl;
						}
						if (nodeW->right->color == BLACK && nodeW->left->color == BLACK)
						{
							nodeW->color = RED;
							nodeX = nodeX->parent;
						}
						else
						{
							if (nodeW->left->color == BLACK)
							{
								nodeW->right->color = BLACK;
								nodeW->color = RED;
								this->_leftRotate(nodeW);
								nodeW = nodeX->parent->left;
							}
							nodeW->color = nodeX->parent->color;
							nodeX->parent->color = BLACK;
							nodeW->left->color = BLACK;
							this->_rightRotate(nodeX->parent);
							nodeX = this->_root;
						}
					}
				}
				nodeX->color = BLACK;
			};

		public:
			void	insert( int value ) {
				t_node*	nodeZ = new t_node(value, this->_null);
				t_node* nodeX = this->_root;
				t_node* nodeY = this->_null;

				while (nodeX != this->_null)
				{
					nodeY = nodeX;
					if (nodeX->value > nodeZ->value)
						nodeX = nodeX->left;
					else
						nodeX = nodeX->right;
				}
				nodeZ->parent = nodeY;

				if (nodeY == this->_null)
					this->_root = nodeZ;
				else if (nodeY->value > nodeZ->value)
					nodeY->left = nodeZ;
				else
					nodeY->right = nodeZ;

				_insertFix(nodeZ);
			};

			void	erase( int value ) {
				t_node*	nodeZ = this->_search(value, this->_root);
				t_node*	nodeX;
				t_node*	nodeY = nodeZ;
				bool	color = nodeZ->color;

				if (nodeZ == this->_null)
					return ;
				if (nodeZ->left == this->_null)
				{
					nodeX = nodeZ->right;
					this->_transplant(nodeZ, nodeZ->right);
				}
				else if (nodeZ->right == this->_null)
				{
					nodeX = nodeZ->left;
					this->_transplant(nodeZ, nodeZ->left);
				}
				else
				{
					nodeY = this->_minimum(nodeZ->right);
					color = nodeY->color;
					nodeX = nodeY->right;
					if (nodeY != nodeZ->right)
					{
						this->_transplant(nodeY, nodeY->right);
						nodeY->right = nodeZ->right;
						nodeY->right->parent = nodeY;
					}
					else
						nodeX->parent = nodeY;
					this->_transplant(nodeZ, nodeY);
					nodeY->left = nodeZ->left;
					nodeY->left->parent = nodeY;
					nodeY->color = nodeZ->color;
				}
				delete nodeZ;
				// if (color == BLACK)
				// 	this->_eraseFix(nodeX);
				if (color == BLACK)
				{
					if (value == 36)
						this->_eraseFix(nodeX, 1);
					else
						this->_eraseFix(nodeX, 0);
				}
			};

			t_node*	_search( int value, t_node* node ) {
				if (node == this->_null || node->value == value)
					return (node);
				if (node->value > value)
					return (this->_search(value, node->left));
				return (this->_search(value, node->right));
			};

			int	rootValue( void ) {
				return (this->_root->value);
			};

			void	print( void ) {
				this->_print(this->_root, 0);
			};

			void	checkBranch( t_node* node, bool* checker,
									int blackNodes, int* blackTotal ) {
				if (node != this->_null)
				{
					if (node->color == RED && node->parent->color == RED)
						*checker = false;
					if (node->color == BLACK)
						blackNodes++;
					// std::cout << node->value << " ->";
					checkBranch(node->left, checker, blackNodes, blackTotal);
					checkBranch(node->right, checker, blackNodes, blackTotal);
				}
				else
				{
					// std::cout << "---  " << blackNodes << "  ---" << std::endl;
					(*blackTotal) += blackNodes;
				}
			}

			bool	checkRB( void ) {
				t_node*	node = this->_root;
				bool	checker = true;
				int		blackTotal = 0;
				int		height = 0;

				if (this->_root == this->_null)
					return (true);
				if (this->_root->color == RED)
					return false;
				// std::cout << std::endl;
				this->checkBranch(this->_root, &checker, 0, &blackTotal);
				while (node != this->_null)
				{
					if (node->color == BLACK)
						height++;
					node = node->left;
				}
				if (blackTotal % height != 0)
					checker = false;
				return (checker);
			};
	};
}

#endif
