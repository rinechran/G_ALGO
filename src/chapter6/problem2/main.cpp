#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Tower {
public:
	int index; // Ÿ���� �ε���
	int height; // Ÿ���� ����
	int targetTowerIndex;  // �� Ÿ���� �������� �����ϴ� ��� Ÿ��

	Tower(int index, int height) {
		this->index = index;
		this->height = height;
		this->targetTowerIndex = 0;
	}

	void setTargetTowerIndex(int targetTowerIndex) {
		this->targetTowerIndex = targetTowerIndex;
	}

	int getTargetTowerIndex() {
		return this->targetTowerIndex;
	}
};

/**
 * �Ķ���ͷ� �־����� �� Ÿ���鿡 ���� Ÿ�� Ÿ���� ����ϴ� �Լ�
 *
 * @param n         Ÿ���� ��
 * @param towers    ����~������ ������ ����� Ÿ�� �迭
 */
void findTargetTowers(vector<Tower>& towers) {
	// ���� �ٸ� Ÿ���� ��ȣ�� ������ ���ɼ��� �ִ� Ÿ����
	stack<Tower> touchableTowers;

	for (int index = 0; index < towers.size(); ++index) {
		Tower& tower = towers[index];
		int targetTargetIndex = 0;

		while (touchableTowers.empty() == false
			&& touchableTowers.top().height < tower.height) {
			touchableTowers.pop();
		}

		if (touchableTowers.size() > 0) {
			targetTargetIndex = touchableTowers.top().index;
		}
		tower.setTargetTowerIndex(targetTargetIndex);
		touchableTowers.push(tower);
	}
}

int main() {
	int n;
	cin >> n;

	vector<Tower> towers;
	for (int i = 0; i < n; ++i) {
		int hi;
		cin >> hi;
		towers.push_back(Tower(i + 1, hi)); // �ε��� 1���� ����
	}

	// �� Ÿ���� �۽��ϴ� �������� ���� Ÿ���� ��� ����Ѵ�
	findTargetTowers(towers);

	for (int i = 0; i < n; i++) {
		if (i > 0) {
			cout << " ";
		}

		Tower t = towers[i];
		int targetIndex = t.getTargetTowerIndex();
		cout << targetIndex;
	}
}
