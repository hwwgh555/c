#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
} Node;

Node *get_node(int val){
	Node *p = (Node *)malloc(sizeof(Node));
	if(p == NULL) return NULL;
	p->data = val;
	p->next = NULL;
	return p;
}

void clear(Node *head) {
	for(Node *p = head, *q = NULL; p; p = q) {
		q = p -> next;
		free(p);
	}

	return ;
}

Node* insert(Node *head, int pos, int val) {
	Node *p = get_node(val);
	if (pos == 0) {
		p->next = head;
		return p;
	}

	// 不使用虚拟头结点为时，插入时边界反应很长时间
	Node *prev = head;
	for(int i = 0; i < pos - 1; i++) {
		prev = prev->next;
	}
	printf("found prev->data = %d\n", prev->data);
	p->next = prev->next;
	prev->next = p;
	return head;
}


void print_num_arrow(Node* head, int count) {
	for(int i = 0; i < count; i++) {
		printf("     ");
	}
	printf("  %c", '^');
	printf("\n");
	for(int i = 0; i < count; i++) {
		printf("     ");
	}
	printf("  %c", '|');
	printf("\n\n");

	return;
}

void print_list(Node*);

int find_by_val(Node *head, int val) {
	int count = 0;
	Node *p = head;
	while(p) {
		if (p->data == val) {
			print_list(head);
			print_num_arrow(head, count);
			return 1;
		}
		p = p->next;
		count++;
	}
	printf("%d do not exits in LinkedList\n", val);
	return 0;
}

void print_list(Node* head) {
	if(head == NULL) return;
	int count = 0;
	for(Node *p = head; p; p = p->next) {
		count++;
	}
	int charNums = 0;
	for(int i = 0; i < count; i++) {
		charNums += printf("%3d  ", i);
	}
	printf("\n");
	for(int i = 0; i < charNums; i++) {
		printf("-");
	}
	printf("\n");
	Node *p = head;
	for(int i = 0; i < count; i++, p = p->next) {
		printf("%3d", p->data);
		printf("->");
	}
	printf("\n\n");

	return;
}

int main() {
	srand(time(0));
	Node *head = get_node(1);
	int count = 1;
	print_list(head);
	for(int i = 0; i < 10; i++) {
		int pos = rand() % (count + 1);
		int val = rand() % 20;
		printf("count = %d; pos = %d, val = %d\n", count, pos, val);
		// head改变了
		head = insert(head, pos, val);
		print_list(head);
		count++;
	}


	int val = 0;
	while(~scanf("%d", &val)) {
		find_by_val(head, val);
	}

	clear(head);

	return 0;
}
