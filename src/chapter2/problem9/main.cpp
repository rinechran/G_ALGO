#include<cstdio>
#include<iostream>
#include <algorithm>
using namespace std;

/**
* �迭�� N���� ���Ұ� �������� ���� ������ ǥ���� �� �ִ��� �Ǵ��ϴ� �Լ�
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