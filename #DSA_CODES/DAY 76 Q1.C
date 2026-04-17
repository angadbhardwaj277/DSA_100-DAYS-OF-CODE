#include <stdio.h>

int adj[1001][1001];
int visited[1001];

void dfs(int node, int n) {
    visited[node] = 1;
    
    for(int i = 1; i <= n; i++) {
        if(adj[node][i] && !visited[i]) {
            dfs(i, n);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    
    int count = 0;
    
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            dfs(i, n);
            count++;
        }
    }
    
    printf("%d", count);
    
    return 0;
}
