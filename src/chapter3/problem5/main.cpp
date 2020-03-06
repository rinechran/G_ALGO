#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring> 

using namespace std;

int MAP[100][100] = { 0, };

class Paper {
public:
	int leftColumn;   //가장 왼쪽 격자의 열 번호
	int rightColumn;  //가장 오른쪽 격자의 열 번호
	int topRow;       //가장 위쪽 격자의 행 번호
	int bottomRow;    //가장 아래쪽 격자의 행 번호

	Paper(int xPos, int yPos) {
		this->leftColumn = xPos;
		this->rightColumn = this->leftColumn + 9;
		this->bottomRow = yPos;
		this->topRow = this->bottomRow + 9;
	}
};

/**
* 색종이들이 덮고 있는 영역의 총 넓이를 계산하는 함수
*
* @param papers
* @param n
* @return
*/
int getCoveredArea(const vector<Paper>& papers, int n) {
	int answer = 0; //색종이들이 덮은 영역의 총 넓이
	vector < vector<int> > board(100, vector<int>(100, 0));
	for (auto& i : papers) {
		for (int row = i.bottomRow; row <= i.topRow; ++row) {
			for (int col = i.leftColumn; col <= i.rightColumn; ++col) {
				board[row][col]++;
			}
		}
	}

	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j) {
			if (board[i][j] > 0)
				answer++;
		}
	}


	return answer;
}

int main() {
	int caseSize;
	std::cin >> caseSize;
	std::vector<int> a;
	for (int caseIndex = 1; caseIndex <= caseSize; ++caseIndex) {
		int n;
		std::cin >> n;

		vector<Paper> papers;
		for (int i = 0; i < n; ++i) {
			int leftX, bottomY;
			std::cin >> leftX >> bottomY;
			papers.push_back(Paper(leftX, bottomY));
		}

		a.push_back(getCoveredArea(papers, n));

	}
	for (auto& i : a) {
		std::cout << i << std::endl;
	}
	return 0;
}
