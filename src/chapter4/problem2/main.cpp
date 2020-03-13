#include <iostream>
#include <vector>

using namespace std;

class TicketTable {
public:
	vector<bool> used;
	int length;

	TicketTable(int length) {
		this->length = length;
		this->used.assign(length, false);
	}

	/**
	 * 사용자의 회원 번호로 지급받게 될 행운권 번호를 계산하는 메소드
	 */
	int findEmptyIndexByUserId(int userId) {
		int index = userId % length;
		while (this->isEmpty(index) == true) {
			index = (index + 1) % length;
		}
		return index;
	}

	/**
	 * 해당 행운권 번호가 이미 사용 중인지 여부를 반환하는 메소드
	 */
	bool isEmpty(int ticketIndex) {
		return this->used[ticketIndex];
	}

	/**
	 *  티켓 사용 여부를 갱신하기 위한 메소드
	 */
	void setUsed(int index, bool status) {
		used[index] = status;
	}
};

vector<int> getTicketNumbers(int n, int m, const vector<int>& ids) {
	vector<int> tickets;
	TicketTable table = TicketTable(n);

	for (int i = 0; i < m; i++) {
		int userId = ids[i];
		int ticketIndex = table.findEmptyIndexByUserId(userId);
		tickets.push_back(ticketIndex);
		table.setUsed(ticketIndex, true);
	}

	return tickets;
}

int main() {
	int n, m;
	std::cin >> n >> m;
	vector<int> ids(m);

	for (int i = 0; i < m; ++i) {
		std::cin >> ids[i];
	}

	vector<int> tickets = getTicketNumbers(n, m, ids);
	for (int i = 0; i < tickets.size(); ++i) {
		printf("%d\n", tickets[i]);
	}
}
