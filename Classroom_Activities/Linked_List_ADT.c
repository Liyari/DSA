#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} Node;

typedef struct{
    Node *head;
    int count;
} List;

//Variation 2: Done

List *initialize();
void empty(List *list);
void insertFirst(List *list, int data);
void insertLast(List *list, int data);
void insertPos(List *list, int data, int index);
void deleteStart(List *list);
void deleteLast(List *list);
void deletePos(List *list, int index);
int retrieve(List *list, int index);
int locate(List *list, int data);
void display(List *list);

int main(){
    List *list = initialize();

    printf("Insert first...\n");
    insertFirst(list, 1);
    insertFirst(list, 2);
    insertFirst(list, 3);
    display(list);

    printf("Insert last...\n");
    insertLast(list, 4);
    insertLast(list, 5);
    display(list);

    printf("Insert data at position 2...\n");
    insertPos(list, 6, 2);
    display(list);

    printf("Delete first...\n");
    deleteStart(list);
    display(list);

    printf("Delete last...\n");
    deleteLast(list);
    display(list);

    printf("Delete at position 1...\n");
    deletePos(list, 1);
    display(list);

    printf("Retrieve index 1: %d\n", retrieve(list, 1));
    printf("Locate data 4: index %d\n", locate(list, 4));

    empty(list);
    free(list);

    return 0;
}

List *initialize(){
    List *list = (List*) malloc(sizeof(List));
    list->head = NULL;
    list->count = 0;
    return list;
}

void empty(List *list){
    Node *current = list->head;
    Node *temp;

    while(current != NULL){
        temp = current;
        current = current->next;
        free(temp);
    }
    list->head = NULL;
    list->count = 0;
}

void insertFirst(List *list, int data){
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
    list->count++;
}

void insertLast(List *list, int data){
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if(list->head == NULL){
        list->head = newNode;
    } else {
        Node *current = list->head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newNode;
    }
    list->count++;
}

void insertPos(List *list, int data, int index){
    if(index < 0 || index > list->count){
        printf("Invalid index\n");
        return;
    }

    if(index == 0){
        insertFirst(list, data);
        return;
    }

    Node *newNode = (Node*) malloc(sizeof(Node));
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
    if(list->head == NULL){
        printf("List is empty\n");
        return;
    }

    Node *temp = list->head;
    list->head = temp->next;
    free(temp);
    list->count--;
}

void deleteLast(List *list){
    if(list->head == NULL){
        printf("List is empty\n");
        return;
    }

    if(list->head->next == NULL){
        free(list->head);
        list->head = NULL;
    } else {
        Node *current = list->head;
        while(current->next->next != NULL){
            current = current->next;
        }
        free(current->next);
        current->next = NULL;
    }
    list->count--;
}

void deletePos(List *list, int index){
    if(index < 0 || index >= list->count){
        printf("Invalid index\n");
        return;
    }

    if(index == 0){
        deleteStart(list);
        return;
    }

    Node *current = list->head;
    for(int i = 0; i < index - 1; i++){
        current = current->next;
    }

    Node *temp = current->next;
    current->next = temp->next;
    free(temp);
    list->count--;
}

int retrieve(List *list, int index){
    if(index < 0 || index >= list->count){
        printf("Invalid index\n");
        return -1;
    }

    Node *current = list->head;
    for(int i = 0; i < index; i++){
        current = current->next;
    }
    return current->data;
}

int locate(List *list, int data){
    Node *current = list->head;
    int index = 0;

    while(current != NULL){
        if(current->data == data){
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}

void display(List *list){
    Node *current = list->head;
    printf("List: ");

    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\nCount: %d\n\n", list->count);
}
