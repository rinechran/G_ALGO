#include<cstdio>
#include<cmath>
#include<algorithm>
#include<iostream>
#include <numeric>
#include <limits.h>    
#include <tuple>

using namespace std;




/**
 * 평균과의 차가 가장 작은 데이터의 번호를 반환하는 함수
 * 여러 가지라면 가장 빠른 번호를 반환한다.
 *
 * @param data
 * @param n
 * @return int  가장 평균과 가까운 데이터의 번호 (1번부터 시작)
 */
int findIndex(int data[], int n)
{
	int average = std::accumulate(data, data + n, 0) / n;

	int x = 0;
	int diff = INT_MAX;
	for (int i = 0; i < n; i++) {
		if (diff > abs(average - data[i])) {
			diff = abs(average - data[i]);
			x = i;
		}
	}
	return x + 1; 

}

int main()
{
	int n;
	int* data;

	std::cin >> n;
	data = new int[n];

	for (int i = 0; i < n; i++)
	{
		std::cin >> data[i];
	}

	int index = findIndex(data, n);
	printf("%d %d\n", index, data[index - 1]);

	delete[] data;
	return 0;
}