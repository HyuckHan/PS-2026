#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int selection(int *arr, int p, int r, int t){
	int rank ;
	int q = partition(arr,p,r);
	rank = q - p + 1;

	if(rank == t)
		return arr[q];
	else if(t<rank)
		return selection(arr,p,q-1,t);
	else 
		return selection(arr,q+1,r,t-rank);
}

void print_array(int *arr, int n){
	int i;
	for(i=0; i<n; i++)
		printf("%d%c", arr[i], i<n-1?' ':'\n');
}

int main(int argc, char** argv) {
	int n;
	int i, t;
	int *arr;

	srand(time(NULL));
	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int)*n);

	for(i=0; i<n; i++){ 
		arr[i] = rand() % 10000;
	}


	print_array(arr, n);

	scanf("%d", &t);

	printf("%d\n", selection(arr,0,n-1,t));

	free(arr);
	return 0;

}
