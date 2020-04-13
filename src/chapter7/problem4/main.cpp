#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

/**
 * @brief           독립적으로 정렬 된 두 범위 arr[left]~arr[mid], arr[mid+1] ~ arr[right] 범위를 하나의 정렬된 배열로 병합하는 함수
 *
 * @param arr
 * @param left
 * @param mid
 * @param right
 * @param buffer    병합을 위해 사용 될 임시 공간
 */
void concatOrderedArrays(vector<int>& arr, int left, int mid, int right, vector<int>& buffer) {
	int i = left;       // 왼쪽 배열의 인덱스 반복자
	int j = mid + 1;    // 오른쪽 배열의 인덱스 반복자
	int k = left;       // 버퍼 영역의 인덱스 반복자


	while (i <= mid && j <= right) {
		if (arr[i] > arr[j]) {
			buffer[k++] = arr[j++];
		}
		else {
			buffer[k++] = arr[i++];
		}
	}
	while (i <= mid) {
		buffer[k++] = arr[i++];

	}
	while (j <= right) {
		buffer[k++] = arr[j++];
	}
	for (int index = left; index <= right; index += 1) {
		arr[index] = buffer[index];
	}
}

/**
 * @brief           arr[left] ~ arr[right] 범위를 오름 차순으로 정렬해주는 함수
 *
 * @param arr
 * @param left
 * @param right
 * @param buffer    병합을 위해 사용 될 임시 공간
 */
void mergeSort(vector<int>& arr, int left, int right, vector<int>& buffer) {
	if (left >= right) {
		// 범위에 데이터가 하나 이하라면 정렬이 불필요하다
		return;
	}

	int mid = (left + right) / 2;
	mergeSort(arr, left, mid, buffer);
	mergeSort(arr, mid + 1, right, buffer);
	concatOrderedArrays(arr, left, mid, right, buffer);

}

/**
 * @brief       mergeSort   함수 축약형
 *
 * @param arr
 */
void mergeSort(vector<int>& arr) {
	int N = arr.size();
	vector<int> buffer(N);
	mergeSort(arr, 0, N - 1, buffer);
}

int main() {
	int N;
	std::cin >> N;

	vector<int> arr(N);
	for (int i = 0; i < N; i += 1) {
		std::cin >> arr[i];
	}

	mergeSort(arr);
	for (int i = 0; i < N; i += 1) {
		if (i > 0) {
			printf(" ");
		}
		printf("%d", arr[i]);
	}
}
