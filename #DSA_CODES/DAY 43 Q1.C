#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* newNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Node* buildTree(int arr[], int n) {
    if(n == 0 || arr[0] == -1) return NULL;

    Node* root = newNode(arr[0]);
    Node* queue[n];
    int front = 0, rear = 0;
    queue[rear++] = root;
    int i = 1;

    while(i < n) {
        Node* current = queue[front++];

        if(arr[i] != -1) {
            current->left = newNode(arr[i]);
            queue[rear++] = current->left;
        }
        i++;

        if(i < n && arr[i] != -1) {
            current->right = newNode(arr[i]);
            queue[rear++] = current->right;
        }
        i++;
    }

    return root;
}

void inorder(Node* root) {
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);

    Node* root = buildTree(arr, n);
    inorder(root);
    return 0;
}
