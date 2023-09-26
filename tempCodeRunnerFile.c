void printLinkedlist(struct list *head) {
  while (head != NULL) {
    printf("%d ", head->data);
    head= head->next;
  }