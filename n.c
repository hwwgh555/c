#include <stdio.h>

void printf_line(int *arr, int n) {
	for(int i = 0; i < n; i++) {
		if(i) printf(" ");
		printf("%d", arr[i]);
	}
	return;
}
void f(int i, int n, int *arr) {
	if(i == n) {
		printf_line(arr, n);
		printf("\n");
		return;
	}
	for(int k = i + 1; k <= n; k++) {
		arr[i] = k;
		f(i + 1, k + 1, n);
	}
	return;
}

int main() {
	int n;
	scanf("%d", &n);

	int arr[n];
	f(0, n, arr);
	return 0;
}
