#include <iostream>

using namespace std;

const int MAX_ROW = 9;
const int MAX_COL = 9;


class SudokuBoard {
public:
	// ĭ�� ��ȣ�� ���� ��ȣ�� ����ϴ� �޼ҵ�
	int getRowByIndex(int index) {
		int result = --index / MAX_ROW;
		return ++result;

	}

	// ĭ�� ��ȣ�� ���� ��ȣ�� ����ϴ� �޼ҵ�
	int getColByIndex(int index) {
		int result = --index % MAX_ROW;
		return ++result;
	}

	// ĭ�� ��ȣ�� �׷� ��ȣ�� ����ϴ� �޼ҵ�
	int getGroupByIndex(int index) {
		int r = getRowByIndex(index);
		int c = getColByIndex(index);
		return getGroupByPosition(r, c);
	}

	// ĭ�� ��ġ (��, ��)�� �׷� ��ȣ�� ����ϴ� �޼ҵ�
	int getGroupByPosition(int row, int column) {
		int result = 1;
		result += (row - 1) / 3 * 3;
		result += (--column / 3);
		return result;

	}

};


void process(int caseIndex) {
	int index;
	std::cin >> index;
	SudokuBoard board = SudokuBoard();

	// ĭ�� ��ȣ�� ��, ��, �׷� ��ȣ�� ����Ѵ�
	int row = board.getRowByIndex(index);
	int col = board.getColByIndex(index);
	int group = board.getGroupByIndex(index);

	printf("Case #%d:\n", caseIndex);
	printf("%d %d %d\n", row, col, group);
}

int main() {
	int caseSize;
	std::cin >> caseSize;
	for (int caseIndex = 1; caseIndex <= caseSize; ++caseIndex) {
		process(caseIndex);
	}
}