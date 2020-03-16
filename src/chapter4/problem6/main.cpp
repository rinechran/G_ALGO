#include <iostream>
#include <vector>

using namespace std;

//소인수 분해를 빠르게
class Sieve {
public:
	int maximumValue;     // 에라토스테네스의 체에서 다룰 가장 큰 범위의 값
	vector<bool> isPrime; // 각 숫자별 소수 여부
	Sieve(int maximumValue) {
		this->maximumValue = maximumValue;
		this->isPrime.assign(maximumValue + 1, true);
		this->fillSieve();
	}

	/**
	 *
	 * @param num
	 * @return 'num'이 소수라면 true, 그렇지 않으면 false
	 */
	bool isPrimeNumber(int num) const {
		return this->isPrime[num];
	}

	bool isPrimeSolve(int n) {
		if (n <= 1) return false;

		if (n == 2) return true;
		if (n % 2 == 0) return false;

		for (int i = 3; i * i <= n; i++) {
			if (n % i == 0)
				return false;

		}
		return true;
	}

	/**
	 * isPrime 배열의 값을 채우는 함수
	 */
	void fillSieve() {

		this->isPrime[1] = false;
		for (long long i = 1; i <= maximumValue; ++i) {

			if (this->isPrime[i] == false) {
				continue;
			}

			if (this->isPrimeSolve(i)) {
				for (long long j = 2; j * i <= maximumValue; j++) {
					this->isPrime[i * j] = false;
				}
			}
		}

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