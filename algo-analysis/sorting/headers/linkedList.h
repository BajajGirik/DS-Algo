#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "../../myheader.h"
#include "../headers/node.h"

struct LinkedList {
	Node *head, *tail;
	ll total_nodes;
	
	LinkedList();
	void add_node(ll);
	bool search_node(ll);
	void print_data();
	LinkedList operator+ (LinkedList const &);
};

#endif