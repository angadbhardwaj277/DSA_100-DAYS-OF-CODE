#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    int hd;
    struct Node *left, *right;
} Node;

Node* newNode(int data) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->hd = 0;
    n->left = n->right = NULL;
    return n;
}

Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    Node** queue = (Node**)malloc(n * sizeof(Node*));
    int front = 0, rear = 0;
    Node* root = newNode(arr[0]);
    queue[rear++] = root;
    int i = 1;
    while (i < n) {
        Node* curr = queue[front++];
        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }
    free(queue);
    return root;
}

typedef struct QNode {
    Node* node;
    int hd;
} QNode;

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    Node* root = buildTree(arr, n);
    if (!root) return 0;

    QNode* queue = (QNode*)malloc(n * sizeof(QNode));
    int front = 0, rear = 0;

    int map[2001][2001] = {0};
    int count[2001] = {0};
    int offset = 1000;

    queue[rear++] = (QNode){root, 0};

    int min = 0, max = 0;

    while (front < rear) {
        QNode temp = queue[front++];
        Node* node = temp.node;
        int hd = temp.hd;

        if (hd < min) min = hd;
        if (hd > max) max = hd;

        map[hd + offset][count[hd + offset]++] = node->data;

        if (node->left)
            queue[rear++] = (QNode){node->left, hd - 1};
        if (node->right)
            queue[rear++] = (QNode){node->right, hd + 1};
    }

    for (int i = min; i <= max; i++) {
        for (int j = 0; j < count[i + offset]; j++) {
            printf("%d ", map[i + offset][j]);
        }
        printf("\n");
    }

    free(queue);
    return 0;
}
