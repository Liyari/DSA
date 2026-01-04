#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

typedef struct{
    int data[SIZE];
    int front; 
    int rear;
}Queue;

void initialize(Queue *Q){
    Q->front = 0;
    Q->rear = -1;
}

int isEmpty(Queue *Q){
    return (Q->rear < Q->front);
}

int isFull(Queue *Q){
    return (Q->rear == SIZE - 1);
}

void enqueue(Queue *Q, int elem){
    if(isFull(Q)){
        printf("Queue is full\n");
        return;
    }
    
    Q->data[++(Q->rear)] = elem;
    printf("Item %d is enqued\n", elem);
}

int dequeue(Queue *Q){
    if(isEmpty(Q)){
        printf("Queue is Empty\n");
        return -1;
    }
    
    return Q->data[(Q->front)++];
}

void display(Queue *Q){
    printf("Elements are: ");
    
    for(int i = Q->front; i <= Q->rear; i++){
        printf("%d ", Q->data[i]);
    }
    printf("\n\n");
}

int main(){
    Queue Q;
    int elem;
    initialize(&Q);

    enqueue(&Q, 10);
    enqueue(&Q, 20);
    enqueue(&Q, 30);
    display(&Q);

    printf("Dequeued: %d\n", dequeue(&Q));
    display(&Q);

    enqueue(&Q, 40);
    display(&Q);

    return 0;
    
}