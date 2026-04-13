#include <stdio.h>

int main() {
	int N, K, M, i, tlen;
	int digitM[3], digit_i[3];
	int j = 0;
	int pos = 0;
	scanf("%d %d %d", &N, &K, &M);


	digitM[0] = M/100;
	digitM[1] = (M/10)%10;
	digitM[2] = M%10;

	for (i = K; i < N; i += K) {
		int num = i;
		tlen = 0;

		for(tlen=0; num>0; tlen++) {
			digit_i[tlen] = num % 10;
			num /= 10;
		} 

		for (int k = tlen - 1; k >= 0; k--) {
			pos++;
			if( digit_i[k] == digitM[j] ) {
				j++;
				if( j == 3 ) {
					printf("%d\n", pos-2);
					return 0;
				}
			}
			else {
				j = 0;
			}
		}
	}
	printf("-1\n");

	return 0;
}

