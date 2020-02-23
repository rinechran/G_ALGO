#include<cstdio>
#include<iostream>

using namespace std;

int N[100001] = { 0, };
/**
* �ߺ��� ������ ������ ������ ���� ����ϴ� �Լ�
* @param data  ���� �迭
* @param n     ���� �迭�� ũ��
* @return  ������ ������ ��
*/
int getElementTypeCount(int data[], int n)
{
	int countType = 0;
	for (int i = 0; i < n; ++i) {
		if (i == 0 || data[i] - data[i - 1] != 0 ) {
			countType++;
		}
	}

	return countType;
}

int main()
{
	int n;
	int* data;

	scanf("%d", &n);
	data = new int[n];

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &data[i]);
	}

	int answer = getElementTypeCount(data, n);

	printf("%d\n", answer);

	delete[] data;
	return 0;
}