#include <iostream>
#include <vector>


int max_element(int *start,int *end) {
	
	int max = *start;
	for (auto it = start; it != end+1; ++it) {

		if (max < *it) {
			max = *it;

		}
	}
	return max;


}
int main() {

	int n;

	std::cin >> n;

	std::vector<int> data;


	for (int i = 0; i < n; ++i) {
		int temp;
		std::cin >> temp;
		data.push_back(temp);
	}



	int max = max_element(&data[0],&data[n-1]);
	std::cout << max << std::endl;
	

}