#include <stdio.h>
#include <stdlib.h>

int** adj;
int* visited;
int* stack;
int top = -1;
int V;

void dfs(int v) {
    visited[v] = 1;
    for (int i = 0; i < V; i++) {
        if (adj[v][i] && !visited[i])
            dfs(i);
    }
    stack[++top] = v;
}

int main() {
    int E;
    scanf("%d %d", &V, &E);

    adj = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++)
        adj[i] = (int*)calloc(V, sizeof(int));

    visited = (int*)calloc(V, sizeof(int));
    stack = (int*)malloc(V * sizeof(int));

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    for (int i = 0; i < V; i++)
        if (!visited[i])
            dfs(i);

    while (top != -1)
        printf("%d ", stack[top--]);

    return 0;
}
