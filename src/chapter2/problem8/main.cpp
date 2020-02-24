#include<cstdio>
#include<iostream>

using namespace std;

/**
* 왼쪽 아래 좌표가 (x,y)인 픽셀이 반지름 R인 원에 포함되는가?
* @param x
* @param y
* @param R
* @return  포함된다면 true, else false
*/
bool isInside(long long x, long long y, long long R)
{
	return x * x + y * y < R * R;

}
void testcase(int caseIndex) {
	long long R;
	std::cin >> R;

	long long sum = 0; 
	long long y = R;
	for (long x = 0; x <= R; x++) {
		long long height = 0;
		for (; y >= 0; y--) {
			if (isInside(x, y, R)) {   
				height = y + 1;
				break;
			}
		}

		sum += height; 
	}

	printf("#%d\n", caseIndex);
	std::cout << sum * 4 << std::endl;

}

int main()
{
	int caseSize;
	scanf("%d", &caseSize);
	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1)
	{
		testcase(caseIndex);
	}
	return 0;
}