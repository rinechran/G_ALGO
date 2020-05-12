#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
class Edge;

class Node {
public:
	Node(int index) {
		this->index = index;

	}
	int index;
	vector<Edge> edges;

};
class Edge {
public:
	Node* nodeU;
	Node* nodeV;
	int weight;

	Edge(Node* nodeU, Node* nodeV, int weight) :nodeU(nodeU), nodeV(nodeV) {
		this->weight = weight;
	}

	bool operator < (const Edge& other) const {
		return this->weight > other.weight;
	}
};

vector<Edge> getMinimumSpanningTree(int V, int E, vector<Node>& nodes) {

	vector<Edge> spanningTree;

	std::vector<int> visited(V + 1, 0);

	std::priority_queue<Edge> usableEdges;

	for (int i = 0; i < nodes[1].edges.size(); ++i) {
		usableEdges.push(nodes[1].edges[i]);
	}
	visited[1] = true;

	while (usableEdges.empty() == false) {
		Edge current = usableEdges.top();
		usableEdges.pop();

		Node& dest = *current.nodeV;
		if (visited[dest.index] == true) {
			continue;
		}
		visited[dest.index] = true;
		spanningTree.push_back(current);


		for (int i = 0; i < dest.edges.size(); ++i) {
			Node nextNode = *dest.edges[i].nodeV;
			if (visited[nextNode.index] == true) {
				continue;
			}

			usableEdges.push(dest.edges[i]);
		}

	}


	return spanningTree;


}

int main() {
	int V, E;
	std::cin >> V >> E;
	vector<Edge> edges;
	vector<Node> nodes;
	for (int i = 0; i <= V + 1; ++i) {
		nodes.push_back(Node(i));

	}
	for (int i = 0; i < E; i += 1) {
		int u, v, w;
		std::cin >> u >> v >> w;

		nodes[u].edges.push_back(Edge(&(nodes[u]), &(nodes[v]), w));
		nodes[v].edges.push_back(Edge(&(nodes[v]), &(nodes[u]), w));

	}

	vector<Edge> spanningTree = getMinimumSpanningTree(V, E, nodes);

	long long weightSum = 0;
	for (int i = 0; i < spanningTree.size(); i += 1) {
		weightSum += spanningTree[i].weight;
	}

	printf("%lld\n", weightSum);
}
