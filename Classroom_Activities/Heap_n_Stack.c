#include <stdio.h>
#define SIZE 5  

int queue[SIZE];
int front = 0, rear = 0, count = 0;

int isEmpty() {
    return (count == 0);
}

int isFull() {
    return (count == SIZE);
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue is FULL! Cannot enqueue %d\n", value);
        return;
    }
    queue[rear] = value;
    rear = (rear + 1) % SIZE;
    count++;
    printf("Enqueued: %d\n", value);
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue is EMPTY! Cannot dequeue.\n");
        return -1;
    }
    int data = queue[front];
    front = (front + 1) % SIZE;
    count--;
    printf("Dequeued: %d\n", data);
    return data;
}

void display() {
    if (isEmpty()) {
        printf("Queue is EMPTY!\n");
        return;
    }
    printf("Queue: ");
    int i;
    for (i = 0; i < count; i++) {
        int index = (front + i) % SIZE;
        printf("%d ", queue[index]);
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display();
    printf("\n");

    dequeue();
    dequeue();

    display();
    printf("\n");


    enqueue(60);
    enqueue(70);

    display();

    return 0;
}
