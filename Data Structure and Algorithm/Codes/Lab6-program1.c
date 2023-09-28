//Stack implementation using linked list
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
        printf("| _ |\n");
        return;
    }
    struct node *p=top;
    while(p!=NULL){
        printf("| %d |\n",p->data);
        p=p->next;
    }
}

int main(){
    
    printf("Operations:\n");
    printf("1) Push\n2) Pop\n3) Print\n4) Quit\n");
    int ask=0;
    
    while(ask!=4){
        printf("Enter operation: ");
        scanf("%d",&ask);
        switch(ask){
            case 1:
               int data;
               printf("Enter data: ");
               scanf("%d",&data);
               push(data);
               print_stack();
               break;
            case 2:
               printf("Deleted element: %d\n",pop());
               print_stack();
               break;
            case 3:
               print_stack();
               break;
            case 4:
               printf("Program terminated\n");
               break;
            default:
              printf("Wrong operation!!!");
        }
    }
    return 0;
}
