#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    return stack[top--];
}

int priority(char x)
{
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}

int main()
{
    char exp[100];
    char ch;

    printf("Enter infix expression: ");
    scanf("%s", exp);

    int i = 0;

    while(exp[i] != '\0')
    {
        ch = exp[i];

        if(isalnum(ch))
            printf("%c", ch);

        else
        {
            while(top != -1 && priority(stack[top]) >= priority(ch))
                printf("%c", pop());

            push(ch);
        }

        i++;
    }

    while(top != -1)
        printf("%c", pop());

    return 0;
}