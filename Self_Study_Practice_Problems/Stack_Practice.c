#include <stdio.h>
#define SIZE 5

typedef struct{
    int data[SIZE];
    int top;
}Stack;

//initialize
void initialize(Stack *S){
    S->top = -1;
}
//check if empty
int isEmpty(Stack *S){
    return (S->top == -1);
}

//check if full
int isFull(Stack *S){
    return(S->top == SIZE - 1);
}

//push
void push(Stack *S, int elem){
    if(isFull(S)){
        printf("List is full");
        return;
    }
    
    S->data[++(S->top)] = elem;
    printf("Element %d is pushed to stack\n", elem);
}
//pop

int pop(Stack *S){
    if(isEmpty(S)){
        printf("List is Empty");
        return -1;
    }
    
    return S->data[(S->top)--];
}

//LIFO
//peek (optional)
int main(){
    Stack S;
    int elem;
    
    initialize(&S);
    
    push(&S, 1);
    push(&S, 2);
    pop(&S);
    
    push(&S, 3);
    push(&S, 4);
    pop(&S);
    
    return 0;
}