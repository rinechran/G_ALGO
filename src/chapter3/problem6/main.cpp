#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Range {
public:
	int index;
	int left;
	int right;
	long long totalPoint;
	Range(int index, int left, int right) {
		this->index = index;
		this->left = left;
		this->right = right;
		this->totalPoint = 0;
	}


	long long getPoint(std::vector<long long>& table) {
		return totalPoint = table[right] - table[left - 1];
	}
};

/**
*
* @param n   ī���� ��
* @param m   �ٹ��� ������ ���� ��
* @param cards   �� ī�忡 ���� ������ ����Ʈ (cards[1] ~ card[n])
* @param ranges  �� ���� ������ ������ ����Ʈ (ranges[0] ~ ranges[m-1])
* @return        �� ������ ���� ���� ū ���� ��ü
*/
Range getBestRange(int n, int m, const vector<int>& cards, vector<Range>& ranges) {
	std::vector<long long> TABLE(cards.size() + 1);
	Range answer = ranges[0];

	TABLE[1] = cards[1];

	for (int i = 2; i < cards.size(); ++i) {
		TABLE[i] = TABLE[i - 1] + cards[i];
	}
	long long max = 0;
	for (auto& i : ranges) {
		long long tmp = i.getPoint(TABLE);
		if (max < tmp) {
			answer = i;
			max = tmp;
		}
	}



	return answer;
}

int main() {
	int n, m;
	std::cin >> n >> m;
	vector<int> cards(n + 1);
	vector<Range> ranges;

	// �� ī���� ������ �Է¹޴´�.
	for (int i = 1; i <= n; ++i) {
		std::cin >> cards[i];
	}

	// �ҵ��� ������ �Է¹޴´�.
	for (int i = 1; i <= m; ++i) {
		int l, r;
		std::cin >> l >> r;
		ranges.push_back(Range(i, l, r));
	}

	// ������ ���� ���� ū ������ ����Ѵ�.
	Range answer = getBestRange(n, m, cards, ranges);

	printf("%d %lld\n", answer.index, answer.totalPoint);

	return 0;
}
