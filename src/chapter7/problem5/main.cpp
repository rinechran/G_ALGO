#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;



template <class ForwardIt>
void quicksort(ForwardIt first, ForwardIt last)
{
	if (first == last) return;
	auto pivot = *std::next(first, std::distance(first, last) / 2);
	ForwardIt middle1 = std::partition(first, last,
		[pivot](const auto& em) { return em < pivot; });
	ForwardIt middle2 = std::partition(middle1, last,
		[pivot](const auto& em) { return !(pivot < em); });
	quicksort(first, middle1);
	quicksort(middle2, last);
}


int main() {
	int N;
	std::cin >> N;

	vector<int> arr(N);
	for (int i = 0; i < N; i += 1) {
		std::cin >> arr[i];
	}

	quicksort(arr.begin(), arr.end());
	for (int i = 0; i < N; i += 1) {
		if (i > 0) {
			printf(" ");
		}
		printf("%d", arr[i]);
	}
}
