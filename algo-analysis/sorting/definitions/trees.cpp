#include "../headers/trees.h"

Tree::Tree() {
	root = NULL;
	total_nodes = 0;
}

vi Tree::get_array_of_values() {
	queue<Node*> q;
	vi values;
	q.push(root);

	while(!q.empty()) {
		Node* curr = q.front();
		values.pb(curr->value);
	
		if(curr->next != NULL) {
			q.push(curr->next);
		}

		if(curr->next_r != NULL) {
			q.push(curr->next_r);
		}

		q.pop();
	}

	return values;
}

void Tree::print_data() {
	auto data = get_array_of_values();
	cout << "Total elements in the set: " << total_nodes << endl;

	for(auto x : data) {
		cout << x << " ";
	}

	cout << endl << endl;
}

// add a single or multiple nodes
void Tree::add_node(ll value, Node* head, ll total) {
	if(root == NULL and head == NULL) {
		++total_nodes;
		root = new Node(value);
		return;
	}

	if(root == NULL) {
		total_nodes += total;
		root = head;
		return;
	}

	Node* temp = root;
	Node* prev = root;

	while(temp != NULL) {
		prev = temp;

		if(value < temp->value) {
			temp = temp->next;
		} else {
			temp = temp->next_r;
		}
	}

	if(head == NULL) {
		if(value < prev->value) {
			prev->next = new Node(value);
		} else {
			prev->next_r = new Node(value);
		}

		++total_nodes;
	} else {
		if(value < prev->value) {
			prev->next = head;
		} else {
			prev->next_r = head;
		}

		total_nodes += total;
	}
}

bool Tree::search_node(ll value) {
	Node* temp = root;
	while(temp != NULL) {
		if(value == temp->value) {
			cout << "Value " << value << " is present" << endl;
			return true;
		} else if(value < temp->value) {
			temp = temp->next;
		} else {
			temp = temp->next_r;
		}
	}

	cout << "Value " << value << " is not present" << endl;
	return false;
}

Tree Tree::operator+ (Tree const & tree) {
	Tree result;
	
	auto val = get_array_of_values();

	for(auto i: val) {
		result.add_node(i);
	}

	result.add_node(tree.root->value ,tree.root, tree.total_nodes);
	return result;
}
