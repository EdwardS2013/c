
struct list_entry {
    struct list_entry *next;
    int value;
};

int main(void) {
    struct list_entry head;
    head.next = NULL;
    head.value = 0;

    int i;
    for(i = 0; i < 10; i++) {
        struct list_entry *node = malloc(sizeof(struct list_entry));
        node->value = i;

        node->next = head.next;
        head.next = node;
    }

    struct list_entry *iter = &head;
    while(iter->next != NULL) {
        printf("%d\n", iter->value);
        iter = iter->next;
    }

    return 0;
}
