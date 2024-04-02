#include <stdio.h>

// 0表示素数，1表示合数
void init_prime(int *arr, int n) {
	printf("start------------\n");
	arr[0] = 1;
	for(int i = 2; i * i <= n; i++) {
		for(int j = 2; j * i <= n; j++){
			arr[i * j] = 1;
		}
	}
	for(int i = 0; i <= 100; i++) {
		printf("%d ", arr[i]);
		if (i % 10 == 0) {
			printf("\n");
		}
	}
	printf("end------------\n");

	return;
}

int main() {
	int arr[100] = { 0 };
	init_prime(arr, 100);

	int num;
	while(scanf("%d", &num) != EOF) {
		printf("Is Prime?\n");
		if(arr[num]) {
			printf("NO\n");
		} else {
			printf("YES\n");
		}
	}
	return 0;
}
