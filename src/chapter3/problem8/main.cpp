#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
* �ߺ��� ������ �� ī���� ������ ���� �� �ִ� ��÷��ȣ�� ���� ����ϴ� �Լ�
* @param n     ī���� ��
* @param m     �˻��Ϸ��� ��÷��ȣ�� ��
* @param cards   �� ī�忡 ���� ���ڵ�
* @param target  �˻��Ϸ��� �� ��÷��ȣ ����Ʈ
* @return
*/
int getPossibleTargetNumber(int n, int m, int* cards, int* targets) {
	int answer = 0;

	std::sort(cards, cards + n);
	for (int i = 0; i < m; ++i) {
		int target = targets[i];

		bool p = false;

		for (int j = 0; j < n; ++j) {
			int y = target - cards[j];
			if (y < 0) continue;;
			if (std::binary_search(cards, cards + n, y)) {
				p = true;
				break;
			}
		}
		if (p)
			answer++;
	}

	return answer;
}

int main() {
	int n;	// ī���� �� 
	int m;	// �˻� �� �ĺ� ��÷��ȣ�� �� 
	std::cin >> n >> m;
	int* cards = new int[n];
	int* targets = new int[m];

	// �� ī�� ������ �Է¹޴´�
	for (int i = 0; i < n; i++) {
		std::cin >> cards[i];
	}

	// �� �ĺ� ��÷��ȣ�� �Է¹޴´�
	for (int i = 0; i < m; i++) {
		std::cin >> targets[i];

	}

	int answer = getPossibleTargetNumber(n, m, cards, targets);

	printf("%d\n", answer);


	delete[] cards;
	delete[] targets;

	return 0;
}
