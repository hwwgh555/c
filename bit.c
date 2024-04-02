#include <stdio.h>

int main() {
	char a = 'a', b = 'b';
	printf("a = %c, b = %c \n", a, b);
	a ^= b;
	b ^= a;
	a ^= b;

	printf("a = %c, b = %c \n", a, b);

	return 0;
}
