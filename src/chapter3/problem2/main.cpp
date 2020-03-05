#include <iostream>
#include <vector>

using namespace std;

const int MAX_SEAT_NUMBER = 1000;
const int MAX_COLOR_NUMBER = 100;

//좌석들을 한 번 색칠하는 이벤트에 대한 정보
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
* data[0] ~ data[n-1]에 등장한 번호들에 대한 빈도수 테이블을 채우는 함수
* @param data
* @param n
* @param table  table[x] := data배열에서 x가 등장한 횟수
*/
void fillFrequencyTable(int data[], int n, int table[]) {

}

/**
*
* @param n : 좌석의 수. 좌석은 0~(n-1)번의 번호를 가진다.
* @param m : 좌석을 칠한 횟수.
* @param paintings  : 좌석들을 색칠한 이벤트들의 정보
*/
void solve(int n, int m, const Painting* paintings)
{
	int* seats = new int[n];
	int table[MAX_SEAT_NUMBER] = { 0, };
	for (int i = 0; i < n; i++)
	{
		seats[i] = 0;
	}

	for (int i = 0; i < m; ++i) {
		for (int j = paintings[i].left; j < paintings[i].right; ++j) {
			seats[j] = paintings[i].color;
		}
	}

	fillFrequencyTable(seats, n, table);


	int minColor = seats[0]; //가장 적게 등장한 색상
	int maxColor = seats[0]; //가장 많이 등장한 색상

	for (int i = 0; i < MAX_SEAT_NUMBER; ++i) {
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