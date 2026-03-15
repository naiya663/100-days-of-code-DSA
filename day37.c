#include <stdio.h>
#include <string.h>

int main()
{
    int q[100], n, size = 0, i, j, x;
    char op[10];

    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%s", op);

        if(strcmp(op,"insert")==0)
        {
            scanf("%d",&x);
            j = size - 1;

            while(j >= 0 && q[j] > x)
            {
                q[j+1] = q[j];
                j--;
            }

            q[j+1] = x;
            size++;
        }

        else if(strcmp(op,"delete")==0)
        {
            if(size == 0)
                printf("-1\n");
            else
            {
                printf("%d\n", q[0]);
                for(j = 1; j < size; j++)
                    q[j-1] = q[j];
                size--;
            }
        }

        else if(strcmp(op,"peek")==0)
        {
            if(size == 0)
                printf("-1\n");
            else
                printf("%d\n", q[0]);
        }
    }

    return 0;
}