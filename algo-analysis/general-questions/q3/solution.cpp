#include "types.h"

int main() {

	polynomial p1, p2;
	p1.input_data();
	p2.input_data();

	cout << "Polynomial 1: ";
	p1.print_data();
	
	cout << "Polynomial 2: ";
	p2.print_data();

	cout << "Addition of polynomials: ";
	polynomial p3 = p1 + p2;
	p3.print_data();

	cout << "Multiplication of polynomials: ";
	polynomial p4 = p1 * p2;
	p4.print_data();

	return 0;
}