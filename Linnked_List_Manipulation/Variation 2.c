#include <stdio.h>

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
    List list;
}

List *initialize(){
    
}
