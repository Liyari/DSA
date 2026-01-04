#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "sets.h"

Node* createNode(String spell) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strcpy(newNode->spell, spell);
    newNode->next = NULL;
    return newNode;
}

Set* createSet() {
    Set* set = (Set*)malloc(sizeof(Set));
    if (set == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    set->head = NULL;
    set->size = 0;
    return set;
}

bool containsSpell(Set* set, String spell) {
    Node* current = set->head;
    while (current != NULL) {
        if (strcmp(current->spell, spell) == 0)
            return true;
        current = current->next;
    }
    return false;
}

bool addSpell(Set* set, String spell) {
    if (containsSpell(set, spell))
        return false;

    Node* newNode = createNode(spell);
    newNode->next = set->head;
    set->head = newNode;
    set->size++;
    return true;
}

bool removeSpell(Set** set, String spell) {
    if (*set == NULL || (*set)->head == NULL)
        return false;

    Node* current = (*set)->head;
    Node* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->spell, spell) == 0) {
            if (prev == NULL)
                (*set)->head = current->next;
            else
                prev->next = current->next;

            free(current);
            (*set)->size--;
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;
}

void printSet(Set* set) {
    if (set == NULL || set->head == NULL) {
        printf("(empty)\n");
        return;
    }

    Node* current = set->head;
    int index = 1;
    while (current != NULL) {
        printf("  %d. %s\n", index, current->spell);
        current = current->next;
        index++;
    }
}


void destroySet(Set* set) {
    if (set == NULL) return;

    Node* current = set->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(set);
}

Set* unionSets(Set* set1, Set* set2) {
    Set* result = createSet();

    Node* current = set1->head;
    while (current != NULL) {
        addSpell(result, current->spell);
        current = current->next;
    }

    current = set2->head;
    while (current != NULL) {
        addSpell(result, current->spell);
        current = current->next;
    }

    return result;
}

Set* intersectSets(Set* set1, Set* set2) {
    Set* result = createSet();
    Node* current = set1->head;

    while (current != NULL) {
        if (containsSpell(set2, current->spell))
            addSpell(result, current->spell);
        current = current->next;
    }

    return result;
}