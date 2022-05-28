#include "../headers/graph.h"
#include "../headers/utils.h"

int main() {

	file_io("IO/q2/input.txt", "IO/q2/output.txt");
	int noOfVertices, noOfedges;
	std::cin >> noOfVertices >> noOfedges;

	Graph g(noOfVertices);

	for(int i=0; i<noOfedges; ++i) {
		int v1, v2;
		std::cin >> v1 >> v2;
		g.addNode(v1, v2);
	}

	g.dfs(0);
	return 0;
}