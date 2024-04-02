#include <stdio.h>
#include <stdlib.h>#include <time.h>

int main() {
	printf("%ld\n", time(0));
	srand(time(0));
	int count = 10;
	while (count) {
		printf("%d\n", rand());
		count--;
	}

	return 0;
}

