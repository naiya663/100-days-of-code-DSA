#include <stdio.h>

int main()
{
    int q[100], n, m;
    int front = 0, rear = -1, size = 100;
    int i;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        rear = (rear + 1) % size;
        q[rear] = x;
    }

    scanf("%d", &m);

    for(i = 0; i < m; i++)
    {
        front = (front + 1) % size;
    }

    int count = n;
    for(i = 0; i < count; i++)
    {
        printf("%d ", q[(front + i) % size]);
    }

    return 0;
}