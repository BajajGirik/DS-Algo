#ifndef TREES_H
#define	TREES_H

#include "../../myheader.h"
#include "../headers/node.h"

struct Tree {
	Node *root;
	ll total_nodes;

	Tree();
	void print_data();
	vi get_array_of_values();
	void add_node(ll, Node* = NULL, ll = 0);
	bool search_node(ll);
	Tree operator+ (Tree const &);
};

#endif