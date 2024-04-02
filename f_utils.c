#include <stdio.h>
#include <time.h>
#include <stdlib.h>


const char *file_name = "f_utils.txt";

void get_random(int *arr, int n){
	for(int i = 0; i < n; i++) {
		arr[i] = rand() % 26;
	}
	return;
}

void output_arr(int *arr, int n) {
	for(int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	return;
}

void output_arr_to_file(int *arr, int n) {
	FILE *fp = fopen(file_name, "a");
	for(int i = 0; i < n; i++) {
		fprintf(fp, "%d ", arr[i]);
	}
	fclose(fp);
	return;
}

void clear_file() {
	FILE *fp = fopen(file_name, "w");
	fclose(fp);
	return;
}


int main() {
	srand(time(0));
	int arr[10];
	get_random(arr, 10);
	output_arr(arr, 10);
	output_arr_to_file(arr, 10);
	clear_file();
	return 0;
}
