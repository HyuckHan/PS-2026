#include <stdio.h>
#include <stdlib.h>

void pick(int *arr, int n, int *bucket, int m, int toPick) {
	int i, j, flag, last_index, smallest;

	if(toPick == 0) {
		for(i=0; i<m; i++) {
			printf("%d%c", arr[bucket[i]], i==(m-1)? '\n':' '); 
		}
		return;
	}

	last_index = m - toPick - 1;

	for(i=0; i<n; i++) {
		flag = 0;
		for(j=0; j<=last_index; j++) {
			if(bucket[j] == i) {
				flag = 1;
				break;
			}
		}
		if(flag == 1) continue;
			
		bucket[last_index+1] = i;
		pick(arr, n, bucket, m, toPick -1);
	}
}

int main() {
	int N, K, i;
	int *arr;
	int *bucket;

	scanf("%d", &N);
	scanf("%d", &K);

	arr = (int*)malloc(sizeof(int)*N);
	bucket = (int*)malloc(sizeof(int)*K);

	for(i=0; i<N; i++) 
		scanf("%d", &arr[i]);

	pick(arr, N, bucket, K, K);

	free(arr);
	free(bucket);
	return 0;
}
