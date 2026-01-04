#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int data[MAX];
    int top;
} Stack;

//Array Stack: Done

void init(Stack *s);
int isEmpty(Stack *s);
int isFull(Stack *s);
void push(Stack *s, int value);
void pop(Stack *s);
int peek(Stack *s);
void display(Stack *s);

int main(){
    Stack s;
    init(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    display(&s);

    pop(&s);
    display(&s);

    printf("Top: %d\n", peek(&s));
    return 0;
}

void init(Stack *s){
    s->top = -1;
}

int isEmpty(Stack *s){
    return s->top == -1;
}

int isFull(Stack *s){
    return s->top == MAX - 1;
}

void push(Stack *s, int value){
    if(isFull(s)){
        printf("Stack Overflow\n");
        return;
    }
    s->data[++s->top] = value;
}

void pop(Stack *s){
    if(isEmpty(s)){
        printf("Stack Underflow\n");
        return;
    }
    s->top--;
}

int peek(Stack *s){
    if(isEmpty(s)){
        printf("Stack Empty\n");
        return -1;
    }
    return s->data[s->top];
}

void display(Stack *s){
    printf("Stack: ");
    for(int i = s->top; i >= 0; i--){
        printf("%d ", s->data[i]);
    }
    printf("\n\n");
}
