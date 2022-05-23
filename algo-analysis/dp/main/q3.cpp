#include "../headers/dp.h"
#include "../headers/utils.h"

int main() {

	file_io("IO/q3/input.txt", "IO/q3/output.txt");
	int n, W;
	std::cin >> n >> W;
	int w[n], p[n];
	for(int i = 0; i < n; ++i) {
		std::cin >> w[i];
	}
	for(int i = 0; i < n; ++i) {
		std::cin >> p[i];
	}

	std::cout << "Result for fractional knapsack: " << fractionalKnapsack(w, p, n, W) << "\n";
	std::cout << "Result for 0/1 knapsack: " << zero_one_knapsack(w, p, n, W) << "\n";
	return 0;
}