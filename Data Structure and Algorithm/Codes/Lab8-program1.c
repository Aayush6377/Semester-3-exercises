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
    inorder(p->left);
    printf("%d ",p->data);
    inorder(p->right);
}

void postorder(struct node *p){
    if (p==NULL) return;
    postorder(p->left);
    postorder(p->right);
    printf("%d ",p->data);
}

struct node* create(int data){
    struct node* temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

struct node* insert(struct node *p,int data){
    if (p==NULL){
        return create(data);
    }
    else if (p->data > data){
        p->left=insert(p->left,data);
    }
    else if (p->data < data){
        p->right=insert(p->right,data);
    }
    return p;
}

int main(){
    printf("Aayush Kukreja\n");
    printf("1/22/FET/BCS/159\n\n");
    
    int a[5]={23,45,56,3,12};
    struct node *root=NULL;
    
    for (int i=0; i<5; i++){
        root=insert(root,a[i]);
        preorder(root);
        printf("\n");
    }
    printf("\nBST created!!!\n");
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
