#include <stdio.h>
#define MAX 10

typedef struct{
    int elem[MAX];
    int count;
}Etype, *EPtr;

void inialize(EPtr L, int size);
void insertPos(EPtr L, int data, int position);
void deletePos(EPtr L, int position);
int locate(EPtr L, int data);
int retrieve(EPtr L, int position);
void insertSorted(EPtr L, int data);
void makeNULL(EPtr L);

int main(){
    EPtr L;
    int size;

    printf("Enter List Size: ");
    scanf("%d", &size);

    initialize(&L, size);


}

void initialize(EPtr L, int size){
    for(int i = 0; i < size; i++){
        printf("Enter Value: ");
        scanf("%d", &L->elem[i]);
        printf("\n");
    }
}