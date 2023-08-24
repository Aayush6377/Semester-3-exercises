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

struct node* insert_begin(struct node* p,int data){
    struct node* t=create(data);
    if (t==NULL){
        printf("Memory full\n");
    }
    else{
        if (p==NULL){
            printf("Error linked list not created\n");
            return NULL;
        }
        t->link=p;
        p=t;
        return p;
    }
}

struct node* insert_end(struct node* q, int data){
    struct node* t=create(data);
    if (t==NULL){
        printf("Memory full\n");
    }
    else{
        if (q==NULL){
            printf("Error linked list not created\n");
            return NULL;
        }
        struct node* u=q;
        while(u->link!=NULL) u=u->link;
        u->link=t;
        return q;
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

int main(){
    struct node* head=NULL;
    printf("Operations of linked list:\n");
    printf("1) Create new linked list\n");
    printf("2) Insert at the beginning\n");
    printf("3) Insert at the end\n");
    printf("4) Display\n");
    printf("5) Exit\n");
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
               head=insert_begin(head,data);
               break;
            case 3:
               printf("Enter data: ");
               scanf("%d",&data);
               head=insert_end(head,data);
               break;
            case 4:
               display(head);
               break;
            case 5:
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
