#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
class ShiftingArray {
public:
	vector<T> array; // ���ο� �����͸� ������ �迭
	int length;       // �迭�� ����
	int leftIndex;

	ShiftingArray(int length) {
		this->length = length;
		this->array.resize(length);
		this->leftIndex = 0;
	}

	/**
	 * ���� �迭���� 'index'��°�� �����ϴ� ���Ҹ� ��ȯ�ϴ� �Լ�
	 *
	 * @param index
	 * @return
	 */
	T get(int index) {
		return array[(leftIndex + index) % length];

	}

	/**
	 * ���� �迭���� 'index'��°�� �����ϴ� ���Ҹ� 'value'�� �����ϴ� �Լ�
	 *
	 * @param index
	 * @param value
	 */
	void set(int index, T value) {
		array[(leftIndex + index) % length] = value;

	}

	/**
	 * ���� �迭�� ��� ���Ҹ� �������� 'times'�� �̵��ϴ� �Լ�
	 * @param times
	 */
	void shiftLeft(int times) {
		leftIndex = (leftIndex + times) % length;

	}

	/**
	 * ���� �迭�� ��� ���Ҹ� ���������� 'times'�� �̵��ϴ� �Լ�
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
	 * ���� �迭�� ��� ���Ҹ� ���� �ʱ� ��ġ�� �ǵ����� �Լ�
	 */
	void initializePosition() {
		leftIndex = 0;
	}

};

int main() {
	int nNumbers;   // �迭�� ������ ��
	int nCommands;  // ó���� ��ɾ��� ��
	scanf("%d%d", &nNumbers, &nCommands);

	// Shift ������ ������ �迭�� �����ϰ� ���Ҹ� ���ʷ� �Է��Ѵ�
	ShiftingArray<int> array(nNumbers);

	for (int i = 0; i < nNumbers; ++i) {
		int val;
		scanf("%d", &val);
		array.set(i, val);
	}

	// �� ��ɾ ó���Ѵ�
	for (int i = 0; i < nCommands; ++i) {
		// ��ɾ� ������ �Է¹޴´�
		int cmd;
		scanf("%d", &cmd);

		if (cmd == 0) {
			// ���� �迭�� p�� �ε����� �ִ� ���Ҹ� ����ϴ� ���
			int p;
			scanf("%d", &p);

			int value = array.get(p);
			printf("%d\n", value);
		}
		else if (cmd == 1) {
			// ���� �迭�� �������� k�� shift�ϴ� ���
			int k;
			scanf("%d", &k);

			array.shiftLeft(k);
		}
		else if (cmd == 2) {
			// ���� �迭�� ���������� k�� shift�ϴ� ���
			int k;
			scanf("%d", &k);

			array.shiftRight(k);
		}
		else if (cmd == 3) {
			// ���� �迭�� ������ ��ġ�� �����ϴ� ���
			array.initializePosition();
		}
	}
}