#include "../headers/graph.h"
#include "../headers/utils.h"

int main() {
	file_io("IO/q4/input.txt", "IO/q4/output.txt");
	int noOfVertices, noOfedges;
	std::cin >> noOfVertices >> noOfedges;

	Graph g(noOfVertices);

	for(int i=0; i<noOfedges; ++i) {
		int v1, v2, w;
		std::cin >> v1 >> v2 >> w;
		g.addNode(v1, v2, w, false);
	}

	g.primsMst();
	return 0;
}