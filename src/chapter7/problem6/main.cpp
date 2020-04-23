#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Histogram {
public:
	int height;    // 히스토그램의 높이
	int leftX;     // 인덱스 혹은 히스토그램의 왼쪽 변의 x 좌표
	int rightX;    // 히스토그램의 오른쪽 변의 x좌표

	Histogram() {}

	Histogram(int index, int height) {
		this->leftX = index;
		this->rightX = this->leftX + 1;   // 각 히스토그램은 너비가 1이므로
		this->height = height;
	}
};


/**
 * @brief           주어진 범위에 대해 가장 큰 직사각형의 크기를 반환하는 함수
 *
 * @param histograms
 * @param left
 * @param right
 * @return          histograms[left] ~ histograms[right] 범위의 막대 내에 존재할 수 있는 가장 큰 직사각형의 크기
 */
long long getLargestRectangleArea(const vector<Histogram>& histograms, int left, int right) {
	if (left > right) {
		return 0;
	}
	else if (left == right) {
		return histograms[left].height;
	}

	int mid = (left + right) / 2;

	long long leftMax = getLargestRectangleArea(histograms, left, mid);
	long long rightMax = getLargestRectangleArea(histograms, mid + 1, right);

	long long globalMax = max(leftMax, rightMax);

	int begin = mid;
	int end = mid + 1;

	int height = min(histograms[mid].height, histograms[mid + 1].height);
	globalMax = max(globalMax, height * 2LL);

	int maxWidth = right - left + 1;
	for (int width = 3; width <= maxWidth; width += 1) {
		int lHn = (left < begin) ? histograms[begin - 1].height : -1;
		int rnh = (end < right) ? histograms[end + 1].height : -1;

		if (lHn >= rnh) {
			begin -= 1;
			height = min(height, histograms[begin].height);
		}
		else if (lHn <= rnh) {
			end += 1;
			height = min(height, histograms[end].height);
		}
		else {

		}
		long long area = (long long)height * width;
		globalMax = max(globalMax, area);

	}


	return globalMax;
}


long long getLargestRectangleArea(const vector<Histogram>& histograms) {
	return getLargestRectangleArea(histograms, 0, histograms.size() - 1);
}


void testCase(int caseIndex) {
	int n;
	std::cin >> n;

	vector<Histogram> histograms;
	for (int i = 0; i < n; i++) {
		int height;
		std::cin >> height;
		histograms.push_back(Histogram(i, height));
	}

	long long answer = getLargestRectangleArea(histograms);
	printf("%lld\n", answer);
}

int main() {
	int caseSize;
	std::cin >> caseSize;

	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) {
		testCase(caseIndex);
	}
}
