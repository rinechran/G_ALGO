#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_SERIAL_NUMBER = 100000;

/**
* data[0] ~ data[n-1]에 등장한 시리얼 번호들에 대한 빈도수 테이블을 채우는 함수
* @param data
* @param n
* @param table  table[x] := data배열에서 x가 등장한 횟수
*/
void fillFrequencyTable(const vector<int>& data, int n, vector<int>& table) {
	for(int i = 0; i < n; ++i) {
		table[data[i]]++;
	}
}


/**
* data[0] ~ data[n-1]에서 중복이 존재하지 않는 원소들을 반환한다.
* 단, 각 원소들은 오름차순으로 정렬되어 있어야 한다.
* @param data  data[0] ~ data[n-1]에는 10만 이하의 자연수다.
* @param n
* @return
*/
vector<int> getUniqueElements(const vector<int>& data, int n) {

	vector<int> ret; //유일한 원소들 배열
	vector<int> table(MAX_SERIAL_NUMBER, 0);
	fillFrequencyTable(data, n, table);

	for (int i = 0; i <= MAX_SERIAL_NUMBER; ++i) {
		if (table[i] == 1) {
			ret.push_back(i);
		}
	}

	//오름차순 순서로 추가했기 때문에 ret에 대한 정렬은 불필요하다.
	return ret;
}

int main() {
	int n;
	std::cin >> n;
	vector<int> data = vector<int>(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> data[i];
	}

	const vector<int> answer = getUniqueElements(data, n);

	// 각 원소들을 출력한다.
	for (int i = 0; i < answer.size(); ++i) {
		if (i > 0) { //첫 번째 원소가 아니라면 앞에 공백을 하나 추가한다.
			printf(" ");
		}
		printf("%d", answer[i]);
	}

	return 0;
}
