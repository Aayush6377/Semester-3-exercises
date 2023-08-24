#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* link;
};

struct node* create(int data){
    struct node* temp=(struct node*) malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;
    return temp;
}

struct node* insert(struct node* p,int data,int pos){
    struct node* t=create(data);
    if (t==NULL){
        printf("Memory full\n");
    }
    else{
        if (p==NULL){
            printf("Error linked list not created\n");
            return NULL;
        }
        if (pos==1){
            t->link=p;
            p=t;
            return p;
        }
        if (pos==-1){
            struct node* u=p;
            while (u->link!=NULL) u=u->link;
            u->link=t;
            return p;
        }
        
        struct node* u=p;
        for (int i=0; i<pos-2;i++) u=u->link;
        
        return p;
    }
}

void display(struct node* p){
    if (p==NULL){
        printf("Linked list is empty\n");
        return;
    }
    while(p!=NULL){
        printf("| %d |->",p->data);
        p=p->link;
    }
    printf("NULL\n");
}

struct node* del(struct node *p, int pos){
    if (p==NULL){
        printf("Linked list is empty\n");
    }
    else{
        struct node* temp=p,*save;
        if (pos==1){
            p=p->link;
            free(temp);
            return p;
        }
        if (pos==-1){
            while(temp->link->link!=NULL) temp=temp->link;
            free(temp->link);
            temp->link=NULL;
            return p;
        }
        for (int i=0; i<pos-2; i++) temp=temp->link;
        save=temp->link;
        temp->link=save->link;
        free(save);
        return p;
    }
}
int main(){
    struct node* head=NULL;
    printf("Operations of linked list:\n");
    printf("1) Create new linked list\n");
    printf("2) Insert at the beginning\n");
    printf("3) Insert at the end\n");
    printf("4) Display\n");
    printf("5) Delete from beginning\n");
    printf("6) Delete from end\n");
    printf("7) Delete at a position\n");
    printf("8) Exit\n");
    int ask,data,exit=1;

    while(exit){
        printf("Enter choice: ");
        scanf("%d",&ask);
        switch(ask){
            case 1:
               printf("Enter 1st element: ");
               scanf("%d",&data);
               head=create(data);
               break;
            case 2:
               printf("Enter data: ");
               scanf("%d",&data);
               head=insert(head,data,1);
               break;
            case 3:
               printf("Enter data: ");
               scanf("%d",&data);
               head=insert(head,data,-1);
               break;
            case 4:
               display(head);
               break;
            case 5:
               head=del(head,1);
               break;
            case 6:
               head=del(head,-1);
               break;
            case 7:
               printf("Enter position: ");
               scanf("%d",&data);
               head=del(head,data);
               break;
            case 8:
               exit=0;
               printf("Program terminated\n");
               break;
            default:
               printf("Wrong choice\n");
               break;
        }
    }
    return 0;
}
