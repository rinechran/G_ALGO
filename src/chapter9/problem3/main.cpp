#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
public:
	int V;
	vector<vector<bool> > adj;
	vector<int> degree;

	Graph(int V) {
		this->adj = vector<vector<bool> >(V + 1, vector<bool>(V + 1, false));
		this->V = V;
		this->degree = vector<int>(V + 1, 0);
	}

	void addEdge(int u, int v) {
		adj[u][v] = adj[v][u] = true;
		degree[u] += 1;
		degree[v] += 1;
	}

	bool hasEdge(int u, int v) const {
		return adj[u][v];
	}

	int getDegree(int nodeIndex) const {
		return this->degree[nodeIndex];
	}

};

bool isConnectedGraph(const Graph& graph) {

	queue<int> reachableNodes;
	std::vector<bool> visited(graph.V + 1, false);

	int visitCount = 0;
	int originNode = 1;

	reachableNodes.push(originNode);

	while (reachableNodes.size() != 0) {

		int currentNode = reachableNodes.front();
		reachableNodes.pop();

		if (visited[currentNode] == true) {
			continue;
		}
		visited[currentNode] = true;
		visitCount++;


		for (int node = 1; node <= graph.V; ++node) {
			if (graph.hasEdge(node, currentNode)) {
				reachableNodes.push(node);
			}
		}
	}


	return visitCount == graph.V;
}

bool hasEulerPath(const Graph& graph) {

	if (isConnectedGraph(graph) == false) {
		return false;
	}
	int oddDegree = 0;
	for (int node = 1; node <= graph.V; node += 1) {
		int degree = graph.getDegree(node);
		if (degree % 2 == 1) {
			oddDegree += 1;
		}
	}
	return oddDegree == 0 || oddDegree == 2;

}

bool hasEulerCircuit(const Graph& graph) {
	if (isConnectedGraph(graph) == false) {
		return false;
	}
	for (int node = 1; node <= graph.V; node += 1) {
		int degree = graph.getDegree(node);
		if (degree % 2 == 1) {
			return false;
		}
	}
	return true;
}

int main() {
	int V;
	std::cin >> V;

	Graph graph(V);
	for (int u = 1; u <= V; u += 1) {
		for (int v = 1; v <= V; v += 1) {
			int exist;
			std::cin >> exist;
			if (exist == 1) {
				graph.addEdge(u, v);
			}
		}
	}

	if (hasEulerPath(graph)) {
		puts("YES");
	}
	else {
		puts("NO");
	}

	if (hasEulerCircuit(graph)) {
		puts("YES");
	}
	else {
		puts("NO");
	}
}