#include "../headers/sorting.h"
#include "../headers/utils.h"

void file_i_o() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("IO/input.txt","r", stdin);
	freopen("IO/q5/output.txt","w", stdout);
}

int main() {
	file_i_o();
	auto v = input_data();
	ll pos = 2;

	print_data(v);
	cout << endl;
	ll k = get_smallest_kth_element(v, pos, 0, v.size() - 1);
	cout << pos <<  "th Largest element: " << k << endl;
	
	return 0;
}