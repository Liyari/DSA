#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void appendNode(Node **head, int data) {
    Node *newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

typedef struct {
    Node **arr;
    int size;
    int capacity;
} MinHeap;

MinHeap* createHeap(int capacity) {
    MinHeap *heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->arr = (Node**)malloc(sizeof(Node*) * capacity);
    return heap;
}

void swap(Node **a, Node **b) {
    Node *temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(MinHeap *heap, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap->arr[parent]->data > heap->arr[index]->data) {
            swap(&heap->arr[parent], &heap->arr[index]);
            index = parent;
        } else {
            break;
        }
    }
}

void heapifyDown(MinHeap *heap, int index) {
    int smallest = index;

    while (1) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < heap->size &&
            heap->arr[left]->data < heap->arr[smallest]->data)
            smallest = left;

        if (right < heap->size &&
            heap->arr[right]->data < heap->arr[smallest]->data)
            smallest = right;

        if (smallest != index) {
            swap(&heap->arr[index], &heap->arr[smallest]);
            index = smallest;
        } else {
            break;
        }
    }
}

void insertHeap(MinHeap *heap, Node *node) {
    heap->arr[heap->size] = node;
    heapifyUp(heap, heap->size);
    heap->size++;
}

Node* extractMin(MinHeap *heap) {
    if (heap->size == 0)
        return NULL;

    Node *min = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);

    return min;
}

Node* mergeKLists(Node **lists, int k) {
    MinHeap *heap = createHeap(k);

    for (int i = 0; i < k; i++) {
        if (lists[i] != NULL)
            insertHeap(heap, lists[i]);
    }

    Node *head = NULL;
    Node *tail = NULL;

    while (heap->size > 0) {
        Node *minNode = extractMin(heap);

        if (head == NULL) {
            head = minNode;
            tail = minNode;
        } else {
            tail->next = minNode;
            tail = minNode;
        }

        if (minNode->next != NULL)
            insertHeap(heap, minNode->next);
    }

    return head;
}

void printList(Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int k;
    printf("Enter the number of lists to be merged: ");
    scanf("%d", &k);

    Node **lists = (Node**)malloc(sizeof(Node*) * k);

    for (int i = 0; i < k; i++) {
        lists[i] = NULL;
        int n;
        printf("Enter the number of nodes in list %d: ", i + 1);
        scanf("%d", &n);

        for (int j = 0; j < n; j++) {
            int val;
            printf("Enter the value of node %d: ", j + 1);
            scanf("%d", &val);
            appendNode(&lists[i], val);
        }
    }

    Node *mergedList = mergeKLists(lists, k);

    printf("The merged list is: ");
    printList(mergedList);

    return 0;
}
