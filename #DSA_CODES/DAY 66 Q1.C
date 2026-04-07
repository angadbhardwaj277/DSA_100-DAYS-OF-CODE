#include <stdio.h>
#include <stdlib.h>

int** adj;
int* visited;
int* recStack;
int V;

int dfs(int node) {
    if (!visited[node]) {
        visited[node] = 1;
        recStack[node] = 1;

        for (int i = 0; i < V; i++) {
            if (adj[node][i]) {
                if (!visited[i] && dfs(i))
                    return 1;
                else if (recStack[i])
                    return 1;
            }
        }
    }
    recStack[node] = 0;
    return 0;
}

int main() {
    int E;
    scanf("%d %d", &V, &E);

    adj = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        adj[i] = (int*)calloc(V, sizeof(int));
    }

    visited = (int*)calloc(V, sizeof(int));
    recStack = (int*)calloc(V, sizeof(int));

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    for (int i = 0; i < V; i++) {
        if (dfs(i)) {
            printf("YES");
            return 0;
        }
    }

    printf("NO");
    return 0;
}
