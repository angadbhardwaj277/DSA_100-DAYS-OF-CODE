#include <stdio.h>
#include <limits.h>

int n, m;
int graph[1005][1005];
int key[1005];
int mst[1005];
int visited[1005];

int minKey() {
    int min = INT_MAX, min_index = -1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && key[i] < min) {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    key[1] = 0;

    for (int count = 1; count <= n; count++) {
        int u = minKey();
        visited[u] = 1;

        for (int v = 1; v <= n; v++) {
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                mst[v] = u;
            }
        }
    }

    int total = 0;
    for (int i = 2; i <= n; i++) {
        total += key[i];
    }

    printf("%d", total);
    return 0;
}
