#include <stdio.h>
#include <stdlib.h>

typedef struct List {
    int data;
    struct List* next;
} List;

List* initialize(int size);
void display(List *L);
List* concatenate(List* list1, List* list2);   

int main(){
    int size1, size2;
    printf("Enter size of first linked list: ");
    scanf("%d", &size1);
    List* list1 = initialize(size1);
    
    printf("Enter size of second linked list: ");
    scanf("%d", &size2);
    List* list2 = initialize(size2);
    
    printf("First linked list: ");
    display(list1);
    
    printf("\nSecond linked list: ");
    display(list2);
    
    List* combined = concatenate(list1, list2);
    printf("\nConcatenated linked list: ");
    display(combined);

    return 0;
}

List* initialize(int size){
    List *head = NULL;
    List *tail = NULL;
    
    for(int i = 0; i < size; i++){
        List* newNode = (List*)malloc(sizeof(List));
        printf("Enter element %d: ", i+1);
        scanf("%d", &newNode->data);
        newNode->next = NULL;  

        if (head == NULL) {
            head = newNode;    
            tail = newNode;
        } else {
            tail->next = newNode; 
            tail = newNode;      
        }
    }
    return head;
}

void display(List *head){
    List *current = head;
    
    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    printf("NULL\n");   
}

List* concatenate(List* list1, List* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    List* temp = list1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = list2;
    return list1;
}
