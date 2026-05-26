#include <stdio.h>
#include <stdlib.h>

int comb_memo1(int n, int r, int **M) {
	if( r == 0 || r == n ) 
		return 1;
	else {
		if(M[n-1][r-1] == 0)
			M[n-1][r-1] = comb_memo1(n-1, r-1, M);
		
		if(M[n-1][r] == 0)
			M[n-1][r] = comb_memo1(n-1, r, M);
		return M[n-1][r-1] + M[n-1][r];
	}
}

int comb_memo2(int n, int r, int **M) {
	if(M[n][r] != 0)
		return M[n][r];
	if( r == 0 || r == n ) 
		return 1;
	else {
		M[n][r] = comb_memo2(n-1, r-1, M) + comb_memo2(n-1, r, M);
		return M[n][r];
	}
}

int main(void) {
	int C,i,j;
	int **M;
	int r,n;
	n = 31;
	r = 15;

	M = (int**)malloc(sizeof(int*)*(n+1));
	for(i=0; i<n+1; i++)
		M[i] = (int*)malloc(sizeof(int)*(r+1));

	for(i=0; i<n+1; i++)
		for(j=0; j<r+1; j++)
			M[i][j] = 0;
	C = comb_memo1(n,r,M); 
	printf("%d\n", C);

	for(i=0; i<n+1; i++)
		for(j=0; j<r+1; j++)
			M[i][j] = 0;
	C = comb_memo2(n,r,M); 
	printf("%d\n", C);

	for(i=0; i<n+1; i++)
		free(M[i]);
	free(M);

	return 0;
}
