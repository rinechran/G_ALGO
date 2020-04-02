#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;


class Parenthesis {
public:
	bool type;  // ���� ��ȣ�� true, ���� ��ȣ�� false
	int index;  // �ش� ��ȣ�� �ε���

	Parenthesis(int index, bool type) {
		this->index = index;
		this->type = type;
	}

	Parenthesis(int index, char c) {
		this->index = index;
		if (c == '(') {
			this->type = true;
		}
		else {
			this->type = false;
		}
	}
};

/**
 * ��ȣ���� ������ ���ʷ� �迭�� �־��� ��, �ùٸ� ��ȣ ���ڿ����� �Ǵ��ϴ� �Լ�
 *
 * @param n             ��ȣ ���ڿ��� ����
 * @param parentheses   ��ȣ ���ڿ� ���� �迭
 * @return
 */
bool isValidParentheses(const vector<Parenthesis>& parentheses) {
	// ���� ¦�� ã�� ���� ���� ��ȣ��
	stack<Parenthesis> myStack;

	for (auto& parent : parentheses) {

		if (myStack.size() == 0) {
			myStack.push(parent);
		}
		else if (myStack.top().type == true && parent.type == false) {
			myStack.pop();
		}
		else {
			myStack.push(parent);
		}
	}

	return myStack.size() == 0;
}

void process(int caseIndex) {
	string str;
	cin >> str;

	vector<Parenthesis> parentheses;
	for (int i = 0; i < str.length(); ++i) {
		parentheses.push_back(Parenthesis(i, str[i]));
	}

	bool isValid = isValidParentheses(parentheses);

	if (isValid) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}

int main() {
	int caseSize;
	cin >> caseSize;

	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) {
		process(caseIndex);
	}
}
