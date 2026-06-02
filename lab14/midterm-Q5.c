#include <stdio.h>
#include <stdlib.h>

void pick(int *arr, int n, int *bucket, int m, int toPick) {
	int i, last_index, smallest;

	if(toPick == 0) {
		for(i=0; i<m; i++) {
			printf("%d%c", arr[bucket[i]], i==(m-1)? '\n':' '); 
		}
		return;
	}

	last_index = m - toPick - 1;

	for(i=0; i<n; i++) {
		bucket[last_index+1] = i;
		pick(arr, n, bucket, m, toPick -1);
	}
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

	pick(items, 2, bucket, N, N);

	free(arr);
	free(bucket);
	return 0;
}
