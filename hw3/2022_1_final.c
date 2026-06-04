#include <stdio.h>
#include <stdlib.h>

int pick(int *arr, int n, int *bucket, int m, int toPick, int total) {
	int i, j, flag, last_index, smallest, sum, diff, min, ret;

	if(toPick == 0) {
		sum = 0;
		for(i=0; i<m; i++) {
			printf("%d ", arr[bucket[i]]);
			sum = sum + arr[bucket[i]];
		}
		printf("= %d %d\n", sum, total - sum);
		return total - sum > sum ? (total - sum - sum) : ( sum + sum - total);
	}

	last_index = m - toPick - 1;

	if(m == toPick)
		smallest = 0;
	else 
		smallest = bucket[last_index] + 1;

	min = total;
	for(i=smallest; i<n; i++) {
		bucket[last_index+1] = i;
		ret = pick(arr, n, bucket, m, toPick -1, total);
		if(min > ret)
			min = ret;
	}
	return min;
}

int main() {
	int N, i;
	int *arr;
	int *bucket;
	int total = 0;

	scanf("%d", &N);

	bucket = (int*)malloc(sizeof(int)*N/2);
	arr = (int*)malloc(sizeof(int)*N);

	for(i=0; i<N; i++) {
		scanf("%d", &arr[i]);
		total = total + arr[i];
	}

	bucket[0] = 0;
	printf("%d\n", pick(arr, N, bucket, N/2, N/2 - 1, total));

	free(bucket);
	return 0;
}
