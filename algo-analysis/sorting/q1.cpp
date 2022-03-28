#include "sorting.h"

int main() {
	file_i_o();

	auto v = input_data();

	cout << "---------Sorting Analysis---------" << endl;

	insertion_sort(v);
	selection_sort(v);
	bubble_sort(v);
	count_sort(v);
	quick_sort_analysis(v, 0, v.size()-1);

	return 0;
}