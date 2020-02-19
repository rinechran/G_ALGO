#include<iostream>
#include<algorithm>

using namespace std;

/**
* �迭���� Ư�� ������ ��ġ�� ã�� �Լ�
* @param data �ߺ� ���� ���� �迭 data[0] ~ data[n-1]
* @param n    �迭�� ũ�� n
* @param m    �迭���� ã���� �ϴ� ����
* @return     ���Ұ� �����Ѵٸ� �ε�����, �������� ������ -1�� ��ȯ�Ѵ�.
*/
int findIndex(int data[], int n, int m)
{
	for (int i = 0; i < n; i++) {
		if (data[i] == m) {
			return i;
		}
	}
	return -1;;

}

int main()
{
	int n, m;
	int* data;

	std::cin >> n >> m;
	data = new int[n];
	for (int i = 0; i < n; i++)
	{
		std::cin >> data[i];
	}

	int answer = findIndex(data, n, m);

	printf("%d\n", answer);
	delete[] data;
	return 0;
}