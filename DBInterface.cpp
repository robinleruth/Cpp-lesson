/*
Robin Leruth
3242277
SENG1120
Friday 6th November
*/

#include "DBInterface.h"

using namespace std;

namespace robin_assignment3
{
DBInterface::DBInterface(){
	m_tree = new BSTree<MechPart>();
}
DBInterface::~DBInterface(){
	delete m_tree;
}

int DBInterface::read_file(){
	FILE *fp = NULL;
	 string filename = query_user();
	 string code ="";
	char str[20] = "";
	int quantity = 0;
	MechPart *part = NULL;
	fp = fopen(filename.c_str(), "r");
	if(fp != NULL){
		fscanf(fp, "%s %s", str, str);
		while(!feof(fp)){
			fscanf(fp, "%s %d", str, &quantity);
			code = (string)str;
			if(code == "\n") continue;
			part = new MechPart(code, quantity);
			m_tree->insert(part);
		}
		fclose(fp);
		return 0;
	}
	else{
		printf("Couldn't read the file\n");
		return -1;
	}
}

int DBInterface::monthly_update(){
	if(m_tree->get_root() == NULL){
		 cout << "The tree is empty, hence cannot be updated" <<  endl;
		return -1;
	}
	FILE *fp = NULL;
	BTNode<MechPart>* node = NULL;
	string filename = query_user();
	string code ="";
	char str[20] = "";
	int quantity = 0;
	MechPart *part = NULL;
	MechPart *node_part = NULL;
	fp = fopen(filename.c_str(), "r");
	if(fp != NULL){
		fscanf(fp, "%s %s", str, str);
		while(!feof(fp)){
			fscanf(fp, "%s %d", str, &quantity);
			code = ( string)str;
			part = new MechPart(code, quantity);
			node = m_tree->search(part);
			if(node != NULL){
				node_part = node->get_data();
				node_part->setQuantity(node_part->getQuantity() + quantity);
			}
			delete part;
		}
		fclose(fp);
		m_tree->delete_node();

		return 0;
	}
	else{
		printf("Couldn't read the file\n");
		return -1;
	}
}

 string DBInterface::query_user(){
	 string str;

	 cout << "Please enter the name of the file to read : " <<  endl;
	 cin >> str;

	return str;
}

 ostream& operator << ( ostream& out, const DBInterface& i){
	BSTree<MechPart> *tree = i.get_tree();
	out << tree->toString() <<  endl;
	return out;
}

BSTree<MechPart>* DBInterface::get_tree() const{
	return m_tree;
}

void DBInterface::launch_menu(){
	bool continuer = true;
	char answer = 0;
	while(continuer){
            	 cout << endl;
		 cout << "Read current inventory file : 1" <<  endl;
		 cout << "Read/Exec monthly update file : 2" <<  endl;
		 cout << "Display statistics : 3" <<  endl;
		 cout << "Search list item file : 4" <<  endl;
		 cout << "Exit : 0" <<  endl;
		 cin >> answer;
		switch(answer){
			case '1':
				this->read_file();
				break;
			case '2':
				this->monthly_update();
				break;
			case '3':
				display_statistics();
				break;
			case '4':
				search_list_item();
				break;
			case '0':
				continuer = false;
				break;
			default:
				 cout << "You haven't chosen a right number" <<  endl;
		}
	}
}

void DBInterface::display_statistics(){
	int result = 0;
	BTNode<MechPart>* node = m_tree->get_root();
	if(node == NULL) cout << "The tree is empty" << endl;
	display_statistics(node, &result);
	cout << endl << "Total number of parts : " << result << endl;
	cout << "Number of different parts : " << m_tree->get_length() << endl;
}

void DBInterface::display_statistics(BTNode<MechPart>* node, int *result){
	if(node == NULL) return;
	MechPart* part = NULL;
	display_statistics(node->get_left(), result);
	part = node->get_data();
	cout << part->getCode() << ":" << part->getQuantity() << endl;
	*result = *result + part->getQuantity();
	display_statistics(node->get_right(), result);
}

void DBInterface::display_null_quantity(){
	BTNode<MechPart>* temp = NULL;
	MechPart * part = NULL;
	do{
		temp = m_tree->search_quantity(0);
		part = temp->get_data();
		cout << part->getCode() << ":" << part->getQuantity() << endl;
		part->setQuantity(1);
	}while(temp != NULL);
}

int DBInterface::search_list_item(){
	if(m_tree->get_root() == NULL){
		 cout << "The tree is empty, hence cannot be updated" <<  endl;
		return -1;
	}

	string filename = query_user();
	string code = "";
	char str[20] = "";
	FILE *fp = NULL;
	int number_of_items_searched = 0;
	int number_of_comparisons = 0;
	double result = 0;

	fp = fopen(filename.c_str(), "r");
	if(fp != NULL){
		fscanf(fp, "%s", str);
		while(!feof(fp)){
			fscanf(fp, "%s", str);
			code = (string)str;
			number_of_comparisons += m_tree->search_code(code);
			number_of_items_searched++;
		}
		fclose(fp);
		result = number_of_comparisons/number_of_items_searched;
		cout << "Average number : " << result << endl;
		return 0;
	}
	else{
		cout << "Couldn't read the file" << endl;
		return -1;
	}
}

void DBInterface::way_display(){
	bool continuer = true;
	char answer = 0;
	while(continuer){
		cout << "How do you want to display the tree ?" << endl;
		cout << "Tree view -> 1" << endl;
		cout << "Code:Quantity -> 2" << endl;
		cin >> answer;
		switch(answer){
			case '1':
				cout << *this << endl;
				continuer = false;
				break;
			case '2':
				display_statistics();
				continuer = false;
				break;
			default:
				 cout << "You haven't chosen a right number" <<  endl;
		}
	}
}
}
