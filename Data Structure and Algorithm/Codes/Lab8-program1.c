//Inorder, Preorder and Postorder traversal
#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node *left,*right;
};

void preorder(struct node *p){
    if (p==NULL) return;
    printf("%d ",p->data);
    preorder(p->left);
    preorder(p->right);
}

void inorder(struct node *p){
    if (p==NULL) return;
    preorder(p->left);
    printf("%d ",p->data);
    preorder(p->right);
}

void postorder(struct node *p){
    if (p==NULL) return;
    preorder(p->left);
    preorder(p->right);
    printf("%d ",p->data);
}

struct node* insert(struct node *p,int data){
    if (p==NULL){
        struct node* temp=(struct node *)malloc(sizeof(struct node));
        temp->data=data;
        temp->left=NULL;
        temp->right=NULL;
        return temp;
    }
    if (p->data > data){
        p->left=insert(p->left,data);
    }
    if (p->data < data){
        p->right=insert(p->right,data);
    }
    return p;
}

int main(){
    printf("Aayush Kukreja\n");
    printf("1/22/FET/BCS/159\n\n");
    
    int a[10]={23,4,78,9,12,23,5,89,67,55};
    struct node *root=NULL;
    
    for (int i=0; i<10; i++){
        root=insert(root,a[i]);
    }
    printf("Preorder: ");
    preorder(root);
    printf("\n");
    printf("Inorder: ");
    inorder(root);
    printf("\n");
    printf("Postorder: ");
    postorder(root);
    printf("\n");
    return 0;
}
