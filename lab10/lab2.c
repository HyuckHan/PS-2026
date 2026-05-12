#include <stdio.h>
#include <stdlib.h>
void matrixAdd(int **a, int **b, int **x, int r, int c) {
	int i,j;
	for(i=0; i<r; i++) 
		for(j=0; j<c; j++)
			x[i][j] = a[i][j] + b[i][j];
}

void printMatrix(int **a, int r, int c) {
	int i,j;
	for(i=0; i<r; i++) 
		for(j=0; j<c; j++)
			printf("%d%c", a[i][j], j<c-1?' ':'\n');
}
void readMatrix(int **a, int r, int c) {
	int i,j;
	for(i=0; i<r; i++) 
		for(j=0; j<c; j++)
			scanf("%d", &a[i][j]);
}
int main(void)
{
	int **A, **B;
	int **X; // A + B
	int aRow, aCol;
	int i;

	scanf("%d %d", &aRow, &aCol);

	A = (int**)malloc(sizeof(int*)*aRow);
	B = (int**)malloc(sizeof(int*)*aRow);
	X = (int**)malloc(sizeof(int*)*aRow);

	for(i=0; i<aRow ; i++) {
		A[i] = (int*)malloc(sizeof(int)*aCol);
		B[i] = (int*)malloc(sizeof(int)*aCol);
		X[i] = (int*)malloc(sizeof(int)*aCol);
	}

	readMatrix(A,aRow,aCol);
	readMatrix(B,aRow,aCol);
	matrixAdd(A, B, X, aRow, aCol);
	printf("Matrix Addtion:\n"); 
	printMatrix(X, aRow, aCol); printf("\n");

	for(i=0; i<aRow ; i++) {
		free(A[i]);
		free(B[i]);
		free(X[i]);
	}
	free(A); free(B); free(X);
	return 0;
}

