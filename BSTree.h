/*
Robin Leruth
3242277
SENG1120
Friday 6th November
*/

#ifndef BSTREE_H
#define BSTREE_H

#include "BTNode.h"

namespace robin_assignment3
{
template<typename Item>
class BSTree{
	public:
		BSTree();
		~BSTree();

		int get_length() const;

		BTNode<Item> *get_root() const;
		//pre-condition: none
		//post-condition: returns pointer on root

		void set_root(int quantity);
		//pre-condition: takes as parameter a quantity
		//post-condition: set the root_quantity to 0
		//(test purpose)

		void delete_node();
		//pre-condition:none
		//post-condition: delete all the node with quantity = 0

		void insert(Item*);
		//pre-condition: takes as parameter a pointer on Item
		//post-condition: add it to the tree

		void add(BTNode<Item>*, Item*);
		//pre-condition: takes as parameter a node and an item
		//post-condition: add the item to the tree which has node as root
		
		BTNode<Item>* find_highest_element(BTNode<Item>* node);
		//pre-condition: takes as parameter a node
		//post-condition: return the leaf at right of the right subtree of node

		std::string toString();
		//pre-condition:none
		//post-condition:display the tree

		std::string toString(BTNode<Item> *node, int level);
		//pre-condition: takes as parameter a node and a level
		//post-condition: return a string which display the tree from the node given

		BTNode<Item>* search(Item *data);
		//pre-condition:takes as parameter a pointer on item
		//post-condition: returns the BTNode containing this item
		

		BTNode<Item>* search_quantity(int quantity);
		//pre-condition: takes as parameter an integer
		//post-condition: returns the node which contains the quantity
		
		int search_code(std::string code);
		//pre-condition: takes as parameter a string
		//post-condition: returns the number of comparisons to find the item

	private:
		BTNode<Item> *m_root;
		int m_length;

		void deleteFromTree(BTNode<Item>* node);
		//Called by delete_node

		BTNode<Item>* find_quantity(BTNode<Item>* node, int quantity);
		//pre-condition:
		//post-condition:

		BTNode<Item>* find(BTNode<Item>* node, Item *data);
		//pre-condition:takes as parameter a pointer on item and on node
		//post-condition:same as search

		bool find_code(BTNode<Item>* node, std::string code, int *result);
};

}

#include "BSTree.template"

#endif
