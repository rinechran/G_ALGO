#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;
/**
*
* param a
*/
class Rectangle {
public:
	Rectangle() {

	}
	Rectangle(std::tuple<int, int> oth1, std::tuple<int, int> oth2) {
		if (std::get<0>(oth1) > std::get<0>(oth2)) {
			std::swap(oth1, oth2);
		}
		if (std::get<1>(oth1) < std::get<1>(oth2)) {
			std::swap(std::get<1>(oth1), std::get<1>(oth2));
		}

		rect = std::make_tuple(std::get<0>(oth1), std::get<1>(oth1),
			std::get<0>(oth2), std::get<1>(oth2));


	}
	void set(std::tuple<int, int> oth1, std::tuple<int, int> oth2) {

		if (std::get<0>(oth1) > std::get<0>(oth2)) {
			std::swap(oth1, oth2);
		}
		if (std::get<1>(oth1) < std::get<1>(oth2)) {
			std::swap(std::get<1>(oth1), std::get<1>(oth2));
		}

		rect = std::make_tuple(std::get<0>(oth1), std::get<1>(oth1),
			std::get<0>(oth2), std::get<1>(oth2));
	}

	int getSize() {
		int x = std::get<2>(rect) - std::get<0>(rect);
		int y = std::get<1>(rect) - std::get<3>(rect);
		return abs(x * y);
	}
	std::tuple<int, int, int, int> rect;
};

void test() {
	int Ax, Ay, Bx, By;
	Rectangle rect[2];
	for (int i = 0; i < 2; ++i) {
		cin >> Ax >> Ay >> Bx >> By;
		rect[i].set(std::make_tuple(Ax, Ay), std::make_tuple(Bx, By));
	}
	Ax = std::max(std::get<0>(rect[0].rect), std::get<0>(rect[1].rect));
	Ay = std::min(std::get<1>(rect[0].rect), std::get<1>(rect[1].rect));
	Bx = std::min(std::get<2>(rect[0].rect), std::get<2>(rect[1].rect));
	By = std::max(std::get<3>(rect[0].rect), std::get<3>(rect[1].rect));


	Rectangle diff(make_tuple(Ax, Ay), make_tuple(Bx, By));
	std::cout << diff.getSize() << std::endl;

}
int main() {

	int testCase;
	std::cin >> testCase;
	for (int i = 0; i < testCase; ++i) {
		test();
	}
	return 0;
}
