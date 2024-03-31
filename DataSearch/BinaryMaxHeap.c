#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 100

typedef struct {
    int* arr;
    int size;
    int capacity;
} MaxHeap;

MaxHeap* createMaxHeap(int capacity) {
    MaxHeap* maxHeap = (MaxHeap*)malloc(sizeof(MaxHeap));
    if (maxHeap) {
        maxHeap->capacity = capacity;
        maxHeap->size = 0;
        maxHeap->arr = (int*)malloc(capacity * sizeof(int));
    }
 
    return maxHeap;
}

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return (2 * i) + 1;
}

int rightChild(int i) {
    return (2 * i) + 2;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

static void insert(MaxHeap* maxHeap, int key) {
    if (maxHeap->size >= maxHeap->capacity) {
        printf("Heap overflow\n");
        return;
    }

    maxHeap->size++;
    int i = maxHeap->size - 1;
    maxHeap->arr[i] = key;

    while (i != 0 && maxHeap->arr[parent(i)] < maxHeap->arr[i]) {
        swap(&maxHeap->arr[i], &maxHeap->arr[parent(i)]);
        i = parent(i);
    }
}

void maxHeapify(MaxHeap* maxHeap, int i) {
    int l = leftChild(i);
    int r = rightChild(i);
    int largest = i;

    if (l < maxHeap->size && maxHeap->arr[l] > maxHeap->arr[largest])
        largest = l;

    if (r < maxHeap->size && maxHeap->arr[r] > maxHeap->arr[largest])
        largest = r;

    if (largest != i) {
        swap(&maxHeap->arr[i], &maxHeap->arr[largest]);
        maxHeapify(maxHeap, largest);
    }
}

int extractMax(MaxHeap* maxHeap) {
    if (maxHeap->size <= 0)
        return -1;

    if (maxHeap->size == 1) {
        maxHeap->size--;
        return maxHeap->arr[0];
    }

    int root = maxHeap->arr[0];
    maxHeap->arr[0] = maxHeap->arr[maxHeap->size - 1];
    maxHeap->size--;
    maxHeapify(maxHeap, 0);
    return root;
}

static int peek(MaxHeap* maxHeap) {
    if (maxHeap->size <= 0)
        return -1;
    return maxHeap->arr[0];
}

void increaseKey(MaxHeap* maxHeap, int i, int newKey) {
    if (i < 0 || i >= maxHeap->size) {
        printf("Invalid index\n");
        return;
    }

    if (newKey < maxHeap->arr[i]) {
        printf("New key is smaller than the current key\n");
        return;
    }

    maxHeap->arr[i] = newKey;
    while (i != 0 && maxHeap->arr[parent(i)] < maxHeap->arr[i]) {
        swap(&maxHeap->arr[i], &maxHeap->arr[parent(i)]);
        i = parent(i);
    }
}

void printHeap(MaxHeap* maxHeap) {
    printf("Max Heap: ");
    for (int i = 0; i < maxHeap->size; i++)
        printf("%d ", maxHeap->arr[i]);
    printf("\n");
}

int testHeap() {
    MaxHeap* maxHeap = createMaxHeap(MAX_HEAP_SIZE);

    insert(maxHeap, 10);
    insert(maxHeap, 20);
    insert(maxHeap, 15);
    insert(maxHeap, 30);
    insert(maxHeap, 25);

    printHeap(maxHeap);

    printf("Maximum element in heap: %d\n", peek(maxHeap));

    printf("Extracting maximum element: %d\n", extractMax(maxHeap));
    printf("Maximum element after extraction: %d\n", peek(maxHeap));

    increaseKey(maxHeap, 2, 40);
    printf("Maximum element after increasing key at index 2: %d\n", peek(maxHeap));

    free(maxHeap->arr);
    free(maxHeap);

    return 0;
}