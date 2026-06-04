#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int make_number(int *bucket, int m, char *s) {
	int i;
	int len;
	int ret;

	len = strlen(s);
	
	ret = 0;
	for(i=0; i<len; i++) {
		ret = ret * 10 + bucket[(s[i] - 'A')] + 1;
	}
	return ret;
}

int pick(int n, int *bucket, int m, int toPick, char* s1, char* s2) {
	int i, j, flag, last_index, smallest, sum, max, ret;

	if(toPick == 0) {
		for(i=0; i<m; i++) {
			printf("%d(%c) ", bucket[i]+1, 'A'+i);
		}
		printf("%d %d\n", make_number(bucket, m, s1), make_number(bucket, m, s2));

		sum = make_number(bucket, m, s1) + make_number(bucket, m, s2);
		return sum;
	}

	last_index = m - toPick - 1;

	max = 0;
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
		ret = pick(n, bucket, m, toPick -1, s1, s2);
		if(max<ret)
			max = ret;
	}
	return max;
}

int main() {
	int N, i;
	int bucket[5];
	char s1[9];
	char s2[9];

	scanf("%s", s1);
	scanf("%s", s2);

	printf("%d\n", pick(5, bucket, 5, 5, s1, s2));

	return 0;
}
