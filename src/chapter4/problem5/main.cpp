#include <iostream>
#include <vector>

using namespace std;

/**
 * 자연수 N을 구성하는 모든 소인수를 반환하는 함수
 *
 * @param N
 * @return
 */
vector<long long> factorize(long n) {

	vector<long long> temp;

	for (long long div = 2; div * div <= n; div += 1) {
		while (n % div == 0) {
			temp.push_back(div);

			n /= div;
		}

		if (n > 1) {
			temp.push_back(n);
		}
	}
	return temp;

}

void process(int caseIndex) {
	long long n;
	std::cin >> n;

	vector<long long> factors = factorize(n);

	printf("#%d:\n", caseIndex);
	for (int i = 0; i < factors.size(); ++i) {
		if (i > 0) {
			printf(" ");
		}
		printf("%lld", factors[i]);
	}
	printf("\n");
}

int main() {
	int caseSize;
	std::cin >> caseSize;

	for (int caseIndex = 1; caseIndex <= caseSize; ++caseIndex) {
		process(caseIndex);
	}
}