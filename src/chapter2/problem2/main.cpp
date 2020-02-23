#include<cstdio>
#include<iostream>

using namespace std;

/**
* 주어진 배열이 오름차순인지 검사하는 함수
* @param data
* @param n     데이터의 수
* @return      data[0] ~ data[n-1]이 오름차순이라면 true, else false
*/
bool isOrdered(int data[], int n)
{

	for (int i = 0; i < n - 1; ++i) {
		if (data[i + 1] < data[i])
			return false;
	}
	return true;
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

	bool result = isOrdered(data, n);

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