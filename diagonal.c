#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", n);
	char arr[n][30 * 3 + 5];
	for(int i = 0; i < n; i++) {
		scanf("%[\n]", arr[i]);
		printf("%s\n", arr[i]);
		getchar();
	}
	/*
	for(int i = 0; i < n; i++) {
		printf("%s\n", arr[i]);
	}
	*/
	return 0;
}
