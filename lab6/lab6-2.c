#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int *arr, int p, int q, int r, int *temp_arr) { 
	int i,j,t;
	i=p;
	j=q+1;
	t=p;
	while( i<=q && j<=r ) {
		if(arr[i] < arr[j]) {
			temp_arr[t] = arr[i];
			t++; i++;
		}
		else {
			temp_arr[t] = arr[j];
			t++; j++;
		}
	}
	if( i>q ) {
		for( ; j<=r; j++, t++)
			temp_arr[t] = arr[j];
	}
	else {
		for( ; i<=q; i++, t++)
			temp_arr[t] = arr[i];
	}
	for(i=p; i<=r; i++ ) {
		arr[i] = temp_arr[i];
	}
}

void merge_sort(int *arr, int p, int r, int *temp_arr) { 
	if(p<r) {
		int q = (p+r)/2;
		merge_sort(arr, p, q, temp_arr);
		merge_sort(arr, q+1, r, temp_arr);
		merge(arr, p, q, r, temp_arr);
	}
}

void print_array(int *arr, int n){
	int i;
	for(i=0; i<n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main(int argc, char** argv) {
	int n;
	int i;
	int *arr, *temp_arr;

	srand(time(NULL));
	scanf("%d", &n);	
	arr = (int*)malloc(sizeof(int)*n);
	temp_arr = (int*)malloc(sizeof(int)*n);

	for(i=0; i<n; i++){
		arr[i] = rand() % 10000;
	}
	print_array(arr,n);
	
	merge_sort(arr, 0, n-1, temp_arr);
	print_array(arr,n);	
	
	free(arr);
	free(temp_arr);
	return 0;

}
