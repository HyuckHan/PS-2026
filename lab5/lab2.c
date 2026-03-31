#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selection_sort(int *arr, int n) {
	int i, j, max_idx, temp;

	for(i=0; i<n-1; i++) {
		max_idx = 0;
		for(j=1; j<n-i; j++) {
			if(arr[j]>arr[max_idx]) {
				max_idx = j;
			}
		}
		temp = arr[n-i-1];
		arr[n-i-1] = arr[max_idx];
		arr[max_idx] = temp;
	}
}

int main(int argc, char** argv) {
	int n;
	int i;
	int *arr;

	srand(time(NULL));
	scanf("%d", &n);	
	arr = (int*)malloc(sizeof(int)*n);

	for(i=0; i<n; i++){
		arr[i] = rand() % 10000;
	}

	for(i=0; i<n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");

	selection_sort(arr, n);

	for(i=0; i<n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");	
	free(arr);
	return 0;
}
