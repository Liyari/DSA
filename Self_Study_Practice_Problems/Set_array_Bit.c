#include <stdio.h>
#include <stdbool.h>

#define MAX 50  

typedef struct {
    int elements[MAX];   
    int size;            
} Set;

void initSet(Set* s){
    s->size = 0;
}
bool contains(Set* s, int val){
    for(int i = 0; i < s->size; i++){
        if(s->elements[i] == val){
            return true;
        }
    }
    return false;
}
bool addElement(Set* s, int val){
    if(s->size >= MAX || contains(s, val)){
        return false;
    }
    s->elements[s->size] = val;
    s->size++;
    return true;
}
bool removeElement(Set* s, int val){
    for(int i = 0; i < s->size; i++){
        if(s->elements[i] == val){
            for(int j = i; j < s->size -1; j++){
                s->elements[j] = s->elements[j+1];
            }
            s->size--;
            return true;
        }
    }
    return false;
}
Set unionSets(Set* A, Set* B){
    Set result;
    initSet(&result);
    
    for(int i = 0; i < A->size; i++){
        addElement(&result, A->elements[i]);
    }
    for(int i = 0; i < B->size; i++){
        addElement(&result, B->elements[i]);
    }
    
    return result;
}
Set intersectSets(Set* A, Set* B){
    Set result;
    initSet(&result);
    
    for(int i = 0; i < A->size; i++){
        if(contains(B, A->elements[i])){
            addElement(&result, A->elements[i]);
        }
    }
    return result;
}
Set differenceSets(Set* A, Set* B){
    Set result;
    initSet(&result);
    
    for(int i = 0; i < A->size; i++){
        if(!contains(B, A->elements[i])){
            addElement(&result, A->elements[i]);
        }
    }
    return result;
}
void printSet(Set* s){
    printf("{");
    for(int i = 0; i < s->size; i++){
        printf("%d ", s->elements[i]);
    }
    printf("}\n");
}

int main() {
    Set A, B, U, I, D;
    initSet(&A);
    initSet(&B);

    // Add elements
    addElement(&A, 10);
    addElement(&A, 20);
    addElement(&A, 30);

    addElement(&B, 30);
    addElement(&B, 40);
    addElement(&B, 50);

    printf("Set A: ");
    printSet(&A);

    printf("Set B: ");
    printSet(&B);

    // Union
    U = unionSets(&A, &B);
    printf("Union (A ∪ B): ");
    printSet(&U);

    // Intersection
    I = intersectSets(&A, &B);
    printf("Intersection (A ∩ B): ");
    printSet(&I);

    // Difference
    D = differenceSets(&A, &B);
    printf("Difference (A - B): ");
    printSet(&D);

    // Remove test
    printf("\nRemoving 20 from A...\n");
    removeElement(&A, 20);
    printSet(&A);

    return 0;
}