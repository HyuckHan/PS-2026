#include <stdio.h>

int countDigit(int num, int k) {
    int cnt = 0;
    while (num > 0) {
        if (num % 10 == k)
            cnt++;
        num /= 10;
    }
    return cnt;
}

int main() {
    int N, K, A[1000];
    int total = 0;
    int i;

    scanf("%d", &N);
    scanf("%d", &K);
    for (i = 0; i < N; i++)
        scanf("%d", &A[i]);

    for (i = 0; i < N; i++)
        total += countDigit(A[i], K);

    printf("%d\n", total);
    return 0;
}
