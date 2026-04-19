#include <stdio.h>
#include <stdlib.h>

int pick(int *items, int n, int *bucket, int m, int toPick) {
	int i, smallest, lastIndex, j, sum;

	if(toPick == 0) {
		sum = 0;
		for(i=0; i<m; i++) {
			//printf("%d%c", items[bucket[i]], i<m-1?' ':'\n');
			sum = sum + items[bucket[i]];
		}
		return sum==0?1:0;
	}

	lastIndex = m - toPick - 1;

	if(m==toPick)
		smallest = 0;
	else
		smallest = bucket[lastIndex] + 1;
	
	sum = 0;
	for(i=smallest; i<n; i++) {
		bucket[lastIndex+1] = i;
		sum = sum + pick(items, n, bucket, m, toPick - 1);
	}
	return sum;
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

	printf("%d\n", pick(items, N, bucket, M, M));
	free(items);
	free(bucket);
	return 0;
}

