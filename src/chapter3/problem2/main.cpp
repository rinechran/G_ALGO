#include <iostream>
#include <vector>

using namespace std;

const int MAX_COLOR_NUMBER = 100;

//�¼����� �� �� ��ĥ�ϴ� �̺�Ʈ�� ���� ����
class Painting {
public:
	int left;
	int right;
	int color;

	Painting() { }

	Painting(int left, int right, int color) {
		this->left = left;
		this->right = right;
		this->color = color;
	}
};


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
*
* @param n : �¼��� ��. �¼��� 0~(n-1)���� ��ȣ�� ������.
* @param m : �¼��� ĥ�� Ƚ��.
* @param paintings  : �¼����� ��ĥ�� �̺�Ʈ���� ����
*/
void solve(int n, int m, const Painting* paintings)
{
	int* seats = new int[n];
	int table[MAX_COLOR_NUMBER] = { 0, };
	for (int i = 0; i < n; i++)
	{
		seats[i] = 0;
	}

	for (int i = 0; i < m; ++i) {
		const Painting& p = paintings[i];

		for (int j = p.left; j <= p.right; ++j) {
			seats[j] = p.color;
		}
	}

	fillFrequencyTable(seats, n, table);


	int minColor = seats[0]; //���� ���� ������ ����
	int maxColor = seats[0]; //���� ���� ������ ����

	for (int i = 0; i < MAX_COLOR_NUMBER; ++i) {
		if (table[i] == 0)
			continue;
		if (table[minColor] > table[i]) {
			minColor = i;
		}
		if (table[maxColor] < table[i]) {
			maxColor = i;
		}
	}

	printf("%d\n", maxColor);
	printf("%d\n", minColor);

	delete[] seats;
}

int main() {
	int n, m;
	std::cin >> n >> m;

	Painting* paintings = new Painting[n];

	for (int i = 0; i < m; ++i) {
		std::cin >> paintings[i].left;
		std::cin >> paintings[i].right;
		std::cin >> paintings[i].color;

		paintings[i].left -= 1;
		paintings[i].right -= 1;
	}

	solve(n, m, paintings);

	return 0;
}