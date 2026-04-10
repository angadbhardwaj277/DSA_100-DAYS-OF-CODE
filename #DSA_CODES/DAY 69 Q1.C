#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1000

int V;

typedef struct {
    int v, w;
} Edge;

typedef struct {
    int node, dist;
} Node;

int cmp(const void* a, const void* b) {
    return ((Node*)a)->dist - ((Node*)b)->dist;
}

int main() {
    int E, src;
    scanf("%d %d", &V, &E);

    Edge* adj[MAX];
    int sz[MAX] = {0};

    for (int i = 0; i < V; i++)
        adj[i] = malloc(V * sizeof(Edge));

    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][sz[u]].v = v;
        adj[u][sz[u]].w = w;
        sz[u]++;
    }

    scanf("%d", &src);

    int dist[MAX];
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    Node pq[MAX];
    int pqSize = 0;

    pq[pqSize++] = (Node){src, 0};

    while (pqSize) {
        qsort(pq, pqSize, sizeof(Node), cmp);
        Node cur = pq[0];

        for (int i = 1; i < pqSize; i++)
            pq[i - 1] = pq[i];
        pqSize--;

        int u = cur.node;

        for (int i = 0; i < sz[u]; i++) {
            int v = adj[u][i].v;
            int w = adj[u][i].w;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq[pqSize++] = (Node){v, dist[v]};
            }
        }
    }

    for (int i = 0; i < V; i++)
        printf("%d ", dist[i]);

    return 0;
}
