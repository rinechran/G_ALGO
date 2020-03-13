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
	 * ������� ȸ�� ��ȣ�� ���޹ް� �� ���� ��ȣ�� ����ϴ� �޼ҵ�
	 */
	int findEmptyIndexByUserId(int userId) {
		int index = userId % length;
		while (this->isEmpty(index) == true) {
			index = (index + 1) % length;
		}
		return index;
	}

	/**
	 * �ش� ���� ��ȣ�� �̹� ��� ������ ���θ� ��ȯ�ϴ� �޼ҵ�
	 */
	bool isEmpty(int ticketIndex) {
		return this->used[ticketIndex];
	}

	/**
	 *  Ƽ�� ��� ���θ� �����ϱ� ���� �޼ҵ�
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
