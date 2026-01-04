/*1st Activity(08/26/25)
From PracticeExer_01_Array File*/

#include <stdio.h>
#include <stdbool.h>

#define MAX 10

typedef bool BOOL;

typedef struct {
    char elem[MAX];
    int count;
} charList;

BOOL findElem(charList L, char searchElem);

int main(){
    charList L;
    char searchElem;
    BOOL result;

    L.count = 0;
    searchElem = 'A';
    result = findElem(L, searchElem);
    printf("Test Case a: %s\n", result ? "Element Found" : "Element Not Found");

    L.count = 3;
    L.elem[0] = 'A';
    L.elem[1] = 'B';
    L.elem[2] = 'C';
    searchElem = 'B';
    result = findElem(L, searchElem);
    printf("Test Case b: %s\n", result ? "Element Found" : "Element Not Found");

    searchElem = 'Z';
    result = findElem(L, searchElem);
    printf("Test Case c: %s\n", result ? "Element Found" : "Element Not Found");

    return 0;
}

BOOL findElem(charList L, char searchElem){
    BOOL found = false;
    
    if(L.count > 0){
        int i = 0;
        while(i < L.count && !found){
            if(L.elem[i] == searchElem){
                found = true;
            }
            i++;
        }
    }
    
    return found;
}
