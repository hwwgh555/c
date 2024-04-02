#include <stdio.h>
#include <stdlib.h>

struct Str3{
	char str[30 * 3 + 5];
};


void mp(int start, char* str) {
	int end = start + 2;
	for(int i = start; i <= end; i++) {
		printf("%c", str[i]);
	}
	printf("\n");
	return;
}

int main() {
	int n;
	scanf("%d", &n);
	getchar();

	char* arr[n];
	
	for(int i = 0; i < n; i++) {
		arr[i] = (char *)malloc(sizeof(char) * n * 5);
	}
	
	for(int i = 0; i < n; i++) {
				printf("i = %d\n", i);
		scanf("%[^\n]s", arr[i]);
		printf("%s\n", arr[i]);
		//printf("%c\n", arr[i][0]);
		getchar();
	}
	
	
	for(int i = 0; i < n; i++) {
		// printf("%s", arr[i]);
		// mp(i*4, arr[i]);
	}
	
	 
	return 0;
}
