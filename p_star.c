#include <stdio.h>

int main() {
	int x = 0x61626364;
	char *p = (char *)(&x);

	printf("*p = %c\n", *p);
	printf("p[1] = %c\n", *(p + 1));
	printf("p[2] = %c\n", *(p + 2));
	printf("p[3] = %c\n", *(p + 3));


	return 0;
}
