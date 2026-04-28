#include <stdio.h>
#include <stdlib.h>

struct two_number {
	int original_number;
	int reverse_number;
};

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

int partition(struct two_number *arr, int p, int r) {
	int i,j;
	struct two_number temp;

	for(i=p-1, j=p; j<r; j++){
		if(arr[j].reverse_number < arr[r].reverse_number){
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		else if(arr[j].reverse_number == arr[r].reverse_number){
			if(arr[j].original_number < arr[r].original_number){
				i++;
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	i++;
	temp = arr[i];
	arr[i] = arr[r];
	arr[r] = temp;
	return i;
}

void quick_sort(struct two_number *arr, int p, int r){
	if(p<r){
		int q = partition(arr,p,r);
		quick_sort(arr, p, q-1);
		quick_sort(arr, q+1, r);
	}
}

void print_array(struct two_number *arr, int n){
	int i;
	for(i=0; i<n; i++)
		printf("%d%c", arr[i].original_number, i<n-1?' ':'\n');
}

int main(int argc, char** argv) {
	int n;
	int i;
	struct two_number *arr;

	scanf("%d", &n);
	arr = (struct two_number*)malloc(sizeof(struct two_number)*n);

	for(i=0; i<n; i++){
		scanf("%d", &arr[i].original_number);
		arr[i].reverse_number = get_reverse_number(arr[i].original_number);
	}
	
	quick_sort(arr, 0, n-1);

	print_array(arr, n);

	free(arr);
	return 0;

}
