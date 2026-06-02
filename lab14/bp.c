#include <stdio.h>
#include <stdlib.h>

#define START 0
#define LEFT 1
#define UP 2

void print_path(int **bp, int i, int j) {
	if(i==0 && j==0) {
		printf("<0,0>");
		return;
	}
	
	if(bp[i][j]==UP)
		print_path(bp, i-1, j);
	else
		print_path(bp, i, j-1); 
	printf(" -> <%d,%d>", i, j);
}

int matrixPath_memo(int **m, int r, int c, int i, int j, 
		int **M, int **M2, int **bp ) {
        if ( M2[i][j] != 0 ) 
		return M[i][j];

        if ( i == 0 && j == 0 ) return m[i][j];
        else if ( i == 0 ) {
		M[i][j] = matrixPath_memo(m,r,c,0,j-1,M,M2,bp)+ m[i][j];
		bp[i][j] = LEFT;
	}
        else if ( j == 0 ) {
		M[i][j] = matrixPath_memo(m,r,c,i-1,0,M,M2,bp)+ m[i][j];
		bp[i][j] = UP;
	}
        else {
                int a,b;
                a = matrixPath_memo(m,r,c,i-1,j,M,M2,bp); //UP
                b = matrixPath_memo(m,r,c,i,j-1,M,M2,bp); //LEFT
                M[i][j] = ((a<b)? a:b) + m[i][j];
		bp[i][j] = (a<b)? UP:LEFT;
        }
	M2[i][j] = 1; //계산 O
	return M[i][j];
}

int main() {
	int **m, **M, **M2, **bp;
	int i, j, r, c;
	r = c = 4; // 4x4 matrix
	m = (int**) malloc( sizeof(int*) * r);
	M = (int**) malloc( sizeof(int*) * r); //중간 계산 결과 저장
	M2 = (int**) malloc( sizeof(int*) * r); //계산 여부만 표시
	bp = (int**) malloc( sizeof(int*) * r); //BP
	for(i = 0; i < r; i++ ){
		m[i] = (int*) malloc(sizeof(int) * c);
		M[i] = (int*) malloc(sizeof(int) * c);
		M2[i] = (int*) malloc(sizeof(int) * c);
		bp[i] = (int*) malloc(sizeof(int) * c);
	}
	for(i = 0; i < r; i++)
		for(j = 0; j < c; j++) {
			scanf("%d", &m[i][j] );
			M[i][j] = 0;
			M2[i][j] = 0; //계산 X
			bp[i][j] = START;
		}
	
	printf("%d\n", matrixPath_memo(m, r, c, 3, 3, M, M2, bp) );

	for(i = 0; i < r; i++){
		for(j = 0; j < c; j++) {
			printf("%d ", bp[i][j]);
		}
		printf("\n");
	}

	print_path(bp, 3, 3);
	printf("\n");

	for(i = 0; i < r; i++ ) {
		free(m[i]);
		free(M[i]);
		free(M2[i]);
	}
	free(m);
	free(M);
	free(M2);
	return 0;
}
