#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	int size;
	int count;
	int *data;
} vector;

// 初始化
vector* get_vectory(int size) {
	vector *v = (vector *) malloc(sizeof(vector) * 1);
	if(v == NULL) {
		perror("fail to apply for memory ");
		return 0;
	}
	v->size = size;
	v->count = 0;
	v->data = (int*)malloc(sizeof(int) * size);
	return v;
}

// 销毁
void clear(vector *v) {
	free(v->data);
	free(v);
	return ;
}

int insert(vector *v, int pos, int val) {
	if (v->size == v->count) {
		perror("the v is full!");
		return 0;
	}
	if (pos < 0 || pos > v -> count) {
		perror("the pos is not valid!");
		return 0;
	}
	// 这里边界判断很慢
	for(int i = v->count - 1; i >= pos; i--) {
		v->data[i + 1] = v->data[i];
	}
	v->data[pos] = val;
	v->count++;

	return 1;
}

int removeAt(vector *v, int pos) {
	if(v->count == 0) {
		perror("the v is empty!");
		return 0;
	}
	if(pos < 0 || pos > v->count - 1){
		perror("the pos do not exist!");
		return 0;
	}
	for(int i = pos; i < v->count; i++){
		v->data[i] = v->data[i+1];
	}
	v->count--;

	return 1;
}

#define MAX_SIZE 10

void show_arr(vector *v) {
	int len = 0;
	for(int i = 0; i < v->size; i++) {
		len += printf("%3d", i);
	}
	printf("\n");
	for(int i = 0; i < len; i++) {
		printf("-");
	}
	printf("\n");
	for(int i = 0; i < v->count; i++) {
		printf("%3d", v->data[i]);
	}
	printf("\n");
	return;
}

int main() {
	vector *v = get_vectory(MAX_SIZE);

	srand(time(0));

	for(int i = 0; i < MAX_SIZE; i++) {
		int r = rand() % 4;
		int pos;
		int val;
		switch(r) {
			case 0:
			case 1:
			case 2:
				pos = rand() % (v->count + 2);
				val = rand() % 100;
				printf("insert val = %d at pos = %d\n", val, pos);
				insert(v, pos, val);
				show_arr(v);
				break;
			case 3:
				pos = rand() % (v->count + 2);
				printf("remove pos = %d\n", pos);
				removeAt(v, pos);
				show_arr(v);
				break;
		}
	}
	clear(v);

	return 0;
}


