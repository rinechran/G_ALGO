#include<cstdio>
#include<cmath>
#include<climits>
#include<iostream>
using namespace std;

class Point2D {
private:
	int x;
	int y;

public:
	Point2D(int x = 0, int y = 0)
	{
		this->x = x;
		this->y = y;
	}

	/**
	* 2���� ��� �󿡼� �� this���� �� target���� �Ÿ��� ������ ����ϴ� �Լ�
	* @param target
	* @return
	*/
	int getSquaredDistanceTo(const Point2D& target) const
	{
		int dx = abs(this->x - target.x);
		int dy = abs(this->y - target.y);
		return dx * dx + dy * dy;
	}

	double getDistanceTo(const Point2D& target) const {
		double sqd = (double)this->getSquaredDistanceTo(target);
		return sqrt(sqd);
	}
};


int main()
{
	int n;
	Point2D* points;

	scanf("%d", &n);
	points = new Point2D[n];

	for (int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);

		points[i] = Point2D(x, y);
	}

	double min = 1000000000000;
	int count = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			double sel = points[i].getDistanceTo(points[j]);
			if (min > sel) {
				min = sel;
				count = 1;
			}
			else if (min == sel)
			{
				count++;
			}


		}
	}


	printf("%0.1f\n", min);
	std::cout << count << std::endl;

	delete[] points;
	return 0;
}