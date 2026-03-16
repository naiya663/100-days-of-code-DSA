#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left,*right;
};

struct node* createNode(int x)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(struct node* root)
{
    if(root==NULL)
        return;

    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

int main()
{
    int n,i;
    scanf("%d",&n);

    int a[100];
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    struct node* nodes[100];

    for(i=0;i<n;i++)
    {
        if(a[i]==-1)
            nodes[i]=NULL;
        else
            nodes[i]=createNode(a[i]);
    }

    for(i=0;i<n;i++)
    {
        if(nodes[i]!=NULL)
        {
            int l=2*i+1;
            int r=2*i+2;

            if(l<n)
                nodes[i]->left=nodes[l];
            if(r<n)
                nodes[i]->right=nodes[r];
        }
    }

    inorder(nodes[0]);

    return 0;
}