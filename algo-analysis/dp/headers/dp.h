#include "utils.h"

#ifndef DP_H
#define DP_H

int matrix_chain_multiplication(int [], int);
char * longest_common_subsequence(char *, char *, int, int);
int fractionalKnapsack(int [], int [], int, int);
int zero_one_knapsack(int [], int [], int, int);
void huffman_encoding_tree_parser(struct Node *, struct HuffmanCodes *, char [HUFFMAN_CODE_SIZE], int, char = 'a');
struct HuffmanCodes * huffman_encoding(char *, int);

#endif