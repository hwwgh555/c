#include <stdio.h>


int main(){
	printf("%d\n", EOF);
	if(EOF == 0) {
		printf("EOF == 0 is TRUE\n");
	}
	if(EOF == -1) {
		printf("EOF == -1 is TRUE\n");
	}
	return 0;
}
