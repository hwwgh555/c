#include <stdio.h>


int main() {
	FILE *fp = fopen("w.txt", "w");
	fprintf(fp, "%s", "w: hello from hww");

	fclose(fp);

	return 0;
}
