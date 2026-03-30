#include <stdio.h>
#include <stdlib.h>
/**
 * 4진수 출력하기
 **/
void pick(int n, int *bucket, int m, int k) {
	int i, smallest, lastIndex;

	if(k==0) {
		for(i=0; i<m; i++) {
			printf("%d", bucket[i]);
		}
		printf("\n");
		return;
	}

	lastIndex = m - k - 1;
	smallest = 0;

	for(i=0; i<n; i++) {
		bucket[lastIndex+1] = i;
		pick(n, bucket, m, k-1);
	}
}

int main(int argc, char *argv[]) {
	int n=4;
	int *bucket;
	int m;

	scanf("%d", &m);
	bucket = (int *)malloc(sizeof(int) * m);

	pick(n, bucket, m, m);

	free(bucket);
	return 0;
}

