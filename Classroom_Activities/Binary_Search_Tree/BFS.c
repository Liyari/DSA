#include <stdio.h>
#include <stdlib.h>

#define MAX 9
#define V -1
#define U -2

typedef struct node {
    int elem;
    struct node* link;
}ntype, *ptr;

typedef ptr Graph[MAX];

void bfs(Graph G, int start){
    int visited[MAX];
    int queue[MAX];
    int front = 0, rear = 0;

    
    for(int i = 0; i < MAX; ++i){
        visited[i] = U;
    }

    
    visited[start] = V;
    printf("%d ", start);

    
    queue[rear++] = start;

    while(front < rear) {
        int v = queue[front++];   

        
        ptr trav = G[v];
        while(trav != NULL){
            int w = trav->elem;

            if(visited[w] == U){      
                visited[w] = V;       
                printf("%d ", w);     
                queue[rear++] = w;    
            }

            trav = trav->link;
        }
    }
}

int main() {
    Graph G = {NULL};

    addEdge(G, 0, 1);
    addEdge(G, 0, 2);
    addEdge(G, 1, 3);
    addEdge(G, 1, 4);
    addEdge(G, 2, 5);
    addEdge(G, 2, 6);
    addEdge(G, 3, 7);
    addEdge(G, 4, 7);
    addEdge(G, 5, 8);
    addEdge(G, 6, 8);

    bfs(G, 0);

    return 0;
}
