#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

typedef struct{
    Node *head;
    int count;
}List;

//Accessed by pointer (Done)

List *initialize();
void empty(List *list);
void insertFirst(List *list, int data);
void insertLast(List *list, int data);
void insertPos(List *list, int data, int index);
void deleteStart(List *list);
void deleteLast(List *list);
void deletePos(List *list, int index);
int retreive(List *list, int index);
int locate(List *lsit, int data);
void display(List *list);


int main(){
    List *list = initialize();
    int data, index;
    
    printf("Insert first...\n");
    insertFirst(&list, 1);
    insertFirst(&list, 2);
    insertFirst(&list, 3);
    display(&list);

    printf("Insert last...\n");
    insertLast(&list, 4);
    insertLast(&list, 5);
    display(&list);

    printf("Insert data at position 2...\n");
    insertPos(&list, 6, 2);
    display(&list);



}

List *initialize(){
    List *list = (List*) malloc (sizeof(List));

    list->count = 0;
    list->head = NULL;
    
    return list;
}

void empty(List *list){
    Node *temp;
    Node *current = list->head;

    while(current != NULL){
        temp = current;
        current = current->next;
        free(temp);
    }
    list->count = 0;
    list->head = NULL;
}

void insertFirst(List *list, int data){
    Node *newNode = (Node*) malloc (sizeof(Node));
    if(newNode == NULL){
        printf("Memory allocation failed\n");
    }

    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
    list->count++;
}

void insertLast(List *list, int data){
    Node *newNode = (Node*) malloc (sizeof(Node));

    newNode->data = data;
    newNode->next = NULL;

    if(list->head == NULL){
        list->head = newNode;
    }else{
        Node *current = list->head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newNode;
    }
    list->count++;
}

void insertPos(List *list, int data, int index){
    if(index == 0){
        insertFirst(list, data);
        return;
    }

    if(index ==  list->count){
        insertLast(list, data);
        return;
    }

    Node *newNode = (Node*) malloc (sizeof(Node));
    newNode->data = data;

    Node *current = list->head;
    
    for(int i = 0; i < index - 1; i++){
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
    list->count++;
}

void deleteStart(List *list){
    Node *current = list->head;

    list->head = current->next;
    free(current);
    list->count--;
}

void display(List *list){
    printf("List: ");
    for(int i = 0; i < list->count; i++){
        printf("%d ", list->head[i]);
    }
    printf("\n\n");
}

