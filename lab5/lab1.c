#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

	free(arr);
	return 0;
}
