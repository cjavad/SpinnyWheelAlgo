#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Item {
    int value;
    Item *next = nullptr;
};

struct Queue {
    Item *head = nullptr;
    Item *tail = nullptr;
};

void enqueue(Queue* queue, Item* item) {
    if (queue->head) queue->head->next = item;
    if (!queue->tail) queue->tail = item;
    queue->head = item;
}

Item* dequeue(Queue* queue) {
    if (!queue->tail) *(int*)0;

    Item* tail = queue->tail;
    queue->tail = tail->next;

    if (!queue->tail) queue->head = nullptr;

    return tail;
}

int main() {
    int n;
    cin >> n;
    
    Queue queue{};
    
    for (int i = 0; i < n; i++) {
        char cmd;
        cin >> cmd;

        switch (cmd) {
            case 'E': {
                int value;
                cin >> value;
                enqueue(&queue, new Item{value, nullptr});
                break;
            }
            case 'D': {
                Item* item = dequeue(&queue);
                cout << item->value << endl;
                delete item;
                break;
            }
        }  
    }
}