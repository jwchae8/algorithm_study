#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int val;
  struct node *next;
} node_t;

void print_node(node_t *node) {
  if(node == NULL)
    return;
  print_node(node->next);
  printf("%d ", node->val);
}

int main() {
  int i, n, r;
  node_t head, *cur, *tmp;
  head.next = NULL;
  scanf("%d", &n);
  for(i=1; i<=n; i++) {
    scanf("%d", &r);
    cur = &head;
    while(r-- > 0)
      cur = cur->next;
    tmp = (node_t *) malloc(sizeof(node_t));
    tmp->val = i;
    tmp->next = cur->next;
    cur->next = tmp;
  }
  print_node(head.next);
  return 0;
}
