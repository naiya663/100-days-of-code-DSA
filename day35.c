#include <stdio.h>

int main()
{
    int queue[100], front = 0, rear = -1;
    int n, i;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &queue[++rear]);
    }

    for(i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    return 0;
}