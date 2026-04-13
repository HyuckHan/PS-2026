#include <stdio.h>
#include <stdlib.h>

void pick(int *items, int n, int *bucket, int m, int toPick) {
	int i, smallest, lastIndex, j, flag;

	if(toPick == 0) {
		for(i=0; i<m; i++)
			printf("%d%c", bucket[i], i<m-1?' ':'\n');
		return;
	}

	lastIndex = m - toPick - 1;

	for(i=0; i<n; i++) {
		flag = 0;
		for(j=0; j<=lastIndex; j++) {
			if(bucket[j] == i)
				flag = 1;
		}
		if(flag == 1)
			continue;
		bucket[lastIndex+1] = i;
		pick(items, n, bucket, m, toPick - 1);
	}
}

int main() {
	int N;
	int *items;
	int *bucket;

	scanf("%d", &N);
	items = (int*)malloc(sizeof(int)*N);
	bucket = (int*)malloc(sizeof(int)*(N-1));
	for (int i = 0; i < N; i++)
		scanf("%d", &items[i]);

	pick(items, N, bucket, N-1, N-1);
	return 0;
}

