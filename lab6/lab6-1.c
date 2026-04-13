#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion_sort(int *arr, int n) {
	int i,j,k,temp;

	for(i=1; i<n; i++) {
		for(j=0; j<i; j++)
			if( arr[j] > arr[i] ) break;
		temp = arr[i];
		for(k=i; k>j; k--)
			arr[k] = arr[k-1];
		arr[j] = temp;

		/*
		for(k=i; k>j; k--) {
			if( arr[k-1] > arr[k] ) {
				temp = arr[k];
				arr[k] = arr[k-1];
				arr[k-1] = temp;
			}
			else
				break;
		}
		*/
	}
	
}

void print_array(int *arr, int n){
	int i;
	for(i=0; i<n; i++)
		printf("%d%c", arr[i], i<n-1?' ':'\n');
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
	print_array(arr,n);
	
	insertion_sort(arr, n);
	print_array(arr,n);	
	
	free(arr);
	return 0;

}
