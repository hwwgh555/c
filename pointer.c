#include <stdio.h>

int main() {
	int *(*p[10])[20];	
	printf("p = %p\n", p);
	printf("p + 1 = %p\n", p + 1);
	printf("p + 2 = %p\n", p + 2);


	return 0;
}
