#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class Player {
public:
	int index;

	Player(int index) {
		this->index = index;
	}
};

/**
 * �����۽� ������ �����Ͽ� �� �÷��̾ ���ŵ� ������ ����Ʈ�� ��ȯ�ϴ� �Լ�
 *
 * @param n         �÷��̾��� ��
 * @param m         �� �ϸ��� �ǳ� �� ����� ��
 * @param players   �¼��� �ɾ��ִ� ������� �־����� �÷��̾� ����
 * @return
 */
vector<Player> getDeadPlayersList(int n, int m, const vector<Player>& players) {
	// ���� ���ӿ��� ���ܵ� �÷��̾���� ����Ʈ
	vector<Player> deadPlayers;

	// ���� ���ӿ��� ���ܵ��� �ʴ� �÷��̾���� ����Ʈ
	queue<Player> playerQueue;

	for (int i = 0; i < n; ++i) {
		playerQueue.push(i + 1);
	}

	for (int i = 0; i < n; ++i) {
		int jump = (m - 1) % playerQueue.size();
		for (int j = 0; j < jump; ++j) {
			Player p = playerQueue.front();
			playerQueue.pop();
			playerQueue.push(p);
		}

		Player dead = playerQueue.front();
	
		playerQueue.pop();

		deadPlayers.push_back(dead);
	}

	return deadPlayers;
}

void process(int caseIndex) {
	int n, m;
	cin >> n >> m;

	vector<Player> players;
	for (int i = 0; i < n; i++) {
		players.push_back(Player(i + 1));
	}

	vector<Player> deadPlayers = getDeadPlayersList(n, m, players);

	for (int i = 0; i < n; i++) {
		if (i > 0) {
			cout << " ";
		}

		Player p = deadPlayers[i];
		cout << p.index;
	}

	cout << endl;
}

int main() {
	int caseSize;
	cin >> caseSize;

	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) {
		process(caseIndex);
	}
}

