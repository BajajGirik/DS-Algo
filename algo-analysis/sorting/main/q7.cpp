#include "../headers/trees.h"

void file_i_o() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("IO/q7/input.txt","r", stdin);
	freopen("IO/q7/output.txt","w", stdout);
}

int main() {
	file_i_o();

	Tree t1, t2;

	t1.add_node(2);
	t1.add_node(3);
	t1.add_node(5);
	t1.print_data();

	t2.add_node(7);
	t2.add_node(8);
	t2.add_node(9);
	t2.add_node(10);
	t2.print_data();

	Tree t3 = t1 + t2;
	t3.print_data();

	t3.search_node(2);
	t3.search_node(6);

	return 0;
}