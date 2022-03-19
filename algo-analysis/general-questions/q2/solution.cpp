#include "types.h"

int main() {
	matrix m1, m2;
	m1.input_data();
	m2.input_data();

	cout << "Matrix 1:" << endl;
	m1.print_data();
	
	cout << "Matrix 2:" << endl;
	m2.print_data();

	matrix m3 = m1 * m2;
	cout << "Resultant product:" << endl;
	m3.print_data();

	matrix m4 = m1 + m2;
	cout << "Resultant addition:" << endl;
	m4.print_data();

	return 0;
}