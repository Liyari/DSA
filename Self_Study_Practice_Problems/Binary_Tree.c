#include <stdio.h>
#include <stdlib.h> 

typedef struct node{
    int elem;
    struct node *LC;
    struct node *RC;
}Node, *BST;

void insert(BST * T, int value){
    BST *trav; 
    for(trav = T; *trav != NULL && (*trav)->elem != value;){
        trav = ((*trav)->elem > value ? &(*trav)->LC : &(*trav)->RC);
    }
    
    //using calloc
    if(*trav == NULL){
        *trav = (BST)calloc(1, sizeof(Node));
        (*trav)->elem = value;
    }
    /*//using malloc
        if(*trav == NULL) {
        *trav = (BST)malloc(sizeof(Node));
        (*trav)->elem = value;
        (*trav)->LC = NULL;
        (*trav)->RC = NULL;
    }*/
}

void inorder(BST B){
    if(B != NULL){
        inorder(B->LC);
        printf("%d ", B->elem);
        inorder(B->RC);
    }
}

int main(){
    BST B = NULL;

    insert(&B, 5);
    insert(&B, 3);
    insert(&B, 7);

    printf("BST inorder: ");
    inorder(B); 
    printf("\n");

    return 0;
}