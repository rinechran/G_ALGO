#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;


class Parenthesis {
public:
	bool type;  // 열린 괄호면 true, 닫힌 괄호면 false
	int index;  // 해당 괄호의 인덱스

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
 * 괄호들의 정보가 차례로 배열로 주어질 때, 올바른 괄호 문자열인지 판단하는 함수
 *
 * @param n             괄호 문자열의 길이
 * @param parentheses   괄호 문자에 대한 배열
 * @return
 */
bool isValidParentheses(const vector<Parenthesis>& parentheses) {
	// 현재 짝을 찾지 못한 열린 괄호들
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
