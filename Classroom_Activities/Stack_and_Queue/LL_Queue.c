#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
} Queue;

//Linked-List Queue: Done
void init(Queue *q);
int isEmpty(Queue *q);
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
    q->front = q->rear = NULL;
}

int isEmpty(Queue *q){
    return q->front == NULL;
}

void enqueue(Queue *q, int value){
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if(isEmpty(q)){
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

void dequeue(Queue *q){
    if(isEmpty(q)){
        printf("Queue Underflow\n");
        return;
    }
    Node *temp = q->front;
    q->front = temp->next;

    if(q->front == NULL)
        q->rear = NULL;

    free(temp);
}

int peek(Queue *q){
    if(isEmpty(q)){
        printf("Queue Empty\n");
        return -1;
    }
    return q->front->data;
}

void display(Queue *q){
    Node *current = q->front;
    printf("Queue: ");
    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n\n");
}
