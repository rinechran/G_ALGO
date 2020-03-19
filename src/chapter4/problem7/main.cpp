#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
class ShiftingArray {
public:
	vector<T> array; // 내부에 데이터를 저장할 배열
	int length;       // 배열의 길이
	int leftIndex;

	ShiftingArray(int length) {
		this->length = length;
		this->array.resize(length);
		this->leftIndex = 0;
	}

	/**
	 * 현재 배열에서 'index'번째에 존재하는 원소를 반환하는 함수
	 *
	 * @param index
	 * @return
	 */
	T get(int index) {
		return array[(leftIndex + index) % length];

	}

	/**
	 * 현재 배열에서 'index'번째에 존재하는 원소를 'value'로 변경하는 함수
	 *
	 * @param index
	 * @param value
	 */
	void set(int index, T value) {
		array[(leftIndex + index) % length] = value;

	}

	/**
	 * 현재 배열의 모든 원소를 왼쪽으로 'times'번 이동하는 함수
	 * @param times
	 */
	void shiftLeft(int times) {
		leftIndex = (leftIndex + times) % length;

	}

	/**
	 * 현재 배열의 모든 원소를 오른쪽으로 'times'번 이동하는 함수
	 *
	 * @param times
	 */
	void shiftRight(int times) {
		int temp = leftIndex - times;
		if (temp < 0) {
			temp = length - (std::abs(temp) % length);
		}

		leftIndex = temp % length;
	}

	/**
	 * 현재 배열의 모든 원소를 가장 초기 위치로 되돌리는 함수
	 */
	void initializePosition() {
		leftIndex = 0;
	}

};

int main() {
	int nNumbers;   // 배열의 원소의 수
	int nCommands;  // 처리할 명령어의 수
	scanf("%d%d", &nNumbers, &nCommands);

	// Shift 연산이 가능한 배열을 선언하고 원소를 차례로 입력한다
	ShiftingArray<int> array(nNumbers);

	for (int i = 0; i < nNumbers; ++i) {
		int val;
		scanf("%d", &val);
		array.set(i, val);
	}

	// 각 명령어를 처리한다
	for (int i = 0; i < nCommands; ++i) {
		// 명령어 정보를 입력받는다
		int cmd;
		scanf("%d", &cmd);

		if (cmd == 0) {
			// 현재 배열에 p번 인덱스에 있는 원소를 출력하는 명령
			int p;
			scanf("%d", &p);

			int value = array.get(p);
			printf("%d\n", value);
		}
		else if (cmd == 1) {
			// 현재 배열을 왼쪽으로 k번 shift하는 명령
			int k;
			scanf("%d", &k);

			array.shiftLeft(k);
		}
		else if (cmd == 2) {
			// 현재 배열을 오른쪽으로 k번 shift하는 명령
			int k;
			scanf("%d", &k);

			array.shiftRight(k);
		}
		else if (cmd == 3) {
			// 현재 배열을 최초의 위치로 복원하는 명령
			array.initializePosition();
		}
	}
}