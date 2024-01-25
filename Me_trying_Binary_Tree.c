#include <stdio.h>
#include <stdlib.h>

typedef struct Tree{
    struct Tree* left;
    int data;
    struct Tree* right;
}tree;

int depth=0;
tree* root=NULL;
tree* new,*temp;

tree* creation(){
    tree* h=NULL;
    printf("\nEnter the no of data to be entered -> ");
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        new =(tree*)malloc(sizeof(tree));
        printf("\nEnter Data -> ");
        scanf("%d",&new->data);
        new->left =NULL;
        new->right =NULL;
}