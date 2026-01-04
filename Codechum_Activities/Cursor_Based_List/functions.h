#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "types.h"
#include <stdio.h>
#include <string.h>

void initVHeap(VHeap *vh) {
    for (int i = 0; i < MAX_SIZE - 1; i++) {
        vh->H[i].next = i + 1;
    }
    vh->H[MAX_SIZE - 1].next = -1;
    vh->avail = 0;
}

int alloc(VHeap *vh) {
    if (vh->avail == -1) return -1;
    int p = vh->avail;
    vh->avail = vh->H[p].next;
    return p;
}

int insertArticle(VHeap *vh, int *L, Article a, int position) {
    int newCell = alloc(vh);
    if (newCell == -1) {
        printf("Error: Heap is full. Cannot insert new article.\n");
        return 0;
    } 

    vh->H[newCell].article = a;

    if (*L == -1 || position == 0) {
        vh->H[newCell].next = *L;
        *L = newCell;
        return 1;
    }

    int curr = *L, prev = -1, idx = 0;
    while (curr != -1 && (position == -1 || idx < position)) {
        prev = curr;
        curr = vh->H[curr].next;
        idx++;
    }

    vh->H[newCell].next = curr;
    vh->H[prev].next = newCell;
    return 1;
}

void viewArticles(VHeap vh, int L) {
    if (L == -1) {
        printf("The knowledge base is empty.\n");
        return;
    }
    int curr = L;
    printf("\n--- List of Articles ---\n");
    while (curr != -1) {
        printf("ID: %d | Title: %s\n", vh.H[curr].article.id, vh.H[curr].article.title);
        curr = vh.H[curr].next;
    }
    printf("------------------------\n\n");
}

void searchArticle(VHeap vh, int L, int id) {
    int curr = L;
    while (curr != -1) {
        if (vh.H[curr].article.id == id) {
            printf("\n--- Article Found ---\n");
            printf("ID: %d\n", vh.H[curr].article.id);
            printf("Title: %s\n", vh.H[curr].article.title);
            printf("Content: %s\n", vh.H[curr].article.content);
            printf("---------------------\n\n");
            return;
        }
        curr = vh.H[curr].next;
    }
    printf("Article with ID %d not found.\n\n", id);
}

int deleteArticle(VHeap *vh, int *L, int id) {
    int curr = *L, prev = -1;
    while (curr != -1) {
        if (vh->H[curr].article.id == id) {
            if (prev == -1) {
                *L = vh->H[curr].next;
            } else {
                vh->H[prev].next = vh->H[curr].next;
            }
            vh->H[curr].next = vh->avail;
            vh->avail = curr;
            printf("Article with ID %d deleted successfully.\n\n", id);
            return 1;
        }
        prev = curr;
        curr = vh->H[curr].next;
    }
    printf("Article with ID %d not found.\n\n", id);
    return 0;
}

#endif