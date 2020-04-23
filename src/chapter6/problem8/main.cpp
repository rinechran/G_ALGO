#include <iostream>
#include <unordered_set>
#include <set>

using namespace std;

int main() {
	int N;
	cin >> N;

	// integers := 이전까지 등장한 모든 정수를 저장한 집합
	unordered_set<int> integers;

	for (int i = 0; i < N; ++i) {
		int X;
		scanf("%d", &X);
		if (integers.find(X) != integers.end()) {
			printf("DUPLICATED\n");
		}
		else {
			integers.insert(X);
			printf("OK\n");
		}

	}

}
