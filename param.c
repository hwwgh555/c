#include <stdio.h>
#define D(a) #a[0] ? a : 97
#define test_func(a, b, c) {\
__test_func(D(a), D(b), D(c));\
}

void __test_func(int a, int b, double c) {
	printf("a = %d, b = %d, c = %lf\n", a, b, c);
	return;
}

int main() {
	test_func(,,);
	test_func(1,,);
	test_func(,2,);
	test_func(,,3);
	test_func(1,2,3);

	return 0;
}
