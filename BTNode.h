/*
Robin Leruth
3242277
SENG1120
Friday 6th November
*/

#ifndef BTNODE_H
#define BTNODE_H

#include <iostream>
#include <cstdlib>

namespace robin_assignment3
{
template<typename Item>
class BTNode{
	public:
		BTNode();
		BTNode(Item*, BTNode*, BTNode*, BTNode*);
		//Constructors
		
		~BTNode();
		//Destructor

		void set_data(Item*);
		void set_parent(BTNode*);
		void set_left(BTNode*);
		void set_right(BTNode*);
		//Mutator

		Item *get_data() const;
		BTNode* get_parent();
		BTNode* get_right();
		BTNode* get_left();
		//Accessor
	private:
		Item *m_data;
		BTNode *m_first_child;
		BTNode *m_second_child;
		BTNode *m_parent;
};
}

#include "BTNode.template"

#endif
