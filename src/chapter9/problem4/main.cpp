#include <iostream>
#include <vector>

using namespace std;

class DisjointSet {
public:
	int size;
	vector<int> groupBoss;
	vector<int> groupSize;

	DisjointSet(int size) {
		this->size = size;
		this->groupBoss = vector<int>(size + 1);
		this->groupSize = vector<int>(size + 1, 1);
		for (int nodeIndex = 1; nodeIndex <= size; nodeIndex += 1) {
			groupBoss[nodeIndex] = nodeIndex;
		}
	}

	int getGroupBoss(int u) {
		if (groupBoss[u] == u)
			return u;
		else {
			int uBoss = groupBoss[u];
			groupBoss[u] = getGroupBoss(u);
			return groupBoss[u];
		}
	}

	void unionGroup(int u, int v) {
		if (isConnected(u, v))
			return;
		int uBoss = getGroupBoss(u);
		int vBoss = getGroupBoss(v);

		groupSize[uBoss] += groupSize[vBoss];
		groupBoss[vBoss] = uBoss;
	}

	bool isConnected(int u, int v) {
		int uBoss = getGroupBoss(u);
		int vBoss = getGroupBoss(u);
		return uBoss = vBoss;
	}

	int getNumberOfConnectedNodes(int u) {
		int uboss = getGroupBoss(u);
		return groupSize[u];
	}
};

int main() {
	int N, M;
	scanf("%d%d", &N, &M);

	DisjointSet disjointSet(N);

	for (int i = 0; i < M; i += 1) {
		char command[10];
		int u, v;
		std::cin >> command >> u >> v;
		if (command[0] == 'L') {
			disjointSet.unionGroup(u, v);
			int groupSize = disjointSet.getNumberOfConnectedNodes(u);
			printf("SIZE = %d\n", groupSize);
		}
		else if (command[0] == 'C') {
			if (disjointSet.isConnected(u, v) == true) {
				puts("Connected");
			}
			else {
				puts("Separated");
			}
		}

	}
}
