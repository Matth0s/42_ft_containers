/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 20:11:57 by mmoreira          #+#    #+#             */
/*   Updated: 2022/05/13 22:50:35 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RB_TREE_HPP
# define FT_RB_TREE_HPP

# define RED true
# define BLACK false

#include "rb_iterator.hpp"
#include "reverse_iterator.hpp"

namespace ft
{
	template <typename Key, typename Val, class KeyOfValue, class Compare
			, class Alloc = std::allocator<Val> >
	class rb_tree
	{
		protected:
			typedef ft::rb_node<Val>						node_base;
			typedef node_base*								base_ptr;
			typedef const base_ptr							const_base_ptr;

		public:
			typedef Key										key_type;
			typedef Val										value_type;
			typedef value_type*								pointer;
			typedef const value_type*						const_pointer;
			typedef value_type&								reference;
			typedef const value_type&						const_reference;
			typedef std::size_t 							size_type;
			typedef std::ptrdiff_t 							difference_type;
			typedef Alloc									allocator_type;

			typedef ft::rb_iterator<value_type>				iterator;
			typedef ft::rb_iterator<const value_type>		const_iterator;
			typedef ft::reverse_iterator<iterator>			reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		private:
			typedef typename Alloc::template rebind<node_base>::other
				node_allocator_type;

		protected:
			base_ptr	_root;
			base_ptr	_null;

			allocator_type			_alloc;
			node_allocator_type		_node_alloc;

		public:
			rb_tree( void ): _root(NULL), _null(NULL) {
				this->_null = this->_node_alloc.allocate(1);
				this->_node_alloc.construct(this->_null,
										node_base(value_type(), NULL, BLACK));
				this->_null->left = this->_null;
				this->_null->right = this->_null;
				this->_root = this->_null;
				this->_null->parent = this->_root;
			};

			~rb_tree( void ) {
				this->_destroy(this->_root);
				if (this->_root != this->_null)
					this->_deleteNode(this->_root);
				this->_deleteNode(this->_null);
			};

		private:
			void	_destroy( base_ptr node ) {
				if (node->left != this->_null)
					_destroy(node->left);
				if (node->left != this->_null)
					this->_deleteNode(node->left);
				if (node->right != this->_null)
					_destroy(node->right);
				if (node->right != this->_null)
					this->_deleteNode(node->right);
			};

			base_ptr	_newNode( value_type value ) {
				base_ptr	node;

				node = this->_node_alloc.allocate(1);
				this->_node_alloc.construct(node, node_base(value, this->_null));
				return (node);
			};

			void	_deleteNode( base_ptr node ) {
				this->_node_alloc.destroy(node);
				this->_node_alloc.deallocate(node, 1);
			};

			void	_leftRotate( base_ptr nodeX ) {
				base_ptr	nodeY;

				nodeY = nodeX->right;
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

			void	_rightRotate( base_ptr nodeX ) {
				base_ptr	nodeY;

				nodeY = nodeX->left;
				nodeX->left = nodeY->right;
				if (nodeY->right != this->_null)
					nodeY->right->parent = nodeX;
				nodeY->parent = nodeX->parent;
				if (nodeX->parent == this->_null)
					this->_root = nodeY;
				else if (nodeX->parent->right == nodeX)
					nodeX->parent->right = nodeY;
				else
					nodeX->parent->left = nodeY;
				nodeY->right = nodeX;
				nodeX->parent = nodeY;
			};

			void	_transplant( base_ptr nodeU, base_ptr nodeV ) {
				if (nodeU->parent == this->_null)
					this->_root = nodeV;
				else if (nodeU == nodeU->parent->left)
					nodeU->parent->left = nodeV;
				else
					nodeU->parent->right = nodeV;
				if (nodeV != this->_null)
					nodeV->parent = nodeU->parent;
				nodeV->parent = nodeU->parent;
			};

			base_ptr	_search( key_type key, base_ptr node ) {
				if (node == this->_null
					|| (!Compare()(KeyOfValue()(node->data), key)
						 && !Compare()(key, KeyOfValue()(node->data))))
					return (node);
				if (Compare()(key, KeyOfValue()(node->data)))
					return (this->_search(key, node->left));
				return (this->_search(key, node->right));
			};

			void	_insertFix( base_ptr nodeX ) {
				base_ptr	nodeY;

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
				this->_null->parent = this->_root;
			};

			void	_eraseFix( base_ptr nodeX ) {
				base_ptr	nodeW;

				while (nodeX != this->_root && nodeX->color == BLACK)
				{
					if (nodeX == nodeX->parent->left)
					{
						nodeW = nodeX->parent->right;
						if (nodeW->color == RED)
						{
							nodeW->color = BLACK;
							nodeX->parent->color = RED;
							this->_leftRotate(nodeX->parent);
							nodeW = nodeX->parent->right;
						}
						if (nodeW->left->color == BLACK
							&& nodeW->right->color == BLACK)
						{
							nodeW->color = RED;
							nodeX = nodeX->parent;
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
						if (nodeW->color == RED)
						{
							nodeW->color = BLACK;
							nodeX->parent->color = RED;
							this->_rightRotate(nodeX->parent);
							nodeW = nodeX->parent->left;
						}
						if (nodeW->right->color == BLACK
							&& nodeW->left->color == BLACK)
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
			void	insert( value_type value ) {
				base_ptr	nodeX = this->_root;
				base_ptr	nodeY = this->_null;
				base_ptr	nodeZ = this->_newNode(value);

				while (nodeX != this->_null)
				{
					nodeY = nodeX;
					if (Compare()(
						KeyOfValue()(nodeZ->data), KeyOfValue()(nodeX->data)))
						nodeX = nodeX->left;
					else
						nodeX = nodeX->right;
				}
				nodeZ->parent = nodeY;
				if (nodeY == this->_null)
					this->_root = nodeZ;
				else if (Compare()(
					KeyOfValue()(nodeZ->data), KeyOfValue()(nodeY->data)))
					nodeY->left = nodeZ;
				else
					nodeY->right = nodeZ;
				_insertFix(nodeZ);
			};

			void	erase( value_type value ) {
				base_ptr	nodeX;
				base_ptr	nodeZ = this->search(KeyOfValue()(value));
				base_ptr	nodeY = nodeZ;
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
					nodeY = node_base::max(nodeZ->left, this->_null);
					color = nodeY->color;
					nodeX = nodeY->left;
					if (nodeY != nodeZ->left)
					{
						this->_transplant(nodeY, nodeY->left);
						nodeY->left = nodeZ->left;
						nodeY->left->parent = nodeY;
					}
					else
						nodeX->parent = nodeY;
					this->_transplant(nodeZ, nodeY);
					nodeY->right = nodeZ->right;
					nodeY->right->parent = nodeY;
					nodeY->color = nodeZ->color;
				}
				this->_deleteNode(nodeZ);
				if (color == BLACK)
					this->_eraseFix(nodeX);
				this->_null->parent = this->_root;
			};

			base_ptr	search( key_type key ) {
				return this->_search(key, this->_root);
			};

			base_ptr	root( void ) {
				return (this->_root);
			};

			base_ptr	null( void ) {
				return (this->_null);
			};
	};

	template <class KeyOfValue, class Node>
	void	printRbTree( Node node, Node null, int level) {
		if (node != null)
		{
			printRbTree<KeyOfValue, Node>(node->left, null, level + 1);
			if (node->left != null) std::cout << "  <";

			if (node->color == RED) std::cout << "\033[31m";
			std::cout << "({" << level << "} " << KeyOfValue()(node->data) << ")";
			std::cout << "\033[0m";

			if (node->right != null) std::cout << ">  ";
			printRbTree<KeyOfValue, Node>(node->right, null, level + 1);
		}
	};

	template <class Node>
	void	checkDoubleRed( Node node, Node null,	bool& doubleRed ) {
		if (node != null)
		{
			if (node->color == RED && node->parent->color == RED)
				doubleRed = true;
			checkDoubleRed(node->left, null, doubleRed);
			checkDoubleRed(node->right, null, doubleRed);
		}
	};

	template <class Node>
	void	checkBlackNodes( Node node, Node null, int* nullNodes,
								int branchBlackNodes, int* totalBlackNodes ) {
		if (node != null)
		{
			if (node->color == BLACK)
				branchBlackNodes++;
			checkBlackNodes(node->left, null, nullNodes,
							branchBlackNodes, totalBlackNodes);
			checkBlackNodes(node->right, null, nullNodes,
							branchBlackNodes, totalBlackNodes);
		}
		else
		{
			(*totalBlackNodes) += branchBlackNodes;
			(*nullNodes)++;
		}
	};

	template <class Node>
	bool	checkRbTree( Node root, Node null ) {
		Node	node = NULL;
		bool	doubleRed = false;
		int		height = 0;
		int		nullNodes = 0;
		int		totalBlackNodes = 0;

		if (root->color != BLACK)
			return (false);

		checkDoubleRed(root, null, doubleRed);
		if (doubleRed)
			return (false);

		node = root;
		while (node != null)
		{
			if (node->color == BLACK)
				height++;
			node = node->left;
		}
		checkBlackNodes(root, null, &nullNodes, 0, &totalBlackNodes);
		if (totalBlackNodes / nullNodes != height)
			return (false);
		return (true);
	};
}

#endif
