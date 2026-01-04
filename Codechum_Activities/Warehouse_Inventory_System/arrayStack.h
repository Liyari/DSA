#include <stdio.h>
#include <stdlib.h>
#include "types.h"

void initializeStack(Stack *s){
    s->top = -1;
}

bool isFull(Stack *s){
    if (s->top == MAX - 1){
        return true;
    }
    return false;
}

bool isEmpty(Stack *s){
    if(s->top == -1){
        return true;
    }
    return false;
}

void push(Stack *s, int value){
    if(isFull(s) == true){
        printf("Stack is full\n");
        return;
    }
    s->items[++(s->top)] = value;
    printf("Container %d is pushed\n", value);
}

int pop(Stack *s){
    if(isEmpty(s) == true){
        printf("Stack is empty\n");
        return -1;
    }
    return s->items[(s->top)--];
}

int peek(Stack *s){
    if(isEmpty(s) == true){
        return -1;
    }
    return s->items[s->top];
}

int top(Stack *s){
    // not done yet
}

void display(Stack* s){
    if(isEmpty(s) == true){
        printf("Stack is empty\n");
        return;
    }
    for(int i = s->top; i >= 0; i--){
        printf("%d\n", s->items[i]);
    }
}