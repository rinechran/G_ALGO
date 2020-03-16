#include <iostream>
#include <vector>

using namespace std;

/**
 * a와 b의 최대 공약수를 계산하는 함수
 *
 * @param a
 * @param b
 * @return
 */
long long getGCD(long long a, long long b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

/**
 * a와 b의 최소 공배수를 계산하는 함수
 *
 * @param a
 * @param b
 * @return
 */
long long getLCM(long long a, long long b) {
    return a * b / getGCD(a, b);
}


/**
 * 여러 숫자에 대한 공통 최소 공배수를 계산하는 함수
 *
 * @param numbers
 * @return
 */
long long getLCMs(vector<long long>& numbers) {

    long long lcm = getLCM(numbers[0], numbers[1]);

    for (int i = 2; i < numbers.size(); ++i) {
        lcm = getLCM(lcm, numbers[i]);
    }
    return lcm;
}

/**
 * 모든 수열이 동시에 최초의 원소를 만나는 최소 주기를 계산하는 함수
 *
 * @param n     수열의 수
 * @param sizes 각 순환 수열의 길이(주기)
 * @return
 */
long long getGlobalPeriod(vector<long long>& sizes) {

    long long allLcm = getLCMs(sizes);

    return allLcm;

}

int main() {
    int n;
    std::cin >> n;

    vector<long long> sizes(n);

    for (int i = 0; i < n; i += 1) {
        std::cin >> sizes[i];
    }

    long long answer = 1 + getGlobalPeriod(sizes);
    printf("%lld\n", answer);
}
