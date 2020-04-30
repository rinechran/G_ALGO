﻿#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>

using namespace std;


class Point2D {
public:
	int x;
	int y;
	int index;

	Point2D(int index, int x, int y) {
		this->index = index;
		this->x = x;
		this->y = y;
	}

	Point2D(int x, int y) {
		this->index = 1;
		this->x = x;
		this->y = y;
	}

	long long getSquaredDistanceTo(Point2D target) {
		// 두 좌표간의 제곱거리를 계산
		long long dx = abs(this->x - target.x);
		long long dy = abs(this->y - target.y);
		return dx * dx + dy * dy;
	}

	double getDistanceTo(Point2D target) {
		// 두 좌표간의 실수 거리를 계산
		long long sqd = this->getSquaredDistanceTo(target);
		return sqrt(sqd);
	}

	bool operator < (const Point2D& other) const {
		// 각 좌표의 우선순위를 비교하기 위한 비교 연산자

		// x좌표가 다르다면 x좌표를 기준으로 비교한다.
		if (this->x != other.x) {
			return this->x < other.x;
		}

		// x좌표가 같다면 y좌표를 기준으로 비교한다.
		return this->y < other.y;
	}
};

long long getMaximumSquareArea(int n, const vector<Point2D>& points) {
	long long answer = 0;

	// 모든 점을 Set에 저장한다
	set<Point2D> pSet;
	for (int i = 0; i < n; i += 1) {
		pSet.insert(points[i]);
	}

	for (int i = 0; i < n; i += 1) {
		Point2D pa = points[i];
		for (int j = 0; j < n; j += 1) {
			Point2D pb = points[j];

			long long area = pa.getSquaredDistanceTo(pb);

			if (area < answer)
				continue;

			int dx = pb.x - pa.x;
			int dy = pb.y - pa.y;

			Point2D pd(pa.x - dy, pa.y + dx);
			Point2D pc(pb.x - dy, pb.y + dx);


			if (pSet.find(pc) != pSet.end() && pSet.find(pd) != pSet.end()) {
				answer = max(answer, area);
			}
		}
	}


	return answer;
}

void process(int caseIndex) {
	int n;
	cin >> n;

	vector<Point2D> points;

	for (int i = 0; i < n; i += 1) {
		int x, y;
		cin >> x >> y;
		points.push_back(Point2D(i, x, y));
	}

	double answer = getMaximumSquareArea(n, points);

	cout << fixed << setprecision(2) << answer << endl;
}

int main() {
	int caseSize;
	cin >> caseSize;

	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) {
		process(caseIndex);
	}
}