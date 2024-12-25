#include <stdio.h>
#include <stdlib.h>


typedef struct MaxHeap {
    int *array;
    long long capacity; // Changed to long long to accommodate large values
    int size;
} MaxHeap;


MaxHeap* createHeap(long long capacity) {
    MaxHeap* heap = (MaxHeap*)malloc(sizeof(MaxHeap));
    if (!heap) {
        fprintf(stderr, "Memory allocation failed for heap.\n");
        exit(EXIT_FAILURE);
    }
   
    heap->capacity = capacity;
    heap->size = 0;
    heap->array = (int*)malloc(capacity * sizeof(int));
    if (!heap->array) {
        fprintf(stderr, "Memory allocation failed for array.\n");
        free(heap);
        exit(EXIT_FAILURE);
    }
   
    return heap;
}


void swap(int *a, int *b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}


void heapify(MaxHeap* heap, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;


    if (left < heap->size && heap->array[left] > heap->array[largest]) {
        largest = left;
    }


    if (right < heap->size && heap->array[right] > heap->array[largest]) {
        largest = right;
    }


    if (largest != index) {
        swap(&heap->array[index], &heap->array[largest]);
        heapify(heap, largest);
    }
}


void insert(MaxHeap* heap, int value) {
    if (heap->size == heap->capacity) {
        printf("Heap is full. Cannot insert %d\n", value);
        return;
    }
    heap->array[heap->size] = value;
    heap->size++;


    // Move up to maintain heap property
    int i = heap->size - 1;
    while (i != 0 && heap->array[(i - 1) / 2] < heap->array[i]) {
        swap(&heap->array[i], &heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}


int extractMax(MaxHeap* heap) {
    if (heap->size <= 0) {
        return -1;
    }


    if (heap->size == 1) {
        heap->size--;
        return heap->array[0];
    }


    int root = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    heapify(heap, 0);


    return root;
}


int getMax(MaxHeap* heap) {
    if (heap->size <= 0) {
        return -1;
    }
    return heap->array[0];
}


void increaseValue(MaxHeap* heap, int index, int newValue) {
    if (index < 0 || index >= heap->size || newValue <= heap->array[index]) {
        printf("Invalid increase operation.\n");
        return;
    }


    heap->array[index] = newValue;
    while (index != 0 && heap->array[(index - 1) / 2] < heap->array[index]) {
        swap(&heap->array[index], &heap->array[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}


void heapifyArray(MaxHeap* heap) {
    for (int i = (heap->size - 1) / 2; i >= 0; i--) {
        heapify(heap, i);
    }
}


int main() {
    long long n;
    int value;
    printf("Enter the number of elements: ");
    scanf("%lld", &n);


    MaxHeap* heap = createHeap(n > 10000000 ? n : 10000000); // Ensure minimum capacity of 10 million


    printf("Enter the elements:\n");
    for (long long i = 0; i < n; i++) {
        scanf("%d", &value);
        insert(heap, value);
    }


    heapifyArray(heap);


    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Extract Max\n");
        printf("3. Get Max\n");
        printf("4. Increase Value\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);


        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(heap, value);
                break;
            case 2:
                printf("Extracted Max: %d\n", extractMax(heap));
                break;
            case 3:
                printf("Current Max: %d\n", getMax(heap));
                break;
            case 4:
                printf("Enter index and new value: ");
                int index, newValue;
                scanf("%d %d", &index, &newValue);
                increaseValue(heap, index, newValue);
                break;
            case 5:
                free(heap->array);
                free(heap);
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }


    return 0;
}


