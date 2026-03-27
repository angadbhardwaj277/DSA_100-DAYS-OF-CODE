#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    if(arr[0] == -1) return 0;

    struct Node* root = newNode(arr[0]);
    struct Node* queue[n];
    int front = 0, rear = 0;
    queue[rear++] = root;

    int i = 1;
    while(i < n) {
        struct Node* curr = queue[front++];

        if(arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if(i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    front = rear = 0;
    queue[rear++] = root;

    while(front < rear) {
        int size = rear - front;
        for(int j = 0; j < size; j++) {
            struct Node* temp = queue[front++];
            if(j == size - 1)
                printf("%d ", temp->data);
            if(temp->left)
                queue[rear++] = temp->left;
            if(temp->right)
                queue[rear++] = temp->right;
        }
    }

    return 0;
}
