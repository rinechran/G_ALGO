#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;
const int MAX_VALUE = 1000000;

//���μ� ���ظ� ������
class Sieve {
public:
	int maximumValue;     // �����佺�׳׽��� ü���� �ٷ� ���� ū ������ ��
	vector<bool> isPrime; // �� ���ں� �Ҽ� ����
	Sieve(int maximumValue) {
		this->maximumValue = maximumValue;
		this->isPrime.assign(maximumValue + 1, false);
		this->fillSieve();
	}

	/**
	 *
	 * @param num
	 * @return 'num'�� �Ҽ���� true, �׷��� ������ false
	 */
	bool isPrimeNumber(int num) const {
		return this->isPrime[num];
	}
	bool isPrimeN(int n) {
		if (n <= 1) return false;

		if (n == 2) return true;
		if (n % 2 == 0) return false;

		for (int i = 3; i * i <= n; i++) {
			if (n % i == 0)
				return false;

		}
		return true;;
	}

	/**
	 * isPrime �迭�� ���� ä��� �Լ�
	 */
	void fillSieve() {
		for (int i = 2; i < maximumValue; ++i) {
			isPrime[i] = isPrimeN(i);
		}
	}
};

void process(int caseIndex, const Sieve& sieve) {
	int x;
	std::cin >> x;

	int a = -1, b = -1;
	// x=a+b
	// a=-x+b
	for (int i = x - 1; i >= 2; --i) {
		if (sieve.isPrimeNumber(i) == true) {
			int y = x - i;
			if (sieve.isPrimeNumber(y) == true) {
				a = y;
				b = i;
				break;
			}
		}
	}
	printf("Case #%d:\n", caseIndex);
	if (a > 0 && b > 0) {
		printf("%d = %d + %d\n", x, a, b);
	}
	else {
		printf("-1\n");
	}
}

int main() {
	Sieve sieve(MAX_VALUE);

	int caseSize;
	std::cin >> caseSize;

	for (int caseIndex = 1; caseIndex <= caseSize; ++caseIndex) {
		process(caseIndex, sieve);
	}
}