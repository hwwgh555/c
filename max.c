#include <stdio.h>
#define MAX(a,b) ({ \
	int _a = (a), _b = (b); \
	((_a) > (_b) ? (_a) : (_b));\
})
int main() {
	printf("MAX(%d,%d) = %d\n", 3, 2, MAX(3, 2));
	printf("5 + MAX(%d,%d) = %d\n", 3, 4, 5 + MAX(3, 4));
	printf("MAX(2, MAX(%d,%d)) = %d\n", 3, 4, MAX(3, 4));
	printf("MAX(2, 3 > 4 ? 3 : 4) = %d\n", MAX(2, 3 > 4 ? 3 :4));
	int a = 7;
	printf("MAX(a++, 6) = %d\n", MAX(a++, 6));
	printf("a = %d\n", a);

	return 0;
}
