#include "../headers/node.h"

Node::Node() {
	value = 0;
	next = next_r = NULL;
}

Node::Node(ll x) {
	value = x;
	next = next_r = NULL;
}

Node::Node(ll x, Node* next_ptr) {
	value = x;
	next = next_ptr;
	next_r = NULL;
}

Node::Node(ll x, Node* next_ptr, Node* next_ptr_r) {
	value = x;
	next = next_ptr;
	next_r = next_ptr_r;
}