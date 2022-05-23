#ifndef UTILS_H
#define UTILS_H

const int MATRIX_MAX_CELL = 50;
const int HUFFMAN_CODE_SIZE = 16;

struct knapsack {
	int w, p;
};

struct Node {
	int data;
	char ch;
	Node *left, *right;

	Node();
};

struct HuffmanCodes {
	char ch;
	char str[HUFFMAN_CODE_SIZE];
};

void file_io(const char *, const char *);
int ** matrix_multiplication(int **, int **, int, int, int, int);
bool fractionalKnapsackCmp(const struct knapsack &, const struct knapsack &);
bool sortLeafNodes(const struct Node *, const struct Node *);
void print_huffman_codes(struct HuffmanCodes [], int);

#endif