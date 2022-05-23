#include "../headers/dp.h"
#include "../headers/utils.h"

int main() {

	file_io("IO/q1/input.txt", "IO/q1/output.txt");
	int n;
	std::cin >> n;
	int a[n];
	for(int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	int res = matrix_chain_multiplication(a, n);
	std::cout << res << "\n";
	return 0;
}