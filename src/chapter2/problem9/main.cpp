#include<cstdio>
#include<iostream>
#include <algorithm>
using namespace std;

/**
* 배열의 N개의 원소가 연속적인 정수 수열로 표현될 수 있는지 판단하는 함수
* @param data
* @param n
* @return
*/
bool isConsecutive(int data[], int n)
{

	auto minmax = std::minmax_element(&(data[0]), &(data[n]));
	int diff = *minmax.second - *minmax.first;
	return diff + 1 == n;
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

	bool result = isConsecutive(data, n);


	if (result)
	{
		printf("YES");
	}
	else {
		printf("NO");
	}

	delete[] data;
	return 0;
}