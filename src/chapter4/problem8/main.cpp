#include <stdio.h>

class KaingCalendar {
public:
	int M;    // ���� ��ȣ�� �ִ� ��
	int N;    // ������ ��ȣ�� �ִ� ��

	KaingCalendar(int M, int N) {
		this->M = M;
		this->N = N;
	}

	/**
	 * 'index'��° ��¥�� X(���� ��ȣ)�� ��ȯ�ϴ� �Լ�
	 *
	 * @param index
	 * @return
	 */
	int getXbyIndex(int index) {
		// M �ֱ�� �ܼ��� ��ȯ�ϹǷ� �������� ����� �� �ִ�.
		return (index - 1) % M + 1;
	}

	/**
	 * 'index'��° ��¥�� Y(������ ��ȣ)�� ��ȯ�ϴ� �Լ�
	 *
	 * @param index
	 * @return
	 */
	int getYByIndex(int index) {
		// N �ֱ�� �ܼ��� ��ȯ�ϹǷ� �������� ����� �� �ִ�.
		return (index - 1) % N + 1;
	}

	/**
	 *
	 *
	 * @param x
	 * @param y
	 * @return  �� �޷¿��� <x, y>��� ������ ���ʷ� �����ϴ� ����
	 *          �������� �ʴ� ������� -1�� ��ȯ�Ѵ�
	 */
	int getIndex(int x, int y) {
		// x��° ��¥�� �׻� ���� ��ȣ�� x��.
		// �׸��� ���� ��¥�� M �ֱ�� �׻� x�� �����Ѵ� 
		for (int index = x; index <= M * N; index += M) {
			// ������ x�� ��� ��¥�� ���� 
			if (getYByIndex(index) == y) {
				// �������� y�� ��¥�� �����Ѵٸ� ��ȯ�Ѵ�
				return index;
			}
		}
		//�������� �ʴ´ٸ� -1�� ��ȯ�Ѵ�
		return -1;
	}
};

void process(int caseIndex) {
	int M, N, x, y;
	scanf("%d%d%d%d", &M, &N, &x, &y);

	// <1,1> ~ <M, N> ������ ǥ���ϴ� ī�� �޷��� �����Ѵ�
	KaingCalendar calendar(M, N);

	// �� �޷¿��� <x, y>�� �� ��° �������� ����Ѵ�
	int answer = calendar.getIndex(x, y);

	// ������ ����Ѵ�
	printf("%d\n", answer);
}

int main() {
	int caseSize;
	scanf("%d", &caseSize);

	for (int caseIndex = 1; caseIndex <= caseSize; ++caseIndex) {
		process(caseIndex);
	}
}