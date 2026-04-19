#include <stdio.h>
#include <stdlib.h>

void pick(int *items, int n, int *bucket, int m, int toPick) {
	int i, smallest, lastIndex, j;

	if(toPick == 0) {
		for(i=0; i<m; i++)
			printf("%d%c", items[bucket[i]], i<m-1?' ':'\n');
		return;
	}

	lastIndex = m - toPick - 1;

	if(m==toPick)
		smallest = 0;
	else
		smallest = bucket[lastIndex] + 1;

	for(i=smallest; i<n; i++) {
		bucket[lastIndex+1] = i;
		pick(items, n, bucket, m, toPick - 1);
	}
}

int main() {
	int N, M;
	int *items;
	int *bucket;

	scanf("%d", &N);
	scanf("%d", &M);
	items = (int*)malloc(sizeof(int)*N);
	bucket = (int*)malloc(sizeof(int)*M);
	for (int i = 0; i < N; i++)
		scanf("%d", &items[i]);

	pick(items, N, bucket, M, M);
	free(items);
	free(bucket);
	return 0;
}

