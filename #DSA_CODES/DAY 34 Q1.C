#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

int pop(){
    struct Node* temp = top;
    int x = temp->data;
    top = top->next;
    free(temp);
    return x;
}

int main(){
    char exp[100];
    fgets(exp,100,stdin);
    char *t = strtok(exp," \n");

    while(t){
        if(isdigit(t[0]) || (t[0]=='-' && isdigit(t[1]))){
            push(atoi(t));
        }else{
            int b = pop();
            int a = pop();
            if(t[0]=='+') push(a+b);
            else if(t[0]=='-') push(a-b);
            else if(t[0]=='*') push(a*b);
            else if(t[0]=='/') push(a/b);
        }
        t = strtok(NULL," \n");
    }

    printf("%d",pop());
    return 0;
}
