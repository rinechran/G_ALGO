#include <cstdio>

using namespace std;


/**
 * a�� b�� �ִ� ������� ����ϴ� �Լ�
 *
 * @param a
 * @param b
 * @return
 */
long long getGCD(long long a, long long b) {
    while (a % b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return b;
}

/**
 * a�� b�� �ּ� ������� ����ϴ� �Լ�
 *
 * @param a
 * @param b
 * @return
 */
long long getLCM(long long a, long long b) {
    return a* b / getGCD(a, b);
}

void process(int caseIndex) {
	int num1, num2;
	scanf("%d%d", &num1, &num2);

	long long gcd = getGCD(num1, num2);
	long long lcm = getLCM(num1, num2);

	printf("Case #%d:\n", caseIndex);
	printf("%lld %lld\n", gcd, lcm);
}

int main() {
	int caseSize;
	scanf("%d", &caseSize);

	for (int caseIndex = 1; caseIndex <= caseSize; ++caseIndex) {
		process(caseIndex);
	}
}