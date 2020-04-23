#include <stdio.h>
//해당 문제는 iostream을 사용할 경우 Timeout이 날 수 있음.
#include <map>
#include <iostream>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	// 각 <정수, 빈도수> 형태로 key-value를 저장할 Map 자료구조
	// frequencyMap := 이전에 입력된 정수들의 빈도수를 저장하고 있다.
	map<int, int> frequencyMap;

	for (int i = 0; i < N; ++i) {
		int X;
		std::cin >> X;
		printf("%d %d\n", frequencyMap.size(), ++frequencyMap[X]);
	}

}
