#include "sorting.h"

int main() {
	file_i_o();
	auto v = input_data();
	ll pos = 2;

	ll k = get_largest_kth_element(v, pos, 0, v.size() - 1);
	cout << pos <<  "th Largest element: " << k << endl;
}