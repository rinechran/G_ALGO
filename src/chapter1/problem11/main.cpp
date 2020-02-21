#include<cstdio>
#include<iostream>
#include <algorithm>
#include <numeric>

using namespace std;



long long dp[2001] = { 0,1 };
/**
* 1���� N������ �ڿ����� ���� ����ϴ� �Լ�
* @param i
* @return
*/
void caluDp() {
	for (int i = 2; i <= 2000; ++i) {
		dp[i] = dp[i - 1] + i;
	}

}


long long getAnswer(int N)
{
	return std::accumulate(&dp[1], &dp[N + 1], 0);;
}

int main()
{
	int n;
	caluDp();
	std::cin >> n;

	long long answer = getAnswer(n);

	printf("%lld\n", answer);

	return 0;
}