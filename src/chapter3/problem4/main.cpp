#include <iostream>
#include <vector>

using namespace std;


const int MAX_N = 1000000;
vector<int> FIBONACCI_TABLE;

/**
* �Ǻ���ġ ������ 1~n��° ���� �迭�� �����Ͽ� ��ȯ���ִ� �Լ�
* * ��, ���� ���� �� 8�ڸ����� �����Ѵ�.
* @param n
* @return fibo[i] := �Ǻ���ġ ������ i��° ��
*/
vector<int> makeFibonacciTable(int n) {
	const int MOD = 100000000;

	// �Ǻ���ġ �迭�� �̸� �������ش�.
	vector<int> ret(n + 1);

	ret[0] = 0;
	ret[1] = 1;

	for (int i = 2; i <= n; ++i) {
		ret[i] = ret[i - 1] + ret[i - 2];
		ret[i] %= MOD;

	}


	return ret;
}

/**
* �Ǻ���ġ ������ n��° ���� ��ȯ�ϴ� �Լ�
* ��, ���� ���� �� 8�ڸ����� ��ȯ�Ѵ�.
* @param n
* @return
*/
int getFibo(int n) {
	return FIBONACCI_TABLE[n - 1];
}

int main() {
	FIBONACCI_TABLE = makeFibonacciTable(MAX_N);

	int caseSize;
	std::cin >> caseSize;


	for (int caseIndex = 1; caseIndex <= caseSize; ++caseIndex) {
		int n;
		std::cin >> n;

		// �Ǻ���ġ ������ n��° ���� ����Ͽ� ����Ѵ�.
		int answer = getFibo(n);
		printf("%d\n", answer);
	}

	// ���ʿ��� �迭�� �����ϸ� �Ҵ� �������ִ� ������ ������.
	FIBONACCI_TABLE.clear();

	return 0;
}
