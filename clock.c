#include <stdio.h>
#include <time.h>



int main() {
	clock_t t1 = clock();
	int n = 1000000;
	while(n--) {
	}
	clock_t t2 = clock();
	double dur = 1000.0 * (t2 - t1) / CLOCKS_PER_SEC;
	printf("run %lfms\n", dur);
	return 0;
}
