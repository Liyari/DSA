#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

bool isElem(int set[], int size, int elem){
    for(int i = 0; i < size; i++){
        if(elem == set[i]){
            return true;
        }
    }
    return false;
}
void insertElem(int set[], int *size, int elem){
    if(*size == MAX){
        printf("Size is full.\n");
        return;
    }
    if(elem % 2 != 0){
        printf("Error! %d is not an even number.\n", elem);
        return;
    }
    if(isElem(set, *size, elem)){
        printf("%d is already in the array.\n", elem);
        return;
    }
    set[*size] = elem;
    (*size)++;
}
void printSet(int set[], int size){
    printf("Set List: ");
    for(int i = 0; i < size; i++){
        printf("%d ", set[i]);
            if(i < size - 1) printf(", ");
    }
}

int main(){
    int set[MAX] = {0};
    int size = 0;

    insertElem(set, &size, 2);
    insertElem(set, &size, 4);
    insertElem(set, &size, 3);  
    insertElem(set, &size, 2);  
    insertElem(set, &size, 8);
    insertElem(set, &size, 10);
    insertElem(set, &size, 12);
    insertElem(set, &size, 16);


    printSet(set, size);

    return 0;
}