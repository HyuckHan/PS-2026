#include <stdio.h>
#include <stdlib.h>

int pick(int n, int *bucket, int m, int toPick, int L) {
	int i, j, flag, last_index, smallest, count, ret;

	if(toPick == 0) {
		count = 0;
		for(i=0; i<m; i++) {
			printf("%d ", bucket[i] + 1);
			if( (bucket[i]+1)%2 == 0)
				count++;
		}
		printf("%d\n", count>=L?1:0);
		return count >= L? 1:0;
	}

	last_index = m - toPick - 1;

	count = 0;
	for(i=0; i<=last_index; i++) {
		if( (bucket[i]+1)%2 == 0)
			count++;
	}
	if(count+toPick<L)
		return 0;

	if(m == toPick)
		smallest = 0;
	else 
		smallest = bucket[last_index] + 1;

	ret = 0;
	for(i=smallest; i<n; i++) {
		bucket[last_index+1] = i;
		ret = ret + pick(n, bucket, m, toPick -1, L);
	}
	return ret;
}

int main() {
	int N, M, L, i;
	int *arr;
	int *bucket;

	scanf("%d", &N);
	scanf("%d", &M);
	scanf("%d", &L);

	bucket = (int*)malloc(sizeof(int)*M);

	printf("%d\n", pick(N, bucket, M, M, L));

	free(bucket);
	return 0;
}
