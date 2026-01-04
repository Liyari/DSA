#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 10
#define LEN 30
typedef char String[LEN];

bool isElem(String set[], int size, String elem){
    for(int i = 0; i < size; i++){
        if(strcmp(elem, set[i]) == 0){
            return true;
        }
    }
    return false;
}
void insertElem(String set[], int *size, String elem){
    if(*size == MAX){
        printf("Set already full.\n");
        return;
    }
    if(isElem(set, *size, elem)){
        printf("Fruit already exists.\n");
        return;
    }
    
    strcpy(set[*size], elem);
    (*size)++;

}
void printSet(String set[], int size){
    printf("Fruit Basket: \n");
    for(int i = 0; i < size; i++){
        printf("%s ", set[i]);
        if(i < size - 1) printf(", ");
    }
}

int main(){
    String fruits[MAX];
    int size = 0;

    insertElem(fruits, &size, "Apple");
    insertElem(fruits, &size, "Banana");
    insertElem(fruits, &size, "Mango");
    insertElem(fruits, &size, "Banana"); 

    printSet(fruits, size);

    return 0;
}
