#include <stdio.h>
#define MAX 10

typedef struct{
    int elem[MAX];
    int count;
}List;

//Fist Variation: Static accessable by value

List initialize(List L, int size);
void display(List L);
List insertPos(List L, int data, int position);
List deletePos(List L, int position);
int locate(List L, int data);
List insertSorted(List L, int data);

int main(){
    List L;
    int size;

    printf("Enter List Size: ");
    scanf("%d", &size);

    L = initialize(L, size);

    display(L);

    printf("Element 8 inserted at Position 3");
    L = insertPos(L, 8, 3);

    display(L);

    printf("Element 2 deleted");
    L=deletePos(L, 2);

    display(L);

    return 0;
}

List initialize(List L, int size) {
    L.count = 0;  
    for (int i = 0; i < size && i < MAX; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &L.elem[i]);
        L.count++;
    }
    return L;
}


void display(List L){
    printf("Element List: \n");
    for(int i = 0; i < L.count; i++){
        printf("%d\n", L.elem[i]);
    }
    printf("\n");
}

List insertPos(List L, int data, int position){
    for (int i = L.count; i >= position; i--) {
        L.elem[i] = L.elem[i - 1];
    }

    L.elem[position - 1] = data;
    L.count++;
    return L;
}

List deletePos(List L, int position){
    for(int i = position-1; i < L.count; i++){
        L.elem[i] = L.elem[i + 1];
    }

    L.count--;
    return L;
}

int locate(List L, int data){
    int pos = 0;

    for(int i = 0; i < L.count; i++){
        if(L.elem[i]== data){
            printf("found at position %d", pos);
        }else{
            printf("Not found");
        }
    }

    return pos;
}

List insertSorted(List L, int data){
    printf("Hekhok");
}