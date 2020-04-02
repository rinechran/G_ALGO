#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Bomb {
public:
	int index;
	int childCnt;
	vector<Bomb*>parentBombs;

	Bomb() {
		childCnt = 0;
	};
	Bomb(int _index) {
		index = _index;
		childCnt = 0;
	}

	void addParentBombs(Bomb* parentBomb) {
		parentBombs.push_back(parentBomb);
		parentBomb->childCnt++;
	}
};

class Cmp {
public:
	bool operator()(Bomb* a, Bomb* b) {
		return a->index > b->index;
	}
};

vector<Bomb*> isAllRemoveable(int n, vector<Bomb*>& bombs) {

	//제거된 폭탄 목록
	vector<Bomb*>removedList;

	//제거 가능한 폭탄 목록
	//priority queue를 사용한다. 폭탄들의 우선순위는 Cmp class로 정의했다.
	priority_queue<Bomb*, vector<Bomb*>, Cmp>removableBombs;

	for (auto& bomb : bombs) {
		if (bomb->childCnt == 0) {
			removableBombs.push(bomb);
		}
	}

	while (removableBombs.size() != 0) {
		Bomb* boom = removableBombs.top();
		removableBombs.pop();
		removedList.push_back(boom);

		for (auto& parentBoom : boom->parentBombs) {
			parentBoom->childCnt--;
			if (parentBoom->childCnt == 0) {
				removableBombs.push(parentBoom);
			}
		}


	}



	//제거한 폭탄들 목록은 return한다.
	return removedList;
}

void testCase(int caseIdx) {
	int n, m;
	std::cin >> n >> m;
	vector<Bomb*>bombs(n);

	for (int i = 0; i < n; i++) {
		bombs[i] = new Bomb(i + 1);
	}

	for (int i = 0; i < m; i++) {
		int u, v;
		std::cin >> u >> v;
		u -= 1;
		v -= 1;
		Bomb* parent = bombs[u];
		Bomb* child = bombs[v];
		child->addParentBombs(parent);
	}
	vector<Bomb*> removable = isAllRemoveable(n, bombs);
	if (removable.size() == n) {
		for (int i = 0; i < removable.size(); i++) {
			if (i)printf(" ");
			printf("%d", removable[i]->index);
		}
	}
	else {
		printf("NO");
	}
	printf("\n");

	for (int i = 0; i < n; i++) {
		delete bombs[i];
	}
}

int main() {
	int caseSize;
	std::cin >> caseSize;

	for (int caseIdx = 1; caseIdx <= caseSize; caseIdx++) {
		testCase(caseIdx);
	}
	return 0;
}