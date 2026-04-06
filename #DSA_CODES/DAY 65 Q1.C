#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

int *adj[MAX];
int size[MAX];
int visited[MAX];

int dfs(int node, int parent) {
    visited[node] = 1;
    for (int i = 0; i < size[node]; i++) {
        int next = adj[node][i];
        if (!visited[next]) {
            if (dfs(next, node)) return 1;
        } else if (next != parent) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        adj[i] = (int*)malloc(MAX * sizeof(int));
        size[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][size[u]++] = v;
        adj[v][size[v]++] = u;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1)) {
                printf("YES");
                return 0;
            }
        }
    }

    printf("NO");
    return 0;
}
