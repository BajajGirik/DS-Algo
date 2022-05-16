#include "utils.h"
#include <iostream>
#ifndef DP_H
#define DP_H

int matrix_chain_multiplication(int [], int);
char * longest_common_subsequence(char *, char *, int, int);
int fractionalKnapsack(int [], int [], int, int);
int zero_one_knapsack(int [], int [], int, int);
void huffman_encoding_tree_parser(Node *, HuffmanCodes *, char [HUFFMAN_CODE_SIZE], int = 0, char = 'a');
HuffmanCodes * huffman_encoding(std::string, int);

#endif