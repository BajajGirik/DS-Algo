#include "../../myheader.h"

struct matrix {
	ll mat[10][10];
	ll rows, cols;

	matrix();
	void input_data();
	void print_data();
	matrix operator * (matrix const &);
	matrix operator + (matrix const &);
};

matrix::matrix() {
	rows = 0;
	cols = 0;
	loop(i, 0, 10) {
		loop(j, 0, 10) {
			mat[i][j] = 0;
		}
	}
}

void matrix::input_data() {
	cout << "Enter rows of matrix: ";
	cin >> rows;
	
	cout << "Enter columns of matrix: ";
	cin >> cols;
	
	cout << "Enter matrix data: " << endl;
	loop(i, 0, rows) {
		loop(j, 0, cols) {
			cout << "matrix[" << i << "][" << j << "]: ";
			cin >> mat[i][j];
		}
	}
}

void matrix::print_data() {
	cout << "Rows: " << rows << endl;
	cout << "Columns: " << cols << endl;

	cout <<"Matrix" << endl;
	loop(i, 0 , rows) {
		loop(j, 0, cols) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}

matrix matrix::operator * (matrix const & obj) {
	clock_t start = clock();
	matrix result;
	
	if(cols != obj.rows) {
		cout << "Matrix multiplication not possible" << endl;
		return result; 
	}

	result.rows = rows;
	result.cols = obj.cols;


	loop(i, 0, result.rows) {
		loop(j, 0, result.cols) {
			loop(k, 0, cols) {
				result.mat[i][j] += mat[i][k] * obj.mat[k][j];
			}
		}
	}

	clock_t end = clock();
	cout << "\n\nMatrix Multiplication Executed in: " << (double)(end - start) / double(CLOCKS_PER_SEC) << " sec\n\n";
	return result;
}

matrix matrix::operator + (matrix const & obj) {
	clock_t start = clock();
	matrix result;

	if(rows != obj.rows || cols != obj.cols) {
		cout << "Matrix addition not possible" << endl;
		return result;
	}

	result.rows = rows;
	result.cols = cols;

	loop(i, 0, result.rows) {
		loop(j, 0, result.cols) {
			result.mat[i][j] = mat[i][j] + obj.mat[i][j];
		}
	}

	clock_t end = clock();
	cout << "\n\nMatrix Addition Executed in: " << (double)(end - start) / double(CLOCKS_PER_SEC) << " sec\n\n";
	return result;
}