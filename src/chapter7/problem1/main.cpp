#include <iostream>
#include <vector>
#include <string>

using namespace std;

const char ITEMS[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

/**
 * @brief   depth 번째 이후 알파벳 조합을 탐색하는 함수
 *          모든 알파벳이 선택되었다면, 선택 된 알파벳을 모두 출력한다
 *
 * @param depth             재귀함수의 깊이 (= 선택된 알파벳 수 + 1)
 * @param limit             재귀함수의 최대 깊이 제한
 * @param selectedIndex     현재까지 선택한 데이터들의 인덱스
 */
void findAllCombinations(int depth, int limit, vector<int> selectedIndex, vector<string>& answer) {
	// depth가 제한보다 커진 경우, limit개 만큼의 문자를 모두 선택했다는 뜻이다
	if (depth > limit) {
		// 선택한 문자들을 차례로 한 줄에 출력한다

		string str;
		for (int i = 1; i < depth; i += 1) {
			int index = selectedIndex[i - 1];
			char c = ITEMS[index];
			str += c;
		}
		answer.push_back(str);

		// 이제 종료한다
		return;
	}
	int minIndex = 0;
	if (depth > 1) {
		minIndex = selectedIndex[selectedIndex.size() - 1] + 1;
	}
	for (int i = minIndex; i < 26; ++i) {
		selectedIndex.push_back(i);
		findAllCombinations(depth + 1, limit, selectedIndex, answer);
		selectedIndex.pop_back();
	}
}

int main() {
	int N;
	cin >> N;

	vector<string> answer;
	findAllCombinations(1, N, vector<int>(), answer);

	for (int i = 0; i < answer.size(); i += 1) {
		cout << answer[i] << endl;
	}
}
