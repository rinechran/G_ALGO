#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_TABLE_LENGTH = 10000;
int table[MAX_TABLE_LENGTH];
/**
* data[0] ~ data[n-1]�� ������ ��ȣ�鿡 ���� �󵵼� ���̺��� ä��� �Լ�
* @param data
* @param n
* @param table  table[x] := data�迭���� x�� ������ Ƚ��
*/
void fillFrequencyTable(int data[], int n, int table[]) {

	for (int i = 0; i < n; ++i) {
		table[data[i]]++;
	}

}

/**
* data[0] ~ data[n-1]���̿��� ���� ���� ������ ��ȣ�� ��ȯ�ϴ� �Լ�
* @param data
* @param n
* @return  ���� ���� ������ ��ȣ. �������� ��� ���������� ���� ���� ��ȣ.
*/
int getFrequentNumber(int data[], int n) {
	int table[MAX_TABLE_LENGTH] = { 0, };

	fillFrequencyTable(data, n, table);

	int frequent_number = 0;
	for (int i = 0; i < MAX_TABLE_LENGTH; ++i) {
		if (table[i] > table[frequent_number]) {
			frequent_number = i;
		}
	}

	return frequent_number;
}

int main() {
	int n;

	std::cin >> n;

	int* data = new int[n];

	for (int i = 0; i < n; ++i) {
		std::cin >> data[i];
	}

	int answer = getFrequentNumber(data, n);

	// �� �ڸ��� ���
	printf("%04d", answer);

	delete[] data;

	return 0;
}
