#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

/**
* ������ m���� ���� ū Ű�� ���丮�� ã�� �Լ�
* @param height  �� ���丮�� Ű
* @param month   �� ���丮�� ��� ��
* @param n   ���丮�� ��
* @param m   ã���� �ϴ� ��
* @return    month[k] == m�� ���� ū height[k]
*/
int getMaximumHeight(int height[], int month[], int n, int m)
{

	for (int i = n - 1; i >= 0; --i) {
		if (month[i] == m) {
			return height[i];
		}
	}
	return -1;
}

int main()
{
	int n, m;
	int* height;
	int* month;

	scanf("%d", &n);
	height = new int[n];
	month = new int[n];

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &height[i]);
	}

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &month[i]);
	}

	scanf("%d", &m);

	int answer = getMaximumHeight(height, month, n, m);

	printf("%d\n", answer);

	delete[] height;
	delete[] month;
	return 0;
}