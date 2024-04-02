#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void get_random(int* arr, int n) {
	for (int i = 1; i < n; i++) {
		arr[i] += arr[i - 1] + rand() % 10;
	}
	int len = 0;
	for (int i = 0; i < n; i++) {
		len += printf("%3d ", i);
	}
	printf("\n");
	for (int i = 0; i < len; i++) {
		printf("-");
	}
	printf("\n");
	for (int i = 0; i < n; i++) {
		printf("%3d ", arr[i]);
	}
	printf("\n");
	return;
}

int main() {
	srand(time(0));
	int arr[10] = {0};
	get_random(arr, 10);

	int target;
	while(scanf("%d", &target) != EOF) {
		printf("target = %d\n", target);
		int l = 0, r = 9, ans = -1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			printf("mid = %d, arr[%d] = %d\n", mid, mid, arr[mid]);
			if (arr[mid] == target) {
				ans = mid;
				break;
			}
			if (target < arr[mid]) {
				r = mid - 1;
			} else {
				l = mid + 1;
			}
			printf("l = %d, r = %d\n", l, r);
		}
		printf("ans = %d\n", ans);
	}


	return 0;
}
