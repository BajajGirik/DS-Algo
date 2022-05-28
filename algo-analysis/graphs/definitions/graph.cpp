#include "../headers/graph.h"

Graph::Graph(int n) {
	totalVertices = n;
	std::vector<int> temp(n, INT_MAX);
	for(int i = 0; i < n; ++i) {
		edges.push_back(temp);
		visited.push_back(false);
	}
}

void Graph::displayGraph() {
	for(int i=0; i<totalVertices; ++i) {
		for(int j=0; j<totalVertices; ++j)
			std::cout << edges[i][j] << " ";

		std::cout << "\n";
	}
}

void Graph::addNode(int v1, int v2, int weight ,bool bidirectional) {
	if(v1 >= totalVertices and v2 >= totalVertices) {
		std::cout << "Vertices out of bounds!\n";
		return;
	}

	edges[v1][v2] = weight;
	if(bidirectional) edges[v2][v1] = weight;
}

void Graph::dfs(int v){
	visited[v] = true;
	std::cout << v << " ";
	for(int i=0; i<totalVertices; ++i)
		if(edges[v][i] != INT_MAX && !visited[i])
			dfs(i);
}

void Graph::bfs(int v) {
	static std::queue<int> q;
	for(int i=0; i<totalVertices; ++i)
	{
		if(edges[v][i] != INT_MAX && !visited[i])
		{
			visited[i] = true;
			q.push(i);
		}
	}
	while(!q.empty())
	{
		std::cout<< q.front() <<" ";
		q.pop();
		bfs(q.front());
	}
}


// void Graph::bfs(int v) {
// 	std::queue<int> q;
// 	q.push(v);
// 	visited[v] = true;

// 	while(!q.empty()) {
// 		int node = q.front();
// 		std::cout << node << " ";
// 		q.pop();

// 		for(int i=0; i<totalVertices; ++i)
// 			if(edges[node][i] != INT_MAX and !visited[i]) {
// 				visited[i] = true;
// 				q.push(i);
// 			}
// 	}
// }