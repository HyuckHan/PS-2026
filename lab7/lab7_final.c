#include <stdio.h>
#include <stdlib.h>

int pick(int *items, int n, int *bucket, int m, int toPick, int target) {
	int i, smallest, lastIndex, sum;

	if(toPick == 0) {
		sum = 0;
		for(i=0; i<m; i++){
			sum = sum + items[bucket[i]];
			//printf("%d%c", items[bucket[i]], i<m-1?' ':'\n');
		}
		return sum == target?1:0;
	}

	lastIndex = m - toPick - 1;

	sum = 0;
	for(i=0; i<=lastIndex; i++)
		sum = sum + items[bucket[i]];
	
	//Bound
	if(sum == target)
		return 1;
	else if(sum > target)
		return 0;


	if(m == toPick) 
		smallest = 0;
	else
		smallest = bucket[lastIndex];

	sum = 0;
	for(i=smallest; i<n; i++) { 
		bucket[lastIndex+1] = i;
		//Branch
		sum = sum + pick(items, n, bucket, m, toPick - 1, target);
	}
	return sum;
}

int main() {
	int N;
	int items[3] = {1000, 5000, 10000};
	int *bucket;

	scanf("%d", &N);
	bucket = (int*)malloc(sizeof(int)*(N/1000));

	printf("%d\n", pick(items, 3, bucket, N/1000, N/1000, N));
	free(bucket);
	return 0;
}

