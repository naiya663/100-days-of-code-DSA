#include <stdio.h>
#include <string.h>

int heap[100];
int size = 0;

void insert(int x)
{
    int i = size++;
    heap[i] = x;

    while(i != 0 && heap[(i-1)/2] > heap[i])
    {
        int temp = heap[i];
        heap[i] = heap[(i-1)/2];
        heap[(i-1)/2] = temp;
        i = (i-1)/2;
    }
}

int extractMin()
{
    if(size <= 0)
        return -1;

    int root = heap[0];
    heap[0] = heap[size-1];
    size--;

    int i = 0;

    while(1)
    {
        int left = 2*i + 1;
        int right = 2*i + 2;
        int smallest = i;

        if(left < size && heap[left] < heap[smallest])
            smallest = left;

        if(right < size && heap[right] < heap[smallest])
            smallest = right;

        if(smallest != i)
        {
            int temp = heap[i];
            heap[i] = heap[smallest];
            heap[smallest] = temp;
            i = smallest;
        }
        else
            break;
    }

    return root;
}

int peek()
{
    if(size == 0)
        return -1;
    return heap[0];
}

int main()
{
    int n, x;
    char op[20];

    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        scanf("%s",op);

        if(strcmp(op,"insert")==0)
        {
            scanf("%d",&x);
            insert(x);
        }
        else if(strcmp(op,"extractMin")==0)
        {
            printf("%d\n",extractMin());
        }
        else if(strcmp(op,"peek")==0)
        {
            printf("%d\n",peek());
        }
    }

    return 0;
}