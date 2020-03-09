#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class FrequencyTable {
public:
	const int MAX_SIZE = 1000000;

	int uniqueElements; //현재 중복이 존재하지 않는 unique한 생일의 수
	vector<int> frequency; //frequency[b] := 생일이 b인 정보의 수

	FrequencyTable() {
		this->uniqueElements = 0;
		this->frequency = vector<int>(MAX_SIZE, 0);
	}

	/**
	* 새로운 생일을 등록하고 빈도수를 갱신한다.
	* @param birthDate
	*/
	void addBirthDate(int birthDate) {

		if (this->frequency[birthDate] == 0) {
			this->uniqueElements++;
		}
		this->frequency[birthDate]++;
	}

	/**
	* 기존의 생일을 제거하고 빈도수를 갱신한다.
	* @param birthDate
	*/
	void removeBirthDate(int birthDate) {
		this->frequency[birthDate]--;

		if (this->frequency[birthDate] == 0) {
			this->uniqueElements--;
		}
	}
};

int getUniqueRangeNumber(const vector<int>& birthDate, int n, int k) {

	int answer = 0;

	FrequencyTable table = FrequencyTable();
	for (int i = 0; i < k - 1; i++) {
		table.addBirthDate(birthDate[i]);
	}

	for (int i = 0; i + k - 1 < n; i++) {

		int left = i;
		int right = i + k - 1;

		table.addBirthDate(birthDate[right]);

		if (left > 0) {
			table.removeBirthDate(birthDate[left - 1]);
		}

		if (table.uniqueElements == k) {

			answer += 1;
		}
	}

	return answer;
}

int main() {
	int n, k;
	std::cin >> n >> k;
	vector<int> birthDate(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> birthDate[i];
	}

	int answer = getUniqueRangeNumber(birthDate, n, k);

	printf("%d\n", answer);
}
