#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct {
    int items[MAX_SIZE];
    int front, rear;
} CircularQueue;

void initializeQueue(CircularQueue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

static int isFull(CircularQueue* queue) {
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

static int isEmpty(CircularQueue* queue) {
    return (queue->front == -1 && queue->rear == -1);
}

void enqueue(CircularQueue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full\n");
        return;
    }
    else if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    }
    else {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }
    queue->items[queue->rear] = value;
}

int dequeue(CircularQueue* queue) {
    int dequeuedItem;
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    else if (queue->front == queue->rear) {
        dequeuedItem = queue->items[queue->front];
        queue->front = -1;
        queue->rear = -1;
    }
    else {
        dequeuedItem = queue->items[queue->front];
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    return dequeuedItem;
}

static int peek(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    else {
        return queue->items[queue->front];
    }
}

int testCircularQueue() {
    CircularQueue queue;
    initializeQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);
    enqueue(&queue, 50);

    printf("Peek: %d\n", peek(&queue));

    printf("Dequeued: %d\n", dequeue(&queue));
    printf("Dequeued: %d\n", dequeue(&queue));

    enqueue(&queue, 60);

    printf("Peek: %d\n", peek(&queue));

    return 0;
}