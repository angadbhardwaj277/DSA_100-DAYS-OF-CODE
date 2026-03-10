#include <stdio.h>
#define MAX 1000

int dq[MAX];
int front = -1;
int rear = -1;

void push_front(int x){
    if(front == -1){
        front = rear = 0;
    }else if(front == 0){
        printf("Overflow\n");
        return;
    }else{
        front--;
    }
    dq[front] = x;
}

void push_back(int x){
    if(front == -1){
        front = rear = 0;
    }else if(rear == MAX-1){
        printf("Overflow\n");
        return;
    }else{
        rear++;
    }
    dq[rear] = x;
}

void pop_front(){
    if(front == -1){
        printf("Underflow\n");
        return;
    }
    if(front == rear){
        front = rear = -1;
    }else{
        front++;
    }
}

void pop_back(){
    if(front == -1){
        printf("Underflow\n");
        return;
    }
    if(front == rear){
        front = rear = -1;
    }else{
        rear--;
    }
}

int get_front(){
    if(front == -1) return -1;
    return dq[front];
}

int get_back(){
    if(front == -1) return -1;
    return dq[rear];
}

int empty(){
    if(front == -1) return 1;
    return 0;
}

int size(){
    if(front == -1) return 0;
    return rear - front + 1;
}

void display(){
    if(front == -1){
        printf("Deque Empty\n");
        return;
    }
    for(int i=front;i<=rear;i++){
        printf("%d ",dq[i]);
    }
    printf("\n");
}

int main(){
    push_back(10);
    push_back(20);
    push_front(5);
    push_back(30);
    display();
    printf("%d\n", get_front());
    printf("%d\n", get_back());
    pop_front();
    pop_back();
    display();
    printf("%d\n", size());
    printf("%d\n", empty());
    return 0;
}
