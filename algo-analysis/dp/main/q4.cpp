#include "../headers/dp.h"
#include "../headers/utils.h"

int main() {
	file_io("IO/q4/input.txt", "IO/q4/output.txt");
	std::string s;
	std::cin >> s;
	HuffmanCodes* hc = huffman_encoding(s, s.size());

	int count = 0, a[26] = {0};
	for(int i = 0; i < s.size(); ++i) {
		if(a[s[i]-'a'] == 0) {
			++count;
			a[s[i]-'a'] = 1;
		}
	}

	print_huffman_codes(hc, count);
	return 0;
}