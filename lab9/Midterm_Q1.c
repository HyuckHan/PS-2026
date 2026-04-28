#include <stdio.h>

int digit_len(int n) {
	int len = 1;
	while (n >= 10) { n /= 10; len++; }
	return len;
}

int power10(int n) {
	int result = 1;
	while (n--) result *= 10;
	return result;
}

int main() {
	int a, b;
	scanf("%d %d", &a, &b);

	int ab = a * power10(digit_len(b)) + b;
	int ba = b * power10(digit_len(a)) + a;

	printf("%d\n", ab >= ba ? ab : ba);
	return 0;
}
