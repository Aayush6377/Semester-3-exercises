#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
} *top=NULL;

int isempty(){
    if (top==NULL) return 1;
    else return 0;
}

void push(int data){
    struct node* temp=(struct node*) malloc(sizeof(struct node));
    if (temp==NULL){
        printf("Stack overflow\n");
        return;
    }
    temp->data=data;
    temp->next=top;
    top=temp;
}

int pop(){
    if (isempty()){
        printf("Stack underflow\n");
    }
    else{
        struct node* p=top;
        int d=p->data;
        top=top->next;
        p->next=NULL;
        free(p);
        return d;
    }
}

void print_stack(){
    if (isempty()){
        printf("| _ |\n\n");
        return;
    }
    struct node *p=top;
    while(p!=NULL){
        printf("| %d |\n",p->data);
        p=p->next;
    }
    printf("\n");
}
