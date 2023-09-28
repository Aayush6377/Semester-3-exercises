#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct node{
  int exp;
  int base;
  struct node* next;
};

struct node* Add(struct node *head, int b, int e){
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
        while(p->next!=NULL && p->next->exp>e){
            p=p->next;
        }
        
        if (p->next->exp==e){
            p->next->base+=b;
            return head;
        }
        
        temp->next=p->next;
        p->next=temp;
        return head;
    }
}

int main(){
    return 0;
}
