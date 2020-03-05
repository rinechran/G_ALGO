#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_SERIAL_NUMBER = 100000;

/**
* data[0] ~ data[n-1]�� ������ �ø��� ��ȣ�鿡 ���� �󵵼� ���̺��� ä��� �Լ�
* @param data
* @param n
* @param table  table[x] := data�迭���� x�� ������ Ƚ��
*/
void fillFrequencyTable(const vector<int>& data, int n, vector<int>& table) {
	for(int i = 0; i < n; ++i) {
		table[data[i]]++;
	}
}


/**
* data[0] ~ data[n-1]���� �ߺ��� �������� �ʴ� ���ҵ��� ��ȯ�Ѵ�.
* ��, �� ���ҵ��� ������������ ���ĵǾ� �־�� �Ѵ�.
* @param data  data[0] ~ data[n-1]���� 10�� ������ �ڿ�����.
* @param n
* @return
*/
vector<int> getUniqueElements(const vector<int>& data, int n) {

	vector<int> ret; //������ ���ҵ� �迭
	vector<int> table(MAX_SERIAL_NUMBER, 0);
	fillFrequencyTable(data, n, table);

	for (int i = 0; i <= MAX_SERIAL_NUMBER; ++i) {
		if (table[i] == 1) {
			ret.push_back(i);
		}
	}

	//�������� ������ �߰��߱� ������ ret�� ���� ������ ���ʿ��ϴ�.
	return ret;
}

int main() {
	int n;
	std::cin >> n;
	vector<int> data = vector<int>(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> data[i];
	}

	const vector<int> answer = getUniqueElements(data, n);

	// �� ���ҵ��� ����Ѵ�.
	for (int i = 0; i < answer.size(); ++i) {
		if (i > 0) { //ù ��° ���Ұ� �ƴ϶�� �տ� ������ �ϳ� �߰��Ѵ�.
			printf(" ");
		}
		printf("%d", answer[i]);
	}

	return 0;
}
