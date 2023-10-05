//C program to construct a binary tree
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left,*right;
};

struct node* create(){
    int ask;
    printf("Do you want to add a node: ");
    scanf("%d",&ask);
    if (ask==0){
        return NULL;
    }
    else{
        struct node* temp=(struct node*) malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&temp->data);
        
        printf("For %d left child: \n",temp->data);
        temp->left=create();
        
        printf("For %d right child: \n",temp->data);
        temp->right=create();
        return temp;
    }
}

void preorder(struct node* p){
    if (p==NULL){
        return;
    }
    printf("%d ",p->data);
    preorder(p->left);
    preorder(p->right);
}

int main(){
    struct node* root=create();
    printf("Preorder traversal: ");
    preorder(root);
    return 0;
}
