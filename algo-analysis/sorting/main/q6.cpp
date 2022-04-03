#include "../headers/linkedList.h"

void file_i_o() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("IO/q6/input.txt","r", stdin);
	freopen("IO/q6/output.txt","w", stdout);
}

int main() {
	file_i_o();

	LinkedList l1, l2;

	l1.add_node(2);
	l1.add_node(3);
	l1.add_node(5);
	l1.print_data();

	l2.add_node(7);
	l2.add_node(8);
	l2.add_node(9);
	l2.add_node(10);
	l2.print_data();

	LinkedList l3 = l1 + l2;
	l3.print_data();

	l3.search_node(7);
	l3.search_node(1);
	return 0;
}