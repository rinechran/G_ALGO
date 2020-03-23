#include <iostream>
#include <vector>
using namespace std;

bool isPossible(int size, int row, int col) {
	return row >= 0 && row < size && col >= 0 && col < size;
}
void process() {
	int size;
	std::cin >> size;
	std::vector<std::vector<int>> map(size);
	for (int i = 0; i < size; ++i) {
		map[i].resize(size, 0);
	}
	int mr[4] = { 0,1,0,-1 };
	int mc[4] = { 1,0,-1,0 };

	int row = 0;
	int col = 0;
	int move = 1;
	map[0][0] = move++;
	while (move <= (size * size)) {
		for (int i = 0; i < 4; ++i) {

			while (isPossible(size, row + mr[i], col + mc[i])) {
				if (map[row + mr[i]][col + mc[i]] != 0) {
					break;
				}
				row += mr[i];
				col += mc[i];
				map[row][col] = move++;

			}
		}
	}
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			std::cout << map[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int main() {

	int testCase = 0;
	std::cin >> testCase;

	for (int i = 0; i < testCase; ++i) {
		process();
	}
	return 0;
}
