#ifndef NODE_H
#define NODE_H

#include "../../myheader.h"

struct Node {
	ll value;
	Node* next;

	Node();
	Node(ll);
	Node(ll, Node*);
};

#endif