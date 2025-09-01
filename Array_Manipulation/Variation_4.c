#include <stdio.h>
#define LENGTH 10

typedef struct{
    studType *elemPtr;
    int count;
    int max
}List;

void initialize(List *L);
void insertPos(List L, studType elem, int pos);
void deletePos(List L, int pos);


int main(){
    List L;
    studType elem; 
}