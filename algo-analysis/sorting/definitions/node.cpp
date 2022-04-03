#include "../headers/node.h"

Node::Node() {
	value = 0;
	next = NULL;
}

Node::Node(ll x) {
	value = x;
	next = NULL;
}

Node::Node(ll x, Node* next_ptr) {
	value = x;
	next = next_ptr;
}