#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    char elem;
    struct node *link;
} *charList;

bool findElem(charList L, char searchElem);

charList insertFront(charList L, char data) {
    charList temp = (charList)malloc(sizeof(struct node));
    temp->elem = data;
    temp->link = L;
    return temp;
}

int main() {
    charList L = NULL;
    bool result;
    char searchElem;

    L = NULL;
    searchElem = 'A';
    result = findElem(L, searchElem);
    printf("Test Case a (Empty List): %s\n", result ? "Element Found" : "Element Not Found");

    L = NULL;
    L = insertFront(L, 'C');
    L = insertFront(L, 'B');
    L = insertFront(L, 'A');

    searchElem = 'B';
    result = findElem(L, searchElem);
    printf("Test Case b (Element in List): %s\n", result ? "Element Found" : "Element Not Found");

    searchElem = 'Z';
    result = findElem(L, searchElem);
    printf("Test Case c (Element not in List): %s\n", result ? "Element Found" : "Element Not Found");

    return 0;
}

bool findElem(charList L, char searchElem) {
    bool found = false;
    charList current = L;
    while (current != NULL) {
        if (current->elem == searchElem) {
            found = true;
        }
        current = current->link;
    }
    return found;
}
