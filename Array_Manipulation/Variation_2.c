#include <stdio.h>
#define MAX 10

typedef struct{
    int elem[MAX];
    int count;
}Etype, *EPtr;

//Second Variation: Done

void initialize(EPtr L);
void insertPos(EPtr L, int data, int position);
void deletePos(EPtr L, int position);
int locate(EPtr L, int data);
int retrieve(EPtr L, int position);
void insertSorted(EPtr L, int data);
void display(EPtr L);
void makeNULL(EPtr L);

int main(){
    Etype L;
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

    printf("Locate if value exists...\n");
    int pos = locate(&L, 10);
    if (pos != -1) {
        printf("Found at position: %d\n\n", pos + 1);  
    } else {
        printf("Not found!\n\n");
    }

    printf("Retreive value at position 3...\n");
    int get = retrieve(&L, 3);

     if(get != -1){
        printf("Value at position 3: %d\n\n", get);
    } else {
        printf("Invalid position!\n\n");
    }

    printf("Inserting 25 in sorted order...\n");
    insertSorted(&L, 25);
    display(&L);

    printf("Clearing the list...\n");
    makeNULL(&L);
    display(&L);

    return 0;
}

void initialize(EPtr L){
    L->count = 0;
}

void insertPos(EPtr L, int data, int position){
    for(int i = L->count; i >= position; i--){
        L->elem[i] = L->elem[i - 1];
    }
    L->elem[position-1] = data;
    L->count++;
}

void deletePos(EPtr L, int position){
    if(L->count == 0){
        printf("List is empty.");
    }

    for(int i = position - 1; i < L->count - 1; i++){
        L->elem[i] = L->elem[i + 1];
    }
    L->count--;
}

int locate(EPtr L, int data){
    for(int i = 0; i < L->count; i++){
        if(L->elem[i] == data){
            return i + 1;
        }
    }
    return -1;
}

int retrieve(EPtr L, int position){
    if(position < 1 || position > L->count) return -1;
    return L->elem[position - 1];
}

void insertSorted(EPtr L, int data){
    int pos = 0;

    while(pos < L->count && L->elem[pos] < data){
        pos++;
    }

    for(int i = L->count; i >= pos; i--){
        L->elem[i] = L->elem[i - 1];
    }
    L->elem[pos] = data;
    L->count++;
}

void display(EPtr L){
    printf("List: ");
    for(int i = 0; i < L->count; i++){
        printf("%d ", L->elem[i]);
    }
    printf("\n\n");
}

void makeNULL(EPtr L){
    L->count = 0;
}



