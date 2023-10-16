#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node *left, *right;
};

struct node* insert(struct node*p,int key){
    if (p==NULL){
        struct node* temp=(struct node*)malloc(sizeof(struct node));
        temp->data=key;
        temp->left=NULL;
        temp->right=NULL;
        return temp;
    }
    if (p->data > key){
        p->left=insert(p->left,key);
    }
    else if(p->data < key){
        p->right=insert(p->right,key);
    }
    return p;
}

struct node* findmin(struct node*p){
    if (p==NULL) return p;
    while(p->left!=NULL) p=p->left;
    return p;
}

struct node* del(struct node*p, int key){
    if (p==NULL){
        return NULL;
    }
    if (p->data > key){
        p->left=del(p->left,key);
    }
    else if (p->data < key){
        p->right=del(p->right,key);
    }
    else{
        struct node* temp;
        if (p->left==NULL){
            temp=p;
            p=p->right;
            temp->right=NULL;
            free(temp);
        }
        else if (p->right==NULL){
            temp=p;
            p=p->left;
            temp->left=NULL;
            free(temp);
        }
        else{
            temp=findmin(p->right);
            p->data=temp->data;
            p->right=del(p->right,temp->data);
        }
    }
    return p;
}

void preorder(struct node* p){
    if (p==NULL) return;
    printf("%d ",p->data);
    preorder(p->left);
    preorder(p->right);
}
int main(){
    struct node* root=NULL;
    printf("Operations:- \n");
    printf("1) Insert\n");
    printf("2) Delete\n");
    printf("3) Preorder\n");
    printf("4) Quit\n");
    
    int ask=0;
    while(ask!=4){
        printf("Enter task: ");
        scanf("%d",&ask);
        int n;
        switch(ask){
            case 1:
               printf("Enter data to be inserted: ");
               scanf("%d",&n);
               root=insert(root,n);
               preorder(root);
               break;
            case 2:
               printf("Enter data to be deleted: ");
               scanf("%d",&n);
               root=del(root,n);
               preorder(root);
               break;
            case 3:
               preorder(root);
               break;
            case 4:
               ask=4;
               break;
            default:
               printf("Wrong operation");
        }
        printf("\n");
    }
    return 0;
}
