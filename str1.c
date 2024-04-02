#include <stdio.h>
#include <stdlib.h>

int main() {
	int n = 3;
	char* arr[n];
	for(int i = 0; i < n; i++) {
		arr[i] = (char *)malloc(sizeof(char) * 30 * 4);
	}
	/*
	arr[0] = (char *)malloc(sizeof(char) * 30 * 4);
	arr[1] = (char *)malloc(sizeof(char) * 30 * 4);
	*/

	arr[0] = "hello world";
	arr[1] = "hello world";
	printf("%s\n", arr[0]);
	printf("%s\n", arr[1]);

	return 0;
}
