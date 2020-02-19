#include<stdio.h>
#include<iostream>
#include <functional>
#include <numeric>

using namespace std;

/**
* 정수 배열의 모든 원소의 합을 계산하는 함수
*
* @param data
* @param n
* @return data[0] ~ data[n-1]의 합
*/
int getSum(int data[], int n) {

	return std::accumulate(&(data[0]), &(data[n]), 0);;
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

	int answer = getSum(data, n);

	printf("%d\n", answer);
	delete[] data;
	return 0;
}