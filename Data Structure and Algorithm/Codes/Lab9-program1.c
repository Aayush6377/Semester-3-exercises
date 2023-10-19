#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left, *right;
};

void traverse(struct node* p,int i){
    if (p==NULL) return;
    if (i==1) printf("%d ",p->data);
    traverse(p->left,i);
    if (i==2) printf("%d ",p->data);
    traverse(p->right,i);
    if (i==3) printf("%d ",p->data);
}

int search(int array[],int key,int l, int h){
    for (int i=l;i<=h;i++){
        if (array[i]==key){
            return i;
        }
    }
    return -1;
}

struct node* newnode(int data){
    struct node* p=(struct node*) malloc(sizeof(struct node));
    p->data=data;
    p->left=NULL;
    p->right=NULL;
    return p;
}

struct node* create(int pre[],int in[],int l, int h){
    static int i=0;
    if (l>h) return NULL;
    struct node* temp=newnode(pre[i]);
    int index=search(in,pre[i],l,h);
    i++;
    if (l==h) return temp;
    temp->left=create(pre,in,l,index-1);
    temp->right=create(pre,in,index+1,h);
    return temp;
}

int main(){
    struct node* root=NULL;
    int n;
    printf("Enter no. of nodes: ");
    scanf("%d",&n);
    
    int pre[n],in[n];
    printf("Enter preorder: ");
    for (int i=0;i<n;i++) scanf("%d",&pre[i]);
    
    printf("Enter inorder: ");
    for (int j=0;j<n;j++) scanf("%d",&in[j]);
    
    root=create(pre,in,0,n-1);
    printf("Binary Tree Created!!!\n");
    
    printf("Preorder: ");
    traverse(root,1);
    printf("\n");
    
    printf("Inorder: ");
    traverse(root,2);
    printf("\n");
    
    printf("Postorder: ");
    traverse(root,3);
    printf("\n");
    return 0;
}
