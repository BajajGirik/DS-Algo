#include "../headers/dp.h"
#include "../headers/utils.h"

int main() {

	file_io("IO/q1/input.txt", "IO/q1/output.txt");
	HuffmanCodes* hc = huffman_encoding("aaaabbbcccdd", 12);
	print_huffman_codes(hc, 4);
	return 0;
}