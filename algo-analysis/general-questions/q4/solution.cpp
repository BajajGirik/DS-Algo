#include "functions.h"

int main() {
	ll n;
	cout << "Enter matrix size: ";
	cin >> n;
	cout << endl;

	print_left_side_pattern(n);
	print_right_side_pattern(n);
	print_pattern_c(n);
	print_pattern_d(n);

	return 0;
}