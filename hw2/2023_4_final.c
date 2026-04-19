#include <stdio.h>
#include <stdlib.h>

int  pick(char *items, int n, int *bucket, int m, int toPick, int *numbers) {
	int i, smallest, lastIndex, j, flag, max, first, ret;

	if(toPick == 0) {
		int sum = 0;
		for(i=0; i<m; i++) {
			//printf("%c%d%c", items[bucket[i]], numbers[i], i<m-1?' ':'\n'); 
			if(items[bucket[i]] == '+')
				sum = sum + numbers[i];
			else if(items[bucket[i]] == '-')
				sum = sum - numbers[i];
			else if(items[bucket[i]] == '*')
				sum = sum * numbers[i];
		}
		//printf("%d\n", sum);
		return sum;
	}

	lastIndex = m - toPick - 1;

	first = 1;
	for(i=0; i<n; i++) {
		if(m==toPick && items[i] == '*')
			continue;

		bucket[lastIndex+1] = i;
		ret = pick(items, n, bucket, m, toPick - 1, numbers);

		if(first==1) max = ret;
		else max = (max>ret)?max:ret;

		first = 0;
	}
	return max;
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

	printf("%d\n", pick(items, 3, bucket, N, N, numbers));
	free(numbers);
	free(bucket);
	return 0;
}

