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

List *initialize();
void empty(List *list);
void insertFirst(List *lis, int data);
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

}

List *initialize(){
    List *list = (List*) malloc (sizeof(List));
    list->head = NULL;
    list->count = 0;
    return list;
}

void empty(List *list){
    if(list->count == 0){
        printf("List already empty.");
    }else{
        free(list);
        list->count = 0;
        printf("Successfully freed");
    }
}

void insertFirst(List *list, int data){
    Node *newNode = (Node*) malloc (sizeof(Node));
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
        Node *temp = list->head;
        while(temp->next == NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    list->count++;
}

void insertPos(List *list, int data, int index){
    Node *newNode = (Node*) malloc (sizeof(Node));
    newNode->data = data;
    newNode->next = list->head;
    

}


