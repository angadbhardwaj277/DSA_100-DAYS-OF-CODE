#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int u, v, w;
} Edge;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Edge *edges = malloc(m * sizeof(Edge));
    for (int i = 0; i < m; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);

    int src;
    scanf("%d", &src);

    int *dist = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < m; j++)
            if (dist[edges[j].u] != INT_MAX &&
                dist[edges[j].u] + edges[j].w < dist[edges[j].v])
                dist[edges[j].v] = dist[edges[j].u] + edges[j].w;

    for (int j = 0; j < m; j++)
        if (dist[edges[j].u] != INT_MAX &&
            dist[edges[j].u] + edges[j].w < dist[edges[j].v]) {
            printf("NEGATIVE CYCLE");
            return 0;
        }

    for (int i = 0; i < n; i++)
        printf("%d ", dist[i]);

    return 0;
}
