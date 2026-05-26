#include <stdio.h>
#include <stdlib.h>

int fib_memo2(int n, int *M) {
	if(M[n] != 0)
		return M[n];
		
	if( n == 1 || n == 2 ) 
		return 1;
	else {
		M[n] = fib_memo2(n-1, M) + fib_memo2(n-2, M);
		return M[n];
	}
}

int fib_memo1(int n, int *M) {
	if( n == 1 || n == 2 ) 
		return 1;
	else {
		if(M[n-1] == 0)
			M[n-1] = fib_memo1(n-1, M);
		if(M[n-2] == 0)
			M[n-2] = fib_memo1(n-2, M);
		return M[n-1] + M[n-2];
	}
}

int main() {
	int n,i;
	int *M;

	n = 44;
	M = (int*)malloc(sizeof(int)*(n+1));

	for(i=0; i<n+1; i++)
		M[i] = 0;
	printf("%d\n", fib_memo1(n, M) );

	for(i=0; i<n+1; i++)
		M[i] = 0;
	printf("%d\n", fib_memo2(n, M) );

	free(M);

	return 0;
}
