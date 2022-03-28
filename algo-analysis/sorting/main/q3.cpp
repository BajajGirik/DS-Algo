#include "../headers/sorting.h"
#include "../headers/utils.h"

int main() {
	file_i_o();
	auto v = input_data();
	ll pos = 4;

	ll k = get_largest_kth_element(v, pos, 0, v.size() - 1);
	cout << pos <<  "th Largest element: " << k << endl;
	
	return 0;
}