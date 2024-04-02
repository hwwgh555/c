#include <stdio.h>
#include <time.h>

#define TIME(fn) {/
	fn;/
	printf(#fn);/
	printf("run %lfms\n", 0);/
}
/*
#define TIME(fn) {/
	clock_t t1 = clock();/
	fn;/
	clock_t t2 = clock();/
	double dur = 1000.0 * (t2 - t1) / CLOCKS_PER_SEC;/
	printf(#fn);/
	printf("run %lfms\n", dur);/
}
*/

void test(int n) {
	long long sum = 0;
	for (int i = 1; i <=n; i++) sum +=i;
	printf("sum = %lld\n", sum);
	return ;
}

int main() {
	TIME(test(100000));
	TIME(test(1000000));
	TIME(test(10000000));

	return 0;
}
