/*
Robin Leruth
3242277
SENG1120
Friday 6th November
*/

#include <string>

namespace robin_assignment3
{
template<typename Item>
BSTree<Item>::BSTree(){
	m_root = NULL;
	m_length = 0;
}

template<typename Item>
BSTree<Item>::~BSTree(){
	if(m_root == NULL) return;
	delete m_root;
}

template<typename Item>
void BSTree<Item>::insert(Item *newItem){
	if(m_root == NULL){
		m_root = new BTNode<Item>(newItem, NULL, NULL, NULL);
	}
	else{
		add(m_root, newItem);
	}
	m_length++;
}

template<typename Item>
void BSTree<Item>::add(BTNode<Item>* node, Item* it){
	Item *data = node->get_data();
	BTNode<Item> *nouv = NULL;

	if(*it == *data){
		node->set_data(it);
	}
	else if(*it > *data){
		//working on the right side
		if(node->get_right() == NULL){
			nouv = new BTNode<Item>(it, NULL, NULL, node);
			node->set_right(nouv);
		}
		else{
			add(node->get_right(), it);
		}
	}
	else{
		//working on the left side
		if(node->get_left() == NULL){
			nouv = new BTNode<Item>(it, NULL, NULL, node);
			node->set_left(nouv);
		}
		else{
			add(node->get_left(), it);
		}
	}
}

template<typename Item>
std::string BSTree<Item>::toString(){
	return toString(m_root, 0);
}

template<typename Item>
std::string BSTree<Item>::toString(BTNode<Item> *node, int level){
	std::string str = "";
	Item *data = node->get_data();
	if(node != NULL){
		str += toString(node->get_right(), level + 1);
		for(int i=1;i<=level;i++){
			str = str + " ";
		}
		str+= data->getCode() + "\n";
		str+=toString(node->get_left(), level + 1);
	}
	return str;
}

template<typename Item>
BTNode<Item>* BSTree<Item>::search(Item *data){
	return find(m_root, data);
}

template<typename Item>
BTNode<Item>* BSTree<Item>::find(BTNode<Item>* node, Item *data){
	if(node == NULL) return NULL;
	Item *it = node->get_data();

	if(*it == *data){
		return node;
	}
	else if(*it < *data){
		return find(node->get_right(), data);
	}
	else{
		return find(node->get_left(), data);
	}
}

template<typename Item>
BTNode<Item>* BSTree<Item>::get_root() const{
	return m_root;
}

template<typename Item>
BTNode<Item>* BSTree<Item>::search_quantity(int quantity){
	return find_quantity(m_root, quantity);
}

template<typename Item>
BTNode<Item>* BSTree<Item>::find_quantity(BTNode<Item>* node, int quantity){
	if(node == NULL) return NULL;
	static BTNode<Item>* aRetourner = NULL;
	if(node == m_root) aRetourner = NULL;
	Item *it = node->get_data();
	int part_quantity = it->getQuantity();

	if(part_quantity == quantity){
		aRetourner =  node;
		return aRetourner;
	}
	if(aRetourner == NULL){
		find_quantity(node->get_right(), quantity);
		find_quantity(node->get_left(), quantity);
	}

	return aRetourner;
}

template<typename Item>
BTNode<Item>* BSTree<Item>::find_highest_element(BTNode<Item>* node){
	BTNode<Item> *check = node->get_right();
	if(check != NULL)
		return find_highest_element(node->get_right());
	else
		return node;
}

template<typename Item>
void BSTree<Item>::deleteFromTree(BTNode<Item> *node){
	BTNode<Item>* curr = NULL;
	BTNode<Item>* p_curr = NULL;
	BTNode<Item>* temp = NULL;
	BTNode<Item>* parent = node->get_parent();

	if(node == NULL) return;
	else if(node->get_left() == NULL && node->get_right() == NULL){
		temp = node;
		if(parent->get_left() == temp) parent->set_left(NULL);
		else parent->set_right(NULL);
		delete temp;
		m_length--;
		node = NULL;
	}
	else if(node->get_left() == NULL){
		temp = node;
		node = node->get_right();
		if(parent->get_left() == temp) parent->set_left(node);
		else parent->set_right(node);
		node->set_parent(parent);
		temp->set_right(NULL);
		temp->set_parent(NULL);
		delete temp;
		m_length--;
		temp = NULL;
	}
	else if(node->get_right() == NULL){
		temp = node;
		node = node->get_left();
		if(parent->get_left() == temp) parent->set_left(node);
		else parent->set_right(node);
		temp->set_left(NULL);
		temp->set_parent(NULL);
		delete temp;
		m_length--;
		temp = NULL;
	}
	else{
		curr = node->get_left();
		p_curr=NULL;

		while(curr->get_right() != NULL){
			p_curr = curr;
			curr = curr->get_right();
		}

		node->set_data(curr->get_data());

		if(p_curr == NULL){
			node->set_left(curr->get_left());
		}
		else{
			p_curr->set_right(curr->get_left());
		}
		curr->set_right(NULL);
		curr->set_left(NULL);
		curr->set_parent(NULL);

		delete curr;
		m_length--;
		curr = NULL;
	}
}

template<typename Item>
void BSTree<Item>::set_root(int quantity){
	Item *data = m_root->get_data();
	data->setQuantity(quantity);
}

//template<typename Item>
//bool BSTree<Item>::delete_node(const int quantity){
//	BTNode<Item>* curr = NULL;
//	BTNode<Item>* p_curr = NULL;
//	bool found = false;
//	Item *it = NULL;
//
//	if(m_root == NULL) return false;
//	else{
//		curr = m_root;
//		p_curr = m_root;
//
//		while(curr != NULL && !found){
//			it = curr->get_data();
//			if(it->getQuantity() == quantity){
//				found = true;
//			}
//			else{
//				curr = find_quantity(curr, 0);
//				if(curr != NULL) p_curr = curr->get_parent();
//			}
//		}
//
//		if(found){
//			if(curr == m_root) deleteFromTree(m_root);
//			else if (p_curr->get_left() == curr)
//				deleteFromTree(p_curr->get_left());
//			else
//				deleteFromTree(p_curr->get_right());
//			return true;
//		}
//		else return false;
//	}
//}

template<typename Item>
void BSTree<Item>::delete_node(){
	BTNode<Item>* curr = NULL;
	BTNode<Item>* p_curr = NULL;

	if(m_root == NULL) return;
	else{
		do{
			curr = search_quantity(0);
			if(curr != m_root)
				p_curr = curr->get_parent();
			if(curr == m_root) deleteFromTree(m_root);
			else if (p_curr->get_left() == curr)
				deleteFromTree(p_curr->get_left());
			else
				deleteFromTree(p_curr->get_right());
		}while(curr != NULL);
	}
}

template<typename Item>
int BSTree<Item>::search_code(std::string code){
	int result = 0;
	bool found = find_code(m_root, code, &result);
	if(found) return result;
	else return 0;
}

template<typename Item>
bool BSTree<Item>::find_code(BTNode<Item>* node, std::string code, int *result){
	if(node == NULL){
		 std::cout << code << " : 0" << std::endl;
		 return true;
	}
	Item *data = node->get_data();

	if(*data == code){
		*result=*result+1;
		std::cout << *data << std::endl;
		return true;
	}
	else if(*data < code){
		*result=*result+1;
		return find_code(node->get_right(), code, result);
	}
	else{
		*result=*result+1;
		return find_code(node->get_left(), code, result);
	}
}

template<typename Item>
int BSTree<Item>::get_length() const{
	return m_length - 1;
}
}
