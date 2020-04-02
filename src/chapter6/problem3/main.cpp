#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>

using namespace std;

class Histogram {
public:
	int height;    // ������׷��� ����
	int leftX;     // �ε��� Ȥ�� ������׷��� ���� ���� x ��ǥ
	int rightX;    // ������׷��� ������ ���� x��ǥ

	Histogram() { }

	Histogram(int index, int height) {
		this->leftX = index;
		this->rightX = this->leftX + 1;   // �� ������׷��� �ʺ� 1�̹Ƿ�
		this->height = height;
	}

};

/**
 * ���ʿ��� ���������� ���ʷ� ������ ������׷��� ���ο� ���� �� �ִ�
 * �ִ��� ���簢�� ���̸� ����ϴ� �Լ�
 *
 * @param n             ������׷��� ��
 * @param histograms    ������׷��� ���ʷ� ����� �迭
 * @return
 */
long long getLargestRectangleArea(const vector<Histogram>& histograms) {
	long long answer = 0;    // �ִ� ���簢���� ����

	// ���� �������� Ȯ�� ���ɼ��� �ִ� ������׷���
	stack<Histogram> continuedHistograms;
	continuedHistograms.push(Histogram(-1, 0));

	for (int i = 0; i < histograms.size() + 1; ++i) {
		Histogram h;
		if (i < histograms.size()) {
			h = histograms[i];
		}
		else {
			h = Histogram(histograms.size(), 0);
		}

		while (continuedHistograms.size() > 1
			&& continuedHistograms.top().height >= h.height) {
			Histogram lh = continuedHistograms.top();
			continuedHistograms.pop();

			Histogram bh = continuedHistograms.top();

			long long width = abs(h.leftX - bh.rightX);
			long long height = lh.height;
			long long area = width * height;

			answer = max(answer, area);

		}

		continuedHistograms.push(h);

	}




	return answer;
}

void process(int caseIndex) {
	int n;
	cin >> n;

	vector<Histogram> histograms;
	for (int i = 0; i < n; i++) {
		int height;
		cin >> height;
		histograms.push_back(Histogram(i, height));
	}

	long long answer = getLargestRectangleArea(histograms);
	cout << answer << endl;
}

int main() {
	int caseSize;
	cin >> caseSize;

	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) {
		process(caseIndex);
	}
}
