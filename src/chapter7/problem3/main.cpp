#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/**
 * @brief   (r행 c열)의 집으로부터 연결 된 '아직 방문하지 않은 집'의 총 수를 계산하는 함수
 *          이 과정에서 방문하는 집은 모두 visited[r][c]를 true로 갱신한다
 *
 * @param r         현재 기준 칸의 행 번호
 * @param c         현재 기준 칸의 열 번호
 * @param N         지도의 크기
 * @param isHouse   isHouse[r][c] := r행 c열의 칸에 집이 존재하는지 여부
 * @param visited   visited[r][c] := r행 c열의 칸의 집이 이미 고려 되었는지 여부
 * @return
 */
int getLinkedHousesNumber(int r, int c, int N, const vector<vector<bool> >& isHouse, vector<vector<bool> >& visited) {
	if (r <= 0 || c <= 0 || r > N || c > N) {
		// 지도를 벗어나는 집은 존재하지 않으므로 0
		return 0;
	}
	else if (!isHouse[r][c] || visited[r][c]) {
		// 집이 없는 칸 이나 이미 단지에 속한 집은 고려하지 않음
		return 0;
	}
	visited[r][c] = 1;
	return
		+1
		+ getLinkedHousesNumber(r + 1, c, N, isHouse, visited)
		+ getLinkedHousesNumber(r - 1, c, N, isHouse, visited)
		+ getLinkedHousesNumber(r, c - 1, N, isHouse, visited)
		+ getLinkedHousesNumber(r, c + 1, N, isHouse, visited);

}

/**
 * @brief   문제의 조건에 따라 지도에 존재하는 모든 단지의 크기들을 반환하는 함수
 *
 * @param isHouse   isHouse[r][c] := r행 c열에 집이 존재하는지 여부 (1행 1열 ~ N행 N열)
 * @param N         지도의 크기
 * @return          모든 단지들의 크기의 리스트, 오름차순으로 정렬해야 한다
 */
vector<int> getAllGroupSizes(const vector<vector<bool> >& isHouse, int N) {

	vector<vector<bool> > visited(N + 2, vector<bool>(N + 2, false));

	// 각 단지들의 크기를 저장할 그룹
	vector<int> groups;

	for (int r = 1; r <= N; r += 1) {
		for (int c = 1; c <= N; c += 1) {
			int result = getLinkedHousesNumber(r, c, N, isHouse, visited);
			if (result != 0) {
				groups.push_back(result);
			}
		}
	}

	// 정렬 후 반환한다
	sort(groups.begin(), groups.end());

	return groups;
}

int main() {
	int N;
	std::cin >> N;
	vector<vector<bool> > isHouse(N + 2, vector<bool>(N + 2, false));

	// 2차원 격자의 경우 가장자리에 한 칸을 두고 고려하면 처리가 편해진다
	for (int r = 1; r <= N; r += 1) {
		for (int c = 1; c <= N; c += 1) {
			int value;
			std::cin >> value;
			if (value == 1) {
				isHouse[r][c] = true;
			}
		}
	}

	vector<int> groupSizes = getAllGroupSizes(isHouse, N);

	printf("%d\n", groupSizes.size());
	for (int i = 0; i < groupSizes.size(); i += 1) {
		int size = groupSizes[i];
		printf("%d\n", size);
	}
}
