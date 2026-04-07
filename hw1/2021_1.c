#include <stdio.h>
#include <string.h>

int main() {
    char a[101], b[101];
    scanf("%s", a);
    scanf("%s", b);

    int len_a = strlen(a);
    int len_b = strlen(b);

    int i = len_a - 1;
    int j = len_b - 1;

    int carry = 0;
    int carry_count = 0;

    while (i >= 0 || j >= 0) {
        int digit_a = (i >= 0) ? a[i] - '0' : 0;
        int digit_b = (j >= 0) ? b[j] - '0' : 0;

        int sum = digit_a + digit_b + carry;

        if (sum >= 10) {
            carry = 1;
            carry_count++;
        } else {
            carry = 0;
        }

        i--;
        j--;
    }

    printf("%d", carry_count);
    return 0;
}