#ifndef NODE_H
#define NODE_H

#include "../../myheader.h"

struct Node {
	ll value;
	Node* next;
	Node* next_r;

	Node();
	Node(ll);
	Node(ll, Node*);
	Node(ll, Node*, Node*);
};

#endif