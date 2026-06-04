#include <stdio.h>
#include <stdlib.h>

void pick(int n, int *bucket, int m, int toPick) {
	int i, j, flag, last_index, smallest, sum;

	if(toPick == 0) {
		for(i=0; i<m; i++) {
			printf("%d(%c) ", bucket[i]+1, 'A'+i);
		}
		printf("\n");
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
		if(flag == 1)
			continue;

		bucket[last_index+1] = i;
		pick(n, bucket, m, toPick -1);
	}
}

int main() {
	int N, i;
	int bucket[5];

	pick(5, bucket, 5, 5);

	return 0;
}
