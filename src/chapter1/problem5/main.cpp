#include<iostream>

using namespace std;

/**
* ���Ƹ� ������� ž�� ���� ���θ� ����ϴ� �Լ�
*
* @param data �� ������� ������ data[0] ~ data[n-1]
* @param n    ������� ��
* @param p    ���̱ⱸ ž�� ���� ü�� ����
* @param q    ���̱ⱸ �ִ� ����
*/
void solve(int data[], int n, int p, int q)
{
	int max = 0;
	int count = 0;
	for (int i = 0; i < n; ++i) {
		if (data[i] <= p) {
			max += data[i];
			count++;
		}
	}

	std::cout << count << " " << max << std::endl;
	if (q > max) {
		std::cout << "YES" << std::endl;
	}
	else {
		std::cout << "NO" << std::endl;

	}
}

int main()
{
	int n, p, q;
	int* data;

	std::cin >> n >> p >> q;
	data = new int[n];
	for (int i = 0; i < n; i++)
	{
		std::cin >> data[i];
	}

	solve(data, n, p, q);

	delete[] data;
	return 0;
}