#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int val;
  struct node *next;
} node_t;

int main() {
  int i, n, m;
  node_t *head = (node_t *) malloc(sizeof(node_t));
  node_t *cur = head, *tmp;
  scanf("%d %d", &n, &m);
  for(i=1; i<=n; i++) {
    tmp = (node_t *) malloc(sizeof(node_t));
    tmp->val = i;
    tmp->next = NULL;
    cur->next = tmp;
    cur = tmp;
  }
  if(cur != head->next) 
    cur->next = head->next;
  printf("<");
  while(cur->next != NULL) {
    for(i=0; i<m-1; i++) {
      cur = cur->next;
    }
    printf("%d, ", cur->next->val);
    if(cur != cur->next->next) 
      cur->next = cur->next->next;
    else
      cur->next = NULL;
  }
  printf("%d>\n", cur->val);
  return 0;
}
