#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data; 
    struct Node *next;
}Node;

typedef struct{
    Node *top;
}Stack;

void initialize(Stack *S){
    S->top = NULL;
}

int isEmpty(Stack *S){
    return (S->top == NULL);
}

void push(Stack *S, int elem){
    Node *newNode = (Node*) malloc(sizeof(Node));
    
    newNode->data = elem;
    newNode->next = S->top;
    S->top = newNode;
    
    printf("Element %d is pushed to stack\n", elem);
}

int pop(Stack *S){
    if(isEmpty(S)){
        printf("Error: Stack Empty\n");
        return -1;
    }
    
    Node *temp = S->top;
    int popped = temp->data;
    S->top = temp->next;
    free(temp);
    return popped;
}

int main(){
    Stack S;
    initialize(&S);
    
    push(&S, 1);
    push(&S, 2);
    push(&S, 3);
    printf("Popped: %d\n", pop(&S));
    push(&S, 4);
    return 0;
}