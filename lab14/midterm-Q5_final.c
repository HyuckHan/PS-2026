#include <stdio.h>
#include <stdlib.h>

int pick(int *arr, int n, int *bucket, int m, int toPick, int *nums, int K) {
	int i, last_index, smallest, sum, ret, max;

	if(toPick == 0) {
		for(i=0; i<m; i++) {
			printf("%d ", arr[bucket[i]]);
		}

		sum = 0;
		for(i=0; i<m; i++) {
			if( arr[bucket[i]] == 1)
				sum = sum + nums[i];
		} 
		printf("%d\n", sum);

		if(sum < K)
			return sum;
		return 0;
	}

	last_index = m - toPick - 1;

	max = 0;
	for(i=0; i<n; i++) {
		bucket[last_index+1] = i;
		ret = pick(arr, n, bucket, m, toPick -1, nums, K);
		if(ret < K && max < ret)
			max = ret;
	}
	return max;
}

int main() {
	int N, K, i;
	int *arr;
	int *bucket;
	int items[2] = {0, 1};

	scanf("%d", &N);
	scanf("%d", &K);

	arr = (int*)malloc(sizeof(int)*N);
	bucket = (int*)malloc(sizeof(int)*N);

	for(i=0; i<N; i++) 
		scanf("%d", &arr[i]);

	printf("%d\n", pick(items, 2, bucket, N, N, arr, K));

	free(arr);
	free(bucket);
	return 0;
}
