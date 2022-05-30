#ifndef UTILS_H
#define UTILS_H

#include <bits/stdc++.h>

struct KruskalsInfo {
	int dist;
	std::pair<int, int> edge;
};

struct Union {
	std::vector<int> parent;
	
	Union(int);
	void performUnion(int, int);
	bool formsCycle(int, int);
};

void file_io(const char *, const char *);
int getMinIndex(std::vector<std::pair<int, bool>>, int);
void printPMst(std::vector<int>, std::vector<std::vector<int>>, int);
void printKMst(std::vector<int>, std::vector<KruskalsInfo>);
bool kruskalsInfoCmp(const KruskalsInfo, const KruskalsInfo);

#endif