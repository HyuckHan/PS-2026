#include <stdio.h>
#include <stdlib.h>

void pick(char *items, int n, int *bucket, int m, int toPick, int *numbers) {
	int i, smallest, lastIndex, j, flag;

	if(toPick == 0) {
		for(i=0; i<m; i++)
			printf("%c%c", items[bucket[i]], i<m-1?' ':'\n');
		return;
	}

	lastIndex = m - toPick - 1;

	for(i=0; i<n; i++) {
		bucket[lastIndex+1] = i;
		pick(items, n, bucket, m, toPick - 1, numbers);
	}
}

int main() {
	int N;
	char items[] = "+-*";
	int *bucket;
	int *numbers;

	scanf("%d", &N);
	numbers = (int*)malloc(sizeof(int)*N);
	bucket = (int*)malloc(sizeof(int)*N);
	for (int i = 0; i < N; i++)
		scanf("%d", &numbers[i]);

	pick(items, 3, bucket, N, N, numbers);
	free(numbers);
	free(bucket);
	return 0;
}

