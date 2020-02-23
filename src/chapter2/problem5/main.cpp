#include<cstdio>
#include<iostream>
using namespace std;

/**
 * 주어진 숫자가 소수인지 판별하는 함수
 *
 * @param N
 * @return true   소수라면
 * @return false  소수가 아니라면
 */
bool isPrime(int n) {
	if (n <= 1) return false;

	if (n == 2) return true;
	if (n % 2 == 0) return false;

	for (int i = 3; i * i <= n; i++) {
		if (n % i == 0)
			return false;

	}
	return true;
}

void testcase(int caseIndex)
{
	int n;
	std::cin >> n;

	bool result = isPrime(n);

	printf("Case #%d\n", caseIndex);
	if (result)
	{
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}
}

int main()
{
	int caseSize;
	std::cin >> caseSize;
	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1)
	{
		testcase(caseIndex);
	}
	return 0;
}