#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/**
* 중복을 포함해 두 카드의 합으로 만들 수 있는 당첨번호의 수를 계산하는 함수
* @param n     카드의 수
* @param m     검사하려는 당첨번호의 수
* @param cards   각 카드에 적힌 숫자들
* @param target  검사하려는 각 당첨번호 리스트
* @return
*/
vector<int> getPossibleTargets(int n, int m, int* cards, int* targets) {
	vector<int> possibleTargets; // 만들 수 있는 당첨 번호들

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
	int n;	// 카드의 수 
	int m;	// 검사 할 후보 당첨번호의 수 
	std::cin >> n >> m;

	int* cards = new int[n];
	int* targets = new int[m];

	// 각 카드 정보를 입력받는다
	for (int i = 0; i < n; i++) {
		std::cin >> cards[i];
	}

	// 각 후보 당첨번호를 입력받는다
	for (int i = 0; i < m; i++) {
		std::cin >> targets[i];
	}

	vector<int> answers = getPossibleTargets(n, m, cards, targets);

	if (answers.size() == 0)
	{ 	// 가능한 당첨번호가 없다면 NO를 출력한다
		printf("NO");
	}
	else
	{ //가능한 당첨번호가 존재한다면 그 목록을 출력한다.
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
