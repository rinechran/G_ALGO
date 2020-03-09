#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
* 중복을 포함해 두 카드의 합으로 만들 수 있는 당첨번호의 수를 계산하는 함수
* @param n     카드의 수
* @param m     검사하려는 당첨번호의 수
* @param cards   각 카드에 적힌 숫자들
* @param target  검사하려는 각 당첨번호 리스트
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

	int answer = getPossibleTargetNumber(n, m, cards, targets);

	printf("%d\n", answer);


	delete[] cards;
	delete[] targets;

	return 0;
}
