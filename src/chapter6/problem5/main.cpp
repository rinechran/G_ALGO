#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Bomb {
public:
	int childCnt;  //�� ��ź�� ������ �� �Բ� �����ϴ� ���� ��ź�� ��
	vector<Bomb*>parentBombs;// �� ��ź�� ������ ������ �� �ִ� ��ź ����Ʈ


	void addParentBombs(Bomb* parentBomb) {
		// �� ��ź�� �����Ѵ�.
		// �׷��Ƿ� �θ� ��ź���� ���� ��ź �ϳ��� ����� ���� �ȴ�.
		parentBombs.push_back(parentBomb);
		parentBomb->childCnt++;
	}
};


/**
 * ������ ���ǿ� ���� ��� ��ź�� ������ �� �ִ��� �Ǵ��ϴ� �Լ�
 *
 * @param n
 * @param bombs
 * @return
 */
bool isAllRemoveable(int n, vector<Bomb*>& bombs) {

	//���ŵ� ��ź ����
	int removedBombCount = 0;

	//���� ������ ��ź ���
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


	//���� �� ��ź ������ n�̶�� true �ƴ϶�� false�� return
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