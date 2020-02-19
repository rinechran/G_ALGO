#include<iostream>
#include<algorithm>

using namespace std;

/**
* 배열에서 특정 원소의 위치를 찾는 함수
* @param data 중복 없는 정수 배열 data[0] ~ data[n-1]
* @param n    배열의 크기 n
* @param m    배열에서 찾고자 하는 원소
* @return     원소가 존재한다면 인덱스를, 존재하지 않으면 -1을 반환한다.
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