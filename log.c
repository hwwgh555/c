#include <stdio.h>
#define DEBUG 0
#define	ERROR 1
#define FATAL 2
#define LOG(level) \
	if (level>= LOG_LEVEL) {\
		printf("[%s : %d] ", __FILE__, __LINE__);\
	}\
	printf

int main() {
	int a = 123;
	printf("hello\n");
	printf("a = %d\n", a);
	LOG(DEBUG)("hello, DEBUG \n");
	LOG(ERROR)("hello, ERROR\n");
	LOG(FATAL)("hello, FATAL\n");
	return 0;
}
