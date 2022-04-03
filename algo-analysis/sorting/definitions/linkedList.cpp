#include "../../myheader.h"
#include "../headers/linkedList.h"

LinkedList::LinkedList() {
	head = NULL;
	tail = NULL;
	total_nodes = 0;
}

void LinkedList::add_node(ll value) {
	++total_nodes;

	if(head == NULL) {
		Node* ptr = new Node(value);
		head = ptr;
		tail = ptr;
		return;
	}

	Node* ptr = new Node(value);
	tail->next = ptr;
	tail = ptr;
}

bool LinkedList::search_node(ll value) {
	Node* temp = head;

	while(temp != NULL) {
		if(temp->value == value) {
			cout << "Value " << value << " is present in the set" << endl;
			return true;
		}

		temp = temp->next;
	}

	cout << "Value " << value << " is not present in the set" << endl;
	return false;
}

void LinkedList::print_data() {
	Node* temp = head;
	cout << "Total elements in set: " << total_nodes << endl;

	while(temp != NULL) {
		cout << temp->value << " ";
		temp = temp->next;
	}

	cout << endl << endl;
}

LinkedList LinkedList::operator+ (LinkedList const & list) {
	Node* start_list = NULL;
	Node* final_list = NULL;

	if(total_nodes > list.total_nodes) {
		start_list = list.head;
		final_list = head;
	} else {
		start_list = head;
		final_list = list.head;
	}

	LinkedList result;

	while(start_list != NULL) {
		result.add_node(start_list->value);
		start_list = start_list->next;
	}

	result.tail->next = final_list;
	result.total_nodes += max(total_nodes, list.total_nodes);

	return result;
}