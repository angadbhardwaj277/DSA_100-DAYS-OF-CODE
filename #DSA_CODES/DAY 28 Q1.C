#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, i, val;
    struct Node *head = NULL, *temp = NULL, *newNode;

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &val);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;

        if(head == NULL) {
            head = newNode;
            newNode->next = head;
            temp = head;
        } else {
            temp->next = newNode;
            newNode->next = head;
            temp = newNode;
        }
    }

    // Traversal
    if(head != NULL) {
        temp = head;
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while(temp != head);
    }

    return 0;
}
