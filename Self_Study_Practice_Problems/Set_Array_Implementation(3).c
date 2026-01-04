#include <stdio.h>
#include <stdbool.h>
#define MAX 50

bool isElem(int set[], int size, int elem){
    for (int i = 0; i < size; i++){
        if (set[i] == elem)
            return true;
    }
    return false;
}
void insertElem(int set[], int *size, int elem){
    if(*size == MAX){
        printf("Set full.\n");
        return;
    }
    if(isElem(set, *size, elem)){
        printf("Element already exists in the set.\n");
        return;
    }
    set[*size] = elem;
    (*size)++;
}
void deleteElem(int set[], int *size, int elem){
    for(int i = 0; i < *size; i++){
        if(set[i] == elem){
            for(int j = i; i < *size-1; i++){
                set[j] = set[j+1];
                (*size)--;
                return;
            }
        }
    }
}
void printSet(int set[], int size){
    printf("Set: ");
    for(int i = 0; i < size; i++){
        printf("%d ", set[i]);
        
    }
}

int main(){
    int studentIDs[MAX];
    int size = 0;

    insertElem(studentIDs, &size, 101);
    insertElem(studentIDs, &size, 105);
    insertElem(studentIDs, &size, 109);
    insertElem(studentIDs, &size, 105); 

    printf("Initial IDs:\n");
    printSet(studentIDs, size);

    deleteElem(studentIDs, &size, 105);

    printf("\nAfter Deletion:\n");
    printSet(studentIDs, size);

    return 0;
}