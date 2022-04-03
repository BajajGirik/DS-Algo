#include "../headers/linkedList.h"

Node::Node() {
	value = 0;
	next = NULL;
}

Node::Node(ll x) {
	Node* ptr = new Node;
	ptr->value = x;
	ptr->next = NULL;
}

Node::Node(ll x, Node* next_ptr) {
	Node* ptr = new Node;
	ptr->value = x;
	ptr->next = next_ptr;
}

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
			return true;
		}

		temp = temp->next;
	}

	return false;
}

LinkedList LinkedList::operator+ (LinkedList const & list) {
	Node* start_list = NULL;
	Node* final_list = NULL;

	if(total_nodes > list.total_nodes) {
		start_list = head;
		final_list = list.head;
	} else {
		start_list = list.head;
		final_list = head;
	}

	LinkedList result;

	while(start_list->next != NULL) {
		result.add_node(start_list->value);
		start_list = start_list->next;
	}

	result.tail->next = final_list;
	result.total_nodes += max(total_nodes, list.total_nodes);

	return result;
}