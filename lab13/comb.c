#include <stdio.h>
#include <stdlib.h>

int comb(int n, int r) {
	if( r == 0 || r == n ) 
		return 1;
	else
		return comb(n-1, r-1) + comb(n-1, r);
}

int main(void) {
	int C;
	C = comb(31,15); // 31C15
	printf("%d\n", C);
	return 0;
}
