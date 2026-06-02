#include <stdio.h>
#include <stdlib.h>

int pick(int n, int *bucket, int m, int toPick, int S) {
	int i, j, flag, last_index, smallest, sum, ret;

	if(toPick == 0) {
		sum = 0;
		for(i=0; i<m; i++) {
			printf("%d ", bucket[i] + 1);
			sum = sum + (bucket[i] + 1);
		}
		printf( "%d\n", sum);
		if(sum == S)
			return 1;
		else 
			return 0;
	}

	last_index = m - toPick - 1;

	ret = 0;
	for(i=0; i<n; i++) {
		if(last_index>=0 && bucket[last_index] == i)
			continue;

		bucket[last_index+1] = i;
		ret = ret + pick(n, bucket, m, toPick -1, S);
	}
	return ret;
}

int main() {
	int N, K, S, i;
	int *arr;
	int *bucket;

	scanf("%d", &N);
	scanf("%d", &K);
	scanf("%d", &S);

	bucket = (int*)malloc(sizeof(int)*N);

	printf("%d\n", pick(K, bucket, N, N, S));

	free(bucket);
	return 0;
}
