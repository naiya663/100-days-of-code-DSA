#include <stdio.h>

int main()
{
    int stack[100];
    int top = -1;
    int n, m, x;

    scanf("%d",&n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d",&x);
        stack[++top] = x;
    }

    scanf("%d",&m);

    for(int i = 0; i < m; i++)
    {
        if(top != -1)
            top--;
    }

    for(int i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }

    return 0;
}