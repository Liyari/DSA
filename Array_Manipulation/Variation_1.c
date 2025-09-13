#include <stdio.h>
#define MAX 10

typedef struct{
    int elem[MAX];
    int count;
}List;

//Fist Variation: Static accessable by value (DONE)

List initialize(List L);
List insertPos(List L, int data, int position);
List deletePos(List L, int position);
int locate(List L, int data);
List insertSorted(List L, int data);
void display(List L);


int main(){
    List L;
    int data, position;

    L = initialize(L);

    L= insertPos(L, 10, 1);
    L= insertPos(L, 20, 2);
    L= insertPos(L, 30, 3);
    L= insertPos(L, 40, 4);
    L= insertPos(L, 50, 5);
    display(L);

    printf("Insert data at position 2\n");
    L = insertPos(L, 60, 2);
    display(L);

    printf("Delete data at position 2\n");
    L = deletePos(L, 2);
    display(L);

    printf("Locate if 30 exists\n");
    int pos = locate(L, 30);
    if (pos != -1) {
        printf("Found at position: %d\n\n", pos + 1);  
    } else {
        printf("Not found!\n\n");
    }

    printf("Insert Sorted\n");
    L = insertSorted(L, 60);
    display(L);

    return 0;
}

List initialize(List L){
    L.count = 0;
    return L;
}

List insertPos(List L, int data, int position){
    if(L.count >= MAX){
        printf("List full.");
    }

    for(int i = L.count; i >= position; i--){
        L.elem[i] = L.elem[i - 1];
    }
    L.elem[position - 1] = data;
    L.count++;
    return L;
}

List deletePos(List L, int position){
    if(L.count == 0){
        printf("List aleady empty");
    }
    for(int i = position -1; i < L.count - 1; i++){
        L.elem[i] = L.elem[i + 1];
    }
    L.count--;
    return L;
}

int locate(List L, int data){
    for(int i = 0; i < L.count; i++){
        if(L.elem[i] == data){
        return i + 1;
        }
    }
    return -1;
}

List insertSorted(List L, int data){
    if(L.count == MAX){
        printf("List is full");
    }

    int pos = 0;

    while(pos < L.count && L.elem[pos] < data){
        pos++;
    }

    for (int i = L.count; i > pos; i--) {
        L.elem[i] = L.elem[i - 1];
    }
    L.elem[pos] = data;
    L.count++;
    return L;
}

void display(List L){
    printf("List: ");
    for(int i = 0; i < L.count; i++){
        printf("%d ", L.elem[i]);
    }
    printf("\n\n");
}
