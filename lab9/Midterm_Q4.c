#include <stdio.h>
#include <stdlib.h>

struct two_number {
	int number;
	int freq;
};

int freq_arr[1001] = {0,};

int partition(struct two_number *arr, int p, int r) {
	int i,j;
	struct two_number temp;

	for(i=p-1, j=p; j<r; j++){
		if(arr[j].freq > arr[r].freq){
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		else if(arr[j].freq == arr[r].freq){
			if(arr[j].number < arr[r].number){
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
		printf("%d%c", arr[i].number, i<n-1?' ':'\n');
}

int main(int argc, char** argv) {
	int n;
	int i;
	struct two_number *arr;

	scanf("%d", &n);
	arr = (struct two_number*)malloc(sizeof(struct two_number)*n);

	for(i=0; i<n; i++){
		scanf("%d", &arr[i].number);
		freq_arr[arr[i].number]++;
	}

	for(i=0; i<n; i++){
		arr[i].freq = freq_arr[arr[i].number];
	}

	quick_sort(arr, 0, n-1);
	print_array(arr,n);

	free(arr);
	return 0;

}
