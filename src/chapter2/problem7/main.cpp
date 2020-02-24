#include<cstdio>
#include<iostream>

using namespace std;


void bubbleSort(int data[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (data[j] > data[j + 1]) {    
				int temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;

			}
		}
	}
}
int main()
{
	int n;
	int* data;

	scanf("%d", &n);
	data = new int[n];

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &data[i]);
	}

	bubbleSort(data, n);

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