#include "../headers/utils.h"

void file_io(const char * inputPath, const char * outputPath) {
	freopen(inputPath, "r", stdin);
	freopen(outputPath, "w", stdout);
}

Union::Union(int n) {
	for(int i=0; i<n; ++i) {
		parent.push_back(i);
	}
}

void Union::performUnion(int a, int b) {
	parent[b] = parent[a];
}

bool Union::formsCycle(int a, int b) {
	while(parent[a] != a) a = parent[a];
	while(parent[b] != b) b = parent[b];

	return a == b;
}

int getMinIndex(std::vector<std::pair<int, bool>> dist, int n) {
	int minIndex = -1;
	for(int i=0; i<n; ++i)
		if(!dist[i].second and (minIndex==-1 or dist[minIndex].first > dist[i].first))
			minIndex = i;
	return minIndex;
}

void printPMst(std::vector<int> parent, std::vector<std::vector<int>> egdes, int n) {
	for(int i=1; i<n; ++i)
		std::cout << parent[i] << "-" << i << ":  " << egdes[parent[i]][i] << "\n";
}

void printKMst(std::vector<int> selectedEdges, std::vector<KruskalsInfo> K) {
	for(int index: selectedEdges)
		std::cout << K[index].edge.first << "-" << K[index].edge.second << ":   " << K[index].dist << "\n"; 
}

bool kruskalsInfoCmp(const KruskalsInfo k1, const KruskalsInfo k2) {
	return k1.dist < k2.dist;
}