#include <iostream>


int max(int obj1,int obj2) {

	return obj1 > obj2 ? obj1 : obj2;
}
int main() {

	int p, q;

	std::cin >> p >> q;
	std::cout << max(p, q);

}