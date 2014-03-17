#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *leftchild;
    struct Node *rightchild;
} Node;

void InitBinaryTree(Node**root,int elem)
{
    *root=(Node*)malloc(sizeof(Node));
    if(!(*root))
    {
        printf("Memory allocation for root failed.\n");
        return;
    }
    (*root)->data=elem;
    (*root)->leftchild=NULL;
    (*root)->rightchild=NULL;
}

void InsertNode(Node *root,int elem)
{
    Node *newnode=NULL;
    Node *p=root,*last_p=NULL;

    newnode=(Node*)malloc(sizeof(Node));
    if(!newnode)
    {
        printf("Memory allocation for newnode failed.\n");
        return;
    }
    newnode->data=elem;
    newnode->leftchild=NULL;
    newnode->rightchild=NULL;

    while(NULL!=p)
    {
        last_p=p;
        if(newnode->data<p->data)
        {
            p=p->leftchild;
        }
        else if(newnode->data>p->data)
        {
            p=p->rightchild;
        }
        else
        {
            printf("Node to be inserted has existed.\n");
            free(newnode);
            return;
        }
    }
    p=last_p;
    if(newnode->data<p->data)
    {
        p->leftchild=newnode;
    }
    else
    {
        p->rightchild=newnode;
    }
}

void CreatBinarySearchTree(Node **root,int data[],int num)
{
    int i;

    for(i=0;i<num;i++)
    {
        if(NULL==*root)
        {
            InitBinaryTree(root,data[i]);
        }
        else
        {
            InsertNode(*root,data[i]);
        }
    }
}

void PreOrderRec(Node *root)
{
    if(NULL!=root)
    {
        printf("%d  ",root->data);
        PreOrderRec(root->leftchild);
        PreOrderRec(root->rightchild);
    }
}

void PreOrderNoRec(Node *root)
{
    Node *p=root;
    Node *stack[30];
    int num=0;
    while(NULL!=p||num>0)
    {
        while(NULL!=p)
        {
            printf("%d  ",p->data);
            stack[num++]=p;
            p=p->leftchild;
        }
        num--;
        p=stack[num];
        p=p->rightchild;
    }
    printf("\n");
}

void InOrderRec(Node *root)
{
    if(NULL!=root)
    {
        InOrderRec(root->leftchild);
        printf("%d  ",root->data);
        InOrderRec(root->rightchild);
    }
}

void InOrderNoRec(Node *root)
{
    Node *p=root;
    int num=0;
    Node *stack[30];
    while(NULL!=p||num>0)
    {
        while(NULL!=p)
        {
            stack[num++]=p;
            p=p->leftchild;
        }
        num--;
        p=stack[num];
        printf("%d  ",p->data);
        p=p->rightchild;
    }
    printf("\n");
}

void PostOrderRec(Node *root)
{
    if(NULL!=root)
    {
        PostOrderRec(root->leftchild);
        PostOrderRec(root->rightchild);
        printf("%d  ",root->data);
    }
}

void PostOrderNoRec(Node *root)
{
    Node *p=root;
    Node *stack[30];
    int num=0;
    Node *have_visited=NULL;

    while(NULL!=p||num>0)
    {
        while(NULL!=p)
        {
            stack[num++]=p;
            p=p->leftchild;     
        }
        p=stack[num-1];
        if(NULL==p->rightchild||have_visited==p->rightchild)
        {
            printf("%d  ",p->data);
            num--;
            have_visited=p;
            p=NULL;
        }
        else
        {
            p=p->rightchild;
        }
    }
    printf("\n");
}

int main()
{
    Node *root=NULL;
    int num=0;
/*    int data[]={5,2,4,0,0,5,0,0,3,6,8,0,10,0,7,0,9};*/
    int data[]={2,5,8,4,7};
    num=sizeof(data)/sizeof(int);

    CreatBinarySearchTree(&root,data,num);

    printf("This is Preorder traversal.\n");
    PreOrderNoRec(root);
    PreOrderRec(root);
    printf("\n");

    printf("This is Inorder traversal.\n");
    InOrderNoRec(root);
    InOrderRec(root);
    printf("\n");

    printf("This is Postorder traversal.\n");
    PostOrderNoRec(root);
    PostOrderRec(root);
    printf("\n");

    return 0;

}


/*
        2  
             5
          4     8
              7

*/
