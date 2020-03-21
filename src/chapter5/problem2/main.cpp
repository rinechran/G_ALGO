#include<iostream>
#include<cstdlib>
#include<memory.h>
#include<iostream>
#include<algorithm>


using namespace std;


int get_minimum_trashes(int** waste, int N, int K) {
	int answer = K * K;

	for (int firstRow = 0; firstRow <= N - K; ++firstRow) {

		int lastRow = firstRow + K;
		int rowAnswer = 0;
		for (int j = firstRow; j < lastRow; ++j) {
			for (int c = 0; c < K; ++c) {
				if (waste[j][c] == 1) {
					rowAnswer++;
				}
			}
		}

		answer = std::min(answer, rowAnswer);

		for (int col = 0; col <= N - K - 1; ++col) {
			int oldCol = col;
			int newCol = col + K;
			for (int row = firstRow; row < lastRow; ++row) {
				if (waste[row][oldCol] == 1)
					rowAnswer--;
				if (waste[row][newCol] == 1)
					rowAnswer++;

			}

			answer = std::min(answer, rowAnswer);
		}



	}

	return answer;
}

void test_case(int caseIndex) {
	int N, K;
	std::cin >> N >> K;
	int** wastes = new int* [N];
	for (int r = 0; r < N; r += 1) {
		wastes[r] = new int[N];
		for (int c = 0; c < N; c += 1) {
			std::cin >> wastes[r][c];
		}
	}

	int answer = get_minimum_trashes(wastes, N, K);
	printf("%d\n", answer);

	for (int r = 0; r < N; r += 1) {
		delete[] wastes[r];
	}
	delete[] wastes;
}

int main() {
	int caseSize;
	std::cin >> caseSize;

	for (int caseIndex = 0; caseIndex < caseSize; caseIndex += 1) {
		test_case(caseIndex);
	}
	return 0;
}