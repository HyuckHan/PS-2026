#include <stdio.h>
#include <stdlib.h>

int isLang(int a[], int n) { 
	int *count;
	int *first;
	int i, k;

	count = (int*)malloc(sizeof(int)*(n/2+1));
	first = (int*)malloc(sizeof(int)*(n/2+1));

	for(i=0; i<=n/2; i++) {
		count[i] = 0;
		first[i] = 0;
	}

	for(i=0; i<n; i++) {
		k = a[i];

		if(k<1 || k>n) {
			free(count);
			free(first);
			return 0;
		}

		count[k]++;

		if(count[k] == 1) {
			first[k] = i;
		}
		else if(count[k] == 2) {
			if(i - first[k] - 1 != k) {
				free(count);
				free(first);
				return 0;
			}

		} else { 
			free(count);
			free(first);
			return 0;
		}
	}

	for (i = 1; i <= n/2; i++) {
		if (count[i] != 2) {
			free(count);
			free(first);
			return 0;

		}
	}

	free(count);
	free(first);
	return 1;
}

int main(void) { // 변경하지 말라
	int i, k;
	int n;
	int *a;
	scanf("%d", &n);
	a = (int*)malloc(sizeof(int) * 2 * n);
	for (k = 0; k < 4; k++) {
		for (i = 0; i < 2 * n; i++)
			scanf("%d", &a[i]);
		printf("%d\n", isLang(a, 2 * n));
	}
	free(a);
	return 0;
}
