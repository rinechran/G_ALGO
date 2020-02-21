#include<cstdio>
#include<iostream>
#include <algorithm>
using namespace std;



int getMinIndexInRange(int data[], int n, int begin, int end)
{
	int minIndex = begin;
	for (int i = begin; i < end; ++i) {

		if (data[minIndex] > data[i]) {
			minIndex = i;
		}
	}
	return minIndex;
}

void selectionSort(int data[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int minIndex = getMinIndexInRange(data, n, i, n);
		std::swap(data[minIndex], data[i]);

	}
}

int main()
{
	int n;
	int* data;

	std::cin >> n;
	data = new int[n];

	for (int i = 0; i < n; i++)
	{
		std::cin >> data[i];
	}

	selectionSort(data, n);

	for (int i = 0; i < n; i++)
	{
		if (i > 0)
		{
			printf(" ");
		}
		printf("%d", data[i]);
	}

	delete[] data;
	return 0;
}