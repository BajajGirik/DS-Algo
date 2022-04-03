#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "../../myheader.h"

struct Node {
	ll value;
	Node* next;

	Node();
	Node(ll);
	Node(ll, Node*);
};

struct LinkedList {
	Node *head, *tail;
	ll total_nodes;
	
	LinkedList();
	void add_node(ll);
	bool search_node(ll);
	LinkedList operator+ (LinkedList const &);
};

#endif