#include <stdio.h>

int main() {
    int N, M, S, i;
    char ladder[100][100];

    scanf("%d %d %d", &M, &N, &S);

    for (int i = 0; i < N; i++) {
        scanf("%s", ladder[i]);
    }

    /*
    for (i = 0; i < N; i++) {
        if (ladder[i][S - 1] == '1') {
            S--;
        } else if (ladder[i][S + 1] == '1') {
            S++;
        }
    }*/

    for (i = 0; i < N; i++) {
        if ( S != 0 && ladder[i][S - 1] == '1' ) {
            S--;
        } else if ( S != (M-1) && ladder[i][S] == '1' ) {
            S++;
        }
    }

    printf("%d\n", S);
    return 0;
}