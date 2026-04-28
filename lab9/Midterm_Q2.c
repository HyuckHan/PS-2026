#include <stdio.h>
#include <stdlib.h>

int get_reverse_number(int n) {
	int ret;
	ret = 0;

	while( n != 0 ) {
		int remainder_n;

		remainder_n = n % 10;
		n = n / 10;

		ret = ret * 10 + remainder_n;
	}
	return ret;
}

int partition(int *arr, int p, int r) {
	int i,j;
	int temp;

	for(i=p-1, j=p; j<r; j++){
		if(arr[j] < arr[r]) {
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}

	i++;
	temp = arr[i];
	arr[i] = arr[r];
	arr[r] = temp;
	return i;
}

void quick_sort(int *arr, int p, int r){
	if(p<r){
		int q = partition(arr,p,r);
		quick_sort(arr, p, q-1);
		quick_sort(arr, q+1, r);
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

	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int)*n);

	for(i=0; i<n; i++){
		scanf("%d", &arr[i]);
		arr[i] = get_reverse_number(arr[i]);
	}
	
	quick_sort(arr, 0, n-1);

	print_array(arr, n);

	free(arr);
	return 0;

}
