#include <stdio.h>
#include <stdlib.h>

struct node{
  int exp;
  int base;
  struct node* next;
};

struct node* add(struct node *head, int b, int e){
    struct node* temp=(struct node*) malloc(sizeof(struct node));
    if (temp==NULL){
        printf("No memory space\n");
    }
    else{
        temp->exp=e;
        temp->base=b;
        temp->next=NULL;
        if (head==NULL) return temp;
        
        struct node* p=head;
        if (p->exp<e){
            temp->next=p;
            return temp;
        }
        
        while(p->next!=NULL && p->next->exp>e){
            p=p->next;
        }
        
        if (p->next!=NULL && p->next->exp==e){
            p->next->base+=b;
            return head;
        }
        
        temp->next=p->next;
        p->next=temp;
        return head;
    }
}

void print_poly(struct node* p){
    while(p!=NULL){
        printf("%d^%d",p->base,p->exp);
        if (p->next!=NULL){
            printf(" + ");
        }
        p=p->next;
    }
}
int main(){
    struct node* head=NULL;
    head=add(head,5,5);
    head=add(head,9,3);
    head=add(head,8,3);
    head=add(head,8,2);
    head=add(head,9,1);
    head=add(head,56,7);
    print_poly(head);
    return 0;
}
