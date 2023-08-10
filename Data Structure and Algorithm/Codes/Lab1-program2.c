/*Write a program to create a function pop which delete elements from the stack*/
#include <stdio.h>
#define Max 5

int stack[Max];
int top=-1;

void push(int data){
    if (top==Max-1){
        printf("Stack overflow\n");
        return;
    }
    top++;
    stack[top]=data;
}

int pop(){
    if (top==-1){
        printf("Stack underflow\n");
    }
    int r=stack[top];
    top--;
    return r;
}

void print_stack(){
    if (top==-1){
        printf("| _ |\n\n");
        return;
    }
    for (int i=top; i>=0; i--){
        printf("| %d |\n",stack[i]);
    }
    printf("\n");
}

int main(){
    push(34);
    push(45);
    push(90);
    
    print_stack();
    printf("Deleted element: %d\n",pop());
    print_stack();
    printf("Deleted element: %d\n",pop());
    print_stack();
    return 0;
}