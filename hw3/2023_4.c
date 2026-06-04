#include <stdio.h>
#include <string.h>

int char_class(char c) {
	if ('A' <= c && c <= 'Z') return 0;  // 대문자
	if ('a' <= c && c <= 'z') return 1;  // 소문자
	return 2;                            // 숫자
}

int partition(char *arr, int p, int r) {
        int i,j;
        char temp;

        for(i=p-1, j=p; j<r; j++){
                if(char_class(arr[j]) == char_class(arr[r]) &&
			arr[j] < arr[r]) {
                        i++;
                        temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                }
		else if(char_class(arr[j]) < char_class(arr[r])) {
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

void quick_sort(char *arr, int p, int r){
        if(p<r){
                int q = partition(arr,p,r);
                quick_sort(arr, p, q-1);
                quick_sort(arr, q+1, r);
        }
}

int main() {
	char str[500001];

	scanf("%s", str);

	int len = strlen(str);

	quick_sort(str, 0, len - 1);

	printf("%s\n", str);

	return 0;
}
