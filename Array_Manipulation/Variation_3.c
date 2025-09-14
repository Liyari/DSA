#include <stdio.h>
#include <stdlib.h>
#define MAX 10
typedef struct{
    int *elemPtr;
    int count;
    int max;
}List;

//Variation 3: Done

List initialize(List L);
List insertPos(List L, int data, int position);
List deletePos(List L, int position);
int locate(List L, int data);
List  insertSorted(List L, int data);
void display(List L);
List resize(List L);


int main(){
    List L;
    int data, position;
    L = initialize(L);

    L = insertPos(L, 10, 1);
    L =insertPos(L, 20, 2);
    L =insertPos(L, 30, 3);
    L =insertPos(L, 40, 4);
    L =insertPos(L, 50, 5);
    display(L);

    printf("Delete value at index 2...\n");
    L= deletePos(L, 2);
    display(L);

    printf("Locate if 30 exists...\n");
    int pos = locate(L, 30);
    if(pos != -1){
        printf("Found at position %d\n\n", pos - 1);
    }else{
        printf("Not found\n\n");
    }

    printf("Insert sorted...\n");
    L = insertSorted(L, 20);
    display(L);

    printf("Resizing the list...\n");
    L = resize(L);


    return 0;

}

List initialize(List L){
    L.count = 0;
    L.max = MAX;

    L.elemPtr = (int*) malloc (L.max * sizeof(int));
    return L;
}

List insertPos(List L, int data, int position){
    if(L.count == MAX){
        printf("List already full\n");
    }
    for(int i = L.count; i >= position; i--){
        L.elemPtr[i] = L.elemPtr[i - 1];
    }
    L.elemPtr[position - 1]= data;
    L.count++;
    return L;
}

List deletePos(List L, int position){
    if(L.count == 0){
        printf("List is already empty\n");
    }

    for(int i = position - 1; i < L.count - 1; i++){
        L.elemPtr[i] = L.elemPtr[i + 1];
    }
    L.count--;
    return L;
}

int locate(List L, int data){
    for(int i = 0; i < L.count; i++){
        if(L.elemPtr[i] == data){
            return i + 1;
        }
    }
    return -1;
}

List  insertSorted(List L, int data){
    if(L.count == MAX){
        printf("List is already full\n");
    }

    int pos = 0;

    while(pos < L.count && L.elemPtr[pos] < data){
        pos++;
    }

    for(int i = L.count; i > pos; i--){
        L.elemPtr[i] = L.elemPtr[i - 1];
    }
    L.elemPtr[pos - 1]= data;
    L.count++;

    return L;
}

void display(List L){
    printf("List: ");
    for(int i = 0; i < L.count; i++){
        printf("%d ", L.elemPtr[i]);
    }
    printf("\n\n");
}

List resize(List L){
    int newMax = L.max * 2;  
    int *newArr = (int*) malloc(newMax * sizeof(int));

    for (int i = 0; i < L.count; i++) {
        newArr[i] = L.elemPtr[i];
    }

    free(L.elemPtr);   
    L.elemPtr = newArr;
    L.max = newMax;    
    return L;
}
