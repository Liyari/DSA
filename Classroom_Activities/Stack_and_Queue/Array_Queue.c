#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int data[MAX];
    int front;
    int rear;
} Queue;

//Array Queue: Done
void init(Queue *q);
int isEmpty(Queue *q);
int isFull(Queue *q);
void enqueue(Queue *q, int value);
void dequeue(Queue *q);
int peek(Queue *q);
void display(Queue *q);

int main(){
    Queue q;
    init(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    display(&q);

    dequeue(&q);
    display(&q);

    printf("Front: %d\n", peek(&q));
    return 0;
}

void init(Queue *q){
    q->front = 0;
    q->rear = -1;
}

int isEmpty(Queue *q){
    return q->rear < q->front;
}

int isFull(Queue *q){
    return q->rear == MAX - 1;
}

void enqueue(Queue *q, int value){
    if(isFull(q)){
        printf("Queue Overflow\n");
        return;
    }
    q->data[++q->rear] = value;
}

void dequeue(Queue *q){
    if(isEmpty(q)){
        printf("Queue Underflow\n");
        return;
    }
    q->front++;
}

int peek(Queue *q){
    if(isEmpty(q)){
        printf("Queue Empty\n");
        return -1;
    }
    return q->data[q->front];
}

void display(Queue *q){
    printf("Queue: ");
    for(int i = q->front; i <= q->rear; i++){
        printf("%d ", q->data[i]);
    }
    printf("\n\n");
}
