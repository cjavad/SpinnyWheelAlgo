#include <stdio.h>

typedef struct {
    int value;
    void *next;
} priority_item;

typedef struct {
    priority_item *head;
    priority_item *tail;
} priority_queue;


void print_queue(priority_queue *queue) {
    priority_item *item = queue->head;
    while (item != NULL) {
        printf("%d ", item->value);
        item = item->next;
    }
    printf("\n");
}

void insert(priority_queue *queue, int value) {
    priority_item *item = malloc(sizeof(priority_item));
    item->value = value;
    item->next = NULL;
    if (queue->head == NULL) {
        queue->head = item;
        queue->tail = item;
    } else {
        queue->tail->next = item;
        queue->tail = item;
    }   
}

void extract_max(priority_queue *queue) {
    priority_item *item = queue->head;
    queue->head = queue->head->next;
    free(item);
}

priority_queue *create_queue() {
    priority_queue *queue = malloc(sizeof(priority_queue));
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}


int main() {
    priority_queue *queue = create_queue();

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char c;
        int value;
        scanf("%c %d", &c, &value);
        
        switch (c) {
            case 'I':
                insert(queue, value);
                break;
            case 'E':
                extract_max(queue);
                break;
            case 'P':
                print_queue(queue);
                break;
        }
    }

    return 0;
}