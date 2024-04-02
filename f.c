#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *fp = fopen("data.txt", "r");
	if(fp == NULL) {
		perror("failed to open file");
		exit(1);
	}
	char* str = (char *)malloc(sizeof(char) * 100);
	fscanf(fp, "%s", str);
	fclose(fp);

	printf("%s\n", str);

	return 0;
}
