#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>

using namespace std;

class Histogram {
public:
	int height;    // 히스토그램의 높이
	int leftX;     // 인덱스 혹은 히스토그램의 왼쪽 변의 x 좌표
	int rightX;    // 히스토그램의 오른쪽 변의 x좌표

	Histogram() { }

	Histogram(int index, int height) {
		this->leftX = index;
		this->rightX = this->leftX + 1;   // 각 히스토그램은 너비가 1이므로
		this->height = height;
	}

};

/**
 * 왼쪽에서 오른쪽으로 차례로 세워진 히스토그램들 내부에 만들 수 있는
 * 최대의 직사각형 넓이를 계산하는 함수
 *
 * @param n             히스토그램의 수
 * @param histograms    히스토그램이 차례로 저장된 배열
 * @return
 */
long long getLargestRectangleArea(const vector<Histogram>& histograms) {
	long long answer = 0;    // 최대 직사각형의 넓이

	// 현재 우측으로 확장 가능성이 있는 히스토그램들
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
