#include "sorting.h"

int main() {
	file_i_o();

	auto v = input_data();

	cout << "---------Sorting Analysis---------" << endl;

	insertion_sort(v);
	selection_sort(v);
	bubble_sort(v);
	count_sort(v);

	return 0;
}