#include<stdio.h>
#include<string>
#include<iostream>

using namespace std;

/**
* �迭���� �Ҽ��� "AJOU"�� ù ���ҿ� ������ ���Ҹ� ����ϴ� �Լ�
* @param school �� ������� �Ҽ��б� ���� �迭
* @param n      ������� ��
*/
void printIndexes(string school[], int n)
{
	int first = -1; //�������� ������ -1
	int last = -1;  //�������� ������ -1

	for (int i = 0; i < n; ++i) {
		if (school[i] != "AJOU") {
			
		}
		else if (first == -1) {
			first = i;
			last = i;
		}
		else {
			last = i;
		}
		
	}


	printf("%d %d\n", first+1, last+1);
}

int main()
{
	int n;
	char buff[11];
	string* school;

	std::cin >> n;
	school = new string[n];

	for (int i = 0; i < n; i++)
	{
		std::cin >> school[i];
	}

	printIndexes(school, n);

	delete[] school;
	return 0;
}