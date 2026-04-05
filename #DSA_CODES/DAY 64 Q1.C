#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

int main() {
    int n;
    scanf("%d", &n);

    struct Node* adj[n];
    for(int i = 0; i < n; i++)
        adj[i] = NULL;

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

    int visited[n];
    for(int i = 0; i < n; i++)
        visited[i] = 0;

    int queue[n];
    int front = 0, rear = 0;

    visited[s] = 1;
    queue[rear++] = s;

    while(front < rear) {
        int u = queue[front++];
        printf("%d ", u);

        struct Node* temp = adj[u];
        while(temp) {
            int v = temp->vertex;
            if(!visited[v]) {
                visited[v] = 1;
                queue[rear++] = v;
            }
            temp = temp->next;
        }
    }

    return 0;
}
