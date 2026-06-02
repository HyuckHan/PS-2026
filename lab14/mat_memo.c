#include <stdio.h>
#include <stdlib.h>

int matrixPath_memo2(int **m, int r, int c, int i, int j, int **M, int **M2 ) {
        if ( M2[i][j] != 0 ) 
		return M[i][j];

        if ( i == 0 && j == 0 ) return m[i][j];
        else if ( i == 0 ) M[i][j] = matrixPath_memo2(m,r,c,0,j-1,M,M2)+ m[i][j];
        else if ( j == 0 ) M[i][j] = matrixPath_memo2(m,r,c,i-1,0,M,M2)+ m[i][j];
        else {
                int a,b;
                a = matrixPath_memo2(m,r,c,i-1,j,M,M2);
                b = matrixPath_memo2(m,r,c,i,j-1,M,M2);
                M[i][j] = ((a<b)? a:b) + m[i][j];
        }
	M2[i][j] = 1; //계산 O
	return M[i][j];
}

int matrixPath_memo1(int **m, int r, int c, int i, int j, int **M, int **M2 ) {
	if ( i == 0 && j == 0 ) return m[i][j];
	else if (i == 0) {
		if (M2[0][j-1] == 0) {
			M[0][j-1] = matrixPath_memo1(m,r,c,0,j-1,M,M2);
			M2[0][j-1] = 1; //계산 O
		}
		return M[0][j-1] + m[i][j];;
	}
	else if (j == 0) {
		if (M2[i-1][0] == 0) {
			M[i-1][0] = matrixPath_memo1(m,r,c,i-1,0,M,M2);
			M2[i-1][0] = 1; //계산 O
		}
		return M[i-1][0] + m[i][j];
	}
	else {
		if (M2[i-1][j] == 0) {
			M[i-1][j] = matrixPath_memo1(m,r,c,i-1,j,M,M2);
			M2[i-1][j] = 1; //계산 O
		}
		if (M2[i][j-1] == 0) {
			M[i][j-1] = matrixPath_memo1(m,r,c,i,j-1,M,M2);
			M2[i][j-1] = 1; //계산 O
		}
		return (M[i-1][j] < M[i][j-1] ? M[i-1][j]: M[i][j-1]) + m[i][j];
	}
}

int main() {
	int **m, **M, **M2;
	int i, j, r, c;
	r = c = 4; // 4x4 matrix
	m = (int**) malloc( sizeof(int*) * r);
	M = (int**) malloc( sizeof(int*) * r);
	M2 = (int**) malloc( sizeof(int*) * r); //계산 유무만 표시
	for(i = 0; i < r; i++ ){
		m[i] = (int*) malloc(sizeof(int) * c);
		M[i] = (int*) malloc(sizeof(int) * c);
		M2[i] = (int*) malloc(sizeof(int) * c);
	}
	for(i = 0; i < r; i++)
		for(j = 0; j < c; j++) {
			scanf("%d", &m[i][j] );
			M[i][j] = 0;
			M2[i][j] = 0; //계산 X
		}
	printf("%d\n", matrixPath_memo1(m, r, c, 3, 3, M, M2) );

	for(i = 0; i < r; i++)
		for(j = 0; j < c; j++) {
			M[i][j] = 0;
			M2[i][j] = 0; //계산 X
		}
	printf("%d\n", matrixPath_memo2(m, r, c, 3, 3, M, M2) );

	printf("%d %d\n", M[1][1], M2[1][1]);

	for(i = 0; i < r; i++ ) {
		free(m[i]);
		free(M[i]);
	}
	free(m);
	free(M);
	return 0;
}
