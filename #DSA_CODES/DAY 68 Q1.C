#include <stdio.h>
#include <stdlib.h>

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    int **adj = malloc(V * sizeof(int*));
    int *in = calloc(V, sizeof(int));
    int *sz = calloc(V, sizeof(int));

    int u, v;
    int *from = malloc(E * sizeof(int));
    int *to = malloc(E * sizeof(int));

    for (int i = 0; i < E; i++) {
        scanf("%d %d", &from[i], &to[i]);
        sz[from[i]]++;
        in[to[i]]++;
    }

    for (int i = 0; i < V; i++)
        adj[i] = malloc(sz[i] * sizeof(int)), sz[i] = 0;

    for (int i = 0; i < E; i++)
        adj[from[i]][sz[from[i]]++] = to[i];

    int *q = malloc(V * sizeof(int));
    int f = 0, r = 0;

    for (int i = 0; i < V; i++)
        if (in[i] == 0)
            q[r++] = i;

    int count = 0;

    while (f < r) {
        int x = q[f++];
        printf("%d ", x);
        count++;

        for (int i = 0; i < sz[x]; i++) {
            int y = adj[x][i];
            if (--in[y] == 0)
                q[r++] = y;
        }
    }

    if (count != V)
        printf("Cycle");

    return 0;
}
