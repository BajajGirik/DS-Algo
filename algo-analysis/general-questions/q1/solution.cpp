#include "types.h"

int main() {
	clock_t start = clock();
	// file_i_o();

	Easy e1, e2;
	e1.input_data();
	e2.input_data();

	cout << "Data entered: " << endl;
	e1.print_data();
	e2.print_data();

	cout << "Comparison operations" << endl;
	if(e1 > e2) cout << "e1 is greater than e2" << endl;
	else if(e1 < e2) cout << "e1 is less than e2" << endl;
	else cout << "e1 is equal to e2" << endl;

	clock_t end = clock();
	cout << "\n\nExecuted in: " << (double)(end - start) / double(CLOCKS_PER_SEC) << " sec\n";

	return 0;
}