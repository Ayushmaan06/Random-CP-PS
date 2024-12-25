#include <stdio.h>
#include <stdlib.h>


typedef struct MaxHeap {
    int *array;
    int capacity;
    int size;
} MaxHeap;


typedef struct MinHeap {
    int *array;
    int capacity;
    int size;
} MinHeap;

MaxHeap* createMaxHeap(int capacity) {
    MaxHeap* heap = (MaxHeap*)malloc(sizeof(MaxHeap));
    heap->capacity = capacity;
    heap->size = 0;
    heap->array = (int*)malloc(capacity * sizeof(int));
    return heap;
}

MinHeap* createMinHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->capacity = capacity;
    heap->size = 0;
    heap->array = (int*)malloc(capacity * sizeof(int));
    return heap;
}


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void maxHeapify(MaxHeap* heap, int index) {
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
        maxHeapify(heap, largest);
    }
}


void minHeapify(MinHeap* heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;


    if (left < heap->size && heap->array[left] < heap->array[smallest]) {
        smallest = left;
    }
    if (right < heap->size && heap->array[right] < heap->array[smallest]) {
        smallest = right;
    }
    if (smallest != index) {
        swap(&heap->array[index], &heap->array[smallest]);
        minHeapify(heap, smallest);
    }
}


void insertMax(MaxHeap* heap, int value) {
    if (heap->size == heap->capacity) {
        return;
    }
    heap->array[heap->size] = value;
    heap->size++;
    for (int i = (heap->size / 2) - 1; i >= 0; i--) {
        maxHeapify(heap, i);
    }
}


void insertMin(MinHeap* heap, int value) {
    if (heap->size == heap->capacity) {
        return;
    }
    heap->array[heap->size] = value;
    heap->size++;
    for (int i = (heap->size / 2) - 1; i >= 0; i--) {
        minHeapify(heap, i);
    }
}


int extractMax(MaxHeap* heap) {
    if (heap->size <= 0) return -1;
    if (heap->size == 1) {
        heap->size--;
        return heap->array[0];
    }
    int root = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    maxHeapify(heap, 0);
    return root;
}


int extractMin(MinHeap* heap) {
    if (heap->size <= 0) return -1;
    if (heap->size == 1) {
        heap->size--;
        return heap->array[0];
    }
    int root = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    minHeapify(heap, 0);
    return root;
}


void freeMaxHeap(MaxHeap* heap) {
    free(heap->array);
    free(heap);
}


void freeMinHeap(MinHeap* heap) {
    free(heap->array);
    free(heap);
}


void heapSortAsc(int* array, int n) {
    MaxHeap* maxHeap = createMaxHeap(n);
    for (int i = 0; i < n; i++) {
        insertMax(maxHeap, array[i]);
    }
   
    for (int i = n - 1; i >= 0; i--) {
        array[i] = extractMax(maxHeap);
    }
   
    freeMaxHeap(maxHeap);
}


void heapSortDesc(int* array, int n) {
    MinHeap* minHeap = createMinHeap(n);
    for (int i = 0; i < n; i++) {
        insertMin(minHeap, array[i]);
    }


    for (int i = 0; i < n; i++) {
        array[i] = extractMin(minHeap);
    }


    for (int i = 0; i < n / 2; i++) {
        swap(&array[i], &array[n - 1 - i]);
    }
   
    freeMinHeap(minHeap);
}


int main() {
    int n, i;


    printf("Enter the number of elements: ");
    scanf("%d", &n);
   
    int *array = (int*)malloc(n * sizeof(int));
    if (!array) {
        fprintf(stderr, "Memory allocation failed for array.\n");
        return EXIT_FAILURE;
    }
   
    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }




    heapSortAsc(array, n);
    printf("Sorted in ascending order: ");
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");


    heapSortDesc(array, n);
    printf("Sorted in descending order: ");
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");


    free(array);
    return 0;
}
