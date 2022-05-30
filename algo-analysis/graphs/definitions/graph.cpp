#include "../headers/graph.h"
#include "../headers/utils.h"

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
			std::cout << (edges[i][j] == INT_MAX ? 0 : edges[i][j]) << " ";

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
	std::queue<int> q;
	q.push(v);
	visited[v] = true;

	while(!q.empty()) {
		int node = q.front();
		std::cout << node << " ";
		q.pop();

		for(int i=0; i<totalVertices; ++i)
			if(edges[node][i] != INT_MAX and !visited[i]) {
				visited[i] = true;
				q.push(i);
			}
	}
}

void Graph::primsMst() {
	std::vector<std::pair<int, bool>> dist(totalVertices, {INT_MAX, false});
	std::vector<int> parent(totalVertices, -1);
	dist[0].first = 0;

	int count = 0;
	while(count < totalVertices-1) {
		int minIndex = getMinIndex(dist, totalVertices);

		dist[minIndex].second = true;
		++count;

		for(int i=0; i<totalVertices; ++i)
			if(edges[minIndex][i] != INT_MAX and (dist[i].first == INT_MAX or dist[i].first > dist[minIndex].first + edges[minIndex][i])) {
				dist[i].first = dist[minIndex].first + edges[minIndex][i];
				parent[i] = minIndex;
			}
	}

	printPMst(parent, edges, totalVertices);
}

void Graph::kruskalMst() {
	std::vector<KruskalsInfo> K;
	for(int i=0; i<totalVertices; ++i)
		for(int j=0; j<totalVertices; ++j)
			if(edges[i][j] != INT_MAX) {
				KruskalsInfo temp;
				temp.dist = edges[i][j];
				temp.edge = {i, j};
				K.push_back(temp);
			}

	std::sort(K.begin(), K.end(), kruskalsInfoCmp);
	
	int count = 0, index = 0;
	std::vector<int> selectedEdges;
	Union u(totalVertices);
	while(index < K.size() and count < totalVertices - 1) {
		if(!u.formsCycle(K[index].edge.first, K[index].edge.second)) {
			u.performUnion(K[index].edge.first, K[index].edge.second);
			selectedEdges.push_back(index);
			++count;
		}
		++index;
	}

	printKMst(selectedEdges, K);
}