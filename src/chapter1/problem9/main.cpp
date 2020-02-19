#include<cstdio>
#include<cmath>
#include<algorithm>
#include<iostream>
#include <numeric>
#include <limits.h>    
#include <tuple>

using namespace std;




/**
 * ��հ��� ���� ���� ���� �������� ��ȣ�� ��ȯ�ϴ� �Լ�
 * ���� ������� ���� ���� ��ȣ�� ��ȯ�Ѵ�.
 *
 * @param data
 * @param n
 * @return int  ���� ��հ� ����� �������� ��ȣ (1������ ����)
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