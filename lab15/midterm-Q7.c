#include <stdio.h>
#include <stdlib.h>

int pick(int *arr, int n, int *bucket, int m, int toPick, int K) {
	int i, j, flag, last_index, smallest, ret; 
	int sum = 0;

	if(toPick == 0) {
		for(i=0; i<m; i++) {
			printf("%d ", arr[bucket[i]]);
			sum = sum + arr[bucket[i]];
		}
		printf("%d ", sum);

		if(sum == K) {
			printf("1\n");
			return 1;
		}
		else {
			printf("0\n");
			return 0;
		}
	}

	last_index = m - toPick - 1;
	
	sum = 0;
	for(i=0; i<=last_index; i++) {
		sum = sum + arr[bucket[i]];
	}

	if(sum>K)
		return 0;

	if(m == toPick)
		smallest = 0;
	else
		smallest = bucket[last_index];

	ret = 0;
	for(i=smallest; i<n; i++) {
		bucket[last_index+1] = i;
		ret = ret + pick(arr, n, bucket, m, toPick -1, K);
	} 
	return ret;
}

int main() {
	int N, K, i;
	int *arr;
	int *bucket;
	int sum ;
	int min_k = 1000;

	scanf("%d", &N);
	scanf("%d", &K);

	arr = (int*)malloc(sizeof(int)*N);
	//bucket = (int*)malloc(sizeof(int)*K);

	for(i=0; i<N; i++) {
		scanf("%d", &arr[i]);
		min_k = (min_k>arr[i])?arr[i]:min_k;
	}
	bucket = (int*)malloc(sizeof(int)*(K/min_k));

	sum = 0;
	for(i=1; i<=K/min_k; i++)
		sum = sum + pick(arr, N, bucket, i, i, K);

	printf("%d\n", sum);

	free(arr);
	free(bucket);
	return 0;
}
