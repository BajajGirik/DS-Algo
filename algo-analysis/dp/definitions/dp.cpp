#include "../headers/dp.h"
#include "../headers/utils.h"
#include <iostream>
#include <climits>
#include <cstring>
#include <algorithm>

int matrix_chain_multiplication(int d[], int n) {
	int m[n][n];
 
    for (int i = 1; i < n; ++i)
        m[i][i] = 0;
 
    for (int size = 2; size < n; ++size)
    {
        for (int i = 1; i < n - size + 1; i++)
        {
            int j = i + size - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                int q = m[i][k] + m[k + 1][j]
                    + d[i - 1] * d[k] * d[j];

                m[i][j] = std::min(q, m[i][j]);
            }
        }
    }
 
    return m[1][n - 1];
}

char * longest_common_subsequence(char *s1, char *s2, int n1, int n2) {
	int dp[n1][n2];
	
	for(int i = 0; i < n1; ++i) {
		dp[i][0] = 0;
	}
	
	for(int i = 0; i < n2; ++i) {
		dp[0][i] = 0;
	}

	for(int i = 1; i <= n1; ++i) {
		for(int j = 1; j <= n2; ++j) {
			if(s1[i] == s2[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			} else {
				dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}


	int i = n1, j = n2, len = dp[n1][n2];
	char s[len];
	--len;

	while(i >= 1 and j >= 1 and dp[i][j] != 0) {
		if(dp[i][j] == dp[i-1][j])
			--i;
		else if(dp[i][j] == dp[i][j-1])
			--j;
		else {
			s[len--] = s1[i-1];
		}
	}

	return s;
}

int fractionalKnapsack(int w[], int p[], int n, int W) {
	knapsack knap[n];
	for(int i = 0; i < n; ++i) {
		knap[i].w = w[i];
		knap[i].p = p[i];
	}

	std::sort(knap, knap + n, fractionalKnapsackCmp);

	int totalWeight = 0;
	int totalProfit = 0;
	for(int i = n-1; i >= 0; --i) {
		if(totalWeight + knap[i].w >= W) {
			totalProfit += (W-totalWeight)*knap[i].p;
			totalWeight = W;
			break;
		}

		totalProfit += knap[i].w * knap[i].p;
		totalWeight += knap[i].w;
	}

	return totalProfit;
}

int zero_one_knapsack(int w[], int p[], int n, int W) {
	int dp[n+1][W+1];

	for(int i = 0; i <= n; ++i) {
		dp[i][0] = 0;
	}
	
	for(int i = 0; i <= W; ++i) {
		dp[i][0] = 0;
	}

	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= W; ++j) {
			if(j < w[i]) {
				dp[i][j] = dp[i-1][j];
			} else {
				dp[i][j] = std::max(dp[i-1][j-w[i]] + p[i], dp[i-1][j]);
			}
		}
	}

	return dp[n][W];
}

void huffman_encoding_tree_parser(struct Node * root, struct HuffmanCodes * hc, char str[HUFFMAN_CODE_SIZE], int n, char key) {
	static int index = 0;

	if(root == NULL) {
		str[n] = '\n';
		hc[index].ch = key;
		strcpy(hc[index].str, str);
		++index;
	}
	
	str[n] = '0';
	huffman_encoding_tree_parser(root->left, hc, str, n+1, root->data);
	str[n] = '1';
	huffman_encoding_tree_parser(root->right, hc, str, n+1, root->data);
}

struct HuffmanCodes * huffman_encoding(char * s, int n) {
	int freq[26] = {0};

	for(int i = 0; i < n; ++i) {
		++freq[s[i] - 'a'];
	}


	int count = 0;
	for(int i = 0; i < 26; ++i) {
		if(freq[i] != 0) {
			++count;
		}
	}


	struct Node *p[count];

	int index = 0;
	for(int i = 0; i < 26; ++i) {
		if(freq[i] != 0) {
			p[index]->ch = 'a' + i;
			p[index]->data = freq[i];
			p[index]->left = NULL;
			p[index]->right = NULL;
			++index;
		}
	}

	std::sort(p, p + count, sortLeafNodes);

	for(int i = 0; i < count - 1; ++i) {
		struct Node *temp = new Node();
		temp->data = p[i]->data + p[i+1]->data;
		temp->left = p[i];
		temp->right = p[i+1];

		int temp_index = i+2;
		while(temp->data > p[temp_index]->data) {
			p[temp_index-1] = p[temp_index];
			++temp_index;
		}

		p[temp_index - 1] = temp;
	}

	struct HuffmanCodes hc[count];
	char str[HUFFMAN_CODE_SIZE];
	huffman_encoding_tree_parser(p[n-1], hc, str, 0);

	return hc;
}