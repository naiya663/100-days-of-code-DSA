#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node{
    int data;
    struct node *next;
};

struct node *top=NULL;

void push(int x){
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=top;
    top=temp;
}

int pop(){
    struct node *temp;
    int x;
    temp=top;
    x=temp->data;
    top=temp->next;
    free(temp);
    return x;
}

int main(){
    char exp[]="231*+9-";
    int i=0,a,b;

    while(exp[i]!='\0'){
        if(isdigit(exp[i])){
            push(exp[i]-'0');
        }
        else{
            b=pop();
            a=pop();
            if(exp[i]=='+') push(a+b);
            else if(exp[i]=='-') push(a-b);
            else if(exp[i]=='*') push(a*b);
            else if(exp[i]=='/') push(a/b);
        }
        i++;
    }

    printf("Result = %d",pop());
}