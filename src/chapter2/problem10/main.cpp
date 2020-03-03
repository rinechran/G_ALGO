#include<cstdio>
#include<iostream>

using namespace std;

/**
 * ������ ��Ģ�� ���� ������ �¸��� �� �ִ� ����� ���� �����ϴ��� �˻��ϴ� �Լ�
 *
 * @param data
 * @param n
 * @param k
 * @return true   ������ �¸��� �� �ִ� ����� ���� �ϳ� �̻� �����Ѵٸ�
 * @return false  else
 */
bool isWinnable(int data[], int n, int k) {

	int winCount = 0;
	long sum = 0;

	int result = 0;

	for (int i = 0; i < k; ++i) {
		result += data[i];
	}


	for (int i = k; i <= n; ++i) {


		if (result % 2 == 0) {
			winCount++;
		}
		if (i >= n) {
			break;
		}
		result = result - data[i - k] + data[i];
	}

	if (winCount > 0)
	{
		return true;
	}
	else {
		return false;
	}
}

int main()
{
	int n, k;
	int* data;

	std::cin >> n >> k;
	data = new int[n];
	for (int i = 0; i < n; i++)
	{
		std::cin >> data[i];
	}

	bool result = isWinnable(data, n, k);

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