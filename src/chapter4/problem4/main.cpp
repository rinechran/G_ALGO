#include <iostream>
#include <vector>

using namespace std;

/**
 * a�� b�� �ִ� ������� ����ϴ� �Լ�
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
 * a�� b�� �ּ� ������� ����ϴ� �Լ�
 *
 * @param a
 * @param b
 * @return
 */
long long getLCM(long long a, long long b) {
    return a * b / getGCD(a, b);
}


/**
 * ���� ���ڿ� ���� ���� �ּ� ������� ����ϴ� �Լ�
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
 * ��� ������ ���ÿ� ������ ���Ҹ� ������ �ּ� �ֱ⸦ ����ϴ� �Լ�
 *
 * @param n     ������ ��
 * @param sizes �� ��ȯ ������ ����(�ֱ�)
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
