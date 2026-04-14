#include <stdio.h>
#include <stdlib.h>

void pick(int *items, int n, int *bucket, int m, int toPick) {
	int i, smallest, lastIndex;

	if(toPick == 0) {
		for(i=0; i<m; i++)
			printf("%d%c", items[bucket[i]], i<m-1?' ':'\n');
		return;
	}

	lastIndex = m - toPick - 1;

	if(m == toPick) 
		smallest = 0;
	else
		smallest = bucket[lastIndex];

	for(i=smallest; i<n; i++) { 
		bucket[lastIndex+1] = i;
		pick(items, n, bucket, m, toPick - 1);
	}
}

int main() {
	int N;
	int items[3] = {1000, 5000, 10000};
	int *bucket;

	scanf("%d", &N);
	N = N / 1000;
	bucket = (int*)malloc(sizeof(int)*N);

	pick(items, 3, bucket, N, N);
	free(bucket);
	return 0;
}

