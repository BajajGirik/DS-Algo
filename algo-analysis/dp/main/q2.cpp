#include "../headers/dp.h"
#include "../headers/utils.h"

int main() {
	file_io("IO/q2/input.txt", "IO/q2/output.txt");
	std::string s1, s2;
	std::cin >> s1 >> s2;
	std::string s = longest_common_subsequence(s1, s2, s1.size(), s2.size());
	std::cout << s;
	return 0;
}