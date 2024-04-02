#include <stdio.h>

struct LinkedNode {
  int val;
  struct LinkedNode *next;
};

typedef struct LinkedNode Node;
int getLen(Node *head) {
    Node *p = head;
    int count = 0;
    while(p){
        count++;
        p = p->next;
    }
    return count;
}

// 双指针等距离法
struct LinkedNode* rotateRight(struct LinkedNode* head, int k) {
    Node *p = head;
    Node *q = head;

    // 周期性排除
    int len = getLen(head);
    k %= len;

    if(k == 0) return head;

    // 先走k+1步
    for (int i = 0; i <= k; i++) {
        p = p->next;
    }
    printf("p->val = %d\n", p->val);

    // !!!注意：这里是 , 隔开！！！
    while(p) p = p->next, q = q->next;
    Node *newHead = q->next;
    q->next = NULL;

    // 2段链表连接起来
    q = newHead;
    while(q->next) q = q->next;
    q->next = head;

    return newHead;
}

void print_list(Node *head) {
  Node *p = head;
  while(p) {
    printf("%d -> ", p->val);
    p = p->next;
  }

  printf("\n");
}
// 61. 旋转链表
int main() {
  Node v1 = {1, NULL};
  Node v2 = {2, NULL};
  Node v3 = {3, NULL};
  Node v4 = {4, NULL};
  Node v5 = {5, NULL};
  v1.next = &v2;
  v2.next = &v3;
  v3.next = &v4;
  v4.next = &v5;

  print_list(&v1);
  Node *newHead = rotateRight(&v1, 2);
  print_list(newHead);
  return 0;
}