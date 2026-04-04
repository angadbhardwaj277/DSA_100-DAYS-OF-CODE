#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

void dfs(struct Node* adj[], int visited[], int v) {
    visited[v] = 1;
    printf("%d ", v);
    
    struct Node* temp = adj[v];
    while(temp) {
        if(!visited[temp->vertex]) {
            dfs(adj, visited, temp->vertex);
        }
        temp = temp->next;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* adj[n];
    int visited[n];

    for(int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    for(int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);
        for(int j = 0; j < k; j++) {
            int v;
            scanf("%d", &v);
            
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->vertex = v;
            newNode->next = adj[i];
            adj[i] = newNode;
        }
    }

    int s;
    scanf("%d", &s);

    dfs(adj, visited, s);

    return 0;
}
