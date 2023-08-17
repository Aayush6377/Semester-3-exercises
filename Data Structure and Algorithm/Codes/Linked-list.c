//Linked list
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* link;
};

struct node* addnode(struct node* p,int data){
    struct node* temp=(struct node*) malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;
    if (p==NULL){
        p=temp;
        return p;
    }
    struct node* a=p;
    while(a->link!=NULL){
        a=a->link;
    }
    a->link=temp;
    return p;
}

int main(){
    struct node* head=NULL;
    printf("Enter elements: ");
    char c=' ';
    while(c!='\n'){
        int i;
        scanf("%d",&i);
        head=addnode(head,i);
        c=getchar();
    }
    printf("Linked list form:\n");
    struct node* p=head;
    while(p!=NULL){
        printf("| %d |->",p->data);
        p=p->link;
    }
    printf("NULL");
    return 0;
}
