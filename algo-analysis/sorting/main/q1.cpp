#include "../headers/utils.h"

void file_i_o() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("IO/input.txt","r", stdin);
	freopen("IO/q1/output.txt","w", stdout);
}

int main() {
	file_i_o();

	auto v = input_data();

	cout << "---------Sorting Analysis---------" << endl;

	insertion_sort_analysis(v);
	selection_sort_analysis(v);
	bubble_sort_analysis(v);
	quick_sort_analysis(v);
	heap_sort_analysis(v);

	return 0;
}