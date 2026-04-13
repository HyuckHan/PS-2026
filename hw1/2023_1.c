#include <stdio.h>

int main() {
    int N, A[100];
    int d;  // 기준 공차
    int is_ap = 1;
    int i;

    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%d", &A[i]);

    // 원소가 1개이면 등차수열
    if (N == 1) {
        printf("1\n");
        return 0;
    }

    d = A[1] - A[0];  // 기준 공차

    for (i = 2; i < N; i++) {
        if (A[i] - A[i - 1] != d) {
            is_ap = 0;
            break;
        }
    }

    printf("%d\n", is_ap);
    return 0;
}
