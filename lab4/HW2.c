#include <stdio.h>
#include <stdlib.h>
/**
 * 4진수 출력하기
 **/
void pick(char *items, int n, int *bucket, int m, int k) {
	int i, smallest, lastIndex;

	if(k==0) {
		int sum = 0;
		for(i=0; i<m; i++) {
			printf("%c %d ", items[bucket[i]], i+1);
			if( items[bucket[i]] == '+' )
				sum = sum + (i+1);
			else
				sum = sum - (i+1);
		}
		printf(" = %d\n", sum);
		return;
	}

	lastIndex = m - k - 1;
	smallest = 0;

	for(i=0; i<n; i++) {
		bucket[lastIndex+1] = i;
		pick(items, n, bucket, m, k-1);
	}
}

int main(int argc, char *argv[]) {
	char items[] = { '+', '-' };
	int n=2;
	int *bucket;
	int m;

	scanf("%d", &m);
	bucket = (int *)malloc(sizeof(int) * m);

	pick(items, n, bucket, m, m);

	free(bucket);
	return 0;
}
