#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Bomb {
public:
	int childCnt;  //이 폭탄이 터졌을 때 함께 폭발하는 연쇄 폭탄의 수
	vector<Bomb*>parentBombs;// 이 폭탄의 폭발을 유발할 수 있는 폭탄 리스트


	void addParentBombs(Bomb* parentBomb) {
		// 이 폭탄을 제거한다.
		// 그러므로 부모 폭탄들은 연쇄 폭탄 하나가 사라진 꼴이 된다.
		parentBombs.push_back(parentBomb);
		parentBomb->childCnt++;
	}
};


/**
 * 문제의 조건에 따라 모든 폭탄을 제거할 수 있는지 판단하는 함수
 *
 * @param n
 * @param bombs
 * @return
 */
bool isAllRemoveable(int n, vector<Bomb*>& bombs) {

	//제거된 폭탄 갯수
	int removedBombCount = 0;

	//제거 가능한 폭탄 목록
	queue<Bomb*>removableBombs;

	for (int i = 0; i < n; ++i) {
		if (bombs[i]->childCnt == 0) {
			removableBombs.push(bombs[i]);
		}
	}
	while (removableBombs.size()) {
		Bomb* b = removableBombs.front();
		removableBombs.pop();
		removedBombCount++;

		std::vector<Bomb*>& parents = b->parentBombs;
		for (int i = 0; i < parents.size(); ++i) {
			Bomb* p = parents[i];
			p->childCnt--;
			if (p->childCnt == 0) {
				removableBombs.push(p);
			}
		}
	}


	//제거 한 폭탄 갯수가 n이라면 true 아니라면 false를 return
	if (removedBombCount == n) {
		return true;
	}
	else {
		return false;
	}
}

void testCase(int caseIdx) {
	int n, m;
	std::cin >> n >> m;
	vector<Bomb*>bombs(n);

	for (int i = 0; i < n; i++) {
		bombs[i] = new Bomb();
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
	bool removable = isAllRemoveable(n, bombs);
	if (removable) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}

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