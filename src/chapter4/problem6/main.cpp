#include <iostream>
#include <vector>

using namespace std;

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

	/**
	 * isPrime �迭�� ���� ä��� �Լ�
	 */
	void fillSieve() {

	}
};

vector<int> getAllPrimeNumbers(int from, int to, const Sieve& sieve) {
	vector<int> primes;

	for (int num = from; num <= to; num += 1) {
		if (sieve.isPrimeNumber(num)) {
			primes.push_back(num);
		}
	}

	return primes;
}

void process(int caseIndex, const Sieve& sieve) {
	int L, R;
	std::cin >> L >> R;
	vector<int> allPrimeNumbers = getAllPrimeNumbers(L, R, sieve);

	printf("Case #%d:\n", caseIndex);
	printf("%d\n", (int)allPrimeNumbers.size());
}

int main() {
	const int MAX_VALUE = 1000000;
	Sieve sieve = Sieve(MAX_VALUE);

	int caseSize;
	std::cin >> caseSize;

	for (int caseIndex = 1; caseIndex <= caseSize; ++caseIndex) {
		process(caseIndex, sieve);
	}
}