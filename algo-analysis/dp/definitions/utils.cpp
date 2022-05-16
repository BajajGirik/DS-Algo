#include "../headers/utils.h"
#include <iostream>

void file_io(char * inputFilePath, char * outputFilePath) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
	freopen(inputFilePath, "r", stdin);
	freopen(outputFilePath, "w", stdout);
}

int ** matrix_multiplication(int ** m1, int ** m2, int r1, int c1, int r2, int c2) {
	int ** res = new int*[r1];	

	if(c1 != r2) {
		std::cout << "Matrices dimensions not valid\n";
		return res;
	}

	for (int i = 0; i < r1; i++) {
		res[i] = new int[c2];
        for (int j = 0; j < c2; j++) {
            res[i][j] = 0;
            for (int k = 0; k < c1; k++)
                res[i][j] += m1[i][k] * m2[k][j];
        }
    }

	return res;
}

bool fractionalKnapsackCmp(const struct knapsack & s1, const struct knapsack & s2) {
	return (s1.p/s1.w - s2.p/s2.w);
}

bool sortLeafNodes(const struct Node *n1, const struct Node * n2) {
	return (n1->data - n2->data);
}

void print_huffman_codes(struct HuffmanCodes hc[], int n) {
	for(int i = 0; i < n; ++i) {
		std::cout << hc[i].ch << ": " << hc[i].str;
	}
}