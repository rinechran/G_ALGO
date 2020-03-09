#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/**
* �ߺ��� ������ �� ī���� ������ ���� �� �ִ� ��÷��ȣ�� ���� ����ϴ� �Լ�
* @param n     ī���� ��
* @param m     �˻��Ϸ��� ��÷��ȣ�� ��
* @param cards   �� ī�忡 ���� ���ڵ�
* @param target  �˻��Ϸ��� �� ��÷��ȣ ����Ʈ
* @return
*/
vector<int> getPossibleTargets(int n, int m, int* cards, int* targets) {
	vector<int> possibleTargets; // ���� �� �ִ� ��÷ ��ȣ��

	std::sort(cards, cards + n);
	std::sort(targets, targets + m);

	for (int i = 0; i < m; ++i) {
		long long target = targets[i];
		int jk;
		int ps = false;
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				// target = x + y+z
				//target -y-z =x
				long long temp = target - cards[j] - cards[k];
				if (binary_search(cards, cards + n, temp)) {
					possibleTargets.push_back(target);
					ps = true;
					break;
				}
			}
			if (ps)
				break;
		}
	}



	return possibleTargets;
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

	vector<int> answers = getPossibleTargets(n, m, cards, targets);

	if (answers.size() == 0)
	{ 	// ������ ��÷��ȣ�� ���ٸ� NO�� ����Ѵ�
		printf("NO");
	}
	else
	{ //������ ��÷��ȣ�� �����Ѵٸ� �� ����� ����Ѵ�.
		for (int i = 0; i < answers.size(); i++)
		{
			if (i > 0)
			{
				printf(" ");
			}
			printf("%d", answers[i]);
		}
	}

	delete[] cards;
	delete[] targets;

	return 0;
}
