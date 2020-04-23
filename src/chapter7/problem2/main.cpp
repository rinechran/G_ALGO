#include <iostream>
#include <stack>

using namespace std;


class Disk {
public:
	int height;

	Disk(int height) {
		this->height = height;
	}
};

/**
 * @brief   시작 기둥(from)으로부터 목적지 기둥(to)까지 num개의 원반을 모두 옮기는 최소 이동 횟수를 계산하는 함수
 *
 *
 * @param num       현재 시작 기둥(from)에 놓여져 있는 원반의 수
 * @param from      num개의 원반들이 꽂혀있는 기둥
 * @param buffer    비어있는 기둥
 * @param to        원반들을 모두 옮길 기둥
 * @return          모든 원반을 옮길 수 있는 최소 이동 횟수
 */
int getMinimumMove(int num, stack<Disk>& from, stack<Disk>& buffer, stack<Disk>& to) {

	if (num == 0) {
		return 0;
	}
	else if (num == 1) {
		Disk d = from.top();
		from.pop();
		to.push(d);
		return 1;
	}
	int move = 0;
	move += getMinimumMove(num - 1, from, to, buffer);

	move += getMinimumMove(1, from, buffer, to);

	move += getMinimumMove(num - 1, buffer, from, to);

	return move;
}

int main() {
	int N;
	std::cin >> N;
	stack<Disk> A;
	stack<Disk> B;
	stack<Disk> C;

	// 첫 번째 기둥에 N개의 원판을 쌓는다
	for (int i = N; i >= 1; i -= 1) {
		Disk d(i);
		A.push(d);
	}

	int answer = getMinimumMove(N, A, B, C);
	printf("%d\n", answer);
}
