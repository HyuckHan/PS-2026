#include <stdio.h>
#include <stdlib.h>

void pick(int *arr, int n, int *bucket, int m, int toPick){
	int i, j, flag, last_index, smallest, sum;

	if(toPick == 0) {
		sum = 0;
		for(i=0; i<m; i++) {
			printf("%d ", arr[bucket[i]]);
			sum = sum + arr[bucket[i]];
		}
		printf("= %d\n", sum);
		return;
	}

	last_index = m - toPick - 1;

	if(m == toPick)
		smallest = 0;
	else 
		smallest = bucket[last_index] + 1;

	for(i=smallest; i<n; i++) {
		bucket[last_index+1] = i;
		pick(arr, n, bucket, m, toPick -1);
	}
}

int main() {
	int N, i;
	int *arr;
	int *bucket;

	scanf("%d", &N);

	bucket = (int*)malloc(sizeof(int)*N/2);
	arr = (int*)malloc(sizeof(int)*N);

	for(i=0; i<N; i++) 
		scanf("%d", &arr[i]);

	pick(arr, N, bucket, N/2, N/2);

	free(bucket);
	free(arr);
	return 0;
}
