#ifndef GRAPH_H
#define GRAPH_H

#include <bits/stdc++.h>

struct Graph {
	int totalVertices;
	std::vector<std::vector<int>> edges;
	std::vector<bool> visited;

	Graph(int);
	void displayGraph();
	void addNode(int, int, int = 1, bool = true);

	// graph traversals
	void dfs(int);
	void bfs(int);

	// minimum spanning trees
	void primsMst();
	void kruskalMst();

	// shortest path problems
	void dijakstrasSp();
	void floydWarshalSp();
};

#endif