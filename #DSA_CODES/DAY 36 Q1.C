#include <stdio.h>

int main()
{
    int n,m;
    scanf("%d",&n);

    int q[1000];
    int front=0,rear=-1;

    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        rear=(rear+1)%1000;
        q[rear]=x;
    }

    scanf("%d",&m);

    for(int i=0;i<m;i++)
    {
        front=(front+1)%1000;
        rear=(rear+1)%1000;
        q[rear]=q[(front+n-1)%1000];
    }

    int count=n;
    int idx=front;

    for(int i=0;i<count;i++)
    {
        printf("%d ",q[idx]);
        idx=(idx+1)%1000;
    }

    return 0;
}
