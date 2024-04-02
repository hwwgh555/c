#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};
typedef struct ListNode node;

struct ListNode* reverseList(struct ListNode* head) {
    if(head == NULL) return NULL;
    node *p;
    node *q;
    p = head;
    q = head->next;
    while(q) {
        node *temp = q;
        temp->next = p;
        p = temp;
        q = q->next;
    }
    return p;
};

int main() {
	node *head = (node *)malloc(sizeof(node));
	node *p = head;
	//reverseList(head);
	return 0;
}
