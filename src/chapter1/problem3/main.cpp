#include<stdio.h>
#include<iostream>
#include <algorithm>
using namespace std;


int getCount(int data[], int n, int m, int s)
{
	int count = 0; //Ȯ���غ��ƾ� �� �ĺ��� ��


	return std::count_if(&(data[0]), &(data[n]), [=](int n) {return n == s || n == m; });;
}

int main()
{
	int n, m, s;
	int* data;

	std::cin >> n >> m >> s;
	data = new int[n];
	for (int i = 0; i < n; i++)
	{
		std::cin >> data[i];
	}

	int answer = getCount(data, n, m, s);

	printf("%d\n", answer);
	delete[] data;
	return 0;
}