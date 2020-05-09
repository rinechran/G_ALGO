#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

const int MAXIMUM_VIRUS = 10000;

class State {
public:
	int numberOfVirus;
	int depth;

	State(int numberOfVirus, int depth) {
		this->numberOfVirus = numberOfVirus;
		this->depth = depth;
	}
};

void testCase(int caseIndex) {
	int targetNumber;
	std::cin >> targetNumber;

	vector<int> distance(MAXIMUM_VIRUS + 1, 0);

	State initialState(1, 1);
	queue<State> q;
	q.push(initialState);

	while (q.empty() == false) {
		State current = q.front();
		q.pop();
		if (current.numberOfVirus >= MAXIMUM_VIRUS) {
			continue;
		}
		if (current.numberOfVirus == targetNumber) {
			printf("%d\n", current.depth - 1);
			return;
		}

		State nextIncrease(current.numberOfVirus * 2, current.depth + 1);
		State nextDecrease(current.numberOfVirus / 3, current.depth + 1);

		q.push(nextIncrease);
		q.push(nextDecrease);

	}

}

int main() {
	int caseSize;
	std::cin >> caseSize;

	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) {
		testCase(caseIndex);
	}
}
