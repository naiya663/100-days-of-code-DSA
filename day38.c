#include <stdio.h>
#include <string.h>

int main()
{
    int dq[100], front = -1, rear = -1;
    int n, x, i;
    char op[20];

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%s",op);

        if(strcmp(op,"push_front")==0)
        {
            scanf("%d",&x);
            if(front==-1)
                front=rear=0;
            else
                front--;
            dq[front]=x;
        }

        else if(strcmp(op,"push_back")==0)
        {
            scanf("%d",&x);
            if(front==-1)
                front=rear=0;
            else
                rear++;
            dq[rear]=x;
        }

        else if(strcmp(op,"pop_front")==0)
        {
            if(front==-1)
                printf("-1\n");
            else
                front++;
        }

        else if(strcmp(op,"pop_back")==0)
        {
            if(front==-1)
                printf("-1\n");
            else
                rear--;
        }

        else if(strcmp(op,"front")==0)
        {
            if(front==-1)
                printf("-1\n");
            else
                printf("%d\n",dq[front]);
        }

        else if(strcmp(op,"back")==0)
        {
            if(front==-1)
                printf("-1\n");
            else
                printf("%d\n",dq[rear]);
        }
    }

    return 0;
}