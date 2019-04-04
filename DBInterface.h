/*
Robin Leruth
3242277
SENG1120
Friday 6th November
*/

#ifndef DBINTERFACE_H
#define DBINTERFACE_H

#include <iostream>
#include <stdio.h>
#include <string>
#include "BSTree.h"
#include "MechPart.h"
	
namespace robin_assignment3
{
class DBInterface{
	public:
		DBInterface();
		~DBInterface();
		
		void launch_menu();
		//pre-condition: none
		//post-condition: display the program menu

		BSTree<MechPart> *get_tree() const;
		//pre-condition: none
		//post-condition: returns the tree


	private:
		BSTree<MechPart>* m_tree;
		std::string query_user();

		void display_null_quantity();
		//pre-condition : none
		//post-condition : display all the mechpart with quantity = 0

		int read_file();
		//pre-condition: none
		//post-condition: query the user for a filename
		//open this file with read-only option
		//populate the tree of mechpart
		//return 0 if everything was well, -1 if couldn't read the file

		int monthly_update();
		//pre-condition: the tree has to be not empty
		//post-condition: open a file queried by the user
		//		  update quantity of mechpart
		//		  delete all the mechpart with quantity = 0

		void display_statistics();
		//pre-condition: the tree has to be not empty
		//post-condition: display "code:quantity" of every mechpart

		void display_statistics(BTNode<MechPart>* node, int *result);
		//pre-condition: called by display_statistics
		//post-condition:

		int search_list_item();
		//pre-condition:
		//post-condition:

		void way_display();
		//pre-condition:
		//post-condition:

};
std::ostream& operator << (std::ostream& out, const DBInterface& i);
}

#endif
