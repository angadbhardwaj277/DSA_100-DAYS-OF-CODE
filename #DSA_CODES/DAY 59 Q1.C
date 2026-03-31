#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

int search(int inorder[], int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}

struct Node* build(int inorder[], int postorder[], int start, int end, int* pIndex) {
    if (start > end)
        return NULL;

    int val = postorder[*pIndex];
    (*pIndex)--;

    struct Node* root = createNode(val);

    if (start == end)
        return root;

    int i = search(inorder, start, end, val);

    root->right = build(inorder, postorder, i + 1, end, pIndex);
    root->left = build(inorder, postorder, start, i - 1, pIndex);

    return root;
}

void preorder(struct Node* root) {
    if (!root)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int inorder[n], postorder[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    int pIndex = n - 1;

    struct Node* root = build(inorder, postorder, 0, n - 1, &pIndex);

    preorder(root);

    return 0;
}
