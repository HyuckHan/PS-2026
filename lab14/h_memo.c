#include <stdio.h>
#include <stdlib.h>

int h_memo2(int n, int *m) {
	int i, ret;

	if(m[n] != 0)
		return m[n];

	if(n == 1 || n == 0)
		return 1;

	ret = 0;
	for(i=0; i<n; i++) {
		ret = ret + h_memo2(i, m) * h_memo2(n-i-1, m);
	}

	m[n] = ret;
	return ret;
}

int h_memo1(int n, int *m) {
	int i, ret;
	int a, b;
	if(n == 1 || n == 0) 
		return 1;

	ret = 0;
	for(i=0; i<n; i++) {
		if(m[i] == 0) 
			m[i] = h_memo1(i, m);

		if(m[n-i-1] == 0) 
			m[n-i-1] = h_memo1(n-i-1, m);

		ret = ret + m[i] * m[n-i-1];
	}
	return ret;
	
}

int main() {
	int i;
	int n = 19; 
	int *m;

	m = (int*) malloc(sizeof(int)*(n+1));
	for(i=0; i<=n; i++)
		m[i] = 0;
	printf("%d\n",h_memo1(n,m));

	for(i=0; i<=n; i++)
		m[i] = 0;
	printf("%d\n",h_memo2(n,m));
	return 0;
}
