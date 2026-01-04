#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct{
    int *elemPtr;
    int count;
    int max;
}List;

//Variation 4: Done

void initialize(List *L);
void insertPos(List *L, int data, int position);
void deletePos(List *L, int position);
int locate(List *L, int data);
int retrieve(List *L, int position);
void insertSorted(List *L, int data);
void display(List *L);
void resize(List *L);
void makeNULL(List *L);

int main(){
    List L;
    int data, position;
    initialize(&L);

    insertPos(&L, 10, 1);
    insertPos(&L, 20, 2);
    insertPos(&L, 30, 3);
    insertPos(&L, 40, 4);
    insertPos(&L, 50, 5);
    display(&L);

    printf("Delete value at index 2...\n");
    deletePos(&L, 2);
    display(&L);

    printf("Locate if 30 exists...\n");
    int pos = locate(&L, 30);
    if(pos != -1){
        printf("Found at position %d\n\n", pos);
    } else {
        printf("Not found\n\n");
    }

    printf("Insert sorted...\n");
    insertSorted(&L, 25);
    display(&L);

    printf("Resizing the list...\n");
    resize(&L);
    printf("New max capacity: %d\n", L.max);

    return 0;
}

void initialize(List *L){
    L->count = 0;
    L->max = MAX;

    L->elemPtr = (int*) malloc (L->max * (sizeof(int)));
}

void insertPos(List *L, int data, int position){
    if(L->count == MAX){
        printf("List is full");
    }

    for(int i = L->count; i >= position; i--){
        L->elemPtr[i] = L->elemPtr[i - 1];
    }
    L->elemPtr[position - 1] = data;
    L->count++;
}

void deletePos(List *L, int position){
    if(L->count == 0){
        printf("List already empty");
    }

    for(int i = position - 1; i < L->count - 1; i++){
        L->elemPtr[i] = L->elemPtr[i + 1];
    }
    L->count--;
}

int locate(List *L, int data){
    for(int i = 0; i < L->count; i++){
        if(L->elemPtr[i] == data){
            return i + 1;
        }
    }
    return -1;
}

int retrieve(List *L, int position){
    if(position < 1 || position > L->count) return -1;
    return L->elemPtr[position - 1];
}

void insertSorted(List *L, int data){
    if(L->count == MAX){
        printf("List already full");
    }
    int pos = 0;

    while(pos < L->count && L->elemPtr[pos] < data){
        pos++;
    }

    for(int i = L->count; i >= pos; i--){
        L->elemPtr[i] = L->elemPtr[i - 1];
    }
    L->elemPtr[pos] = data;
    L->count++;
}


void display(List *L){
    printf("List: ");
    for(int i = 0; i < L->count; i++){
        printf("%d ", L->elemPtr[i]);
    }
    printf("\n\n");
}

void resize(List *L){
    int newMax = L->max * 2;  
    int *newArr = (int*) malloc(newMax * sizeof(int));

    for (int i = 0; i < L->count; i++) {
        newArr[i] = L->elemPtr[i];
    }

    free(L->elemPtr);   
    L->elemPtr = newArr;
    L->max = newMax;    
}

void makeNULL(List *L){
    L->count = 0;
}
