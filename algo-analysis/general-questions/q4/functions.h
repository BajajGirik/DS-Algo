#include "../../myheader.h"

void print_left_side_pattern(ll n) {
	cout << "Left side " << n << "X" << n << " matrix: " << endl;

	loop(i, 0, n) {
		loop(j, 0, n) {
			if(i >= j) 
				cout << "* ";
			else 
				cout << "  ";
		}
		cout << endl;
	}
	cout << endl;
}

void print_right_side_pattern(ll n) {
	cout << "Right side " << n << "X" << n << " matrix: " << endl;

	loop(i, 0, n) {
		loop(j, 0, n) {
			if(i <= j) 
				cout << "* ";
			else 
				cout << "  ";
		}
		cout << endl;
	}
	cout << endl;
}

void print_pattern_c(ll n) {
	cout << "Pattern C " << n << "X" << n << " matrix: " << endl;

	loop(i, 0, n) {
		loop(j, 0, n) {
			if(i <= j && (i != 0 || j != n-1)) 
				cout << "* ";
			else 
				cout << "  ";
		}
		cout << endl;
	}
	cout << endl;
}

void print_pattern_d(ll n) {
	cout << "Pattern D " << n << "X" << n << " matrix: " << endl;

	loop(i, 0, n) {
		loop(j, 0, n) {
			if(i >= j && (i != n-1 || j != 0)) 
				cout << "* ";
			else 
				cout << "  ";
		}
		cout << endl;
	}
	cout << endl;
}