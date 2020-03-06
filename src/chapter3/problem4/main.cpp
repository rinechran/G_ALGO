#include <iostream>
#include <vector>

using namespace std;


const int MAX_N = 1000000;
vector<int> FIBONACCI_TABLE;

/**
* 피보나치 수열의 1~n번째 항을 배열에 저장하여 반환해주는 함수
* * 단, 항의 가장 뒤 8자리만을 저장한다.
* @param n
* @return fibo[i] := 피보나치 수열의 i번째 항
*/
vector<int> makeFibonacciTable(int n) {
	const int MOD = 100000000;

	// 피보나치 배열을 미리 선언해준다.
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
* 피보나치 수열의 n번째 항을 반환하는 함수
* 단, 항의 가장 뒤 8자리만을 반환한다.
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

		// 피보나치 수열의 n번째 항을 계산하여 출력한다.
		int answer = getFibo(n);
		printf("%d\n", answer);
	}

	// 불필요한 배열은 가능하면 할당 해제해주는 버릇을 들이자.
	FIBONACCI_TABLE.clear();

	return 0;
}
