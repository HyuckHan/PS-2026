#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int *arr, int n) {
	int i, j, temp;

	for(i=0; i<n-1; i++) {
		for(j=0; j<n-i-1; j++) {
			if(arr[j]>arr[j+1]) {
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
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
		arr[i] = rand()%10000;
	}

	for(i=0; i<n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");

	bubble_sort(arr, n);

	for(i=0; i<n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");	
	free(arr);
	return 0;
}
