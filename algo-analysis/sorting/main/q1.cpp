#include "../headers/utils.h"

int main() {
	file_i_o();

	auto v = input_data();

	cout << "---------Sorting Analysis---------" << endl;

	insertion_sort_analysis(v);
	selection_sort_analysis(v);
	bubble_sort_analysis(v);
	count_sort_analysis(v);
	quick_sort_analysis(v);
	heap_sort_analysis(v);

	return 0;
}