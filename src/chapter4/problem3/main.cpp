#include <iostream>

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

void process(int caseIndex) {
    int num1, num2;
    std::cin >> num1, num2;
    long long gcd = getGCD(num1, num2);
    long long lcm = getLCM(num1, num2);

    printf("Case #%d:\n", caseIndex);
    printf("%lld %lld\n", gcd, lcm);
}

int main() {
    int caseSize;
    std::cin >> caseSize;

    for (int caseIndex = 1; caseIndex <= caseSize; ++caseIndex) {
        process(caseIndex);
    }
}