#include <stdio.h>
#include <stdlib.h>

int make_number(int *items, int n, int *bucket, int m) {
	int number = 0;
	int i;

	for(i=0; i<m; i++)
		number = number*10 + items[bucket[i]];
	return number;
}

int pick(int *items, int n, int *bucket, int m, int toPick, int total) {
	int i, smallest, lastIndex, j, flag, sum, lastSelect;

	if(toPick == 0) {
		int number = make_number(items, n, bucket, m);

		sum = 0;
		for(i=0; i<m; i++) 
			sum = sum + items[bucket[i]];
		printf("%d %d %d\n", number, (total-sum), (number % (total-sum)==0));
		return (number % (total-sum)==0);
	}

	lastIndex = m - toPick - 1;

	sum = 0;

	lastSelect = -1;

	for(i=0; i<n; i++) {
		flag = 0;
		for(j=0; j<=lastIndex; j++) {
			if(bucket[j] == i)
				flag = 1;
		}
		if(flag == 1)
			continue;

		if(items[i]==lastSelect)
			continue;

		lastSelect = items[i];
		bucket[lastIndex+1] = i;
		sum = sum + pick(items, n, bucket, m, toPick - 1, total);
	}

	return sum;
}

int main() {
	int N, i, j, temp;
	int *items;
	int *bucket;
	int total = 0;

	scanf("%d", &N);
	items = (int*)malloc(sizeof(int)*N);
	bucket = (int*)malloc(sizeof(int)*(N-1));
	for (i = 0; i < N; i++) {
		scanf("%d", &items[i]);
		total = total + items[i];
	}

	for (i = 0; i < N-1; i++) {
		for (j = 0; j < N-i-1; j++) {
			if(items[j]>items[j+1]) {
				temp = items[j];
				items[j] = items[j+1];
				items[j+1] = temp;
			}
		}
	}

	printf("%d\n", pick(items, N, bucket, N-1, N-1, total));
	free(items);
	free(bucket);
	return 0;
}
