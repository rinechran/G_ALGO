#include<iostream>

using namespace std;

/**
* 동아리 멤버들의 탑승 가능 여부를 출력하는 함수
*
* @param data 각 멤버들의 몸무게 data[0] ~ data[n-1]
* @param n    멤버들의 수
* @param p    놀이기구 탑승 가능 체중 제한
* @param q    놀이기구 최대 하중
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