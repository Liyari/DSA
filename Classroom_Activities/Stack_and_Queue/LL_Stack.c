#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} Node;

typedef struct {
    Node *top;
} Stack;

//Linked-List Stack: Done

void init(Stack *s);
int isEmpty(Stack *s);
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
    s->top = NULL;
}

int isEmpty(Stack *s){
    return s->top == NULL;
}

void push(Stack *s, int value){
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}

void pop(Stack *s){
    if(isEmpty(s)){
        printf("Stack Underflow\n");
        return;
    }
    Node *temp = s->top;
    s->top = temp->next;
    free(temp);
}

int peek(Stack *s){
    if(isEmpty(s)){
        printf("Stack Empty\n");
        return -1;
    }
    return s->top->data;
}

void display(Stack *s){
    Node *current = s->top;
    printf("Stack: ");
    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n\n");
}
