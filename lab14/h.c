#include <stdio.h>
#include <stdlib.h>

int h(int n) {
	int i, ret;
	if(n == 1 || n == 0) 
		return 1;

	ret = 0;
	for(i=0; i<n; i++) {
		ret = ret + h(i) * h(n-i-1);
	}
	return ret;
	
}
int main() {
	int n = 19; 
	printf("%d\n",h(n));
	return 0;
}
